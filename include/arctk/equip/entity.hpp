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



//  == BASE ==
#include <arctk/geom/shape/mesh.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>

//  -- Arctk --
#include <arctk/opt/sop.hpp>



//  == CLASS PROTOTYPES ==
namespace arc
{
    namespace geom
    {
        class Collision;
    } // namespace geom
    namespace math
    {
        template <typename T, size_t N>
        class Vec;
        using vec3 = math::Vec<double, 3>;
    } // namespace math
    namespace opt
    {
        class Mat;
    } // namespace opt
    namespace phys
    {
        class Photon;
    } // namespace phys
    namespace random
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
        class Entity : public geom::shape::Mesh
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Entity(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept;
            inline Entity(const Entity&) = default; //!< Defaulted copy constructor.
            inline Entity(Entity&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            inline ~Entity() noexcept override;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Entity& operator=(const Entity&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Entity& operator=(Entity&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Collision --
            inline bool hit(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept;

          private:
            //  -- Collision --
            virtual bool hit_front(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_,
                                   const geom::Collision& coll_) noexcept = 0; //!< Perform a hit event on the front face entity.   @param  rng_    Random number generator.    @param  phot_   Photon hitting the entity.  @param  mat_    Current active
                                                                               //!< material.    @param  sop_    Current specific-optical-properties.    @param  cell_   Current domain cell.    @param  coll_   Collision event information.    @return False
                                                                               //!< if the photon should be removed from the simulation.
            virtual bool hit_back(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_,
                                  const geom::Collision&
                                    coll_) noexcept = 0; //!< Perform a hit event on the back face entity.   @param  rng_    Random number generator.    @param  phot_   Photon hitting the entity.  @param  mat_    Current active material.    @param  sop_
                                                         //!< Current specific-optical-properties.    @param  cell_   Current domain cell.    @param  coll_   Collision event information.    @return False if the photon should be removed from the simulation.
        };



    } // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
