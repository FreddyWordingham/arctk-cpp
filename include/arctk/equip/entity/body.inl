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
#include <arctk/geom/collision.hpp>
#include <arctk/geom/shape/mesh.hpp>
#include <arctk/math/vec3.hpp>
#include <arctk/opt/func.hpp>
#include <arctk/opt/mat.hpp>
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
            /**
             *  Construct a body entity which changes the optical properties during a photon collision.
             *
             *  @param  surf_       Surface of the body.
             *  @param  front_mat_  Material to enter when hitting the front of the surface.
             *  @param  back_mat_   Material to enter when hitting the back of the surface.
             */
            inline Body::Body(const geom::shape::Mesh& surf_, const opt::Mat& front_mat_, const opt::Mat& back_mat_) noexcept
              : Entity(surf_)
              , _front_mat(front_mat_)
              , _back_mat(back_mat_)
            {
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
            inline bool Body::hit_front(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(mat_ != nullptr);
                assert(sop_ != nullptr);
                assert(cell_ != nullptr);

                std::unique_ptr<opt::Sop> next_sop = _front_mat.gen(*phot_);

                if (rng_->gen() <= opt::func::reflection_prob(std::acos(phot_->dir() * -coll_.norm()), sop_->get()->ref_index(), next_sop->ref_index()))
                {
                    phot_->move(coll_.dist() - consts::num::BUMP, sop_->get()->ref_index());
                    cell_->add_energy(coll_.dist() * phot_->energy() * phot_->weight());

                    phot_->set_dir(opt::func::reflection_dir(phot_->dir(), coll_.norm()));
                }
                else
                {
                    phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index());
                    cell_->add_energy(coll_.dist() * phot_->energy() * phot_->weight());

                    phot_->set_dir(opt::func::refraction_dir(phot_->dir(), coll_.norm(), sop_->get()->ref_index(), next_sop->ref_index()));

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
            inline bool Body::hit_back(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept
            {
                assert(rng_ != nullptr);
                assert(phot_ != nullptr);
                assert(mat_ != nullptr);
                assert(sop_ != nullptr);
                assert(cell_ != nullptr);

                std::unique_ptr<opt::Sop> next_sop = _back_mat.gen(*phot_);

                if (rng_->gen() <= opt::func::reflection_prob(std::acos(phot_->dir() * coll_.norm()), sop_->get()->ref_index(), next_sop->ref_index()))
                {
                    phot_->move(coll_.dist() - consts::num::BUMP, sop_->get()->ref_index());
                    cell_->add_energy(coll_.dist() * phot_->energy() * phot_->weight());

                    phot_->set_dir(opt::func::reflection_dir(phot_->dir(), -coll_.norm()));
                }
                else
                {
                    phot_->move(coll_.dist() + consts::num::BUMP, sop_->get()->ref_index());
                    cell_->add_energy(coll_.dist() * phot_->energy() * phot_->weight());

                    phot_->set_dir(opt::func::refraction_dir(phot_->dir(), -coll_.norm(), sop_->get()->ref_index(), next_sop->ref_index()));

                    *mat_ = &_back_mat;
                    *sop_ = std::move(next_sop);
                }


                return (true);
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_INL
