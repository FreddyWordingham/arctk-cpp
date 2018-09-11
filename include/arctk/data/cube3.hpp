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


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3> res() const noexcept;
        };



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline const std::array<size_t, 3> Cube<T, 3>::res() const noexcept
        {
            return (_res);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE_HPP
