/**
 *  @file   arctk/data/cube3.hpp
 *  @date   10/09/2018
 *  @author Freddy Wordingham
 *
 *  Three-dimensional data cube class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_CUBE3_HPP
#define ARCTK_DATA_CUBE3_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <fstream>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/data/cube.hpp>
#include <arctk/debug.hpp>
#include <arctk/index.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Three-dimensional data cube class.
         *
         *  @tparam T   Type binned.
         */
        template <typename T>
        class Cube<T, 3>
        {
            //  == FIELDS ==
          private:
            //  -- Resolution --
            const std::array<size_t, 3> _res;

            //  -- Data --
            std::vector<std::vector<std::vector<T>>> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Cube(const std::array<size_t, 3>& res_) noexcept;
            inline Cube(const std::array<size_t, 3>& res_, const T& val_) noexcept;
            inline Cube(const std::vector<std::vector<std::vector<T>>>& data_) noexcept;

            //  -- Initialisation --
            inline std::array<size_t, 3> init_res(const std::vector<std::vector<std::vector<T>>>& data_) const noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::vector<std::vector<T>>&       operator[](size_t index_) noexcept;
            inline const std::vector<std::vector<T>>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3> res() const noexcept;
            inline T                           min() const noexcept;
            inline T                           max() const noexcept;

            //  -- Mathematical --
            inline void       normalise() const noexcept;
            inline Cube<T, 3> normal() const noexcept;

            //  -- Saving --
            inline void save_vtk(const std::string& path_, const std::string& name_, const std::string& var_name_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Cube<T, 3>::Cube(const std::array<size_t, 3>& res_) noexcept
          : _res(res_)
          , _data(res_[index::dim::cartesian::X], std::vector<std::vector<T>>(res_[index::dim::cartesian::Y], std::vector<T>(res_[index::dim::cartesian::Z])))
        {
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }

        template <typename T>
        inline Cube<T, 3>::Cube(const std::array<size_t, 3>& res_, const T& val_) noexcept
          : _res(res_)
          , _data(res_[index::dim::cartesian::X], std::vector<std::vector<T>>(res_[index::dim::cartesian::Y], std::vector<T>(res_[index::dim::cartesian::Z], val_)))
        {
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }

        template <typename T>
        inline Cube<T, 3>::Cube(const std::vector<std::vector<std::vector<T>>>& data_) noexcept
          : _res(init_res(data_))
        {
            PRE(data_.size() > 0);
            PRE(data_.front().size() > 0);
            PRE(data_.front().front().size() > 0);
        }


        //  -- Initialisation --
        template <typename T>
        inline std::array<size_t, 3> Cube<T, 3>::init_res(const std::vector<std::vector<std::vector<T>>>& data_) const noexcept
        {
            PRE(data_.size() > 0);
            PRE(data_.front().size() > 0);
            PRE(data_.front().front().size() > 0);

            return (std::array<size_t, 3>({{data_.size(), data_.front().size(), data_.front().front().size()}}));
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename T>
        inline std::vector<std::vector<T>>& Cube<T, 3>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }

        template <typename T>
        inline const std::vector<std::vector<T>>& Cube<T, 3>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline const std::array<size_t, 3> Cube<T, 3>::res() const noexcept
        {
            return (_res);
        }

        template <typename T>
        inline T Cube<T, 3>::min() const noexcept
        {
            T min = _data.front().front().front();

            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        if (_data[i][j][k] < min)
                        {
                            min = _data[i][j][k];
                        }
                    }
                }
            }

            return (min);
        }

        template <typename T>
        inline T Cube<T, 3>::max() const noexcept
        {
            T max = _data.front().front().front();

            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        if (_data[i][j][k] > max)
                        {
                            max = _data[i][j][k];
                        }
                    }
                }
            }

            return (max);
        }


        //  -- Mathematical --
        template <typename T>
        inline void Cube<T, 3>::normalise() const noexcept
        {
            const T min       = min();
            const T inv_range = 1.0 / max() - min;

            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        _data[i][j][k] -= min;
                        _data[i][j][k] *= inv_range;
                    }
                }
            }
        }

        template <typename T>
        inline Cube<T, 3> Cube<T, 3>::normal() const noexcept
        {
            Cube<T, 3> cube = *this;

            cube.normalise();

            return (cube);
        }


        //  -- Saving --
        template <typename T>
        inline void Cube<T, 3>::save_vtk(const std::string& path_, const std::string& name_, const std::string& var_name_) const noexcept
        {
            PRE(!path_.empty());
            PRE(name_.find_first_of('\n') == std::string::npos);

            std::ofstream file(path_);
            file << "# vtk DataFile Version 2.0\n"
                 << name_ << "\n"
                 << "ASCII\n"
                 << "DATASET STRUCTURED_POINTS\n"
                 << "DIMENSIONS " << _res[index::dim::cartesian::X] << " " << _res[index::dim::cartesian::Y] << " " << _res[index::dim::cartesian::Z] << "\n"
                 << "SCALARS " << var_name_ << " double 1\n"
                 << "LOOKUP_TABLE default\n";

            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        file << _data[i][j][k] << " ";
                    }

                    file << '\n';
                }
            }
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE3_HPP
