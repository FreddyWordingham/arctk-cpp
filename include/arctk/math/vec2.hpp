/**
 *  @file   arctk/math/vec2.hpp
 *  @date   10/07/2018
 *  @author Freddy Wordingham
 *
 *  Two-dimensional mathematical vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC2_HPP
#define ARCTK_MATH_VEC2_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <limits>
#include <ostream>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS PROTOTYPES ==
        template <typename T>
        class Mat<T, 2>;



        //  == CLASS ==
        /**
         *  Two-dimensional mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 2>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            /**
             *  First vec element.
             */
            union
            {
                T x,   //!< Cartesian x-dimension.
                  rho; //!< Polar radial-dimension.
            };

            /**
             *  Second vec element.
             */
            union
            {
                T y,     //!< Cartesian y-dimension.
                  theta; //!< Polar inclination-dimension.
            };


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept;
            constexpr inline Vec(T x_, T y_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 2>& vec_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Vec<T, 2>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, 2>& operator+=(const Vec<T, 2>& vec_) noexcept;
            constexpr inline Vec<T, 2>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, 2>& operator-=(const Vec<T, 2>& vec_) noexcept;
            constexpr inline Vec<T, 2>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, 2>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, 2>&      operator++() noexcept;
            constexpr inline const Vec<T, 2> operator++(int) noexcept;
            constexpr inline Vec<T, 2>&      operator--() noexcept;
            constexpr inline const Vec<T, 2> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, 2> operator+() const noexcept;
            constexpr inline Vec<T, 2> operator-() const noexcept;
            constexpr inline Vec<T, 2> operator+(T val_) const noexcept;
            constexpr inline Vec<T, 2> operator+(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Vec<T, 2> operator-(T val_) const noexcept;
            constexpr inline Vec<T, 2> operator-(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Vec<T, 2> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, 2>& vec_) const noexcept;
            constexpr inline Vec<T, 2> operator*(const Mat<T, 2>& mat_) const noexcept;
            constexpr inline Vec<T, 2> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::numeric_limits<T>::epsilon()) const noexcept;

            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         mag() const noexcept;
            constexpr inline T         mag_sq() const noexcept;
            constexpr inline Vec<T, 2> normal() const noexcept;
            constexpr inline void      normalise() noexcept;
        };



    } // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/vec2.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_VEC2_HPP
