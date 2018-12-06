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

//  -- Arctk --
#include <arctk/consts/num.hpp>
#include <arctk/disc/block.hpp>
#include <arctk/opt/material.hpp>
#include <arctk/phys/optical.hpp>



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
            inline bool Body::hit_front(random::Generator* const rng_, phys::Photon* const phot_, disc::Block* const block_, opt::Material* const mat_, opt::Driver* const driver_, const geom::Collision& coll_) noexcept
            {
                // assert(rng_ != nullptr);
                // assert(phot_ != nullptr);
                // assert(mat_ != nullptr);
                // assert(sop_ != nullptr);
                // assert(cell_ != nullptr);

                // std::unique_ptr<opt::Sop> next_sop = _front_mat.gen(*phot_);

                // if (rng_->gen() <= opt::func::reflection_prob(std::acos(phot_->dir() * -coll_.norm()), sop_->get()->ref_index(), next_sop->ref_index()))
                // {
                //     phot_->move(coll_.dist() - consts::num::BUMP, sop_->get()->ref_index());
                //     cell_->add_energy(coll_.dist() * phot_->energy() * phot_->weight());

                //     phot_->set_dir(opt::func::reflection_dir(phot_->dir(), coll_.norm()));
                // }
                // else
                // {
                //     phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index());
                //     cell_->add_energy(coll_.dist() * phot_->energy() * phot_->weight());

                //     phot_->set_dir(opt::func::refraction_dir(phot_->dir(), coll_.norm(), sop_->get()->ref_index(), next_sop->ref_index()));

                //     *mat_ = &_front_mat;
                //     *sop_ = std::move(next_sop);
                // }

                return (true);
            }

            inline bool Body::hit_back(random::Generator* const rng_, phys::Photon* const phot_, disc::Block* const block_, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(block_ != nullptr);
                assert(mat_ != nullptr);
                assert(driver_ != nullptr);
                assert(phot_->cur_mat_id() == _mat_id);

                return (true);
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_INL
