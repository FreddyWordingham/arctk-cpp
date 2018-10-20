/**
 *  @file   arctk/data/cube3.hpp
 *  @date   11/09/2018
 *  @author Freddy Wordingham
 *
 *  Three-dimensional data cube class..
 */



//  == GUARD ==
#ifndef ARCTK_DATA_CUBE3_HPP
#define ARCTK_DATA_CUBE3_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <fstream>
#include <tuple>
#include <vector>

//  -- Arctk --
#include <arctk/data/cube.hpp>
#include <arctk/debug.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Three-dimensional data cube class.
         *
         *  @tparam A   Types stored in data columns.
         */
        template <typename... A>
        class Cube<3, A...>
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3>                             _res;  //!< Resolution of the data.
            std::vector<std::vector<std::vector<std::tuple<A...>>>> _data; //!< Stored data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Cube(const std::array<size_t, 3>& res_) noexcept;
            inline explicit Cube(const std::vector<std::vector<std::vector<std::tuple<A...>>>>& data_) noexcept;

          private:
            //  -- Initialisation --
            inline std::array<size_t, 3> init_res(const std::vector<std::vector<std::vector<std::tuple<A...>>>>& data_) const noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::vector<std::vector<std::tuple<A...>>>&       operator[](size_t index_) noexcept;
            inline const std::vector<std::vector<std::tuple<A...>>>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3> res() const noexcept;
            template <size_t I>
            inline typename std::tuple_element<I, std::tuple<A...>>::type min() const noexcept;
            template <size_t I>
            inline typename std::tuple_element<I, std::tuple<A...>>::type max() const noexcept;

            //  -- Saving --
            inline void save(const std::string& path_, const std::string& set_name_, const std::array<std::string, sizeof...(A)>& var_names_, const vec3& min_ = vec3(0.0, 0.0, 0.0), const vec3& max_ = vec3(1.0, 1.0, 1.0)) const noexcept;

          private:
            //  -- Saving --
            template <size_t... I>
            inline void write_data(const std::array<std::string, sizeof...(A)>& var_names_, std::ofstream& file_, const std::index_sequence<I...>& /*unused*/) const noexcept;
            template <size_t I>
            inline void write_var(const std::string& var_name_, std::ofstream& file_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a three-dimensional data cube with a given resolution in each dimension.
         *
         *  @param  res_    Resolution of the data cube in each dimension.
         *
         *  @pre    res_ must be positive in each dimension.
         */
        template <typename... A>
        inline Cube<3, A...>::Cube(const std::array<size_t, 3>& res_) noexcept
          : _res(res_)
          , _data(res_[index::dim::cartesian::X], std::vector<std::vector<std::tuple<A...>>>(res_[index::dim::cartesian::Y], std::vector<std::tuple<A...>>(res_[index::dim::cartesian::Z])))
        {
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }

        /**
         *  Construct a data cube object using a three-dimensional vector of pre-existing data.
         *
         *  @param  data_   Three-dimensional vector of pre-existing data.
         *
         *  @pre    data_ must not be empty.
         *  @pre    First vector of data_ must not be empty.
         *  @pre    First vector of the first vector of data_ must not be empty.
         *  @pre    data_ must be cube shaped.
         */
        template <typename... A>
        inline Cube<3, A...>::Cube(const std::vector<std::vector<std::vector<std::tuple<A...>>>>& data_) noexcept
          : _res(init_res(data_))
          , _data(data_)
        {
            PRE(!data_.empty());
            PRE(!data_.front().empty());
            PRE(!data_.front().front().empty());
            PRE(utl::properties::cube(data_));
        }


        //  -- Initialisation --
        /**
         *  Initialise the resolution array of the datacube.
         *
         *  @param  data_   Three-dimensional vector of pre-existing data.
         *
         *  @return Initialised resolution array of the datacube.
         */
        template <typename... A>
        inline std::array<size_t, 3> Cube<3, A...>::init_res(const std::vector<std::vector<std::vector<std::tuple<A...>>>>& data_) const noexcept
        {
            PRE(!data_.empty());
            PRE(!data_.front().empty());
            PRE(!data_.front().front().empty());
            PRE(utl::properties::cube(data_));

            return (std::array<size_t, 3>({{data_.size(), data_.front().size(), data_.front().front().size()}}));
        }



        //  == OPERATORS ==
        //  -- Access --
        /**
         *  Access the data vector of the datacube.
         *
         *  @param  index_  Index of the x-dimension element to retrieve.
         *
         *  @pre    index_ must be less than the x value of the res array.
         *
         *  @return Reference to element requested.
         */
        template <typename... A>
        inline std::vector<std::vector<std::tuple<A...>>>& Cube<3, A...>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }

        /**
         *  Access the data vector of the datacube.
         *
         *  @param  index_  Index of the x-dimension element to retrieve.
         *
         *  @pre    index_ must be less than the x value of the res array.
         *
         *  @return Const reference to element requested.
         */
        template <typename... A>
        inline const std::vector<std::vector<std::tuple<A...>>>& Cube<3, A...>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the resolution of the datacube.
         *
         *  @return Resolution of the datacube.
         */
        template <typename... A>
        inline const std::array<size_t, 3> Cube<3, A...>::res() const noexcept
        {
            return (_res);
        }

        /**
         *  Get the minimum value of a channel contained within the datacube.
         *
         *  @tparam I   Index of the channel.
         *
         *  @return Minimum value of a channel contained within the datacube.
         */
        template <typename... A>
        template <size_t I>
        inline typename std::tuple_element<I, std::tuple<A...>>::type Cube<3, A...>::min() const noexcept
        {
            typename std::tuple_element<I, std::tuple<A...>>::type min = std::get<I>(_data.front().front().front());

            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        if (std::get<I>(_data[i][j][k]) < min)
                        {
                            min = std::get<I>(_data[i][j][k]);
                        }
                    }
                }
            }

            return (min);
        }

        /**
         *  Get the maximum value of a channel contained within the datacube.
         *
         *  @tparam I   Index of the channel.
         *
         *  @return Maximum value of a channel contained within the datacube.
         */
        template <typename... A>
        template <size_t I>
        inline typename std::tuple_element<I, std::tuple<A...>>::type Cube<3, A...>::max() const noexcept
        {
            typename std::tuple_element<I, std::tuple<A...>>::type max = std::get<I>(_data.front().front().front());

            for (size_t i = 0; i < _res[index::dim::cartesian::X]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::Z]; ++k)
                    {
                        if (std::get<I>(_data[i][j][k]) > max)
                        {
                            max = std::get<I>(_data[i][j][k]);
                        }
                    }
                }
            }

            return (max);
        }


        //  -- Saving --
        /**
         *  Save the datacube as a vtk file.
         *
         *  @param  path_       Path of the save file.
         *  @param  set_name_   Name of the data set.
         *  @param  var_names_  Array of data channel names.
         *  @param  min_        Minimum bound of the datacube.
         *  @param  max_        Maximum bound of the datacube.
         *
         *  @pre    path_ may not be empty.
         *  @pre    set_name_ may not be empty.
         *  @pre    set_name_ may not contain newline characters.
         *  @pre    set_name_ may not contain blank spaces.
         *  @pre    var_names_ may not be empty.
         *  @pre    var_names_ elements may not contain newline characters.
         *  @pre    var_names_ elements may not contain blank spaces.
         *  @pre    var_names_ may be distinct.
         *  @pre    min_.x may be less than max_.x.
         *  @pre    min_.y may be less than max_.y.
         *  @pre    min_.z may be less than max_.z.
         */
        template <typename... A>
        inline void Cube<3, A...>::save(const std::string& path_, const std::string& set_name_, const std::array<std::string, sizeof...(A)>& var_names_, const vec3& min_, const vec3& max_) const noexcept // NOLINT
        {
            PRE(!path_.empty());
            PRE(!set_name_.empty());
            PRE(set_name_.find_first_of('\n') == std::string::npos);
            PRE(set_name_.find_first_of(' ') == std::string::npos);
            PRE(!var_names_.empty());
            for (size_t i = 0; i < sizeof...(A); ++i)
            {
                PRE(var_names_[i].find_first_of('\n') == std::string::npos);
                PRE(var_names_[i].find_first_of(' ') == std::string::npos);
            }
            PRE(utl::properties::distinct(var_names_));
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);

            vec3 cell_size = max_ - min_;
            cell_size.x /= static_cast<double>(_res[index::dim::cartesian::X]);
            cell_size.y /= static_cast<double>(_res[index::dim::cartesian::Y]);
            cell_size.z /= static_cast<double>(_res[index::dim::cartesian::Z]);

            std::ofstream file(path_ + ".vtk");

            file << "# vtk DataFile Version 3.0\n"
                 << "vtk " << set_name_ << '\n'
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

                file << (min_.x + (cell_size.x * static_cast<double>(i))) << ' ';
            }

            file << "\nY_COORDINATES " << (_res[index::dim::cartesian::Y] + 1) << " double\n";

            for (size_t i = 0; i <= _res[index::dim::cartesian::Y]; ++i)
            {
                if (i != 0)
                {
                    file << ' ';
                }

                file << (min_.y + (cell_size.y * static_cast<double>(i))) << ' ';
            }

            file << "\nZ_COORDINATES " << (_res[index::dim::cartesian::Z] + 1) << " double\n";

            for (size_t i = 0; i <= _res[index::dim::cartesian::Z]; ++i)
            {
                if (i != 0)
                {
                    file << ' ';
                }

                file << (min_.z + (cell_size.z * static_cast<double>(i))) << ' ';
            }

            file << "\nCELL_DATA " << (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]) << "\n\n";

            write_data(var_names_, file, std::index_sequence_for<A...>());
        }

        /**
         *  Data writing control method.
         *
         *  @tparam I   Index sequence of channels to write.
         *
         *  @param  var_names_  Array of data channel names.
         *  @param  file_       Handle of the file to write to.
         *
         *  @pre    var_names_ may not be empty.
         *  @pre    var_names_ elements may not contain newline characters.
         *  @pre    var_names_ elements may not contain blank spaces.
         *  @pre    var_names_ must be distinct.
         *  @pre    file_ must be open.
         */
        template <typename... A>
        template <size_t... I>
        inline void Cube<3, A...>::write_data(const std::array<std::string, sizeof...(A)>& var_names_, std::ofstream& file_, const std::index_sequence<I...>& /*unused*/) const noexcept
        {
            PRE(!var_names_.empty());
            for (size_t i = 0; i < sizeof...(A); ++i)
            {
                PRE(var_names_[i].find_first_of('\n') == std::string::npos);
                PRE(var_names_[i].find_first_of(' ') == std::string::npos);
            }
            PRE(utl::properties::distinct(var_names_));
            PRE(file_.is_open());

            (write_var<I>(var_names_[I], file_), ...);
        }

        /**
         *  Write a channel of data to the file.
         *
         *  @tparam I   Index of the channel to write.
         *
         *  @param  var_name_   Name of data channel.
         *  @param  file_       Handle of the file to write to.
         *
         *  @pre    var_name_ may not be empty.
         *  @pre    var_name_ may not contain newline characters.
         *  @pre    var_name_ may not contain blank spaces.
         *  @pre    var_name_ must be distinct.
         *  @pre    file_ must be open.
         */
        template <typename... A>
        template <size_t I>
        inline void Cube<3, A...>::write_var(const std::string& var_name_, std::ofstream& file_) const noexcept
        {
            PRE(!var_name_.empty());
            PRE(var_name_.find_first_of('\n') == std::string::npos);
            PRE(var_name_.find_first_of(' ') == std::string::npos);
            PRE(file_.is_open());

            file_ << "\nFIELD FieldData 1\n"
                  << var_name_ << ' ' << 1 << ' ' << (_res[index::dim::cartesian::X] * _res[index::dim::cartesian::Y] * _res[index::dim::cartesian::Z]) << ' ' << VTK_TYPENAME<typename std::tuple_element<I, std::tuple<A...>>::type> << '\n';

            for (size_t i = 0; i < _res[index::dim::cartesian::Z]; ++i)
            {
                for (size_t j = 0; j < _res[index::dim::cartesian::Y]; ++j)
                {
                    for (size_t k = 0; k < _res[index::dim::cartesian::X]; ++k)
                    {
                        if (k != 0)
                        {
                            file_ << ' ';
                        }

                        file_ << std::get<I>(_data[k][j][i]);
                    }
                    file_ << '\n';
                }
                file_ << '\n';
            }
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE3_HPP
