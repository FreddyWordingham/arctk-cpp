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
#include <memory>
#include <type_traits>
#include <utility>

//  -- Arctk --
#include <arctk/geom.hpp>
#include <arctk/phys.hpp>
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
            const geom::shape::Mesh _surf; //!< Shape forming the emission surface of the light.

            //  -- Power --
            const double _power; //!< Power of the light source in Watts.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Light(const geom::shape::Mesh& surf_, const double power_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                   min_wavelength() const noexcept;
            inline double                   max_wavelength() const noexcept;
            inline const geom::shape::Mesh& surf() const noexcept;
            inline double                   power() const noexcept;

            //  -- Emission --
            virtual phys::particle::Photon emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Light::Light(const geom::shape::Mesh& surf_, const double power_) noexcept
          : _surf(surf_)
          , _power(power_)
        {
            PRE(power_ > 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get a const reference to the surface of the light.
         *
         *  @return Const reference to the surface of the light.
         */
        inline const geom::shape::Mesh& Light::surf() const noexcept
        {
            return (_surf);
        }

        /**
         *  Get the power of the light source.
         *
         *  @return Power of the light source.
         */
        inline double Light::power() const noexcept
        {
            return (_power);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_HPP
