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
#include <arctk/data.hpp>
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
            const geom::Shape    _surf; //!< Shape forming the surface boundary of the entity.
            const phys::Material _mat;  //!< Matrial composing the entity's volume.


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
        /**
         *  Construct an entity from a surface bounding a given material.
         *
         *  @param  surf_   Bounding surface of the entity.
         *  @param  mat_    Material to form the entity volume.
         *
         *  @pre    surf_ must be a closed surface.
         */
        inline Entity::Entity(const geom::Shape& surf_, const phys::Material& mat_) noexcept
          : _surf(surf_)
          , _mat(mat_)
        {
            PRE(surf_.closed());
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum wavelength that can be handled by the entity.
         *
         *  @return Minimum wavelength that can be handled by the entity.
         */
        inline double Entity::min_wavelength() const noexcept
        {
            return (_mat.min());
        }

        /**
         *  Get the maximum wavelength that can be handled by the entity.
         *
         *  @return Maximum wavelength that can be handled by the entity.
         */
        inline double Entity::max_wavelength() const noexcept
        {
            return (_mat.max());
        }

        /**
         *  Get a const reference to the surface of the entity.
         *
         *  @return Const reference to the surface of the entity.
         */
        inline const geom::Shape& Entity::surf() const noexcept
        {
            return (_surf);
        }

        /**
         *  Get a const reference to the material of the entity.
         *
         *  @return Const reference to the material of the entity.
         */
        inline const phys::Material& Entity::mat() const noexcept
        {
            return (_mat);
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
