/**
 *  @file   arctk/math/mat4.hpp
 *  @date   28/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical four by four matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT4_HPP
#define ARCTK_MATH_MAT4_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/math/mat.hpp>



//  == IMPORTS ==
//  -- Std --
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/math/vec4.hpp>
#include <arctk/settings.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Four by four mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 4>
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
            //  -- Printing --
            constexpr inline std::string str(char delim_ = settings::DEFAULT_DELIM, size_t width_ = settings::DEFAULT_PRINT_WIDTH) const noexcept;

            //  -- Mathematical --
            constexpr inline T sum() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a four by four mat with initial element values.
         *
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mats.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mats.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mats.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mats.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the vec.
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
            assert(index_ < 4);

            return ((&x)[index_]);
        }

        /**
         *  Access an element of the vec.
         *
         *  @tparam T   Type stored by the vec.
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
            assert(index_ < 4);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Printing --
        /**
         *  Form the matrix into a human readable string.
         *
         *  @tparam T   Type stored by the mat.
         *
         *  @param  delim_  Delimiter character used to seperate consecutive values.
         *  @param  width_  Print width allocated to each value.
         *
         *  @return Human readable string of the matrix.
         */
        template <typename T>
        constexpr inline std::string Mat<T, 4>::str(const char delim_, const size_t width_) const noexcept
        {
            std::stringstream stream;

            stream << std::setw(width_) << x.x << delim_ << std::setw(width_) << x.y << delim_ << std::setw(width_) << x.z << delim_ << std::setw(width_) << x.w << "\n";
            stream << std::setw(width_) << y.x << delim_ << std::setw(width_) << y.y << delim_ << std::setw(width_) << y.z << delim_ << std::setw(width_) << y.w << "\n";
            stream << std::setw(width_) << z.x << delim_ << std::setw(width_) << z.y << delim_ << std::setw(width_) << z.z << delim_ << std::setw(width_) << z.w << "\n";
            stream << std::setw(width_) << w.x << delim_ << std::setw(width_) << w.y << delim_ << std::setw(width_) << w.z << delim_ << std::setw(width_) << w.w << "\n";

            return (stream.str());
        }


        //  -- Mathematical --
        /**
         *  Calculate the sum of the mat elements.
         *
         *  @tparam T   Type stored by the mat.
         *
         *  @return Sum of the mat elements.
         */
        template <typename T>
        constexpr inline T Mat<T, 4>::sum() const noexcept
        {
            return (x.x + x.y + x.z + x.w + y.x + y.y + y.z + y.w + z.x + z.y + z.z + z.w + w.x + w.y + w.z + w.w);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_MAT4_HPP
