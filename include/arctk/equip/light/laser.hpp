/**
 *  @file   arctk/equip/light/laser.hpp
 *  @date   03/10/2018
 *  @author Freddy Wordingham
 *
 *  Laser light source equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_LIGHT_LASER_HPP
#define ARCTK_EQUIP_LIGHT_LASER_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/equip/light.hpp>
#include <arctk/phys.hpp>
#include <arctk/random.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace light //! light source namespace
        {



            //  == CLASS ==
            /**
             *  Laser light source class.
             */
            class Laser : public Light
            {
                //  == FIELDS ==
              private:
                //  -- Structure --
                const double _wavelength;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                template <typename T>
                inline Laser(const geom::shape::Mesh& surf_, const double wavelength_, const double power_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



        } // namespace light
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_LASER_HPP
