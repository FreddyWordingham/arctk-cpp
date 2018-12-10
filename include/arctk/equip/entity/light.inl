/**
 *  @file   arctk/equip/entity/light.inl
 *  @date   14/10/2018
 *  @author Freddy Wordingham
 *
 *  Light source entity equipment base class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_LIGHT_INL
#define ARCTK_EQUIP_ENTITY_LIGHT_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/consts/num.hpp>
#include <arctk/geom/collision.hpp>
#include <arctk/opt/material.hpp>
#include <arctk/phys/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Light::Light(const geom::shape::Mesh& surf_, const std::string& mat_id_, opt::Material* const mat_, const double power_, const bool kill_) noexcept
              : Entity(surf_)
              , _mat_id(mat_id_)
              , _mat(mat_)
              , _power(power_)
              , _kill(kill_)
            {
                assert(!mat_id_.empty());
                assert(power_ > 0.0);
            }


            //  -- Destructors --
            /**
             *  Default destructor.
             */
            inline Light::~Light() noexcept = default;



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the power of the light source.
             *
             *  @return Power of the light source.
             */
            inline double Light::power() const noexcept
            {
                return (_power);
            }


            //  -- Collision --
            inline void Light::hit_front(random::Generator* const /*unused*/, phys::Photon* const phot_, disc::Block* const /*unused*/, const geom::Collision& coll_) noexcept
            {
                assert(phot_ != nullptr);

                phot_->travel(coll_.dist() + consts::num::BUMP);

                if (_kill)
                {
                    phot_->kill();
                }
            }

            inline void Light::hit_back(random::Generator* const /*unused*/, phys::Photon* const phot_, disc::Block* const /*unused*/, const geom::Collision& coll_) noexcept
            {
                assert(phot_ != nullptr);

                phot_->travel(coll_.dist() + consts::num::BUMP);

                if (_kill)
                {
                    phot_->kill();
                }
            }



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_INL
