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
            //  -- Power --
            const double _power; //!< Power of the light source in Watts.

          protected:
            //  -- Structure --
            const geom::shape::Mesh _surf; //!< Shape forming the emission surface of the light.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Light(const double power_, const geom::shape::Mesh& surf_) noexcept;
            inline Light(const Light&) = default; //!< Defaulted copy constructor.
            inline Light(Light&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Light() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Light& operator=(const Light&) = default;     //!< Defaulted copy operator. @return Reference to copied object.
            inline Light& operator=(Light&&) noexcept = default; //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                   power() const noexcept;
            inline const geom::shape::Mesh& surf() const noexcept;

            //  -- Emission --
            virtual phys::particle::Photon emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Light::Light(const double power_, const geom::shape::Mesh& surf_) noexcept
          : _power(power_)
          , _surf(surf_)
        {
            PRE(power_ > 0.0);
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

        /**
         *  Get a const reference to the surface of the light.
         *
         *  @return Const reference to the surface of the light.
         */
        inline const geom::shape::Mesh& Light::surf() const noexcept
        {
            return (_surf);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_HPP
