/**
 *  @file   arctk/equip/entity/body.hpp
 *  @date   16/10/2018
 *  @author Freddy Wordingham
 *
 *  Body of material entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_BODY_HPP
#define ARCTK_EQUIP_ENTITY_BODY_HPP



//  == BASE ==
#include <arctk/equip/entity.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>



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
        namespace entity //! entity namespace
        {



            //  == CLASS ==
            /**
             *  Body of material entity equipment class.
             */
            class Body : public Entity
            {
                //  == FIELDS ==
              private:
                //  -- Materials --
                const std::string _mat_id;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Body(const geom::shape::Mesh& surf_, const std::string& mat_id_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline void hit_front(random::Generator* rng_, phys::Photon* phot_, disc::Block* block_, const geom::Collision& coll_) noexcept override;
                inline void hit_back(random::Generator* rng_, phys::Photon* phot_, disc::Block* block_, const geom::Collision& coll_) noexcept override;
            };



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/body.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_HPP
