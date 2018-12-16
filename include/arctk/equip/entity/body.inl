/**
 *  @file   arctk/equip/entity/body.inl
 *  @date   16/10/2018
 *  @author Freddy Wordingham
 *
 *  Body of material entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_BODY_INL
#define ARCTK_EQUIP_ENTITY_BODY_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <utility>

//  -- Arctk --
#include <arctk/consts/num.hpp>
#include <arctk/disc/block.hpp>
#include <arctk/geom/collision.hpp>
#include <arctk/phys/optical.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Body::Body(const geom::shape::Mesh& surf_, const std::string& mat_id_) noexcept
              : Entity(surf_)
              , _mat_id(mat_id_)
            {
                assert(!mat_id_.empty());
            }



            //  == METHODS ==
            //  -- Collision --
            inline void Body::hit_front(random::Generator* const rng_, phys::Photon* const phot_, disc::Block* const block_, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(block_ != nullptr);
                assert(phot_->cur_mat_id() != _mat_id);

                const std::string& next_mat_id = _mat_id;

                const std::unique_ptr<opt::Driver>& cur_driver  = phot_->driver();
                std::unique_ptr<opt::Driver>        next_driver = block_->mat(next_mat_id)->driver(*phot_);

                const double cur_ref_index  = cur_driver->ref_index();
                const double next_ref_index = next_driver->ref_index();

                if (rng_->gen() <= phys::optical::reflection_prob(std::acos(phot_->dir() * -coll_.norm()), cur_ref_index, next_ref_index))
                {
                    phot_->travel(coll_.dist() - consts::num::BUMP);
                    phot_->set_dir(phys::optical::reflection_dir(phot_->dir(), coll_.norm()));
                }
                else
                {
                    phot_->travel(coll_.dist() + consts::num::BUMP);
                    phot_->set_dir(phys::optical::refraction_dir(phot_->dir(), coll_.norm(), cur_ref_index, next_ref_index));

                    phot_->enter_mat(_mat_id, std::move(next_driver));
                }
            }

            inline void Body::hit_back(random::Generator* const rng_, phys::Photon* const phot_, disc::Block* const block_, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(block_ != nullptr);
                assert(phot_->cur_mat_id() == _mat_id);

                const std::string& next_mat_id = phot_->prev_mat_id();

                const std::unique_ptr<opt::Driver>& cur_driver  = phot_->driver();
                std::unique_ptr<opt::Driver>        next_driver = block_->mat(next_mat_id)->driver(*phot_);

                const double cur_ref_index  = cur_driver->ref_index();
                const double next_ref_index = next_driver->ref_index();

                if (rng_->gen() <= phys::optical::reflection_prob(std::acos(phot_->dir() * coll_.norm()), cur_ref_index, next_ref_index))
                {
                    phot_->travel(coll_.dist() - consts::num::BUMP);
                    phot_->set_dir(phys::optical::reflection_dir(phot_->dir(), -coll_.norm()));
                }
                else
                {
                    phot_->travel(coll_.dist() + consts::num::BUMP);
                    phot_->set_dir(phys::optical::refraction_dir(phot_->dir(), -coll_.norm(), cur_ref_index, next_ref_index));

                    phot_->exit_mat(_mat_id, std::move(next_driver));
                }
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_INL
