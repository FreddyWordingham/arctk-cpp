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



//  == BASE ==
#include <arctk/equip/entity.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        class Cell;
    }              // namespace dom
    namespace disc //! discretisation namespace
    {
        class Block;
    }              // namespace disc
    namespace geom //! geometric namespace
    {
        class Collision;
    }                // namespace geom
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



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
                //  == FIELDS ==
              private:
                //  -- Reflectance --
                const double _front_ref; //!< Reflectance of the front mirror.
                const double _back_ref;  //!< Reflectance of the back mirror.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Mirror(const geom::shape::Mesh& surf_, double front_ref_, double back_ref_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline void hit_front(random::Generator* rng_, phys::Photon* phot_, disc::Block* /**unused*/, const geom::Collision& coll_) noexcept override;
                inline void hit_back(random::Generator* rng_, phys::Photon* phot_, disc::Block* /**unused*/, const geom::Collision& coll_) noexcept override;
            };



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/mirror.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_MIRROR_HPP
