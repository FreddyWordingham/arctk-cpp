/**
 *  @file   arctk/math/mat/transform.hpp
 *  @date   23/10/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical matrix transformation functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT_TRANSFORM_HPP
#define ARCTK_MATH_MAT_TRANSFORM_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/mat.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Vec;
    } // namespace math
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace mat //! matrix namespace
        {
            namespace transform //! transformation namespace
            {



                //  == FUNCTION PROTOTYPES ==
                //  -- Transformation --
                template <typename T>
                constexpr inline Mat<T, 4> scale(const Vec<T, 3>& scale_) noexcept;
                template <typename T>
                constexpr inline Mat<T, 4> rotate_x(T ang_) noexcept;
                template <typename T>
                constexpr inline Mat<T, 4> rotate_y(T ang_) noexcept;
                template <typename T>
                constexpr inline Mat<T, 4> rotate_z(T ang_) noexcept;
                template <typename T>
                constexpr inline Mat<T, 4> rotate(const Vec<T, 3>& rot_) noexcept;
                template <typename T>
                constexpr inline Mat<T, 4> rotate(const Vec<T, 3>& axis_, T ang_) noexcept;
                template <typename T>
                constexpr inline Mat<T, 4> translate(const Vec<T, 3>& trans_) noexcept;
                template <typename T>
                constexpr inline Mat<T, 4> scale_rotate_trans(const Vec<T, 3>& scale_, const Vec<T, 3>& rot_, const Vec<T, 3>& trans_) noexcept;



            } // namespace transform
        }     // namespace mat
    }         // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/mat/transform.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_MAT_TRANSFORM_HPP
