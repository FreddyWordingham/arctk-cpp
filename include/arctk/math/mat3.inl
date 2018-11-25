/**
 *  @file   arctk/math/mat3.inl
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical three-by-three matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT3_INL
#define ARCTK_MATH_MAT3_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <ostream>

//  -- Arctk --
#include <arctk/consts/format.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a three by three mat with initial element values.
         *
         *  @param  x_  Initial values of the x row.
         *  @param  y_  Initial values of the y row.
         *  @param  z_  Initial values of the z row.
         */
        template <typename T>
        constexpr inline Mat<T, 3>::Mat(const Vec<T, 3>& x_, const Vec<T, 3>& y_, const Vec<T, 3>& z_) noexcept
          : x(x_)
          , y(y_)
          , z(z_)
        {
        }



        //  == OPERATORS ==
        //  -- Assignment --
        /**
         *  Add a value to all elements of the mat.
         *
         *  @param  val_    Value to add to each mat element.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator+=(const T val_) noexcept
        {
            x.x += val_;
            x.y += val_;
            x.z += val_;

            y.x += val_;
            y.y += val_;
            y.z += val_;

            z.x += val_;
            z.y += val_;
            z.z += val_;

            return (*this);
        }

        /**
         *  Add another mat's elements to each corresponding element of the mat.
         *
         *  @param  mat_    mat to add to this mat.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator+=(const Mat<T, 3>& mat_) noexcept
        {
            x.x += mat_.x.x;
            x.y += mat_.x.y;
            x.z += mat_.x.z;

            y.x += mat_.y.x;
            y.y += mat_.y.y;
            y.z += mat_.y.z;

            z.x += mat_.z.x;
            z.y += mat_.z.y;
            z.z += mat_.z.z;

            return (*this);
        }

        /**
         *  Subtract a value from all elements of the mat.
         *
         *  @param  val_    Value to subtract from each mat element.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator-=(const T val_) noexcept
        {
            x.x -= val_;
            x.y -= val_;
            x.z -= val_;

            y.x -= val_;
            y.y -= val_;
            y.z -= val_;

            z.x -= val_;
            z.y -= val_;
            z.z -= val_;

            return (*this);
        }

        /**
         *  Subtract another mat's elements from each corresponding element of the mat.
         *
         *  @param  mat_    mat to subtract from this mat.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator-=(const Mat<T, 3>& mat_) noexcept
        {
            x.x -= mat_.x.x;
            x.y -= mat_.x.y;
            x.z -= mat_.x.z;

            y.x -= mat_.y.x;
            y.y -= mat_.y.y;
            y.z -= mat_.y.z;

            z.x -= mat_.z.x;
            z.y -= mat_.z.y;
            z.z -= mat_.z.z;

            return (*this);
        }

        /**
         *  Multiply all elements of the mat by a value.
         *
         *  @param  val_    Value used to multiply each mat element by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator*=(const T val_) noexcept
        {
            x.x *= val_;
            x.y *= val_;
            x.z *= val_;

            y.x *= val_;
            y.y *= val_;
            y.z *= val_;

            z.x *= val_;
            z.y *= val_;
            z.z *= val_;

            return (*this);
        }

        /**
         *  Multiply the mat by another mat.
         *
         *  @param  mat_    Matrix to multiply this matrix by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator*=(const Mat<T, 3>& mat_) noexcept
        {
            const Mat<T, 3> pre = *this;

            x.x = (pre.x.x * mat_.x.x) + (pre.x.y * mat_.y.x) + (pre.x.z * mat_.z.x);
            x.y = (pre.x.x * mat_.x.y) + (pre.x.y * mat_.y.y) + (pre.x.z * mat_.z.y);
            x.z = (pre.x.x * mat_.x.z) + (pre.x.y * mat_.y.z) + (pre.x.z * mat_.z.z);

            y.x = (pre.y.x * mat_.x.x) + (pre.y.y * mat_.y.x) + (pre.y.z * mat_.z.x);
            y.y = (pre.y.x * mat_.x.y) + (pre.y.y * mat_.y.y) + (pre.y.z * mat_.z.y);
            y.z = (pre.y.x * mat_.x.z) + (pre.y.y * mat_.y.z) + (pre.y.z * mat_.z.z);

            z.x = (pre.z.x * mat_.x.x) + (pre.z.y * mat_.y.x) + (pre.z.z * mat_.z.x);
            z.y = (pre.z.x * mat_.x.y) + (pre.z.y * mat_.y.y) + (pre.z.z * mat_.z.y);
            z.z = (pre.z.x * mat_.x.z) + (pre.z.y * mat_.y.z) + (pre.z.z * mat_.z.z);

            return (*this);
        }

        /**
         *  Divide all elements of the mat by a value.
         *
         *  @param  val_    Value used to divide each mat element by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator/=(const T val_) noexcept
        {
            x.x /= val_;
            x.y /= val_;
            x.z /= val_;

            y.x /= val_;
            y.y /= val_;
            y.z /= val_;

            z.x /= val_;
            z.y /= val_;
            z.z /= val_;

            return (*this);
        }


        //  -- Increment / Decrement --
        /**
         *  Increment each element of the mat.
         *
         *  @return A reference to this mat pre-increment.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator++() noexcept
        {
            ++x.x;
            ++x.y;
            ++x.z;

            ++y.x;
            ++y.y;
            ++y.z;

            ++z.x;
            ++z.y;
            ++z.z;

            return (*this);
        }

        /**
         *  Increment each element of the mat.
         *
         *  @return A copy of this mat post-increment.
         */
        template <typename T>
        constexpr inline const Mat<T, 3> Mat<T, 3>::operator++(const int) noexcept
        {
            const Mat mat = *this;

            ++x.x;
            ++x.y;
            ++x.z;

            ++y.x;
            ++y.y;
            ++y.z;

            ++z.x;
            ++z.y;
            ++z.z;

            return (mat);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A reference to this mat pre-decrement.
         */
        template <typename T>
        constexpr inline Mat<T, 3>& Mat<T, 3>::operator--() noexcept
        {
            --x.x;
            --x.y;
            --x.z;

            --y.x;
            --y.y;
            --y.z;

            --z.x;
            --z.y;
            --z.z;

            return (*this);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A copy of this mat post-decrement.
         */
        template <typename T>
        constexpr inline const Mat<T, 3> Mat<T, 3>::operator--(const int) noexcept
        {
            const Mat mat = *this;

            --x.x;
            --x.y;
            --x.z;

            --y.x;
            --y.y;
            --y.z;

            --z.x;
            --z.y;
            --z.z;

            return (mat);
        }


        //  -- Arithmetic --
        /**
         *  Positive copy the mat.
         *
         *  @return Positive copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator+() const noexcept
        {
            return (Mat(Vec<T, 3>(+x.x, +x.y, +x.z), Vec<T, 3>(+y.x, +y.y, +y.z), Vec<T, 3>(+z.x, +z.y, +z.z)));
        }

        /**
         *  Negative copy the mat.
         *
         *  @return Negative copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator-() const noexcept
        {
            return (Mat(Vec<T, 3>(-x.x, -x.y, -x.z), Vec<T, 3>(-y.x, -y.y, -y.z), Vec<T, 3>(-z.x, -z.y, -z.z)));
        }

        /**
         *  Add a value to a mat.
         *
         *  @param  val_    Value to add to the mat.
         *
         *  @return Mat formed by adding the value to the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator+(const T val_) const noexcept
        {
            return (Mat(Vec<T, 3>(x.x + val_, x.y + val_, x.z + val_), Vec<T, 3>(y.x + val_, y.y + val_, y.z + val_), Vec<T, 3>(z.x + val_, z.y + val_, z.z + val_)));
        }

        /**
         *  Add a mat to a mat.
         *
         *  @param  mat_    Mat to add to the mat.
         *
         *  @return Mat formed by adding the mat to the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator+(const Mat<T, 3>& mat_) const noexcept
        {
            return (Mat(Vec<T, 3>(x.x + mat_.x.x, x.y + mat_.x.y, x.z + mat_.x.z), Vec<T, 3>(y.x + mat_.y.x, y.y + mat_.y.y, y.z + mat_.y.z), Vec<T, 3>(z.x + mat_.z.x, z.y + mat_.z.y, z.z + mat_.z.z)));
        }

        /**
         *  Subtract a value from a mat.
         *
         *  @param  val_    Value to subtract from the mat.
         *
         *  @return Mat formed by subtracting the value from the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator-(const T val_) const noexcept
        {
            return (Mat(Vec<T, 3>(x.x - val_, x.y - val_, x.z - val_), Vec<T, 3>(y.x - val_, y.y - val_, y.z - val_), Vec<T, 3>(z.x - val_, z.y - val_, z.z - val_)));
        }

        /**
         *  Subtract a mat from a mat.
         *
         *  @param  mat_    Mat to subtract from the mat.
         *
         *  @return Mat formed by subtracting the mat from the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator-(const Mat<T, 3>& mat_) const noexcept
        {
            return (Mat(Vec<T, 3>(x.x - mat_.x.x, x.y - mat_.x.y, x.z - mat_.x.z), Vec<T, 3>(y.x - mat_.y.x, y.y - mat_.y.y, y.z - mat_.y.z), Vec<T, 3>(z.x - mat_.z.x, z.y - mat_.z.y, z.z - mat_.z.z)));
        }

        /**
         *  Multiply a mats elements by a value.
         *
         *  @param  val_    Value used to multiply the mat elements.
         *
         *  @return Mat formed by multiplying the mat elements by the value.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator*(const T val_) const noexcept
        {
            return (Mat(Vec<T, 3>(x.x * val_, x.y * val_, x.z * val_), Vec<T, 3>(y.x * val_, y.y * val_, y.z * val_), Vec<T, 3>(z.x * val_, z.y * val_, z.z * val_)));
        }

        /**
         *  Multiply the mat by a vec.
         *
         *  @param  vec_    Vec to multiply this mat by.
         *
         *  @return Vec formed by multiplying the mat by the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Mat<T, 3>::operator*(const Vec<T, 3>& vec_) const noexcept
        {
            return (Vec<T, 3>((x.x * vec_.x) + (x.y * vec_.y) + (x.z * vec_.z), (y.x * vec_.x) + (y.y * vec_.y) + (y.z * vec_.z), (z.x * vec_.x) + (z.y * vec_.y) + (z.z * vec_.z)));
        }

        /**
         *  Multiply two mats together.
         *
         *  @param  mat_    Right hand side mat of the operation.
         *
         *  @return Mat formed by multiplying the two mats together.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator*(const Mat<T, 3>& mat_) const noexcept
        {
            return (Mat<T, 3>(Vec<T, 3>(x * Vec<T, 3>(mat_.x.x, mat_.y.x, mat_.z.x), x * Vec<T, 3>(mat_.x.y, mat_.y.y, mat_.z.y), x * Vec<T, 3>(mat_.x.z, mat_.y.z, mat_.z.z)),
                              Vec<T, 3>(y * Vec<T, 3>(mat_.x.x, mat_.y.x, mat_.z.x), y * Vec<T, 3>(mat_.x.y, mat_.y.y, mat_.z.y), y * Vec<T, 3>(mat_.x.z, mat_.y.z, mat_.z.z)),
                              Vec<T, 3>(z * Vec<T, 3>(mat_.x.x, mat_.y.x, mat_.z.x), z * Vec<T, 3>(mat_.x.y, mat_.y.y, mat_.z.y), z * Vec<T, 3>(mat_.x.z, mat_.y.z, mat_.z.z))));
        }

        /**
         *  Divide a mats elements by a value.
         *
         *  @param  val_    Value used to divide the mat elements.
         *
         *  @return Mat formed by dividing the mat elements by the value.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::operator/(const T val_) const noexcept
        {
            return (Mat<T, 3>(Vec<T, 3>(x.x / val_, x.y / val_, x.z / val_), Vec<T, 3>(y.x / val_, y.y / val_, y.z / val_), Vec<T, 3>(z.x / val_, z.y / val_, z.z / val_)));
        }


        //  -- Access --
        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than three.
         *
         *  @return A reference to the element requested.
         */
        template <typename T>
        constexpr inline Vec<T, 3>& Mat<T, 3>::operator[](const size_t index_) noexcept
        {
            assert(index_ < 3);

            return ((&x)[index_]);
        }

        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than three.
         *
         *  @return A const reference to the element requested.
         */
        template <typename T>
        constexpr inline const Vec<T, 3>& Mat<T, 3>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 3);

            return ((&x)[index_]);
        }


        //  -- Printing --
        /**
         *  Print the matrix to a stream.
         *
         *  @tparam S   Type stored by the matrix.
         *
         *  @param  stream_ Stream to print to.
         *  @param  mat_    Matrix to be printed.
         *
         *  @return Reference to the matrix post-print.
         */
        template <typename S>
        constexpr inline std::ostream& operator<<(std::ostream& stream_, const Mat<S, 3>& mat_) noexcept
        {
            stream_ << consts::format::OPENERS[consts::format::container::MAT] << mat_.x << consts::format::DELIM << mat_.y << consts::format::DELIM << mat_.z << consts::format::CLOSERS[consts::format::container::MAT];

            return (stream_);
        }



        //  == METHODS ==
        //  -- Mathematical --
        /**
         *  Calculate the sum of the mat elements.
         *
         *  @return Sum of the mat elements.
         */
        template <typename T>
        constexpr inline T Mat<T, 3>::sum() const noexcept
        {
            return (x.x + x.y + x.z + y.x + y.y + y.z + z.x + z.y + z.z);
        }

        /**
         *  Calculate the determinant of the matrix.
         *
         *  @return Determinant of the matrix.
         */
        template <typename T>
        constexpr inline T Mat<T, 3>::det() const noexcept
        {
            return ((x.x * y.y * z.z) - (x.x * y.z * z.y) - (x.y * y.x * z.z) + (x.y * y.z * z.x) + (x.z * y.x * z.y) - (x.z * y.y * z.x));
        }

        /**
         *  Calculate the matrix of minors of the matrix.
         *
         *  @return Matrix of minors of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::minors() const noexcept
        {
            return (Mat<T, 3>(Vec<T, 3>((y.y * z.z) - (y.z * z.y), (y.x * z.z) - (y.z * z.x), (y.x * z.y) - (y.y * z.x)), Vec<T, 3>((x.y * z.z) - (x.z * z.y), (x.x * z.z) - (x.z * z.x), (x.x * z.y) - (x.y * z.x)),
                              Vec<T, 3>((x.y * y.z) - (x.z * y.y), (x.x * y.z) - (x.z * y.x), (x.x * y.y) - (x.y * y.x))));
        }

        /**
         *  Calculate the matrix of cofactors of the matrix.
         *
         *  @return Matrix of cofactors of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::cofactor() const noexcept
        {
            Mat<T, 3> mat = minors();

            mat.x.y *= -1;
            mat.y.x *= -1;
            mat.y.z *= -1;
            mat.z.y *= -1;

            return (mat);
        }

        /**
         *  Calculate the transpose matrix of the matrix.
         *
         *  @return Transpose matrix of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::trans() const noexcept
        {
            return (Mat<T, 3>(Vec<T, 3>(x.x, y.x, z.x), Vec<T, 3>(x.y, y.y, z.y), Vec<T, 3>(x.z, y.z, z.z)));
        }

        /**
         *  Calculate the adjoint matrix of the matrix.
         *
         *  @return Adjoint matrix of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::adj() const noexcept
        {
            return (Mat<T, 3>(Vec<T, 3>((y.y * z.z) - (y.z * z.y), (x.z * z.y) - (x.y * z.z), (x.y * y.z) - (x.z * y.y)), Vec<T, 3>((y.z * z.x) - (y.x * z.z), (x.x * z.z) - (x.z * z.x), (x.z * y.x) - (x.x * y.z)),
                              Vec<T, 3>((y.x * z.y) - (y.y * z.x), (x.y * z.x) - (x.x * z.y), (x.x * y.y) - (x.y * y.x))));
        }

        /**
         *  Calculate the inverse matrix of the matrix.
         *
         *  @return Inverse matrix of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 3> Mat<T, 3>::inv() const noexcept
        {
            return (adj() /= det());
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_MAT3_INL
