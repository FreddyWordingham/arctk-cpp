/**
 *  @file   arctk/scene/domain.hpp
 *  @date   08/10/2018
 *  @author Freddy Wordingham
 *
 *  Domain information class.
 */



//  == GUARD ==
#ifndef ARCTK_SCENE_DOMAIN_HPP
#define ARCTK_SCENE_DOMAIN_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>
#include <arctk/scene/cell.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace scene //! scene namespace
    {



        //  == CLASS ==
        /**
         *  Domain information cell.
         */
        class Domain : public geom::shape::Box
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3>                 _res;
            std::vector<std::vector<std::vector<Cell>>> _cells; //!< Three-dimensional vector of cells.
            const vec3                                  _cell_size;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept;

          private:
            //  -- Initialisation --
            inline std::vector<std::vector<std::vector<Cell>>> init_cells(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline size_t      num_cells() const noexcept;
            inline const Cell& cell(const vec3& pos_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Domain::Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept
          : Box(min_, max_)
          , _res(res_)
          , _cells(init_cells(min_, max_, res_))
          , _cell_size((max_.x - min_.x) / res_[index::dim::cartesian::X], (max_.y - min_.y) / res_[index::dim::cartesian::Y], (max_.z - min_.z) / res_[index::dim::cartesian::Z])
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }


        //  -- Initialisation --
        inline std::vector<std::vector<std::vector<Cell>>> Domain::init_cells(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);

            const vec3 size((max_.x - min_.x) / res_[index::dim::cartesian::X], (max_.y - min_.y) / res_[index::dim::cartesian::Y], (max_.z - min_.z) / res_[index::dim::cartesian::Z]);

            std::vector<std::vector<std::vector<Cell>>> cells(res_[index::dim::cartesian::X], std::vector<std::vector<Cell>>(res_[index::dim::cartesian::Y]));
            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                const double x = min_.x + (i * size.x);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    const double y = min_.y + (j * size.y);

                    for (size_t k = 0; k < res_[index::dim::cartesian::Z]; ++k)
                    {
                        const double z = min_.z + (k * size.z);

                        cells[i][j].emplace_back(Cell(vec3(x, y, z), vec3(x, y, z) + size));
                    }
                }
            }

            return (cells);
        }



        //  == METHODS ==
        //  -- Getters --
        inline size_t Domain::num_cells() const noexcept
        {
            return (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]);
        }

        inline const Cell& Domain::cell(const vec3& pos_) const noexcept
        {
            PRE(_box.contains(pos_));

            const vec3 rel_pos = pos_ - _box.min();
            const auto index_x = static_cast<size_t>(rel_pos.x / _cell_size.x);
            const auto index_y = static_cast<size_t>(rel_pos.y / _cell_size.y);
            const auto index_z = static_cast<size_t>(rel_pos.z / _cell_size.z);

            POST(index_x < _res[index::dim::cartesian::X]);
            POST(index_y < _res[index::dim::cartesian::Y]);
            POST(index_z < _res[index::dim::cartesian::Z]);

            return (_cells[index_x][index_y][index_z]);
        }



    } // namespace scene
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SCENE_DOMAIN_HPP
