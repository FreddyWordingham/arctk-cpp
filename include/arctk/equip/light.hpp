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
#include <string>
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
            std::unique_ptr<geom::Shape>         _surf; //!< Shape forming the emission surface of the light.
            random::distribution::Linear<double> _spec; //!< Spectrum used to draw photon wavelength values from.

            //  -- Power --
            const double _power; //!< Power of the light source in Watts.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename T>
            inline Light(T&& surf_, random::distribution::Linear<double>&& spec_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                 min_wavelength() const noexcept;
            inline double                 max_wavelength() const noexcept;
            inline const geom::Shape*     surf() const noexcept;
            inline phys::particle::Photon emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a light from an emission surface and spectrum.
         *
         *  @tparam T   Type used to form the surface.
         *
         *  @param  surf_ Shape forming the emission surface of the light.
         *  @param  spec_ Spectrum used to draw photon wavelength values from.
         *
         *  @pre    T must be derived from geom::Shape.
         */
        template <typename T>
        inline Light::Light(T&& surf_, random::distribution::Linear<double>&& spec_) noexcept
          : _surf(std::make_unique<T>(std::forward<T>(surf_)))
          , _spec(std::move(spec_))
        {
            static_assert(std::is_base_of<geom::Shape, T>::value);
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
