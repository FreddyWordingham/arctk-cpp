/**
 *  @file   arctk/math/comparison.hpp
 *  @date   22/06/2018
 *  @author Freddy Wordingham
 *
 *  Math comparison functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_COMPARISON_HPP
#define ARCTK_MATH_COMPARISON_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <limits>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Mathematical --
        template <typename T>
        inline bool is_zero(T x_) noexcept;



        //  == FUNCTIONS ==
        //  -- Mathematical --
        /**
         *  Test if a value can be considered equal to zero.
         *  Value is considered equal to zero if it is within epsilon of zero.
         *
         *  @tparam T   Type of value to test.
         *
         *  @param  x_  Value to test.
         *
         *  @return true if the value can be considered equal to zero.
         */
        template <typename T>
        inline bool is_zero(T x_) noexcept
        {
            return ((x_ > -std::numeric_limits<double>::epsilon()) && (x_ < std::numeric_limits<double>::epsilon()));
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_COMPARISON_HPP
