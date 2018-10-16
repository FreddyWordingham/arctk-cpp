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
#include <arctk/consts.hpp>
#include <arctk/debug.hpp>
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
                const double _front_ref;
                const double _back_ref;


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
            inline Mirror::Mirror(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const double front_ref_, const double back_ref_) noexcept
              : Entity(serial_, scale_, rot_, trans_)
              , _front_ref(front_ref_)
              , _back_ref(back_ref_)
            {
                PRE(!serial_.empty());
                PRE(scale_.x > 0.0);
                PRE(scale_.y > 0.0);
                PRE(scale_.z > 0.0);
                PRE((front_ref_ >= 0.0) && (front_ref_ <= 1.0));
                PRE((back_ref_ >= 0.0) && (back_ref_ <= 1.0));
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
                PRE(rng_ != nullptr);
                PRE(phot_ != nullptr);
                PRE(sop_ != nullptr);
                PRE(cell_ != nullptr);

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
                PRE(rng_ != nullptr);
                PRE(phot_ != nullptr);
                PRE(sop_ != nullptr);
                PRE(cell_ != nullptr);

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
