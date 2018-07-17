/**
 *  @file   arctk/math/mat4.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical four-by-four matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT4_HPP
#define ARCTK_MATH_MAT4_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <iomanip>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math/mat.hpp>
#include <arctk/math/vec4.hpp>
#include <arctk/settings.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Four-by-four mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 4> : public str::Printable
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 4> x{}; //!< X-row of matrix.
            Vec<T, 4> y{}; //!< Y-row of matrix.
            Vec<T, 4> z{}; //!< Z-row of matrix.
            Vec<T, 4> w{}; //!< W-row of matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            constexpr inline Mat(const Vec<T, 4>& x_, const Vec<T, 4>& y_, const Vec<T, 4>& z_, const Vec<T, 4>& w_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            constexpr inline Mat<T, 4>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, 4>& operator+=(const Mat<T, 4>& mat_) noexcept;
            constexpr inline Mat<T, 4>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, 4>& operator-=(const Mat<T, 4>& mat_) noexcept;
            constexpr inline Mat<T, 4>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, 4>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, 4>&      operator++() noexcept;
            constexpr inline const Mat<T, 4> operator++(int) noexcept;
            constexpr inline Mat<T, 4>&      operator--() noexcept;
            constexpr inline const Mat<T, 4> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Mat<T, 4> operator+() const noexcept;
            constexpr inline Mat<T, 4> operator-() const noexcept;
            constexpr inline Mat<T, 4> operator+(T val_) const noexcept;
            constexpr inline Mat<T, 4> operator+(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Mat<T, 4> operator-(T val_) const noexcept;
            constexpr inline Mat<T, 4> operator-(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Mat<T, 4> operator*(T val_) const noexcept;
            constexpr inline Mat<T, 4> operator*(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Mat<T, 4> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, 4>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, 4>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         det() const noexcept;
            constexpr inline Mat<T, 4> minor() const noexcept;
            constexpr inline Mat<T, 4> cofactor() const noexcept;
            constexpr inline Mat<T, 4> trans() const noexcept;
            constexpr inline Mat<T, 4> adj() const noexcept;
            constexpr inline Mat<T, 4> inv() const noexcept;

            //  -- Printing --
            inline std::string str() const noexcept override;
        };



        //  == FUNCTION PROTOTYPES ==
        //  -- Transformation --
        template <typename T>
        constexpr inline Mat<T, 4> scale(const Vec<T, 3>& scale_) noexcept;
        template <typename T>
        constexpr inline Mat<T, 4> rotate_x(const T ang_) noexcept;
        template <typename T>
        constexpr inline Mat<T, 4> rotate_y(const T ang_) noexcept;
        template <typename T>
        constexpr inline Mat<T, 4> rotate_z(const T ang_) noexcept;
        template <typename T>
        constexpr inline Mat<T, 4> rotate(const Vec<T, 3>& rot_) noexcept;
        template <typename T>
        constexpr inline Mat<T, 4> rotate(const Vec<T, 3>& axis_, const T ang_) noexcept;
        template <typename T>
        constexpr inline Mat<T, 4> translate(const Vec<T, 3>& trans_) noexcept;
        template <typename T>
        constexpr inline Mat<T, 4> transform(const Vec<T, 3>& scale_, const Vec<T, 3>& rot_, const Vec<T, 3>& trans_) noexcept;



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a four by four mat with initial element values.
         *
         *  @param  x_  Initial values of the x row.
         *  @param  y_  Initial values of the y row.
         *  @param  z_  Initial values of the z row.
         *  @param  w_  Initial values of the w row.
         */
        template <typename T>
        constexpr inline Mat<T, 4>::Mat(const Vec<T, 4>& x_, const Vec<T, 4>& y_, const Vec<T, 4>& z_, const Vec<T, 4>& w_) noexcept
          : x(x_)
          , y(y_)
          , z(z_)
          , w(w_)
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
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator+=(const T val_) noexcept
        {
            x.x += val_;
            x.y += val_;
            x.z += val_;
            x.w += val_;

            y.x += val_;
            y.y += val_;
            y.z += val_;
            y.w += val_;

            z.x += val_;
            z.y += val_;
            z.z += val_;
            z.w += val_;

            w.x += val_;
            w.y += val_;
            w.z += val_;
            w.w += val_;

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
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator+=(const Mat<T, 4>& mat_) noexcept
        {
            x.x += mat_.x.x;
            x.y += mat_.x.y;
            x.z += mat_.x.z;
            x.w += mat_.x.w;

            y.x += mat_.y.x;
            y.y += mat_.y.y;
            y.z += mat_.y.z;
            y.w += mat_.y.w;

            z.x += mat_.z.x;
            z.y += mat_.z.y;
            z.z += mat_.z.z;
            z.w += mat_.z.w;

            w.x += mat_.w.x;
            w.y += mat_.w.y;
            w.z += mat_.w.z;
            w.w += mat_.w.w;

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
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator-=(const T val_) noexcept
        {
            x.x -= val_;
            x.y -= val_;
            x.z -= val_;
            x.w -= val_;

            y.x -= val_;
            y.y -= val_;
            y.z -= val_;
            y.w -= val_;

            z.x -= val_;
            z.y -= val_;
            z.z -= val_;
            z.w -= val_;

            w.x -= val_;
            w.y -= val_;
            w.z -= val_;
            w.w -= val_;

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
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator-=(const Mat<T, 4>& mat_) noexcept
        {
            x.x -= mat_.x.x;
            x.y -= mat_.x.y;
            x.z -= mat_.x.z;
            x.w -= mat_.x.w;

            y.x -= mat_.y.x;
            y.y -= mat_.y.y;
            y.z -= mat_.y.z;
            y.w -= mat_.y.w;

            z.x -= mat_.z.x;
            z.y -= mat_.z.y;
            z.z -= mat_.z.z;
            z.w -= mat_.z.w;

            w.x -= mat_.w.x;
            w.y -= mat_.w.y;
            w.z -= mat_.w.z;
            w.w -= mat_.w.w;

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
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator*=(const T val_) noexcept
        {
            x.x *= val_;
            x.y *= val_;
            x.z *= val_;
            x.w *= val_;

            y.x *= val_;
            y.y *= val_;
            y.z *= val_;
            y.w *= val_;

            z.x *= val_;
            z.y *= val_;
            z.z *= val_;
            z.w *= val_;

            w.x *= val_;
            w.y *= val_;
            w.z *= val_;
            w.w *= val_;

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
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator/=(const T val_) noexcept
        {
            x.x /= val_;
            x.y /= val_;
            x.z /= val_;
            x.w /= val_;

            y.x /= val_;
            y.y /= val_;
            y.z /= val_;
            y.w /= val_;

            z.x /= val_;
            z.y /= val_;
            z.z /= val_;
            z.w /= val_;

            w.x /= val_;
            w.y /= val_;
            w.z /= val_;
            w.w /= val_;

            return (*this);
        }


        //  -- Increment / Decrement --
        /**
         *  Increment each element of the mat.
         *
         *  @return A reference to this mat pre-increment.
         */
        template <typename T>
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator++() noexcept
        {
            ++x.x;
            ++x.y;
            ++x.z;
            ++x.w;

            ++y.x;
            ++y.y;
            ++y.z;
            ++y.w;

            ++z.x;
            ++z.y;
            ++z.z;
            ++z.w;

            ++w.x;
            ++w.y;
            ++w.z;
            ++w.w;

            return (*this);
        }

        /**
         *  Increment each element of the mat.
         *
         *  @return A copy of this mat post-increment.
         */
        template <typename T>
        constexpr inline const Mat<T, 4> Mat<T, 4>::operator++(const int) noexcept
        {
            const Mat mat = *this;

            ++x.x;
            ++x.y;
            ++x.z;
            ++x.w;

            ++y.x;
            ++y.y;
            ++y.z;
            ++y.w;

            ++z.x;
            ++z.y;
            ++z.z;
            ++z.w;

            ++w.x;
            ++w.y;
            ++w.z;
            ++w.w;

            return (mat);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A reference to this mat pre-decrement.
         */
        template <typename T>
        constexpr inline Mat<T, 4>& Mat<T, 4>::operator--() noexcept
        {
            --x.x;
            --x.y;
            --x.z;
            --x.w;

            --y.x;
            --y.y;
            --y.z;
            --y.w;

            --z.x;
            --z.y;
            --z.z;
            --z.w;

            --w.x;
            --w.y;
            --w.z;
            --w.w;

            return (*this);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A copy of this mat post-decrement.
         */
        template <typename T>
        constexpr inline const Mat<T, 4> Mat<T, 4>::operator--(const int) noexcept
        {
            const Mat mat = *this;

            --x.x;
            --x.y;
            --x.z;
            --x.w;

            --y.x;
            --y.y;
            --y.z;
            --y.w;

            --z.x;
            --z.y;
            --z.z;
            --z.w;

            --w.x;
            --w.y;
            --w.z;
            --w.w;

            return (mat);
        }


        //  -- Arithmetic --
        /**
         *  Positive copy the mat.
         *
         *  @return Positive copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator+() const noexcept
        {
            return (Mat(Vec<T, 4>(+x.x, +x.y, +x.z, +x.w), Vec<T, 4>(+y.x, +y.y, +y.z, +y.w), Vec<T, 4>(+z.x, +z.y, +z.z, +z.w), Vec<T, 4>(+w.x, +w.y, +w.z, +w.w)));
        }

        /**
         *  Negative copy the mat.
         *
         *  @return Negative copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator-() const noexcept
        {
            return (Mat(Vec<T, 4>(-x.x, -x.y, -x.z, -x.w), Vec<T, 4>(-y.x, -y.y, -y.z, -y.w), Vec<T, 4>(-z.x, -z.y, -z.z, -z.w), Vec<T, 4>(-w.x, -w.y, -w.z, -w.w)));
        }

        /**
         *  Add a value to a mat.
         *
         *  @param  val_    Value to add to the mat.
         *
         *  @return Mat formed by adding the value to the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator+(const T val_) const noexcept
        {
            return (
              Mat(Vec<T, 4>(x.x + val_, x.y + val_, x.z + val_, x.w + val_), Vec<T, 4>(y.x + val_, y.y + val_, y.z + val_, y.w + val_), Vec<T, 4>(z.x + val_, z.y + val_, z.z + val_, z.w + val_), Vec<T, 4>(w.x + val_, w.y + val_, w.z + val_, w.w + val_)));
        }

        /**
         *  Add a mat to a mat.
         *
         *  @param  mat_    Mat to add to the mat.
         *
         *  @return Mat formed by adding the mat to the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator+(const Mat<T, 4>& mat_) const noexcept
        {
            return (Mat(Vec<T, 4>(x.x + mat_.x.x, x.y + mat_.x.y, x.z + mat_.x.z, x.w + mat_.x.w), Vec<T, 4>(y.x + mat_.y.x, y.y + mat_.y.y, y.z + mat_.y.z, y.w + mat_.y.w), Vec<T, 4>(z.x + mat_.z.x, z.y + mat_.z.y, z.z + mat_.z.z, z.w + mat_.z.w),
                        Vec<T, 4>(w.x + mat_.w.x, w.y + mat_.w.y, w.z + mat_.w.z, w.w + mat_.w.w)));
        }

        /**
         *  Subtract a value from a mat.
         *
         *  @param  val_    Value to subtract from the mat.
         *
         *  @return Mat formed by subtracting the value from the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator-(const T val_) const noexcept
        {
            return (
              Mat(Vec<T, 4>(x.x - val_, x.y - val_, x.z - val_, x.w - val_), Vec<T, 4>(y.x - val_, y.y - val_, y.z - val_, y.w - val_), Vec<T, 4>(z.x - val_, z.y - val_, z.z - val_, z.w - val_), Vec<T, 4>(w.x - val_, w.y - val_, w.z - val_, w.w - val_)));
        }

        /**
         *  Subtract a mat from a mat.
         *
         *  @param  mat_    Mat to subtract from the mat.
         *
         *  @return Mat formed by subtracting the mat from the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator-(const Mat<T, 4>& mat_) const noexcept
        {
            return (Mat(Vec<T, 4>(x.x - mat_.x.x, x.y - mat_.x.y, x.z - mat_.x.z, x.w - mat_.x.w), Vec<T, 4>(y.x - mat_.y.x, y.y - mat_.y.y, y.z - mat_.y.z, y.w - mat_.y.w), Vec<T, 4>(z.x - mat_.z.x, z.y - mat_.z.y, z.z - mat_.z.z, z.w - mat_.z.w),
                        Vec<T, 4>(w.x - mat_.w.x, w.y - mat_.w.y, w.z - mat_.w.z, w.w - mat_.w.w)));
        }

        /**
         *  Multiply a mats elements by a value.
         *
         *  @param  val_    Value used to multiply the mat elements.
         *
         *  @return Mat formed by multiplying the mat elements by the value.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator*(const T val_) const noexcept
        {
            return (
              Mat(Vec<T, 4>(x.x * val_, x.y * val_, x.z * val_, x.w * val_), Vec<T, 4>(y.x * val_, y.y * val_, y.z * val_, y.w * val_), Vec<T, 4>(z.x * val_, z.y * val_, z.z * val_, z.w * val_), Vec<T, 4>(w.x * val_, w.y * val_, w.z * val_, w.w * val_)));
        }

        /**
         *  Multiply two mats together.
         *
         *  @param  mat_    Right hand side mat of the operation.
         *
         *  @return Mat formed by multiplying the two mats together.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator*(const Mat<T, 4>& mat_) const noexcept
        {
            return (
              Mat4(Vec<T, 4>(x * Vec<T, 4>(mat_.x.x, mat_.y.x, mat_.z.x, mat_.w.x), x * Vec<T, 4>(mat_.x.y, mat_.y.y, mat_.z.y, mat_.w.y), x * Vec<T, 4>(mat_.x.z, mat_.y.z, mat_.z.z, mat_.w.z), x * Vec<T, 4>(mat_.x.w, mat_.y.w, mat_.z.w, mat_.w.w)),
                   Vec<T, 4>(y * Vec<T, 4>(mat_.x.x, mat_.y.x, mat_.z.x, mat_.w.x), y * Vec<T, 4>(mat_.x.y, mat_.y.y, mat_.z.y, mat_.w.y), y * Vec<T, 4>(mat_.x.z, mat_.y.z, mat_.z.z, mat_.w.z), y * Vec<T, 4>(mat_.x.w, mat_.y.w, mat_.z.w, mat_.w.w)),
                   Vec<T, 4>(z * Vec<T, 4>(mat_.x.x, mat_.y.x, mat_.z.x, mat_.w.x), z * Vec<T, 4>(mat_.x.y, mat_.y.y, mat_.z.y, mat_.w.y), z * Vec<T, 4>(mat_.x.z, mat_.y.z, mat_.z.z, mat_.w.z), z * Vec<T, 4>(mat_.x.w, mat_.y.w, mat_.z.w, mat_.w.w)),
                   Vec<T, 4>(w * Vec<T, 4>(mat_.x.x, mat_.y.x, mat_.z.x, mat_.w.x), w * Vec<T, 4>(mat_.x.y, mat_.y.y, mat_.z.y, mat_.w.y), w * Vec<T, 4>(mat_.x.z, mat_.y.z, mat_.z.z, mat_.w.z), w * Vec<T, 4>(mat_.x.w, mat_.y.w, mat_.z.w, mat_.w.w))));
        }

        /**
         *  Divide a mats elements by a value.
         *
         *  @param  val_    Value used to divide the mat elements.
         *
         *  @return Mat formed by dividing the mat elements by the value.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::operator/(const T val_) const noexcept
        {
            return (
              Mat(Vec<T, 4>(x.x / val_, x.y / val_, x.z / val_, x.w / val_), Vec<T, 4>(y.x / val_, y.y / val_, y.z / val_, y.w / val_), Vec<T, 4>(z.x / val_, z.y / val_, z.z / val_, z.w / val_), Vec<T, 4>(w.x / val_, w.y / val_, w.z / val_, w.w / val_)));
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
        constexpr inline Vec<T, 4>& Mat<T, 4>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < 4);

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
        constexpr inline const Vec<T, 4>& Mat<T, 4>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < 4);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Mathematical --
        /**
         *  Calculate the sum of the mat elements.
         *
         *  @return Sum of the mat elements.
         */
        template <typename T>
        constexpr inline T Mat<T, 4>::sum() const noexcept
        {
            return (x.x + x.y + x.z + x.w + y.x + y.y + y.z + y.w + z.x + z.y + z.z + z.w + w.x + w.y + w.z + w.w);
        }

        /**
         *  Calculate the determinant of the matrix.
         *
         *  @return Determinant of the matrix.
         */
        template <typename T>
        constexpr inline T Mat<T, 4>::det() const noexcept
        {
            return ((x.x * y.y * z.z * w.w) - (x.x * y.y * z.w * w.z) - (x.x * y.z * z.y * w.w) + (x.x * y.z * z.w * w.y) + (x.x * y.w * z.y * w.z) - (x.x * y.w * z.z * w.y) - (x.y * y.x * z.z * w.w) + (x.y * y.x * z.w * w.z) + (x.y * y.z * z.x * w.w)
                    - (x.y * y.z * z.w * w.x) - (x.y * y.w * z.x * w.z) + (x.y * y.w * z.z * w.x) + (x.z * y.x * z.y * w.w) - (x.z * y.x * z.w * w.y) - (x.z * y.y * z.x * w.w) + (x.z * y.y * z.w * w.x) + (x.z * y.w * z.x * w.y) - (x.z * y.w * z.y * w.x)
                    - (x.w * y.x * z.y * w.z) + (x.w * y.x * z.z * w.y) + (x.w * y.y * z.x * w.z) - (x.w * y.y * z.z * w.x) - (x.w * y.z * z.x * w.y) + (x.w * y.z * z.y * w.x));
        }

        /**
         *  Calculate the matrix of minors of the matrix.
         *
         *  @return Matrix of minors of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::minor() const noexcept
        {
            return (Mat<T, 4>(
              Vec<T, 4>(
                (y.y * z.z * w.w) - (y.y * z.w * w.z) - (y.z * z.y * w.w) + (y.z * z.w * w.y) + (y.w * z.y * w.z) - (y.w * z.z * w.y), (y.x * z.z * w.w) - (y.x * z.w * w.z) - (y.z * z.x * w.w) + (y.z * z.w * w.x) + (y.w * z.x * w.z) - (y.w * z.z * w.x),
                (y.x * z.y * w.w) - (y.x * z.w * w.y) - (y.y * z.x * w.w) + (y.y * z.w * w.x) + (y.w * z.x * w.y) - (y.w * z.y * w.x), (y.x * z.y * w.z) - (y.x * z.z * w.y) - (y.y * z.x * w.z) + (y.y * z.z * w.x) + (y.z * z.x * w.y) - (y.z * z.y * w.x)),
              Vec<T, 4>(
                (x.y * z.z * w.w) - (x.y * z.w * w.z) - (x.z * z.y * w.w) + (x.z * z.w * w.y) + (x.w * z.y * w.z) - (x.w * z.z * w.y), (x.x * z.z * w.w) - (x.x * z.w * w.z) - (x.z * z.x * w.w) + (x.z * z.w * w.x) + (x.w * z.x * w.z) - (x.w * z.z * w.x),
                (x.x * z.y * w.w) - (x.x * z.w * w.y) - (x.y * z.x * w.w) + (x.y * z.w * w.x) + (x.w * z.x * w.y) - (x.w * z.y * w.x), (x.x * z.y * w.z) - (x.x * z.z * w.y) - (x.y * z.x * w.z) + (x.y * z.z * w.x) + (x.z * z.x * w.y) - (x.z * z.y * w.x)),
              Vec<T, 4>(
                (x.y * y.z * w.w) - (x.y * y.w * w.z) - (x.z * y.y * w.w) + (x.z * y.w * w.y) + (x.w * y.y * w.z) - (x.w * y.z * w.y), (x.x * y.z * w.w) - (x.x * y.w * w.z) - (x.z * y.x * w.w) + (x.z * y.w * w.x) + (x.w * y.x * w.z) - (x.w * y.z * w.x),
                (x.x * y.y * w.w) - (x.x * y.w * w.y) - (x.y * y.x * w.w) + (x.y * y.w * w.x) + (x.w * y.x * w.y) - (x.w * y.y * w.x), (x.x * y.y * w.z) - (x.x * y.z * w.y) - (x.y * y.x * w.z) + (x.y * y.z * w.x) + (x.z * y.x * w.y) - (x.z * y.y * w.x)),
              Vec<T, 4>(
                (x.y * y.z * z.w) - (x.y * y.w * z.z) - (x.z * y.y * z.w) + (x.z * y.w * z.y) + (x.w * y.y * z.z) - (x.w * y.z * z.y), (x.x * y.z * z.w) - (x.x * y.w * z.z) - (x.z * y.x * z.w) + (x.z * y.w * z.x) + (x.w * y.x * z.z) - (x.w * y.z * z.x),
                (x.x * y.y * z.w) - (x.x * y.w * z.y) - (x.y * y.x * z.w) + (x.y * y.w * z.x) + (x.w * y.x * z.y) - (x.w * y.y * z.x), (x.x * y.y * z.z) - (x.x * y.z * z.y) - (x.y * y.x * z.z) + (x.y * y.z * z.x) + (x.z * y.x * z.y) - (x.z * y.y * z.x))));
        }

        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::cofactor() const noexcept
        {
            Mat<T, 4> mat = minor();

            mat.x.y *= -1;
            mat.x.w *= -1;
            mat.y.x *= -1;
            mat.y.z *= -1;
            mat.z.y *= -1;
            mat.z.w *= -1;
            mat.w.x *= -1;
            mat.w.y *= -1;

            return (mat);
        }

        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::trans() const noexcept
        {
            return (Mat<T, 4>(Vec<T, 4>(x.x, y.x, z.x, w.x), Vec<T, 4>(x.y, y.y, z.y, w.y), Vec<T, 4>(x.z, y.z, z.z, w.z), Vec<T, 4>(x.w, y.w, z.w, w.w)));
        }

        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::adj() const noexcept
        {
            return (Mat<T, 4>(
              Vec<T, 4>(
                (y.y * z.z * w.w) - (y.y * z.w * w.z) - (y.z * z.y * w.w) + (y.z * z.w * w.y) + (y.w * z.y * w.z) - (y.w * z.z * w.y), (x.y * z.w * w.z) + (x.z * z.y * w.w) - (x.z * z.w * w.y) - (x.w * z.y * w.z) + (x.w * z.z * w.y) - (x.y * z.z * w.w),
                (x.y * y.z * w.w) - (x.y * y.w * w.z) - (x.z * y.y * w.w) + (x.z * y.w * w.y) + (x.w * y.y * w.z) - (x.w * y.z * w.y), (x.y * y.w * z.z) + (x.z * y.y * z.w) - (x.z * y.w * z.y) - (x.w * y.y * z.z) + (x.w * y.z * z.y) - (x.y * y.z * z.w)),
              Vec<T, 4>(
                (y.x * z.w * w.z) + (y.z * z.x * w.w) - (y.z * z.w * w.x) - (y.w * z.x * w.z) + (y.w * z.z * w.x) - (y.x * z.z * w.w), (x.x * z.z * w.w) - (x.x * z.w * w.z) - (x.z * z.x * w.w) + (x.z * z.w * w.x) + (x.w * z.x * w.z) - (x.w * z.z * w.x),
                (x.x * y.w * w.z) + (x.z * y.x * w.w) - (x.z * y.w * w.x) - (x.w * y.x * w.z) + (x.w * y.z * w.x) - (x.x * y.z * w.w), (x.x * y.z * z.w) - (x.x * y.w * z.z) - (x.z * y.x * z.w) + (x.z * y.w * z.x) + (x.w * y.x * z.z) - (x.w * y.z * z.x)),
              Vec<T, 4>(
                (y.x * z.y * w.w) - (y.x * z.w * w.y) - (y.y * z.x * w.w) + (y.y * z.w * w.x) + (y.w * z.x * w.y) - (y.w * z.y * w.x), (x.x * z.w * w.y) + (x.y * z.x * w.w) - (x.y * z.w * w.x) - (x.w * z.x * w.y) + (x.w * z.y * w.x) - (x.x * z.y * w.w),
                (x.x * y.y * w.w) - (x.x * y.w * w.y) - (x.y * y.x * w.w) + (x.y * y.w * w.x) + (x.w * y.x * w.y) - (x.w * y.y * w.x), (x.x * y.w * z.y) + (x.y * y.x * z.w) - (x.y * y.w * z.x) - (x.w * y.x * z.y) + (x.w * y.y * z.x) - (x.x * y.y * z.w)),
              Vec<T, 4>(
                (y.x * z.z * w.y) + (y.y * z.x * w.z) - (y.y * z.z * w.x) - (y.z * z.x * w.y) + (y.z * z.y * w.x) - (y.x * z.y * w.z), (x.x * z.y * w.z) - (x.x * z.z * w.y) - (x.y * z.x * w.z) + (x.y * z.z * w.x) + (x.z * z.x * w.y) - (x.z * z.y * w.x),
                (x.x * y.z * w.y) + (x.y * y.x * w.z) - (x.y * y.z * w.x) - (x.z * y.x * w.y) + (x.z * y.y * w.x) - (x.x * y.y * w.z), (x.x * y.y * z.z) - (x.x * y.z * z.y) - (x.y * y.x * z.z) + (x.y * y.z * z.x) + (x.z * y.x * z.y) - (x.z * y.y * z.x))));
        }

        template <typename T>
        constexpr inline Mat<T, 4> Mat<T, 4>::inv() const noexcept
        {
            return (adj() /= det());
        }


        //  -- Printing --
        /**
         *  Create a human readable string of the mat.
         *
         *  @return Human readable string of the mat.
         */
        template <typename T>
        inline std::string Mat<T, 4>::str() const noexcept
        {
            std::stringstream stream;

            stream << settings::format::VEC_START;
            stream << settings::format::VEC_START << std::setw(settings::format::PRINT_WIDTH) << x.x << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << x.y << settings::format::DELIMITER
                   << std::setw(settings::format::PRINT_WIDTH) << x.z << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << x.w << settings::format::VEC_END << '\n';
            stream << settings::format::DELIMITER << settings::format::VEC_START << std::setw(settings::format::PRINT_WIDTH) << y.x << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << y.y << settings::format::DELIMITER
                   << std::setw(settings::format::PRINT_WIDTH) << y.z << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << y.w << settings::format::VEC_END << '\n';
            stream << settings::format::DELIMITER << settings::format::VEC_START << std::setw(settings::format::PRINT_WIDTH) << z.x << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << z.y << settings::format::DELIMITER
                   << std::setw(settings::format::PRINT_WIDTH) << z.z << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << z.w << settings::format::VEC_END << '\n';
            stream << settings::format::DELIMITER << settings::format::VEC_START << std::setw(settings::format::PRINT_WIDTH) << w.x << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << w.y << settings::format::DELIMITER
                   << std::setw(settings::format::PRINT_WIDTH) << w.z << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << w.w << settings::format::VEC_END;
            stream << settings::format::VEC_END;

            return (stream.str());
        }



        //  == FUNCTIONS ==
        //  -- Utility --
        /**
         *  Create an 4 by 4 identity matrix.
         *
         *  @tparam T   Type stored by the mat.
         *
         *  @return 4 by 4 identity matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 4> indentity() noexcept
        {
            return (Mat<T, 4>(Vec<T, 4>(T{1}, T{0}, T{0}, T{0}), Vec<T, 4>(T{0}, T{1}, T{0}, T{0}), Vec<T, 4>(T{0}, T{0}, T{1}, T{0}), Vec<T, 4>(T{0}, T{0}, T{0}, T{1})));
        }


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
            PRE(axis_.normalised());

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
        constexpr inline Mat<T, 4> transform(const Vec<T, 3>& scale_, const Vec<T, 3>& rot_, const Vec<T, 3>& trans_) noexcept
        {
            return (translate(trans_) * rotate(rot_) * scale(scale_));
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_MAT4_HPP
