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
            //  -- Data --
            const std::string& _name;

            //  -- Structure --
            const geom::Shape&                 _surf;
            const random::distribution::Linear _spec;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Light(const std::string& name_, const geom::Shape& surf_, const random::distribution::Linear& spec_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double             min_wavelength() const noexcept;
            inline double             max_wavelength() const noexcept;
            inline const std::string& name() const noexcept;
            inline const geom::Shape& surf() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Light::Light(const std::string& name_, const geom::Shape& surf_, const random::distribution::Linear& spec_) noexcept
          : _name(name_)
          , _surf(surf_)
          , _mat(mat_)
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

        inline const std::string& Light::name() const noexcept
        {
            return (_name);
        }

        inline const geom::Shape& Light::surf() const noexcept
        {
            return (_surf);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_HPP
