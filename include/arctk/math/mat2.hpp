/**
 *  @file   arctk/math/mat2.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical two-by-two matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT2_HPP
#define ARCTK_MATH_MAT2_HPP



//  == IMPORTS ==
//  -- Std --
#include <iomanip>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math/mat.hpp>
#include <arctk/math/vec2.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Two-by-two mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 2>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 2> x{}; //!< X-row of matrix.
            Vec<T, 2> y{}; //!< Y-row of matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            constexpr inline Mat(const Vec<T, 2>& x_, const Vec<T, 2>& y_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Writing --
            constexpr inline std::ostream& operator<<(std::ostream& stream_) const noexcept;

            //  -- Assignment --
            constexpr inline Mat<T, 2>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator+=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator-=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator*=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, 2>&      operator++() noexcept;
            constexpr inline const Mat<T, 2> operator++(int) noexcept;
            constexpr inline Mat<T, 2>&      operator--() noexcept;
            constexpr inline const Mat<T, 2> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Mat<T, 2> operator+() const noexcept;
            constexpr inline Mat<T, 2> operator-() const noexcept;
            constexpr inline Mat<T, 2> operator+(T val_) const noexcept;
            constexpr inline Mat<T, 2> operator+(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Mat<T, 2> operator-(T val_) const noexcept;
            constexpr inline Mat<T, 2> operator-(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Mat<T, 2> operator*(T val_) const noexcept;
            constexpr inline Vec<T, 2> operator*(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Mat<T, 2> operator*(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Mat<T, 2> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, 2>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, 2>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         det() const noexcept;
            constexpr inline Mat<T, 2> minors() const noexcept;
            constexpr inline Mat<T, 2> cofactor() const noexcept;
            constexpr inline Mat<T, 2> trans() const noexcept;
            constexpr inline Mat<T, 2> adj() const noexcept;
            constexpr inline Mat<T, 2> inv() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a two by two mat with initial element values.
         *
         *  @param  x_  Initial values of the x row.
         *  @param  y_  Initial values of the y row.
         */
        template <typename T>
        constexpr inline Mat<T, 2>::Mat(const Vec<T, 2>& x_, const Vec<T, 2>& y_) noexcept
          : x(x_)
          , y(y_)
        {
        }



        //  == OPERATORS ==
        //  -- Writing --
        template <typename T>
        constexpr inline std::ostream& Mat<T, 2>::operator<<(std::ostream& stream_) const noexcept
        {
            stream_ << "{{" << x.x << ", " << x.y << "}\n{" << y.x << ", " << y.y << "}}";

            return (stream_);
        }


        //  -- Assignment --
        /**
         *  Add a value to all elements of the mat.
         *
         *  @param  val_    Value to add to each mat element.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T>
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator+=(const T val_) noexcept
        {
            x.x += val_;
            x.y += val_;

            y.x += val_;
            y.y += val_;

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
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator+=(const Mat<T, 2>& mat_) noexcept
        {
            x.x += mat_.x.x;
            x.y += mat_.x.y;

            y.x += mat_.y.x;
            y.y += mat_.y.y;

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
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator-=(const T val_) noexcept
        {
            x.x -= val_;
            x.y -= val_;

            y.x -= val_;
            y.y -= val_;

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
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator-=(const Mat<T, 2>& mat_) noexcept
        {
            x.x -= mat_.x.x;
            x.y -= mat_.x.y;

            y.x -= mat_.y.x;
            y.y -= mat_.y.y;

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
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator*=(const T val_) noexcept
        {
            x.x *= val_;
            x.y *= val_;

            y.x *= val_;
            y.y *= val_;

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
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator*=(const Mat<T, 2>& mat_) noexcept
        {
            const Mat<T, 2> pre = *this;

            x.x = (pre.x.x * mat_.x.x) + (pre.x.y * mat_.y.x);
            x.y = (pre.x.x * mat_.x.y) + (pre.x.y * mat_.y.y);

            y.x = (pre.y.x * mat_.x.x) + (pre.y.y * mat_.y.x);
            y.y = (pre.y.x * mat_.x.y) + (pre.y.y * mat_.y.y);

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
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator/=(const T val_) noexcept
        {
            x.x /= val_;
            x.y /= val_;

            y.x /= val_;
            y.y /= val_;

            return (*this);
        }


        //  -- Increment / Decrement --
        /**
         *  Increment each element of the mat.
         *
         *  @return A reference to this mat pre-increment.
         */
        template <typename T>
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator++() noexcept
        {
            ++x.x;
            ++x.y;

            ++y.x;
            ++y.y;

            return (*this);
        }

        /**
         *  Increment each element of the mat.
         *
         *  @return A copy of this mat post-increment.
         */
        template <typename T>
        constexpr inline const Mat<T, 2> Mat<T, 2>::operator++(const int) noexcept
        {
            const Mat mat = *this;

            ++x.x;
            ++x.y;

            ++y.x;
            ++y.y;

            return (mat);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A reference to this mat pre-decrement.
         */
        template <typename T>
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator--() noexcept
        {
            --x.x;
            --x.y;

            --y.x;
            --y.y;

            return (*this);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A copy of this mat post-decrement.
         */
        template <typename T>
        constexpr inline const Mat<T, 2> Mat<T, 2>::operator--(const int) noexcept
        {
            const Mat mat = *this;

            --x.x;
            --x.y;

            --y.x;
            --y.y;

            return (mat);
        }


        //  -- Arithmetic --
        /**
         *  Positive copy the mat.
         *
         *  @return Positive copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator+() const noexcept
        {
            return (Mat(Vec<T, 2>(+x.x, +x.y), Vec<T, 2>(+y.x, +y.y)));
        }

        /**
         *  Negative copy the mat.
         *
         *  @return Negative copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator-() const noexcept
        {
            return (Mat(Vec<T, 2>(-x.x, -x.y), Vec<T, 2>(-y.x, -y.y)));
        }

        /**
         *  Add a value to a mat.
         *
         *  @param  val_    Value to add to the mat.
         *
         *  @return Mat formed by adding the value to the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator+(const T val_) const noexcept
        {
            return (Mat(Vec<T, 2>(x.x + val_, x.y + val_), Vec<T, 2>(y.x + val_, y.y + val_)));
        }

        /**
         *  Add a mat to a mat.
         *
         *  @param  mat_    Mat to add to the mat.
         *
         *  @return Mat formed by adding the mat to the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator+(const Mat<T, 2>& mat_) const noexcept
        {
            return (Mat(Vec<T, 2>(x.x + mat_.x.x, x.y + mat_.x.y), Vec<T, 2>(y.x + mat_.y.x, y.y + mat_.y.y)));
        }

        /**
         *  Subtract a value from a mat.
         *
         *  @param  val_    Value to subtract from the mat.
         *
         *  @return Mat formed by subtracting the value from the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator-(const T val_) const noexcept
        {
            return (Mat(Vec<T, 2>(x.x - val_, x.y - val_), Vec<T, 2>(y.x - val_, y.y - val_)));
        }

        /**
         *  Subtract a mat from a mat.
         *
         *  @param  mat_    Mat to subtract from the mat.
         *
         *  @return Mat formed by subtracting the mat from the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator-(const Mat<T, 2>& mat_) const noexcept
        {
            return (Mat(Vec<T, 2>(x.x - mat_.x.x, x.y - mat_.x.y), Vec<T, 2>(y.x - mat_.y.x, y.y - mat_.y.y)));
        }

        /**
         *  Multiply a mats elements by a value.
         *
         *  @param  val_    Value used to multiply the mat elements.
         *
         *  @return Mat formed by multiplying the mat elements by the value.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator*(const T val_) const noexcept
        {
            return (Mat(Vec<T, 2>(x.x * val_, x.y * val_), Vec<T, 2>(y.x * val_, y.y * val_)));
        }

        /**
         *  Multiply the mat by a vec.
         *
         *  @param  vec_    Vec to multiply this mat by.
         *
         *  @return Vec formed by multiplying the mat by the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 2> Mat<T, 2>::operator*(const Vec<T, 2>& vec_) const noexcept
        {
            return (Vec<T, 2>((x.x * vec_.x) + (x.y * vec_.y), (y.x * vec_.x) + (y.y * vec_.y)));
        }

        /**
         *  Multiply two mats together.
         *
         *  @param  mat_    Right hand side mat of the operation.
         *
         *  @return Mat formed by multiplying the two mats together.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator*(const Mat<T, 2>& mat_) const noexcept
        {
            return (Mat(Vec<T, 2>(x * Vec<T, 2>(mat_.x.x, mat_.y.x), x * Vec<T, 2>(mat_.x.y, mat_.y.y)), Vec<T, 2>(y * Vec<T, 2>(mat_.x.x, mat_.y.x), y * Vec<T, 2>(mat_.x.y, mat_.y.y))));
        }

        /**
         *  Divide a mats elements by a value.
         *
         *  @param  val_    Value used to divide the mat elements.
         *
         *  @return Mat formed by dividing the mat elements by the value.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator/(const T val_) const noexcept
        {
            return (Mat(Vec<T, 2>(x.x / val_, x.y / val_), Vec<T, 2>(y.x / val_, y.y / val_)));
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
        constexpr inline Vec<T, 2>& Mat<T, 2>::operator[](const size_t index_) noexcept
        {
            PRE(index_ < 2);

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
        constexpr inline const Vec<T, 2>& Mat<T, 2>::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < 2);

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
        constexpr inline T Mat<T, 2>::sum() const noexcept
        {
            return (x.x + x.y + y.x + y.y);
        }

        /**
         *  Calculate the determinant of the matrix.
         *
         *  @return Determinant of the matrix.
         */
        template <typename T>
        constexpr inline T Mat<T, 2>::det() const noexcept
        {
            return ((x.x * y.y) - (x.y * y.x));
        }

        /**
         *  Calculate the matrix of minors of the matrix.
         *
         *  @return Matrix of minors of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::minors() const noexcept
        {
            return (Mat<T, 2>(Vec<T, 2>(y.y, y.x), Vec<T, 2>(x.y, x.x)));
        }

        /**
         *  Calculate the matrix of cofactors of the matrix.
         *
         *  @return Matrix of cofactors of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::cofactor() const noexcept
        {
            Mat<T, 2> mat = minors();

            mat.x.y *= -1;
            mat.y.x *= -1;

            return (mat);
        }

        /**
         *  Calculate the transpose matrix of the matrix.
         *
         *  @return Transpose matrix of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::trans() const noexcept
        {
            return (Mat<T, 2>(Vec<T, 2>(x.x, y.x), Vec<T, 2>(x.y, y.y)));
        }

        /**
         *  Calculate the adjoint matrix of the matrix.
         *
         *  @return Adjoint matrix of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::adj() const noexcept
        {
            return (Mat<T, 2>(Vec<T, 2>(y.y, -x.y), Vec<T, 2>(-y.x, x.x)));
        }

        /**
         *  Calculate the inverse matrix of the matrix.
         *
         *  @return Inverse matrix of the matrix.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::inv() const noexcept
        {
            return (adj() /= det());
        }



        namespace mat //! matrix namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Utility --
            template <typename T>
            constexpr inline Mat<T, 2> indentity() noexcept;



            //  == FUNCTIONS ==
            //  -- Utility --
            /**
             *  Create an 2 by 2 identity matrix.
             *
             *  @tparam T   Type stored by the mat.
             *
             *  @return 2 by 2 identity matrix.
             */
            template <typename T>
            constexpr inline Mat<T, 2> indentity() noexcept
            {
                return (Mat<T, 2>(Vec<T, 2>(T{1}, T{0}), Vec<T, 2>(T{0}, T{1})));
            }



        } // namespace mat
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_MAT2_HPP
