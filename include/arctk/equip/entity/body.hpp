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


                //  == METHODS ==
              private:
                //  -- Collision --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Collision --



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_HPP
