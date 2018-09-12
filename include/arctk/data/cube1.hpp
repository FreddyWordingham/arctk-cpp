/**
 *  @file   arctk/data/cube1.hpp
 *  @date   12/09/2018
 *  @author Freddy Wordingham
 *
 *  One-dimensional data cube class..
 */



//  == GUARD ==
#ifndef ARCTK_DATA_CUBE1_HPP
#define ARCTK_DATA_CUBE1_HPP



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
         *  One-dimensional data cube class.
         *
         *  @tparam A   Types stored in data columns.
         */
        template <typename... A>
        class Cube<1, A...>
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const size_t                  _res;
            std::vector<std::tuple<A...>> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Cube(const size_t res_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::tuple<A...>&       operator[](size_t index_) noexcept;
            inline const std::tuple<A...>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline size_t res() const noexcept;
            template <size_t I>
            inline typename std::tuple_element<I, std::tuple<A...>>::type min() const noexcept;
            template <size_t I>
            inline typename std::tuple_element<I, std::tuple<A...>>::type max() const noexcept;

            //  -- Saving --
            inline void save(const std::string& path_, const std::string& set_name_, const std::array<std::string, sizeof...(A)>& var_names_, const double min_ = 0.0, const double max_ = 1.0) const noexcept;

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
         *  Construct a one-dimensional data cube with a given resolution.
         *
         *  @param  res_    Resolution of the data cube.
         *
         *  @pre    res_ must be positive.
         */
        template <typename... A>
        inline Cube<1, A...>::Cube(const size_t res_) noexcept
          : _res(res_)
          , _data(res_)
        {
            PRE(res_ > 0);
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename... A>
        inline std::tuple<A...>& Cube<1, A...>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < _res);

            return (_data[index_]);
        }

        template <typename... A>
        inline const std::tuple<A...>& Cube<1, A...>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < _res);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename... A>
        inline size_t Cube<1, A...>::res() const noexcept
        {
            return (_res);
        }

        template <typename... A>
        template <size_t I>
        inline typename std::tuple_element<I, std::tuple<A...>>::type Cube<1, A...>::min() const noexcept
        {
            typename std::tuple_element<I, std::tuple<A...>>::type min = std::get<I>(_data.front());

            for (size_t i = 0; i < _res; ++i)
            {
                if (std::get<I>(_data[i]) < min)
                {
                    min = std::get<I>(_data[i]);
                }
            }

            return (min);
        }

        template <typename... A>
        template <size_t I>
        inline typename std::tuple_element<I, std::tuple<A...>>::type Cube<1, A...>::max() const noexcept
        {
            typename std::tuple_element<I, std::tuple<A...>>::type max = std::get<I>(_data.front());

            for (size_t i = 0; i < _res; ++i)
            {
                if (std::get<I>(_data[i]) > max)
                {
                    max = std::get<I>(_data[i]);
                }
            }

            return (max);
        }


        //  -- Saving --
        template <typename... A>
        inline void Cube<1, A...>::save(const std::string& path_, const std::string& set_name_, const std::array<std::string, sizeof...(A)>& var_names_, const double min_, const double max_) const noexcept // NOLINT
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
            PRE(min_ < max_);

            double cell_size = (max_ - min_) / static_cast<double>(_res);

            std::ofstream file(path_ + ".vtk");

            file << "# vtk DataFile Version 3.0\n"
                 << "vtk " << set_name_ << '\n'
                 << "ASCII\n"
                 << "DATASET RECTILINEAR_GRID\n"
                 << "DIMENSIONS " << (_res + 1) << " 1 1\n"
                 << "X_COORDINATES " << (_res + 1) << " double\n";

            for (size_t i = 0; i <= _res; ++i)
            {
                if (i != 0)
                {
                    file << ' ';
                }

                file << (min_ + (cell_size * static_cast<double>(i))) << ' ';
            }

            file << "\nY_COORDINATES 1 double\n"
                 << "0\n"
                 << "\nZ_COORDINATES 1 double\n"
                 << "0\n";

            file << "\nCELL_DATA " << _res << "\n\n";

            write_data(var_names_, file, std::index_sequence_for<A...>());
        }

        template <typename... A>
        template <size_t... I>
        inline void Cube<1, A...>::write_data(const std::array<std::string, sizeof...(A)>& var_names_, std::ofstream& file_, const std::index_sequence<I...>& /*unused*/) const noexcept
        {
            PRE(!var_names_.empty());
            for (size_t i = 0; i < sizeof...(A); ++i)
            {
                PRE(var_names_[i].find_first_of('\n') == std::string::npos);
                PRE(var_names_[i].find_first_of(' ') == std::string::npos);
            }
            PRE(utl::properties::distinct(var_names_));

            (write_var<I>(var_names_[I], file_), ...);
        }

        template <typename... A>
        template <size_t I>
        inline void Cube<1, A...>::write_var(const std::string& var_name_, std::ofstream& file_) const noexcept
        {
            PRE(!var_name_.empty());
            PRE(var_name_.find_first_of('\n') == std::string::npos);
            PRE(var_name_.find_first_of(' ') == std::string::npos);

            file_ << "\nFIELD FieldData 1\n" << var_name_ << ' ' << 1 << ' ' << _res << ' ' << VTK_TYPENAME<typename std::tuple_element<I, std::tuple<A...>>::type> << '\n';

            for (size_t i = 0; i < _res; ++i)
            {
                if (i != 0)
                {
                    file_ << ' ';
                }

                file_ << std::get<I>(_data[i]);
            }
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE1_HPP
