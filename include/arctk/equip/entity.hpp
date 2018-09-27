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
#include <memory>
#include <string>
#include <utility>

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
            std::unique_ptr<geom::Shape>    _surf; //!< Shape forming the surface boundary of the entity.
            std::unique_ptr<phys::Material> _mat;  //!< Matrial composing the entity's volume.

            //  -- Data --
            std::unique_ptr<data::Domain> _dom; //!< Data domain.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename T, typename S>
            inline Entity(T&& surf_, S&& mat_, data::Domain&& dom_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min_wavelength() const noexcept;
            inline double                max_wavelength() const noexcept;
            inline const geom::Shape*    surf() const noexcept;
            inline const phys::Material* mat() const noexcept;
            inline const data::Domaid*   dom() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an entity from a surface bounding a given material.
         *
         *  @tparam T   Type used to form the surface.
         *  @tparam S   Type used to form the material.
         *
         *  @param  surf_   Bounding surface of the entity.
         *  @param  mat_    Material to form the entity volume.
         *  @param  dom_    Domain to be taken for this entity.
         *
         *  @pre    surf_ must be a closed surface.
         *
         *  @pre    T must be derived from geom::Shape.
         *  @pre    S must be derived from phys::Material.
         */
        template <typename T, typename S>
        inline Entity::Entity(T&& surf_, S&& mat_, data::Domain&& dom_) noexcept
          : _surf(std::make_unique<T>(std::forward<T>(surf_)))
          , _mat(std::make_unique<S>(std::forward<S>(mat_)))
          , _dom(std::make_unique<data::Domain>(std::forward<data::Domain>(dom_)))
        {
            static_assert(std::is_base_of<geom::Shape, T>::value);
            static_assert(std::is_base_of<phys::Material, S>::value);

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
            return (_mat->min());
        }

        /**
         *  Get the maximum wavelength that can be handled by the entity.
         *
         *  @return Maximum wavelength that can be handled by the entity.
         */
        inline double Entity::max_wavelength() const noexcept
        {
            return (_mat->max());
        }

        /**
         *  Get a const reference to the surface of the entity.
         *
         *  @return Const reference to the surface of the entity.
         */
        inline const geom::Shape* Entity::surf() const noexcept
        {
            return (_surf.get());
        }

        /**
         *  Get a const reference to the material of the entity.
         *
         *  @return Const reference to the material of the entity.
         */
        inline const phys::Material* Entity::mat() const noexcept
        {
            return (_mat.get());
        }

        inline const data::Dom* Entity::dom() const noexcept
        {
            return (_dom.get());
        }



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
