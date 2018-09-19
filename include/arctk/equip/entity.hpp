/**
 *  @file   arctk/equip/entity.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_HPP
#define ARCTK_EQUIP_ENTITY_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>

//  -- Arctk --
#include <arctk/geom.hpp>
#include <arctk/phys.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



        //  == CLASS ==
        /**
         *  Entity class.
         */
        class Entity
        {
            //  == FIELDS ==
          private:
            //  -- Structure --
            const geom::Shape&    _surf; //!< Shape forming the surface boundary of the entity.
            const phys::Material& _mat;  //!< Matrial composing the entity's volume.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Entity(const geom::Shape& surf_, const phys::Material& mat_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min_wavelength() const noexcept;
            inline double                max_wavelength() const noexcept;
            inline const geom::Shape&    surf() const noexcept;
            inline const phys::Material& mat() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Entity::Entity(const geom::Shape& surf_, const phys::Material& mat_) noexcept
          : _surf(surf_)
          , _mat(mat_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        inline double Entity::min_wavelength() const noexcept
        {
            return (_mat.min());
        }

        inline double Entity::max_wavelength() const noexcept
        {
            return (_mat.max());
        }

        inline const geom::Shape& Entity::surf() const noexcept
        {
            return (_surf);
        }

        inline const phys::Material& Entity::mat() const noexcept
        {
            return (_mat);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
