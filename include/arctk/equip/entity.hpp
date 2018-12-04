/**
 *  @file   arctk/equip/entity.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_HPP
#define ARCTK_EQUIP_ENTITY_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>

//  -- Arctk --
#include <arctk/geom/shape/mesh.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace disc //! discretisation namespace
    {
        class Block;
    }              // namespace disc
    namespace geom //! geometric namespace
    {
        class Collision;
    }             // namespace geom
    namespace opt //! optical namespace
    {
        class Driver;
        class Material;
    }              // namespace opt
    namespace phys //! physics namespace
    {
        class Photon;
    }                // namespace phys
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



        //  == CLASS ==
        /**
         *  Entity equipment class.
         */
        class Entity
        {
            //  == FIELDS ==
          protected:
            //  -- Geometry --
            const geom::shape::Mesh _surf; //!< Surface of the entity.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Entity(const geom::shape::Mesh& surf_) noexcept;
            inline Entity(const Entity&) = default; //!< Defaulted copy constructor.
            inline Entity(Entity&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Entity() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Entity& operator=(const Entity&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Entity& operator=(Entity&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const geom::shape::Mesh& surf() const noexcept;

            //  -- Collision --
            inline bool hit(random::Generator* rng_, phys::Photon* phot_, disc::Block* block_, opt::Material* mat_, opt::Driver* driver_, const geom::Collision& coll_) noexcept;

          private:
            //  -- Collision --
            virtual bool hit_front(random::Generator* rng_, phys::Photon* phot_, disc::Block* block_, opt::Material* mat_, opt::Driver* driver_, const geom::Collision& coll_) noexcept = 0;
            virtual bool hit_back(random::Generator* rng_, phys::Photon* phot_, disc::Block* block_, opt::Material* mat_, opt::Driver* driver_, const geom::Collision& coll_) noexcept  = 0;
        };



    } // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
