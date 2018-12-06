/**
 *  @file   arctk/equip/entity/mirror.inl
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Mirror entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_MIRROR_INL
#define ARCTK_EQUIP_ENTITY_MIRROR_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/consts/num.hpp>
#include <arctk/geom/collision.hpp>
#include <arctk/phys/optical.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a mirror entity which has a probability of reflecting incident photons.
             *
             *  @param  surf_       Surface of the mirror.
             *  @param  front_ref_  Reflection probability of the front surface.
             *  @param  back_ref_   Reflection probability of the back surface.
             *
             *  @pre    front_ref_ must be non-negative.
             *  @pre    front_ref_ must be less than, or equal to, unity.
             *  @pre    back_ref_ must be non-negative.
             *  @pre    back_ref_ must be less than, or equal to, unity.
             */
            inline Mirror::Mirror(const geom::shape::Mesh& surf_, const double front_ref_, const double back_ref_) noexcept
              : Entity(surf_)
              , _front_ref(front_ref_)
              , _back_ref(back_ref_)
            {
                assert(front_ref_ >= 0.0);
                assert(front_ref_ <= 1.0);
                assert(back_ref_ >= 0.0);
                assert(back_ref_ <= 1.0);
            }



            //  == METHODS ==
            //  -- Collision --
            inline void Mirror::hit_front(random::Generator* const rng_, phys::Photon* const phot_, disc::Block* const /*unused*/, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);

                if (rng_->gen() <= _front_ref)
                {
                    phot_->travel(coll_.dist() - consts::num::BUMP);
                    phot_->set_dir(phys::optical::reflection_dir(phot_->dir(), coll_.norm()));
                }
                else
                {
                    phot_->travel(coll_.dist() + consts::num::BUMP);
                }
            }

            inline void Mirror::hit_back(random::Generator* const rng_, phys::Photon* const phot_, disc::Block* const /*unused*/, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);

                if (rng_->gen() <= _back_ref)
                {
                    phot_->travel(coll_.dist() - consts::num::BUMP);
                    phot_->set_dir(phys::optical::reflection_dir(phot_->dir(), coll_.norm()));
                }
                else
                {
                    phot_->travel(coll_.dist() + consts::num::BUMP);
                }
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_MIRROR_INL
