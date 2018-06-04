/**
 *  @file   arctk/math/container.hpp
 *  @date   04/05/2018
 *  @author Freddy Wordingham
 *
 *  Math container functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONTAINER_HPP
#define ARCTK_MATH_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Mathematical --
        template <typename C, typename T = typename C::value_type, typename I = typename C::iterator>
        inline T sum(C& cont_) noexcept;


        //  == FUNCTIONS ==
        //  -- Mathematical --
        template <typename C, typename T, typename I>
        inline T sum(C& cont_) noexcept
        {
            T total{};

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                total += *it;
            }

            return (total);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_HPP
