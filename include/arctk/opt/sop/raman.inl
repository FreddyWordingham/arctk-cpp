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
            inline Raman::Raman(const double ref_index_, const double interaction_coef_, const double albedo_, const double raman_prob_, const double wavelength_delta_, const double asym_) noexcept
              : Sop(ref_index_)
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
            inline double Dumb::interact_dist(random::Generator* rng_, const dom::Cell* /*unused*/) const noexcept
            {
                assert(rng_ != nullptr);

                return (-std::log(rng_->gen()) / _interaction_coef);
            }


            //  -- Interaction --
            inline bool Dumb::interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, const double dist_) const noexcept
            {
                cell_->add_energy(dist_ * phot_->energy() * phot_->weight());
                cell_->add_absorb(phot_->weight() * (1.0 - _albedo));
                cell_->add_scatter(phot_->weight());

                phot_->move(dist_, _ref_index);
                phot_->multiply_weight(_albedo);
                phot_->rotate(random::distribution::henyey_greenstein(rng_, _asym), rng_->gen() * consts::math::TWO_PI);

                return (true);
            }



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_RAMAN_INL
