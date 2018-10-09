/**
 *  @file   arctk/equip/entity/mirror.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Mirror entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_MIRROR_HPP
#define ARCTK_EQUIP_ENTITY_MIRROR_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/equip/entity.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {



            //  == CLASS ==
            /**
             *  Mirror entity equipment class.
             */
            class Mirror : public Entity
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Entity(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline void hit_front(phys::Photon* phot_, scene::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline void hit_back(phys::Photon* phot_, scene::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Entity::Entity(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
              : Mesh(serial_, scale_, rot_, trans_)
            {
            }



            //  == METHODS ==
            //  -- Collision --



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_MIRROR_HPP
