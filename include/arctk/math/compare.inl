/**
 *  @file   arctk/math/compare.inl
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Math comparison functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_COMPARE_INL
#define ARCTK_MATH_COMPARE_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace compare //! comparison namespace
        {



            //  == FUNCTIONS ==
            //  -- Comparison --
            /**
             *  Test if a value can be considered equal to zero.
             *  Value is considered equal to zero if it is within the given tolerance of zero.
             *
             *  @tparam T   Type of value to test.
             *
             *  @param  x_      Value to test.
             *  @param  tol_    Tolerance of the test/
             *
             *  @return true if the value can be considered equal to zero.
             */
            template <typename T>
            inline bool zero(const T x_, const T tol_) noexcept
            {
                return ((x_ > -tol_) && (x_ < tol_));
            }

            /**
             *  Test if a value can be considered equal to unity.
             *  Value is considered equal to unity if it is within the given tolerance of one.
             *
             *  @tparam T   Type of value to test.
             *
             *  @param  x_      Value to test.
             *  @param  tol_    Tolerance of the test/
             *
             *  @return true if the value can be considered equal to unity.
             */
            template <typename T>
            inline bool unity(const T x_, const T tol_) noexcept
            {
                return (zero(x_ - T{1.0}, tol_));
            }

            /**
             *  Test if a pair of values can be considered equal to one another.
             *  Values are considered equal to zero if they are equal to within the given tolerance.
             *
             *  @tparam T   Type of values to test.
             *
             *  @param  x_      Fist value to test.
             *  @param  y_      Second value to test.
             *  @param  tol_    Tolerance of the test/
             *
             *  @return true if the values can be considered equal.
             */
            template <typename T>
            inline bool equal(const T x_, const T y_, const T tol_) noexcept // NOLINT
            {
                return (zero(x_ - y_, tol_));
            }



        } // namespace compare
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_COMPARE_INL
