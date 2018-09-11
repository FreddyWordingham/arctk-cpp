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
#include <tuple>
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
         *  @tparam A   Types stored in data columns.
         */
        template <typename... A>
        class Cube<3, A...>
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3>                             _res;
            std::vector<std::vector<std::vector<std::tuple<A...>>>> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Cube(const std::array<size_t, 3>& res_) noexcept;


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
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename... A>
        inline Cube<3, A...>::Cube(const std::array<size_t, 3>& res_) noexcept
          : _res(res_)
          , _data(res_[index::dim::cartesian::X], std::vector<std::vector<std::tuple<A...>>>(res_[index::dim::cartesian::Y], std::vector<std::tuple<A...>>(res_[index::dim::cartesian::Z])))
        {
            PRE(res_[index::dim::cartesian::X] > 0);
            PRE(res_[index::dim::cartesian::Y] > 0);
            PRE(res_[index::dim::cartesian::Z] > 0);
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename... A>
        inline std::vector<std::vector<std::tuple<A...>>>& Cube<3, A...>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }

        template <typename... A>
        inline const std::vector<std::vector<std::tuple<A...>>>& Cube<3, A...>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename... A>
        inline const std::array<size_t, 3> Cube<3, A...>::res() const noexcept
        {
            return (_res);
        }

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



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE3_HPP
