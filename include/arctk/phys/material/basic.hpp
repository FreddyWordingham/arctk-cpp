/**
 *  @file   arctk/phys/material/basic.hpp
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  basic material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_BASIC_HPP
#define ARCTK_PHYS_MATERIAL_BASIC_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/material.hpp>
#include <arctk/phys/optical.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Basic material particle class.
             */
            class Basic : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Optical --
                const math::formula::Linear _ref_index;     //!< Refractive index as a function of wavelength.
                const math::formula::Linear _interact_coef; //!< Interaction coefficient albedo as a function of wavelength.
                const math::formula::Linear _albedo;        //!< Single scattering albedo as a function of wavelength.
                const math::formula::Linear _asym;          //!< Asymmetry parameter as a function of wavelength.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Basic(const std::vector<double>& wavelength_, const std::vector<double>& ref_index_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& asym_) noexcept;

              private:
                //  -- Initialisation --
                inline math::formula::Linear init_interact_coef(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_) const noexcept;
                inline math::formula::Linear init_albedo(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Properties --
                inline void set_optical_props(particle::Photon* phot_) const noexcept override;

                //  -- Interaction --
                inline double interaction_dist(random::Generator* rng_, const particle::Photon& phot_) const noexcept override;
                inline void   interact(random::Generator* rng_, particle::Photon* phot_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a basic material.
             *
             *  @param  wavelength_ Vector of wavelengths.
             *  @param  ref_index_  Vector of corresponding refractive indices.
             *  @param  scat_coef_  Vector of corresponding scattering coefficients.
             *  @param  abs_coef_   Vector of corresponding absorption coefficients.
             *  @param  asym_       Vector of corresponding asymmetry parameters.
             *
             *  @pre    wavelength_ must contain multiple values.
             *  @pre    ref_index_ must contain multiple values.
             *  @pre    scat_coef_ must contain multiple values.
             *  @pre    abs_coef_ must contain multiple values.
             *  @pre    asym_ must contain multiple values.
             *  @pre    wavelength_ size must match ref_index_ size.
             *  @pre    wavelength_ size must match scat_coef_ size.
             *  @pre    wavelength_ size must match abs_coef_ size.
             *  @pre    wavelength_ size must match asym_ size.
             *  @pre    wavelength_ values must be in ascending order.
             *  @pre    wavelength_ values must all be non-negative.
             *  @pre    scat_coef_ values must all be non-negative.
             *  @pre    abs_coef_ values must all be non-negative.
             *  @pre    asym_ values must all be greater than, or equal to, minus one.
             *  @pre    asym_ values must all be less than, or equal to, unity.
             */
            inline Basic::Basic(const std::vector<double>& wavelength_, const std::vector<double>& ref_index_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& asym_) noexcept
              : Material(wavelength_.front(), wavelength_.back())
              , _ref_index(math::formula::Linear(wavelength_, ref_index_))
              , _interact_coef(init_interact_coef(wavelength_, scat_coef_, abs_coef_))
              , _albedo(init_albedo(wavelength_, scat_coef_, abs_coef_))
              , _asym(math::formula::Linear(wavelength_, asym_))
            {
                PRE(wavelength_.size() > 1);
                PRE(ref_index_.size() > 1);
                PRE(scat_coef_.size() > 1);
                PRE(abs_coef_.size() > 1);
                PRE(asym_.size() > 1);
                PRE(wavelength_.size() == ref_index_.size());
                PRE(wavelength_.size() == scat_coef_.size());
                PRE(wavelength_.size() == abs_coef_.size());
                PRE(wavelength_.size() == asym_.size());
                PRE(utl::properties::ascending(wavelength_));
                PRE(utl::properties::always_greater_than_or_equal_to(wavelength_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(scat_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(abs_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(asym_, -1.0));
                PRE(utl::properties::always_less_than_or_equal_to(asym_, 1.0));
            }


            //  -- Initialisation --
            /**
             *  Initialise the interaction coefficient formula.
             *  Interaction coefficient values are calculated from the sum of coefficient values.
             *
             *  @param  wavelength_ Vector of wavelengths.
             *  @param  scat_coef_  Vector of corresponding scattering coefficients.
             *  @param  abs_coef_   Vector of corresponding absorption coefficients.
             *
             *  @pre    wavelength_ must contain multiple values.
             *  @pre    scat_coef_ must contain multiple values.
             *  @pre    abs_coef_ must contain multiple values.
             *  @pre    wavelength_ size must match scat_coef_ size.
             *  @pre    wavelength_ size must match abs_coef_ size.
             *  @pre    wavelength_ values must be in ascending order.
             *  @pre    wavelength_ values must all be non-negative.
             *  @pre    scat_coef_ values must all be non-negative.
             *  @pre    abs_coef_ values must all be non-negative.
             *
             *  @post   interact_coef values must all be positive.
             *
             *  @return Interaction coefficient formula.
             */
            inline math::formula::Linear Basic::init_interact_coef(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_) const noexcept
            {
                PRE(wavelength_.size() > 1);
                PRE(scat_coef_.size() > 1);
                PRE(abs_coef_.size() > 1);
                PRE(wavelength_.size() == scat_coef_.size());
                PRE(wavelength_.size() == abs_coef_.size());
                PRE(utl::properties::ascending(wavelength_));
                PRE(utl::properties::always_greater_than_or_equal_to(wavelength_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(scat_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(abs_coef_, 0.0));

                std::vector<double> interact_coef(wavelength_.size());

                for (size_t i = 0; i < interact_coef.size(); ++i)
                {
                    interact_coef[i] = scat_coef_[i] + abs_coef_[i];
                }

                POST(utl::properties::always_greater_than(interact_coef, 0.0));

                return (math::formula::Linear(wavelength_, interact_coef));
            }

            /**
             *  Initialise the singled scattering albedo formula.
             *  Single scattering albedo is calculated by one minus the ratio of the absorption coefficient to the sum of all of the coefficients.
             *
             *  @param  wavelength_ Vector of wavelengths.
             *  @param  scat_coef_  Vector of corresponding scattering coefficients.
             *  @param  abs_coef_   Vector of corresponding absorption coefficients.
             *
             *  @pre    wavelength_ must contain multiple values.
             *  @pre    scat_coef_ must contain multiple values.
             *  @pre    abs_coef_ must contain multiple values.
             *  @pre    wavelength_ size must match scat_coef_ size.
             *  @pre    wavelength_ size must match abs_coef_ size.
             *  @pre    wavelength_ values must be in ascending order.
             *  @pre    wavelength_ values must all be non-negative.
             *  @pre    scat_coef_ values must all be non-negative.
             *  @pre    abs_coef_ values must all be non-negative.
             *
             *  @post   albedo values must all be non-negative.
             *  @post   albedo values must all be less than, or equal to, unity.
             *
             *  @return Singled scattering albedo formula.
             */
            inline math::formula::Linear Basic::init_albedo(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_) const noexcept
            {
                PRE(wavelength_.size() > 1);
                PRE(scat_coef_.size() > 1);
                PRE(abs_coef_.size() > 1);
                PRE(wavelength_.size() == scat_coef_.size());
                PRE(wavelength_.size() == abs_coef_.size());
                PRE(utl::properties::ascending(wavelength_));
                PRE(utl::properties::always_greater_than_or_equal_to(wavelength_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(scat_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(abs_coef_, 0.0));

                std::vector<double> albedo(wavelength_.size());

                for (size_t i = 0; i < albedo.size(); ++i)
                {
                    albedo[i] = 1.0 - (abs_coef_[i] / (scat_coef_[i] + abs_coef_[i]));
                }

                POST(utl::properties::always_greater_than_or_equal_to(albedo, 0.0));
                POST(utl::properties::always_less_than_or_equal_to(albedo, 1.0));

                return (math::formula::Linear(wavelength_, albedo));
            }



            //  == METHODS ==
            //  -- Properties --
            /**
             *  Set the optical properties of a photon.
             *
             *  @param  phot_   Photon to set the optical properties of.
             */
            inline void Basic::set_optical_props(particle::Photon* const phot_) const noexcept
            {
                phot_->set_optical_props(Optical(_ref_index(phot_->wavelength()), _interact_coef(phot_->wavelength()), _albedo(phot_->wavelength()), _asym(phot_->wavelength())));
            }


            //  -- Interaction --
            /**
             *  Determine the distance until a material interaction occurs.
             *
             *  @param  rng_    Random number generator.
             *  @param  phot_   Photon to interact with.
             *
             *  @return Distance to interaction.
             */
            inline double Basic::interaction_dist(random::Generator* rng_, const particle::Photon& phot_) const noexcept
            {
                return (-std::log(rng_->gen()) / phot_.opt().interact_coef());
            }

            /**
             *  Perform an interaction on a given photon.
             *
             *  @param  rng_    Random number generator.
             *  @param  phot_   Photon to interact with.
             */
            inline void Basic::interact(random::Generator* rng_, particle::Photon* phot_) const noexcept
            {
                phot_->multiply_weight(phot_->opt().albedo());
                phot_->rotate(random::distribution::henyey_greenstein(rng_, phot_->opt().asym()), rng_->gen() * 2.0 * consts::math::PI);
            }



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_BASIC_HPP
