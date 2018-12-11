/**
 *  @file   arctk/equip/entity/light.hpp
 *  @date   14/10/2018
 *  @author Freddy Wordingham
 *
 *  Light source entity equipment base class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_LIGHT_HPP
#define ARCTK_EQUIP_ENTITY_LIGHT_HPP



//  == BASE ==
#include <arctk/equip/entity.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>
#include <tuple>

//  -- Arctk --
#include <arctk/phys/photon.hpp>



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
        namespace shape //! shape namespace
        {
            class Mesh;
        }         // namespace shape
    }             // namespace geom
    namespace opt //! optical namespace
    {
        class Material;
    }                // namespace opt
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
             *  Light entity equipment base class.
             */
            class Light : public Entity
            {
                //  == FIELDS ==
              protected:
                //  -- Material --
                const std::string _mat_id;

                //  -- Power --
                const double _power; //!< Power of the light.

              private:
                //  -- Killing --
                const bool _kill; //!< False if photon is killed upon hit.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Light(const geom::shape::Mesh& surf_, const std::string& mat_id_, double power_, bool kill_) noexcept;
                inline Light(const Light&) = default; //!< Defaulted copy constructor.
                inline Light(Light&&)      = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~Light() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Light& operator=(const Light&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Light& operator=(Light&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double power() const noexcept;

                //  -- Emission --
                virtual phys::Photon emit(random::Generator* rng_, disc::Domain* dom_, double time_, unsigned long int num_phot_) const noexcept = 0;

              private:
                //  -- Collision --
                inline void hit_front(random::Generator* rng_, phys::Photon* phot_, disc::Block* block_, const geom::Collision& coll_) noexcept override;
                inline void hit_back(random::Generator* rng_, phys::Photon* phot_, disc::Block* block_, const geom::Collision& coll_) noexcept override;
            };



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/light.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_HPP
