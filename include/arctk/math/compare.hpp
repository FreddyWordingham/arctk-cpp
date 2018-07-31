/**
 *  @file   arctk/math/compare.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Math comparison functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_COMPARE_HPP
#define ARCTK_MATH_COMPARE_HPP



//  == IMPORTS ==
//  -- Std --
#include <limits>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace compare //! comparison namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Comparison --
            template <typename T>
            inline bool zero(T x_) noexcept;
            template <typename T>
            inline bool equal(T x_, T y_) noexcept;



            //  == FUNCTIONS ==
            //  -- Comparison --
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
            inline bool zero(const T x_) noexcept
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



        } // namespace compare
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_COMPARE_HPP
