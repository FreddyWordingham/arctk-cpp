/**
 *  @file   arctk/math/mat3.hpp
 *  @date   27/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical three by three matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT3_HPP
#define ARCTK_MATH_MAT3_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/math/mat.hpp>



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Thee by three mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         */
        template <typename T>
        class Mat<T, 3>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            Vec<T, 3> x{};
            Vec<T, 3> y{};
            Vec<T, 3> z{};


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            constexpr inline Mat(const Vec<T, 3>& x_, const Vec<T, 3>& y_, const Vec<T, 3>& z_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            constexpr inline Mat<T, 3>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, 3>& operator+=(const Mat<T, 3>& mat_) noexcept;
            constexpr inline Mat<T, 3>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, 3>& operator-=(const Mat<T, 3>& mat_) noexcept;
            constexpr inline Mat<T, 3>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, 3>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, 3>&      operator++() noexcept;
            constexpr inline const Mat<T, 3> operator++(int) noexcept;
            constexpr inline Mat<T, 3>&      operator--() noexcept;
            constexpr inline const Mat<T, 3> operator--(int) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @param  val_    Value to add to each mat element.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator+=(const T val_) noexcept
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
         *  @tparam T   Type stored by the mats.
         *  @tparam N   Size of the mat.
         *
         *  @param  mat_    mat to add to this mat.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator+=(const Mat<T, N>& mat_) noexcept
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @param  val_    Value to subtract from each mat element.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator-=(const T val_) noexcept
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
         *  @tparam T   Type stored by the mats.
         *  @tparam N   Size of the mat.
         *
         *  @param  mat_    mat to subtract from this mat.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator-=(const Mat<T, N>& mat_) noexcept
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @param  val_    Value used to multiply each mat element by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator*=(const T val_) noexcept
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
         *  Divide all elements of the mat by a value.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @param  val_    Value used to divide each mat element by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator/=(const T val_) noexcept
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @return A reference to this mat pre-increment.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator++() noexcept
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @return A copy of this mat post-increment.
         */
        template <typename T, size_t N>
        constexpr inline const Mat<T, N> Mat<T, N>::operator++(const int) noexcept
        {
            const Mat mat = *this;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    ++_data[i][j];
                }
            }

            return (mat);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @return A reference to this mat pre-decrement.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator--() noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    --_data[i][j];
                }
            }

            return (*this);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         *
         *  @return A copy of this mat post-decrement.
         */
        template <typename T, size_t N>
        constexpr inline const Mat<T, N> Mat<T, N>::operator--(const int) noexcept
        {
            const Mat mat = *this;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    --_data[i][j];
                }
            }

            return (mat);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_MAT3_HPP
