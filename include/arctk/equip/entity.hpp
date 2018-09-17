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
            //  -- Data --
            const std::string& _name;

            //  -- Structure --
            const geom::Shape&    _surf;
            const phys::Material& _mat;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Entity(const std::string& name_, const geom::Shape& surf_, const phys::Material& mat_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min_wavelength() const noexcept;
            inline double                max_wavelength() const noexcept;
            inline const std::string&    name() const noexcept;
            inline const geom::Shape&    surf() const noexcept;
            inline const phys::Material& mat() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Entity::Entity(const std::string& name_, const geom::Shape& surf_, const phys::Material& mat_) noexcept
          : _name(name_)
          , _surf(surf_)
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

        inline const std::string& Entity::name() const noexcept
        {
            return (_name);
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
