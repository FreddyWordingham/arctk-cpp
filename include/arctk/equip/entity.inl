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
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



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
         *  @pre    scale_.x must be positive.
         *  @pre    scale_.y must be positive.
         *  @pre    scale_.z must be positive.
         */
        inline Entity::Entity(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
          : Mesh(serial_, scale_, rot_, trans_)
        {
            assert(!serial_.empty());
            assert(scale_.x > 0.0);
            assert(scale_.y > 0.0);
            assert(scale_.z > 0.0);
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
         *  @pre    rng_ may not be nullptr.
         *  @pre    phot_ may not be nullptr.
         *  @pre    mat_ may not be nullptr.
         *  @pre    sop_ may not be nullptr.
         *  @pre    cell_ may not be nullptr.
         *
         *  @return False if the photon should be removed from the simulation.
         */
        inline bool Entity::hit(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept
        {
            assert(rng_ != nullptr);
            assert(phot_ != nullptr);
            assert(mat_ != nullptr);
            assert(sop_ != nullptr);
            assert(cell_ != nullptr);

            if (coll_.front())
            {
                return (hit_front(rng_, phot_, mat_, sop_, cell_, coll_));
            }

            return (hit_back(rng_, phot_, mat_, sop_, cell_, coll_));
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_INL
