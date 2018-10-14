/**
 *  @file   arctk/equip/entity/light.hpp
 *  @date   14/10/2018
 *  @author Freddy Wordingham
 *
 *  Light source entity equipment base class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_LIGHT_HPP
#define ARCTK_EQUIP_ENTITY_LIGHT_HPP



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
             *  Light entity equipment base class.
             */
            class Light : public Entity
            {
                //  == FIELDS ==
              private:
                //  -- Killing --
                const bool _kill;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Collision --
            inline bool Light::hit_front(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept
            {
                phot_->move(coll_.dist() + consts::num::BUMP);

                return (_kill);
            }

            inline bool Light::hit_back(random::Generator* /*unused*/, phys::Photon* phot_, phys::Cell* /*unused*/, const geom::Collision& coll_) noexcept 
            {
                phot_->move(coll_.dist() + consts::num::BUMP);

                return (_kill);
            }




        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_HPP
