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
                const phys::Mat& _front_mat;
                const phys::Mat& _back_mat;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Body(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const phys::Mat& front_mat_, const phys::Mat& back_mat_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat* mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat* mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Body::Body(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const phys::Mat& front_mat_, const phys::Mat& back_mat_) noexcept
              : Entity(serial_, scale_, rot_, trans_)
              , _front_mat(front_mat_)
              , _back_mat(back_mat_)
            {
            }



            //  == METHODS ==
            //  -- Collision --
            inline bool Body::hit_front(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat* mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);

                mat_  = &_front_mat;
                *sop_ = mat_->gen(*phot_);

                return (true);
            }

            inline bool Body::hit_back(random::Generator* /*unused*/, phys::Photon* phot_, const phys::Mat* mat_, std::unique_ptr<arc::phys::Sop>* sop_, phys::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index(), cell_);

                mat_  = &_back_mat;
                *sop_ = mat_->gen(*phot_);

                return (true);
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_HPP
