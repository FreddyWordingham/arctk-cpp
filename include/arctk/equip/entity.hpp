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
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
#include <arctk/phys.hpp>
#include <arctk/random.hpp>



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
            inline bool hit(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept;

          private:
            //  -- Collision --
            virtual bool hit_front(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept = 0;
            virtual bool hit_back(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept  = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an entity with a given surface and transformations.
         *
         *  @param  serial_ Serialised wavefront file.
         *  @param  scale_  Scaling transformation.
         *  @param  rot_    Rotation transformation.
         *  @param  trans_  Translation transformation.
         *
         *  @pre    serial_ may not be empty.
         */
        inline Entity::Entity(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
          : Mesh(serial_, scale_, rot_, trans_)
        {
            PRE(!serial_.empty());
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Entity::~Entity() noexcept = default;



        //  == METHODS ==
        //  -- Collision --
        /**
         *  Perform a hit event on the entity.
         *
         *  @param  rng_    Random number generator.
         *  @param  phot_   Photon hitting the entity.
         *  @param  mat_    Current active material.
         *  @param  sop_    Current specific-optical-properties.
         *  @param  cell_   Current domain cell.
         *  @param  coll_   Collision event information.
         *
         *  @return False if the photon should be removed from the simulation.
         */
        inline bool Entity::hit(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
        {
            if (coll_.front())
            {
                return (hit_front(rng_, phot_, mat_, sop_, cell_, coll_));
            }

            return (hit_back(rng_, phot_, mat_, sop_, cell_, coll_));
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
