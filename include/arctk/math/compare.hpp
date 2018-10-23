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
            inline bool zero(T x_, T tol_ = std::numeric_limits<T>::epsilon()) noexcept;
            template <typename T>
            inline bool unity(T x_, T tol_ = std::numeric_limits<T>::epsilon()) noexcept;
            template <typename T>
            inline bool equal(T x_, T y_, T tol_ = std::numeric_limits<T>::epsilon()) noexcept;



        } // namespace compare
    }     // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/compare.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_COMPARE_HPP
