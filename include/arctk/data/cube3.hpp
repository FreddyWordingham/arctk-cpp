/**
 *  @file   arctk/data/cube3.hpp
 *  @date   11/09/2018
 *  @author Freddy Wordingham
 *
 *  Three-dimensional data cube class..
 */



//  == GUARD ==
#ifndef ARCTK_DATA_CUBE_HPP
#define ARCTK_DATA_CUBE_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <tuple>
#include <vector>

//  -- Arctk --
#include <arctk/data/cube.hpp>



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


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::vector<std::vector<std::tuple<A...>>>&       operator[](size_t index_) noexcept;
            inline const std::vector<std::vector<std::tuple<A...>>>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3> res() const noexcept;
        };



        //  == OPERATORS ==
        //  -- Access --
        template <typename... A>
        inline std::vector<std::vector<std::tuple<A...>>>& Cube<std::tuple<A...>, 3>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }

        template <typename... A>
        inline const std::vector<std::vector<std::tuple<A...>>>& Cube<std::tuple<A...>, 3>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < _res[index::dim::cartesian::X]);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename... A>
        inline const std::array<size_t, 3> Cube<A..., 3>::res() const noexcept
        {
            return (_res);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE_HPP
