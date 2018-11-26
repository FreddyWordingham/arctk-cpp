/**
 *  @file   arctk/opt/sop/raman.inl
 *  @date   13/11/2018
 *  @author Freddy Wordingham
 *
 *  Raman specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_RAMAN_INL
#define ARCTK_OPT_SOP_RAMAN_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>

//  -- Arctk --
#include <arctk/consts/math.hpp>
#include <arctk/dom/cell.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace sop //! specific-optical-properties namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a raman scattering specific-optical-property.
             *
             *  @param  ref_index_          Refractive index.
             *  @param  interaction_coef_   Interaction coefficient.
             *  @param  albedo_             Single scattering albedo.
             *  @param  raman_prob_         Raman scattering probability.
             *  @param  wavelength_delta_   Wavelength change to occur during a raman scattering event.
             *  @param  asym_               Asymmetry parameter.
             *
             *  @pre    ref_index_ must be greater than, or equal to, unity.
             *  @pre    interaction_coef_ must be positive.
             *  @pre    albedo_ must be positive.
             *  @pre    albedo_ must less than, or equal to, unity.
             *  @pre    raman_prob_ must be positive.
             *  @pre    raman_prob_ must less than, or equal to, unity.
             *  @pre    asym_ must greater than, or equal to, minus one.
             *  @pre    asym_ must less than, or equal to, unity.
             */
            inline Raman::Raman(const double ref_index_, const double interaction_coef_, const double albedo_, const double raman_prob_, const double wavelength_delta_, const double asym_) noexcept
              : _ref_index(ref_index_)
              , _interaction_coef(interaction_coef_)
              , _albedo(albedo_)
              , _raman_prob(raman_prob_)
              , _wavelength_delta(wavelength_delta_)
              , _asym(asym_)
            {
                assert(ref_index_ >= 1.0);
                assert(interaction_coef_ > 0.0);
                assert(albedo_ >= 0.0);
                assert(albedo_ <= 1.0);
                assert(raman_prob_ >= 0.0);
                assert(raman_prob_ <= 1.0);
                assert(asym_ >= -1.0);
                assert(asym_ <= 1.0);
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Raman::ref_index() const noexcept
            {
                return (_ref_index);
            }

            inline double Raman::interaction_coef() const noexcept
            {
                return (_interaction_coef);
            }

            /**
             *  Get the distance until the next interaction event.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    rng_ may not be nullptr.
             *
             *  @return Distance until the next interaction event.
             */
            inline double Raman::interact_dist(random::Generator* rng_, const dom::Cell* /*unused*/) const noexcept
            {
                assert(rng_ != nullptr);

                return (-std::log(rng_->gen()) / _interaction_coef);
            }


            //  -- Interaction --
            /**
             *  Perform an interaction event on the photon.
             *
             *  @param  rng_    Random number generator.
             *  @param  phot_   Photon to interact with.
             *  @param  cell_   Current domain cell.
             *  @param  dist_   Distance to the interaction event.
             *
             *  @return True if the photon's specific-optical-properties require updating after the interaction event.
             */
            inline bool Raman::interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, const double dist_) const noexcept
            {
                cell_->add_energy(dist_ * phot_->energy() * phot_->weight());
                cell_->add_absorb(phot_->weight() * (1.0 - _albedo));
                cell_->add_scatter(phot_->weight());

                phot_->move(dist_, _ref_index);
                phot_->multiply_weight(_albedo);
                phot_->rotate(random::distribution::henyey_greenstein(rng_, _asym), rng_->gen() * consts::math::TWO_PI);

                if (rng_->gen() > _raman_prob)
                {
                    phot_->shift_wavelength(_wavelength_delta);
                    phot_->rotate(random::distribution::henyey_greenstein(rng_, 0.0), rng_->gen() * consts::math::TWO_PI);

                    return (true);
                }

                return (false);
            }



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_RAMAN_INL
