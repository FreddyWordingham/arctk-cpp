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
#include <array>
#include <memory>
#include <string>
#include <utility>

//  -- Arctk --
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
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

            //  -- Domain --
            const std::array<size_t, 3>                                        _res;
            std::vector<std::vector<std::vector<std::unique_ptr<phys::Cell>>>> _cells;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename T, typename S>
            inline Entity(T&& surf_, S&& mat_, const std::array<size_t, 3>& res_) noexcept;

          private:
            //  -- Initialisation --
            inline std::vector<std::vector<std::vector<std::unique_ptr<phys::Cell>>>> init_cells(const std::array<size_t, 3>& res_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min_wavelength() const noexcept;
            inline double                max_wavelength() const noexcept;
            inline const geom::Shape*    surf() const noexcept;
            inline const phys::Material* mat() const noexcept;
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
         *  @param  res_    Resolution of the domain.
         *
         *  @pre    T must be derived from geom::Shape.
         *  @pre    S must be derived from phys::Material.
         *
         *  @pre    surf_ must be a closed surface.
         *  @pre    res_ values must all be positive.
         */
        template <typename T, typename S>
        inline Entity::Entity(T&& surf_, S&& mat_, const std::array<size_t, 3>& res_) noexcept
          : _surf(std::make_unique<T>(std::forward<T>(surf_)))
          , _mat(std::make_unique<S>(std::forward<S>(mat_)))
          , _res(res_)
          , _cells(init_cells(res_))
        {
            static_assert(std::is_base_of<geom::Shape, T>::value);
            static_assert(std::is_base_of<phys::Material, S>::value);

            PRE(surf_.closed());
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }


        //  -- Initialisation --
        inline std::vector<std::vector<std::vector<std::unique_ptr<phys::Cell>>>> Entity::init_cells(const std::array<size_t, 3>& res_) const noexcept
        {
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);

            const vec3 min = _mat.min();
            const vec3 max = _mat.max();
            const vec3 cell_size((max.x - min.x) / res_[index::dim::cartesian::X], (max.y - min.y) / res_[index::dim::cartesian::Y], (max.z - min.z) / res_[index::dim::cartesian::Z]);

            std::vector<std::vector<std::vector<std::unique_ptr<phys::Cell>>>> cells;
            cells.reserve(index::dim::cartesian::X);

            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                cells.emplace_back(std::vector<std::vector<std::unique_ptr<phys::Cell>>>());
                cells.back().reserve(res_[index::dim::cartesian::Y]);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    cells.back().emplace_back(std::vector<std::unique_ptr<phys::Cell>>());
                    cells.back().back().reserve(res_[index::dim::cartesian::Z]);

                    for (size_t k = 0; k < res_[index::dim::cartesian::Z]; ++k)
                    {
                        const vec3 cell_min(min.x + (cell_size.x * i), min.y + (cell_size.y * j), min.z + (cell_size.z * k));
                        cells.back().back().emplace_back(_mat.create_cell(cell_min, cell_min + cell_size));
                    }
                }
            }

            return (cells);
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



    } // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_HPP
