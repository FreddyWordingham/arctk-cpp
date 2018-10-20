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
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/equip/entity.hpp>
#include <arctk/phys.hpp>



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
                inline Mirror(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, double front_ref_, double back_ref_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a mirror enity which has a probability of reflecting incident photons.
             *
             *  @param  serial_     Serialised wavefront file.
             *  @param  scale_      Scaling transformation.
             *  @param  rot_        Rotation transformation.
             *  @param  trans_      Translation transformation.
             *  @param  front_ref_  Reflection probability of the front surface.
             *  @param  back_ref_   Reflection probability of the back surface.
             *
             *  @pre    serial may not be empty.
             *  @pre    scale_.x must be positive.
             *  @pre    scale_.y must be positive.
             *  @pre    scale_.z must be positive.
             *  @pre    front_ref_ must be non-negative.
             *  @pre    front_ref_ must be less than, or equal to, unity.
             *  @pre    back_ref_ must be non-negative.
             *  @pre    back_ref_ must be less than, or equal to, unity.
             */
            inline Mirror::Mirror(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const double front_ref_, const double back_ref_) noexcept
              : Entity(serial_, scale_, rot_, trans_)
              , _front_ref(front_ref_)
              , _back_ref(back_ref_)
            {
                assert(!serial_.empty());
                assert(scale_.x > 0.0);
                assert(scale_.y > 0.0);
                assert(scale_.z > 0.0);
                assert(front_ref_ >= 0.0);
                assert(front_ref_ <= 1.0));
                assert(back_ref_ >= 0.0);
                assert(back_ref_ <= 1.0));
            }



            //  == METHODS ==
            //  -- Collision --
            /**
             *  Perform a front hit event.
             *
             *  @param  rng_    Random number generator.
             *  @param  phot_   Photon hitting the entity.
             *  @param  sop_    Current specific-optical-properties.
             *  @param  cell_   Current domain cell.
             *  @param  coll_   Collision event information.
             *
             *  @pre    rng_ may not be nullptr.
             *  @pre    phot_ may not be nullptr.
             *  @pre    sop_ may not be nullptr.
             *  @pre    cell_ may not be nullptr.
             *
             *  @return False if the photon should be removed from the simulation.
             */
            inline bool Mirror::hit_front(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(sop_ != nullptr);
                assert(cell_ != nullptr);

                if (rng_->gen() <= _front_ref)
                {
                    phot_->move(coll_.dist() - consts::num::BUMP, sop_->get()->ref_index(), cell_);
                    phot_->set_dir(phys::optics::reflection_dir(phot_->dir(), coll_.norm()));
                }
                else
                {
                    phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);
                }

                return (true);
            }

            /**
             *  Perform a back hit event.
             *
             *  @param  rng_    Random number generator.
             *  @param  phot_   Photon hitting the entity.
             *  @param  sop_    Current specific-optical-properties.
             *  @param  cell_   Current domain cell.
             *  @param  coll_   Collision event information.
             *
             *  @pre    rng_ may not be nullptr.
             *  @pre    phot_ may not be nullptr.
             *  @pre    sop_ may not be nullptr.
             *  @pre    cell_ may not be nullptr.
             *
             *  @return False if the photon should be removed from the simulation.
             */
            inline bool Mirror::hit_back(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** /*unused*/, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(sop_ != nullptr);
                assert(cell_ != nullptr);

                if (rng_->gen() <= _back_ref)
                {
                    phot_->move(coll_.dist() - consts::num::BUMP, sop_->get()->ref_index(), cell_);
                    phot_->set_dir(phys::optics::reflection_dir(phot_->dir(), coll_.norm()));
                }
                else
                {
                    phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);
                }

                return (true);
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_MIRROR_HPP
