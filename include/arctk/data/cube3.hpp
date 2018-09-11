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
         */
        template <>
        class Cube<3>
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::array<size_t, 3> _res;


            //  == OPERATORS ==
          public:
            //  -- Access --


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<size_t, 3> res() const noexcept;
        };



        //  == OPERATORS ==
        //  -- Access --



        //  == METHODS ==
        //  -- Getters --
        template <>
        inline const std::array<size_t, 3> Cube<3>::res() const noexcept
        {
            return (_res);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_CUBE_HPP
