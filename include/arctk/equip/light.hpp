/**
 *  @file   arctk/equip/light.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Light source equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_LIGHT_HPP
#define ARCTK_EQUIP_LIGHT_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>

//  -- Arctk --
#include <arctk/geom.hpp>
#include <arctk/random.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



        //  == CLASS ==
        /**
         *  Light source class.
         */
        class Light
        {
            //  == FIELDS ==
          private:
            //  -- Structure --
            const geom::Shape&                         _surf; //!< Shape forming the emission surface of the light.
            const random::distribution::Linear<double> _spec; //!< Spectrum used to draw photon wavelength values from.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Light(const geom::Shape& surf_, const random::distribution::Linear<double>& spec_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double             min_wavelength() const noexcept;
            inline double             max_wavelength() const noexcept;
            inline const geom::Shape& surf() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Light::Light(const geom::Shape& surf_, const random::distribution::Linear<double>& spec_) noexcept
          : _surf(surf_)
          , _spec(spec_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Light::min_wavelength() const noexcept
        {
            return (_spec.min());
        }

        inline double Light::max_wavelength() const noexcept
        {
            return (_spec.max());
        }

        inline const geom::Shape& Light::surf() const noexcept
        {
            return (_surf);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_HPP
