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
#include <fstream>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/cell.hpp>



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
            const std::array<size_t, 3>                       _res;       //!< Resolution of the domain cells.
            std::vector<std::vector<std::vector<phys::Cell>>> _cells;     //!< Three-dimensional vector of cells.
            const vec3                                        _cell_size; //!< Size of each domain cell.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept;

          private:
            //  -- Initialisation --
            inline std::vector<std::vector<std::vector<phys::Cell>>> init_cells(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3>&                             res() const noexcept;
            inline const std::vector<std::vector<std::vector<phys::Cell>>>& cells() const noexcept;
            inline const vec3&                                              cell_size() const noexcept;
            inline size_t                                                   num_cells() const noexcept;

            //  -- Retrieval --
            inline phys::Cell* cell(const vec3& pos_) noexcept;

            //  -- Saving --
            inline void save(const std::string& path_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a domain of cells with given bounds and resolution.
         *
         *  @param  min_    Minimum bound of the domain.
         *  @param  max_    Maximum bound of the domain.
         *  @param  res_    Resolution of the domain cells.
         *
         *  @pre    min_.x must be less than, or equal to, min.x.
         *  @pre    min_.y must be less than, or equal to, min.y.
         *  @pre    min_.z must be less than, or equal to, min.z.
         *  @pre    res_[index::dim::cartesian::X] must be positive.
         *  @pre    res_[index::dim::cartesian::Y] must be positive.
         *  @pre    res_[index::dim::cartesian::Z] must be positive.
         */
        inline Domain::Domain(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) noexcept
          : Box(min_, max_)
          , _res(res_)
          , _cells(init_cells(min_, max_, res_))
          , _cell_size((max_.x - min_.x) / static_cast<double>(res_[index::dim::cartesian::X]), (max_.y - min_.y) / static_cast<double>(res_[index::dim::cartesian::Y]), (max_.z - min_.z) / static_cast<double>(res_[index::dim::cartesian::Z]))
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }


        //  -- Initialisation --
        /**
         *  Initialise the three-dimensional vector of domain cells.
         *
         *  @param  min_    Minimum bound of the domain.
         *  @param  max_    Maximum bound of the domain.
         *  @param  res_    Resolution of the domain cells.
         *
         *  @pre    min_.x must be less than, or equal to, min.x.
         *  @pre    min_.y must be less than, or equal to, min.y.
         *  @pre    min_.z must be less than, or equal to, min.z.
         *  @pre    res_[index::dim::cartesian::X] must be positive.
         *  @pre    res_[index::dim::cartesian::Y] must be positive.
         *  @pre    res_[index::dim::cartesian::Z] must be positive.
         *
         *  @return Initialised three-dimensional vector of domain cells.
         */
        inline std::vector<std::vector<std::vector<phys::Cell>>> Domain::init_cells(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_) const noexcept
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);

            const vec3 size((max_.x - min_.x) / static_cast<double>(res_[index::dim::cartesian::X]), (max_.y - min_.y) / static_cast<double>(res_[index::dim::cartesian::Y]), (max_.z - min_.z) / static_cast<double>(res_[index::dim::cartesian::Z]));

            std::vector<std::vector<std::vector<phys::Cell>>> cells(res_[index::dim::cartesian::X], std::vector<std::vector<phys::Cell>>(res_[index::dim::cartesian::Y]));
            for (size_t i = 0; i < res_[index::dim::cartesian::X]; ++i)
            {
                const double x = min_.x + (static_cast<double>(i) * size.x);

                for (size_t j = 0; j < res_[index::dim::cartesian::Y]; ++j)
                {
                    const double y = min_.y + (static_cast<double>(j) * size.y);

                    for (size_t k = 0; k < res_[index::dim::cartesian::Z]; ++k)
                    {
                        const double z = min_.z + (static_cast<double>(k) * size.z);

                        cells[i][j].emplace_back(phys::Cell(vec3(x, y, z), vec3(x, y, z) + size));
                    }
                }
            }

            return (cells);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the resolution of the domain cells.
         *
         *  @return Resolution of the domain cells.
         */
        inline const std::array<size_t, 3>& Domain::res() const noexcept
        {
            return (_res);
        }

        /**
         *  Get a const reference to the three-dimensional vector of domain cells.
         *
         *  @return Const reference to the three-dimensional vector of domain cells.
         */
        inline const std::vector<std::vector<std::vector<phys::Cell>>>& Domain::cells() const noexcept
        {
            return (_cells);
        }

        /**
         *  Get the cell size.
         *
         *  @return Cell size.
         */
        inline const vec3& Domain::cell_size() const noexcept
        {
            return (_cell_size);
        }

        /**
         *  Get the total number of cells in the domain.
         *
         *  @return Total number of cells in the domain.
         */
        inline size_t Domain::num_cells() const noexcept
        {
            return (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]);
        }


        //  -- Retrieval --
        /**
         *  Get the domain cell corresponding to a given position within the domain.
         *
         *  @param  pos_    Position within the domain.
         *
         *  @pre    pos_ must intersect with the domain.
         *
         *  @post   index_x must be less than _res[index::dim::cartesian::X].
         *  @post   index_y must be less than _res[index::dim::cartesian::Y].
         *  @post   index_z must be less than _res[index::dim::cartesian::Z].
         *
         *  @return Domain cell corresponding to a given position within the domain.
         */
        inline phys::Cell* Domain::cell(const vec3& pos_) noexcept
        {
            PRE(intersect(pos_));

            const vec3 rel_pos = pos_ - _min;
            const auto index_x = static_cast<size_t>(rel_pos.x / _cell_size.x);
            const auto index_y = static_cast<size_t>(rel_pos.y / _cell_size.y);
            const auto index_z = static_cast<size_t>(rel_pos.z / _cell_size.z);

            POST(index_x < _res[index::dim::cartesian::X]);
            POST(index_y < _res[index::dim::cartesian::Y]);
            POST(index_z < _res[index::dim::cartesian::Z]);

            return (&_cells[index_x][index_y][index_z]);
        }


        //  -- Saving --
        /**
         *  Save the domain cell data as a vtk file.
         *
         *  @param  path_   Path to the vtk save file.
         *
         *  @pre    path_ may not be empty.
         */
        inline void Domain::save(const std::string& path_) const noexcept // NOLINT
        {
            PRE(!path_.empty());

            std::ofstream file(path_ + ".vtk");

            file << "# vtk DataFile Version 3.0\n"
                 << "vtk "
                 << "sim_output" << '\n'
                 << "ASCII\n"
                 << "DATASET RECTILINEAR_GRID\n"
                 << "DIMENSIONS " << (_res[index::dim::cartesian::X] + 1) << " " << (_res[index::dim::cartesian::Y] + 1) << " " << (_res[index::dim::cartesian::Z] + 1) << '\n'
                 << "X_COORDINATES " << (_res[index::dim::cartesian::X] + 1) << " double\n";

            for (size_t i = 0; i <= _res[index::dim::cartesian::X]; ++i)
            {
                if (i != 0)
                {
                    file << ' ';
                }

                file << (_min.x + (_cell_size.x * static_cast<double>(i))) << ' ';
            }

            file << "\nY_COORDINATES " << (_res[index::dim::cartesian::Y] + 1) << " double\n";

            for (size_t i = 0; i <= _res[index::dim::cartesian::Y]; ++i)
            {
                if (i != 0)
                {
                    file << ' ';
                }

                file << (_min.y + (_cell_size.y * static_cast<double>(i))) << ' ';
            }

            file << "\nZ_COORDINATES " << (_res[index::dim::cartesian::Z] + 1) << " double\n";

            for (size_t i = 0; i <= _res[index::dim::cartesian::Z]; ++i)
            {
                if (i != 0)
                {
                    file << ' ';
                }

                file << (_min.z + (_cell_size.z * static_cast<double>(i))) << ' ';
            }

            file << "\nCELL_DATA " << (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]) << "\n\n";


            file << "\nFIELD FieldData 1\n"
                 << "scatter_dens" << ' ' << 1 << ' ' << (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]) << ' ' << "double" << '\n';

            for (size_t i = 0; i < _res[index::dim::cartesian::Z]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::X]; ++k)
                    {
                        if (k != 0)
                        {
                            file << ' ';
                        }

                        file << _cells[k][j][i].scatter_dens();
                    }
                    file << '\n';
                }
                file << '\n';
            }

            file << "\nFIELD FieldData 1\n"
                 << "energy_dens" << ' ' << 1 << ' ' << (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]) << ' ' << "double" << '\n';

            for (size_t i = 0; i < _res[index::dim::cartesian::Z]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::X]; ++k)
                    {
                        if (k != 0)
                        {
                            file << ' ';
                        }

                        file << _cells[k][j][i].energy_dens();
                    }
                    file << '\n';
                }
                file << '\n';
            }
        }



    } // namespace scene
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SCENE_DOMAIN_HPP
