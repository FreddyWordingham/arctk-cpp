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
             *  Body of material entity equipment class.
             */
            class Body : public Entity
            {
                //  == FIELDS ==
              private:
                //  -- Materials --
                const phys::Mat& _front_mat; //!< Front hit material.
                const phys::Mat& _back_mat;  //!< Back hit material.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Body(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const phys::Mat& front_mat_, const phys::Mat& back_mat_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a body entity which changes the optical properties during a photon collision.
             *
             *  @param  serial_     Serialised wavefront file.
             *  @param  scale_      Scaling transformation.
             *  @param  rot_        Rotation transformation.
             *  @param  trans_      Translation transformation.
             *  @param  front_mat_  Material to enter when hitting the front of the surface.
             *  @param  back_mat_   Material to enter when hitting the back of the surface.
             *
             *  @pre    serial may not be empty.
             *  @pre    scale_.x must be positive.
             *  @pre    scale_.y must be positive.
             *  @pre    scale_.z must be positive.
             */
            inline Body::Body(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const phys::Mat& front_mat_, const phys::Mat& back_mat_) noexcept
              : Entity(serial_, scale_, rot_, trans_)
              , _front_mat(front_mat_)
              , _back_mat(back_mat_)
            {
                PRE(!serial_.empty());
                PRE(scale_.x > 0.0);
                PRE(scale_.y > 0.0);
                PRE(scale_.z > 0.0);
            }



            //  == METHODS ==
            //  -- Collision --
            /**
             *  Perform a front hit event and update the material and specific-optical-properties.
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
            inline bool Body::hit_front(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                PRE(rng_ != nullptr);
                PRE(phot_ != nullptr);
                PRE(mat_ != nullptr);
                PRE(sop_ != nullptr);
                PRE(cell_ != nullptr);

                std::unique_ptr<arc::phys::Sop> next_sop = _front_mat.gen(*phot_);

                if (rng_->gen() <= phys::optics::reflection_prob(std::acos(phot_->dir() * -coll_.norm()), sop_->get()->ref_index(), next_sop->ref_index()))
                {
                    phot_->move(coll_.dist() - consts::num::BUMP, sop_->get()->ref_index(), cell_);

                    phot_->set_dir(phys::optics::reflection_dir(phot_->dir(), coll_.norm()));
                }
                else
                {
                    phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);

                    phot_->set_dir(phys::optics::refraction_dir(phot_->dir(), coll_.norm(), sop_->get()->ref_index(), next_sop->ref_index()));

                    *mat_ = &_front_mat;
                    *sop_ = std::move(next_sop);
                }

                return (true);
            }

            /**
             *  Perform a back hit event and update the material and specific-optical-properties.
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
            inline bool Body::hit_back(random::Generator* rng_, phys::Photon* phot_, const phys::Mat** mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                PRE(rng_ != nullptr);
                PRE(phot_ != nullptr);
                PRE(mat_ != nullptr);
                PRE(sop_ != nullptr);
                PRE(cell_ != nullptr);

                std::unique_ptr<arc::phys::Sop> next_sop = _back_mat.gen(*phot_);

                if (rng_->gen() <= phys::optics::reflection_prob(std::acos(phot_->dir() * coll_.norm()), sop_->get()->ref_index(), next_sop->ref_index()))
                {
                    phot_->move(coll_.dist() - consts::num::BUMP, sop_->get()->ref_index(), cell_);

                    phot_->set_dir(phys::optics::reflection_dir(phot_->dir(), -coll_.norm()));
                }
                else
                {
                    phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);

                    phot_->set_dir(phys::optics::refraction_dir(phot_->dir(), -coll_.norm(), sop_->get()->ref_index(), next_sop->ref_index()));

                    *mat_ = &_back_mat;
                    *sop_ = std::move(next_sop);
                }


                return (true);
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_HPP
