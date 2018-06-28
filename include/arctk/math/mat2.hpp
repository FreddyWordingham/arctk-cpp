/**
 *  @file   arctk/math/mat2.hpp
 *  @date   28/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical two by two matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT2_HPP
#define ARCTK_MATH_MAT2_HPP



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
#include <arctk/math/vec2.hpp>
#include <arctk/settings.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Two by two mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 2>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 2> x{};
            Vec<T, 2> y{};


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            constexpr inline Mat(const Vec<T, 2>& x_, const Vec<T, 2>& y_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            constexpr inline Mat<T, 2>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator+=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, 2>& operator-=(const Mat<T, 2>& mat_) noexcept;
            constexpr inline Mat<T, 2>& operator*=(T val_) noexcept;
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
            constexpr inline Mat<T, 2> operator*(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Mat<T, 2> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, 2>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, 2>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Printing --
            constexpr inline std::string str(char delim_ = settings::DEFAULT_DELIM, size_t width_ = settings::DEFAULT_PRINT_WIDTH) const noexcept;

            //  -- Mathematical --
            constexpr inline T sum() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        template <typename T>
        constexpr inline Mat<T, 2>::Mat(const Vec<T, 2>& x_, const Vec<T, 2>& y_) noexcept
          : x(x_)
          , y(y_)
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
         *  @tparam T   Type stored by the mats.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mats.
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
         *  @tparam T   Type stored by the mat.
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
         *  Divide all elements of the mat by a value.
         *
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
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
         *  @tparam T   Type stored by the mat.
         *
         *  @return A reference to this mat pre-decrement.
         */
        template <typename T>
        constexpr inline Mat<T, 2>& Mat<T, 2>::operator--() noexcept
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
         *  @tparam T   Type stored by the mat.
         *
         *  @return A copy of this mat post-decrement.
         */
        template <typename T>
        constexpr inline const Mat<T, 2> Mat<T, 2>::operator--(const int) noexcept
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
         *  @tparam T   Type stored by the mat.
         *
         *  @return Positive copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator+() const noexcept
        {
            Mat mat;

            mat.x.x = +x.x;
            mat.x.y = +x.y;
            mat.x.z = +x.z;

            mat.y.x = +y.x;
            mat.y.y = +y.y;
            mat.y.z = +y.z;

            mat.z.x = +z.x;
            mat.z.y = +z.y;
            mat.z.z = +z.z;

            return (mat);
        }

        /**
         *  Negative copy the mat.
         *
         *  @tparam T   Type stored by the mat.
         *
         *  @return Negative copy of the mat.
         */
        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator-() const noexcept
        {
            Mat mat;

            mat.x.x = -x.x;
            mat.x.y = -x.y;
            mat.x.z = -x.z;

            mat.y.x = -y.x;
            mat.y.y = -y.y;
            mat.y.z = -y.z;

            mat.z.x = -z.x;
            mat.z.y = -z.y;
            mat.z.z = -z.z;

            return (mat);
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
        constexpr inline Mat<T, 2> Mat<T, 2>::operator+(const T val_) const noexcept
        {
            Mat mat;

            mat.x.x = x.x + val_;
            mat.x.y = x.y + val_;
            mat.x.z = x.z + val_;

            mat.y.x = y.x + val_;
            mat.y.y = y.y + val_;
            mat.y.z = y.z + val_;

            mat.z.x = z.x + val_;
            mat.z.y = z.y + val_;
            mat.z.z = z.z + val_;

            return (mat);
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
        constexpr inline Mat<T, 2> Mat<T, 2>::operator+(const Mat<T, 2>& mat_) const noexcept
        {
            Mat mat;

            mat.x.x = x.x + mat_.x.x;
            mat.x.y = x.y + mat_.x.y;
            mat.x.z = x.z + mat_.x.z;

            mat.y.x = y.x + mat_.y.x;
            mat.y.y = y.y + mat_.y.y;
            mat.y.z = y.z + mat_.y.z;

            mat.z.x = z.x + mat_.z.x;
            mat.z.y = z.y + mat_.z.y;
            mat.z.z = z.z + mat_.z.z;

            return (mat);
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
        constexpr inline Mat<T, 2> Mat<T, 2>::operator-(const T val_) const noexcept
        {
            Mat mat;

            mat.x.x = x.x - val_;
            mat.x.y = x.y - val_;
            mat.x.z = x.z - val_;

            mat.y.x = y.x - val_;
            mat.y.y = y.y - val_;
            mat.y.z = y.z - val_;

            mat.z.x = z.x - val_;
            mat.z.y = z.y - val_;
            mat.z.z = z.z - val_;

            return (mat);
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
        constexpr inline Mat<T, 2> Mat<T, 2>::operator-(const Mat<T, 2>& mat_) const noexcept
        {
            Mat mat;

            mat.x.x = x.x - mat_.x.x;
            mat.x.y = x.y - mat_.x.y;
            mat.x.z = x.z - mat_.x.z;

            mat.y.x = y.x - mat_.y.x;
            mat.y.y = y.y - mat_.y.y;
            mat.y.z = y.z - mat_.y.z;

            mat.z.x = z.x - mat_.z.x;
            mat.z.y = z.y - mat_.z.y;
            mat.z.z = z.z - mat_.z.z;

            return (mat);
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
        constexpr inline Mat<T, 2> Mat<T, 2>::operator*(const T val_) const noexcept
        {
            Mat mat;

            mat.x.x = x.x * val_;
            mat.x.y = x.y * val_;
            mat.x.z = x.z * val_;

            mat.y.x = y.x * val_;
            mat.y.y = y.y * val_;
            mat.y.z = y.z * val_;

            mat.z.x = z.x * val_;
            mat.z.y = z.y * val_;
            mat.z.z = z.z * val_;

            return (mat);
        }

        template <typename T>
        constexpr inline Mat<T, 2> Mat<T, 2>::operator*(const Mat<T, 2>& mat_) const noexcept
        {
            return (Mat<T, 2>(Vec<T, 2>(x * Vec<T, 2>(mat_.x.x, mat_.y.x, mat_.z.x), x * Vec<T, 2>(mat_.x.y, mat_.y.y, mat_.z.y), x * Vec<T, 2>(mat_.x.z, mat_.y.z, mat_.z.z)),
                              Vec<T, 2>(y * Vec<T, 2>(mat_.x.x, mat_.y.x, mat_.z.x), y * Vec<T, 2>(mat_.x.y, mat_.y.y, mat_.z.y), y * Vec<T, 2>(mat_.x.z, mat_.y.z, mat_.z.z)),
                              Vec<T, 2>(z * Vec<T, 2>(mat_.x.x, mat_.y.x, mat_.z.x), z * Vec<T, 2>(mat_.x.y, mat_.y.y, mat_.z.y), z * Vec<T, 2>(mat_.x.z, mat_.y.z, mat_.z.z))));
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
        constexpr inline Mat<T, 2> Mat<T, 2>::operator/(const T val_) const noexcept
        {
            return (Mat<T, 2>(Vec<T, 2>(x.x / val_, x.y / val_, x.z / val_), Vec<T, 2>(y.x / val_, y.y / val_, y.z / val_), Vec<T, 2>(z.x / val_, z.y / val_, z.z / val_)));
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
        constexpr inline Vec<T, 2>& Mat<T, 2>::operator[](const size_t index_) noexcept
        {
            assert(index_ < 3);

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
        constexpr inline const Vec<T, 2>& Mat<T, 2>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 3);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Printing --
        template <typename T>
        constexpr inline std::string Mat<T, 2>::str(const char delim_, const size_t width_) const noexcept
        {
            std::stringstream stream;

            stream << std::setw(width_) << x.x << delim_ << std::setw(width_) << x.y << delim_ << std::setw(width_) << x.z << "\n";
            stream << std::setw(width_) << y.x << delim_ << std::setw(width_) << y.y << delim_ << std::setw(width_) << y.z << "\n";
            stream << std::setw(width_) << z.x << delim_ << std::setw(width_) << z.y << delim_ << std::setw(width_) << z.z << "\n";

            return (stream.str());
        }


        //  -- Mathematical --
        template <typename T>
        constexpr inline T Mat<T, 2>::sum() const noexcept
        {
            return (x.x + x.y + x.z + y.x + y.y + y.z + z.x + z.y + z.z);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_MAT2_HPP
