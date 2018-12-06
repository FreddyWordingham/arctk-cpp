/**
 *  @file   arctk/equip/entity.inl
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_INL
#define ARCTK_EQUIP_ENTITY_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an entity with a given surface.
         *
         *  @param  surf_   Entity surface.
         */
        inline Entity::Entity(const geom::shape::Mesh& surf_) noexcept
          : _surf(surf_)
        {
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Entity::~Entity() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the surface mesh of an entity.
         *
         *  @return Surface mesh of an entity.
         */
        inline const geom::shape::Mesh& Entity::surf() const noexcept
        {
            return (_surf);
        }


        //  -- Collision --
        inline bool Entity::hit(random::Generator* const rng_, phys::Photon* const phot_, disc::Block* const block_, const geom::Collision& coll_) noexcept
        {
            assert(rng_ != nullptr);
            assert(phot_ != nullptr);
            assert(block_ != nullptr);

            if (coll_.front())
            {
                return (hit_front(rng_, phot_, block_, coll_));
            }

            return (hit_back(rng_, phot_, block_, coll_));
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_INL
