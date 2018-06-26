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
        template <typename T>
        inline bool equal(const T x_, const T y_) noexcept;



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

        /**
         *  Test if a pair of values can be considered equal to one another.
         *  Values are considered equal to zero if they are equal to within epsilon.
         *
         *  @tparam T   Type of values to test.
         *
         *  @param  x_  Fist value to test.
         *  @param  y_  Second value to test.
         *
         *  @return true if the values can be considered equal.
         */
        template <typename T>
        inline bool equal(const T x_, const T y_) noexcept
        {
            return (zero(x_ - y_));
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_COMPARISON_HPP
