/**
 *  @file   arctk/phys/material/fluorescent.hpp
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  Fluorescent material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_FLUORESCENT_HPP
#define ARCTK_PHYS_MATERIAL_FLUORESCENT_HPP



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
             *  Fluorescent material particle class.
             */
            class Fluorescent : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Optical --
                const math::formula::Linear _ref_index;
                const math::formula::Linear _interact_coef;
                const math::formula::Linear _albedo;
                const math::formula::Linear _asym;
                const math::formula::Linear _flu_prob;
                const math::formula::Linear _delta_wavelength;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fluorescent(const std::vector<double>& wavelength_, const std::vector<double>& ref_index_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& asym_,
                                   const std::vector<double>& flu_coef_, const std::vector<double>& delta_wavelength_) noexcept;

              private:
                //  -- Initialisation --
                inline math::formula::Linear init_interact_coef(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& flu_coef_) const noexcept;
                inline math::formula::Linear init_albedo(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& flu_coef_) const noexcept;
                inline math::formula::Linear init_flu_prob(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& flu_coef_) const noexcept;


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
            inline Flourescent::Flourescent(const std::vector<double>& wavelength_, const std::vector<double>& ref_index_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& asym_,
                                            const std::vector<double>& flu_coef_, const std::vector<double>& delta_wavelength_) noexcept
              : Material(wavelength_.front(), wavelength_.back())
              , _ref_index(math::formula::Linear(wavelength_, ref_index_))
              , _interact_coef(init_interact_coef(wavelength_, scat_coef_, abs_coef_, flu_coef_))
              , _albedo(init_albedo(wavelength_, scat_coef_, abs_coef_, flu_coef_))
              , _asym(math::formula::Linear(wavelength_, asym_))
              , _flu_prob(init_albedo(wavelength_, scat_coef_, abs_coef_, flu_coef_))
              , _delta_wavelength(math::formula::Linear(wavelength_, delta_wavelength_))
            {
                PRE(wavelength_.size() > 1);
                PRE(ref_index_.size() > 1);
                PRE(scat_coef_.size() > 1);
                PRE(abs_coef_.size() > 1);
                PRE(asym_.size() > 1);
                PRE(flu_coef_.size() > 1);
                PRE(delta_wavelength_.size() > 1);
                PRE(wavelength_.size() == ref_index_.size());
                PRE(wavelength_.size() == scat_coef_.size());
                PRE(wavelength_.size() == abs_coef_.size());
                PRE(wavelength_.size() == asym_.size());
                PRE(wavelength_.size() == flu_coef_.size());
                PRE(wavelength_.size() == delta_wavelength_.size());
                PRE(utl::properties::ascending(wavelength_));
                PRE(utl::properties::always_greater_than_or_equal_to(wavelength_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(scat_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(abs_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(asym_, -1.0));
                PRE(utl::properties::always_less_than_or_equal_to(asym_, 1.0));
                PRE(utl::properties::always_greater_than_or_equal_to(flu_coef_, 0.0));
            }


            //  -- Initialisation --
            inline math::formula::Linear Fluorescent::init_interact_coef(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& flu_coef_) const noexcept
            {
                PRE(wavelength_.size() > 1);
                PRE(scat_coef_.size() > 1);
                PRE(abs_coef_.size() > 1);
                PRE(flu_coef_.size() > 1);
                PRE(wavelength_.size() == scat_coef_.size());
                PRE(wavelength_.size() == abs_coef_.size());
                PRE(wavelength_.size() == flu_coef_.size());
                PRE(utl::properties::ascending(wavelength_));
                PRE(utl::properties::always_greater_than_or_equal_to(wavelength_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(scat_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(abs_coef_, 0.0));
                PRE(utl::properties::always_greater_than_or_equal_to(flu_coef_, 0.0));

                std::vector<double> interact_coef(scat_coef_.size());

                for (size_t i = 0; i < interact_coef.size(); ++i)
                {
                    interact_coef[i] = scat_coef_[i] + abs_coef_[i] + flu_coef_[i];
                }

                POST(utl::properties::always_greater_than(interact_coef, 0.0));

                return (math::formula::Linear(wavelength_, interact_coef));
            }

            inline math::formula::Linear Fluorescent::init_albedo(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& flu_coef_) const noexcept
            {
            }

            inline math::formula::Linear Fluorescent::init_flu_prob(const std::vector<double>& wavelength_, const std::vector<double>& scat_coef_, const std::vector<double>& abs_coef_, const std::vector<double>& flu_coef_) const noexcept
            {
            }



            //  == METHODS ==
            //  -- Properties --
            inline void Flourescent::set_optical_props(particle::Photon* const phot_) const noexcept
            {
            }


            //  -- Interaction --
            inline double Flourescent::interaction_dist(random::Generator* rng_, const particle::Photon& phot_) const noexcept
            {
            }

            inline void Flourescent::interact(random::Generator* rng_, particle::Photon* phot_) const noexcept
            {
            }



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_FLUORESCENT_HPP
