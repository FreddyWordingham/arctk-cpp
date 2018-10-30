/**
 *  @file   arctk/opt/sop/simple.inl
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Simple specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_SIMPLE_INL
#define ARCTK_OPT_SOP_SIMPLE_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

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
             *  Construct a simple specific-optical-property.
             *
             *  @param  ref_index_  Refractive index.
             *  @param  dist_       Interaction distance.
             *  @param  albedo_     Single scattering albedo.
             *  @param  asym_       Asymmetry parameter.
             *
             *  @pre    ref_index_ must be greater than, or equal to, unity.
             *  @pre    dist_ must be positive.
             *  @pre    albedo_ must be positive.
             *  @pre    albedo_ must less than, or equal to, unity.
             *  @pre    asym_ must greater than, or equal to, minus one.
             *  @pre    asym_ must less than, or equal to, unity.
             */
            inline Simple::Simple(const double ref_index_, const double dist_, const double albedo_, const double asym_) noexcept
              : Sop(ref_index_)
              , _dist(dist_)
              , _albedo(albedo_)
              , _asym(asym_)
            {
                assert(ref_index_ >= 1.0);
                assert(dist_ > 0.0);
                assert(albedo_ >= 0.0);
                assert(albedo_ <= 1.0);
                assert(asym_ >= -1.0);
                assert(asym_ <= 1.0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the distance until the next interaction event.
             *
             *  @return Distance until the next interaction event.
             */
            inline double Simple::interact_dist(random::Generator* /*unused*/, const dom::Cell* /*unused*/) const noexcept
            {
                return (_dist);
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
             *  @return False if the photon should be removed from the loop after interacting.
             */
            inline bool Simple::interact(random::Generator* rng_, phys::Photon* phot_, dom::Cell* cell_, const double dist_) const noexcept
            {
                cell_->add_scatter(phot_->weight());

                phot_->multiply_weight(_albedo);

                phot_->move(dist_, _ref_index, cell_);
                phot_->rotate(random::distribution::henyey_greenstein(rng_, _asym), rng_->gen() * consts::math::TWO_PI);
                phot_->multiply_weight(_albedo);

                return (true);
            }



        } // namespace sop
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_SIMPLE_INL
