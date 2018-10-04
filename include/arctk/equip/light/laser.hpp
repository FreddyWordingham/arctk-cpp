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
                inline Laser(const geom::shape::Mesh& surf_, double power_, double wavelength_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Laser::Laser(const geom::shape::Mesh& surf_, const double power_, const double wavelength_) noexcept
              : Light(surf_, power_)
              , _wavelength(wavelength_)
            {
                PRE(wavelength_ > 0.0);
            }



        } // namespace light
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_LASER_HPP
