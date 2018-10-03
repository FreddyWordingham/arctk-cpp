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
            template <typename T>
            inline Light(const T& surf_, const double power_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double             min_wavelength() const noexcept;
            inline double             max_wavelength() const noexcept;
            inline const geom::Shape* surf() const noexcept;
            inline double             power() const noexcept;

            //  -- Emission --
            inline phys::particle::Photon emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a light from an emission surface and spectrum.
         *
         *  @tparam T   Type used to form the surface.
         *
         *  @param  surf_   Shape forming the emission surface of the light.
         *  @param  spec_   Spectrum used to draw photon wavelength values from.
         *  @param  power_  Power of the light source in Watts.
         *
         *  @pre    T must be derived from geom::Shape.
         *  @pre    power_ must be positive.
         */
        template <typename T>
        inline Light::Light(const T& surf_, random::distribution::Linear<double>&& spec_, const double power_) noexcept
          : _surf(std::make_unique<T>(std::forward<T>(surf_)))
          , _spec(std::move(spec_))
          , _power(power_)
        {
            static_assert(std::is_base_of<geom::Shape, T>::value);

            PRE(power_ > 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum wavelength that can be emitted by the light.
         *
         *  @return Minimum wavelength that can be emitted by the light.
         */
        inline double Light::min_wavelength() const noexcept
        {
            return (_spec.min());
        }

        /**
         *  Get the maximum wavelength that can be emitted by the light.
         *
         *  @return maximum wavelength that can be emitted by the light.
         */
        inline double Light::max_wavelength() const noexcept
        {
            return (_spec.max());
        }

        /**
         *  Get a const reference to the surface of the light.
         *
         *  @return Const reference to the surface of the light.
         */
        inline const geom::Shape* Light::surf() const noexcept
        {
            return (_surf.get());
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


        //  -- Emission --
        /**
         *  Emit a photon from the light source.
         *
         *  @param  rng_        Random number generator.
         *  @param  cur_ent_    Entity to emit the photon within.
         *
         *  @return Newly emitted photon.
         */
        inline phys::particle::Photon Light::emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept
        {
            const std::pair<vec3, vec3> pos_norm = _surf->random_pos_and_norm(rng_);

            return (phys::particle::Photon(pos_norm.first, pos_norm.second, _spec.sample(rng_), cur_ent_));
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_HPP
