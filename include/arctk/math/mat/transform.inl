/**
 *  @file   arctk/math/mat/transform.inl
 *  @date   23/10/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical matrix transformation functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT_TRANSFORM_INL
#define ARCTK_MATH_MAT_TRANSFORM_INL



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace mat //! matrix namespace
        {
            namespace transform //! transformation namespace
            {



                //  == FUNCTIONS ==
                //  -- Transformation --
                /**
                 *  Create a scale transformation matrix.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  scale_  Vec of scaling to be applied in each dimension.
                 *
                 *  @return Scale transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> scale(const Vec<T, 3>& scale_) noexcept
                {
                    return (Mat<T, 4>(Vec<T, 4>(scale_.x, T{0}, T{0}, T{0}), Vec<T, 4>(T{0}, scale_.y, T{0}, T{0}), Vec<T, 4>(T{0}, T{0}, scale_.z, T{0}), Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
                }

                /**
                 *  Create a x-axis rotation transformation matrix.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  ang_    Angle to rotate around the x-axis.
                 *
                 *  @return X-axis rotation transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> rotate_x(const T ang_) noexcept
                {
                    return (Mat<T, 4>(Vec<T, 4>(T{1}, T{0}, T{0}, T{0}), Vec<T, 4>(T{0}, std::cos(ang_), -std::sin(ang_), T{0}), Vec<T, 4>(T{0}, std::sin(ang_), std::cos(ang_), T{0}), Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
                }

                /**
                 *  Create a y-axis rotation transformation matrix.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  ang_    Angle to rotate around the x-axis.
                 *
                 *  @return Y-axis rotation transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> rotate_y(const T ang_) noexcept
                {
                    return (Mat<T, 4>(Vec<T, 4>(std::cos(ang_), T{0}, std::sin(ang_), T{0}), Vec<T, 4>(T{0}, T{1}, T{0}, T{0}), Vec<T, 4>(-std::sin(ang_), T{0}, std::cos(ang_), T{0}), Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
                }

                /**
                 *  Create a z-axis rotation transformation matrix.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  ang_    Angle to rotate around the x-axis.
                 *
                 *  @return Z-axis rotation transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> rotate_z(const T ang_) noexcept
                {
                    return (Mat<T, 4>(Vec<T, 4>(std::cos(ang_), -std::sin(ang_), T{0}, T{0}), Vec<T, 4>(std::sin(ang_), std::cos(ang_), T{0}, T{0}), Vec<T, 4>(T{0}, T{0}, T{1}, T{0}), Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
                }

                /**
                 *  Create a Euler rotation transformation matrix.
                 *  Rotations are performed in x-y-z order.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  rot_    Vec of rotation angles to be applied in each dimension.
                 *
                 *  @return Rotation transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> rotate(const Vec<T, 3>& rot_) noexcept
                {
                    return (Mat<T, 4>(Vec<T, 4>(std::cos(rot_.z) * std::cos(rot_.y), (std::cos(rot_.z) * std::sin(rot_.y) * std::sin(rot_.x)) - (std::sin(rot_.z) * std::cos(rot_.x)),
                                                (std::sin(rot_.z) * std::sin(rot_.x)) + (std::cos(rot_.z) * std::sin(rot_.y) * std::cos(rot_.x)), T{0}),
                                      Vec<T, 4>(std::sin(rot_.z) * std::cos(rot_.y), (std::cos(rot_.z) * std::cos(rot_.x)) + (std::sin(rot_.z) * std::sin(rot_.y) * std::sin(rot_.x)),
                                                (std::sin(rot_.z) * std::sin(rot_.y) * std::cos(rot_.x)) - (std::cos(rot_.z) * std::sin(rot_.x)), T{0}),
                                      Vec<T, 4>(-std::sin(rot_.y), std::cos(rot_.y) * std::sin(rot_.x), std::cos(rot_.y) * std::cos(rot_.x), T{0}), Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
                }

                /**
                 *  Create a rotation transformation matrix.
                 *  Rotation is performed around a given axis through a given angle.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  axis_   Axis around which to perform the rotation.
                 *  @param  ang_    Angle to rotate around the axis.
                 *
                 *  @pre    axis_ must be normalised.
                 *
                 *  @return Rotation transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> rotate(const Vec<T, 3>& axis_, const T ang_) noexcept
                {
                    assert(axis_.normalised());

                    const T sin_ang = std::sin(ang_);
                    const T cos_ang = std::cos(ang_);

                    return (Mat<T, 4>(Vec<T, 4>(cos_ang + (axis_.x * axis_.x * (T{1} - cos_ang)), ((axis_.x * axis_.y * (T{1} - cos_ang)) - (axis_.z * sin_ang)), ((axis_.x * axis_.z * (T{1} - cos_ang)) + (axis_.y * sin_ang)), T{0}),
                                      Vec<T, 4>(((axis_.y * axis_.x * (T{1} - cos_ang)) + (axis_.z * sin_ang)), cos_ang + (axis_.y * axis_.y * (T{1} - cos_ang)), ((axis_.y * axis_.z * (T{1} - cos_ang)) - (axis_.x * sin_ang)), T{0}),
                                      Vec<T, 4>(((axis_.z * axis_.x * (T{1} - cos_ang)) - (axis_.y * sin_ang)), ((axis_.z * axis_.y * (T{1} - cos_ang)) + (axis_.x * sin_ang)), cos_ang + (axis_.z * axis_.z * (T{1} - cos_ang)), T{0}),
                                      Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
                }

                /**
                 *  Create a translation transformation matrix.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  trans_  Vec of translations to be applied in each dimension.
                 *
                 *  @return Translation transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> translate(const Vec<T, 3>& trans_) noexcept
                {
                    return (Mat<T, 4>(Vec<T, 4>(T{1}, T{0}, T{0}, trans_.x), Vec<T, 4>(T{0}, T{1}, T{0}, trans_.y), Vec<T, 4>(T{0}, T{0}, T{1}, trans_.z), Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
                }

                /**
                 *  Create a transformation matrix which applies a scaling, followed by a rotation followed by a translation.
                 *  Rotations are performed in x-y-z order.
                 *
                 *  @tparam T   Type stored by the mat
                 *
                 *  @param  scale_  Vec of translations to be applied in each dimension.
                 *  @param  rot_    Vec of rotation angles to be applied in each dimension.
                 *  @param  trans_  Vec of translations to be applied in each dimension.
                 *
                 *  @return Transformation matrix.
                 */
                template <typename T>
                constexpr inline Mat<T, 4> scale_rotate_trans(const Vec<T, 3>& scale_, const Vec<T, 3>& rot_, const Vec<T, 3>& trans_) noexcept
                {
                    return (translate(trans_) * rotate(rot_) * scale(scale_));
                }



            } // namespace transform
        }     // namespace mat
    }         // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_MAT_TRANSFORM_INL
