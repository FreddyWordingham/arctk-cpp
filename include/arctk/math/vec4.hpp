/**
 *  @file   arctk/math/vec4.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  Four-dimensional mathematical vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC4_HPP
#define ARCTK_MATH_VEC4_HPP



//  == BASE ==
#include <arctk/math/vec.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <limits>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS PROTOTYPES ==
        template <typename T, size_t N>
        class Mat;



    } // namespace math
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Four-dimensional mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 4>
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            /**
             *  First vec element.
             */
            union
            {
                T x, //!< Cartesian x-dimension.
                  r; //!< Colour red-dimension.
            };

            /**
             *  Second vec element.
             */
            union
            {
                T y, //!< Cartesian y-dimension.
                  g; //!< Colour green-dimension.
            };

            /**
             *  Third vec element.
             */
            union
            {
                T z, //!< Cartesian z-dimension.
                  b; //!< Colour blue-dimension.
            };

            /**
             *  Fourth vec element.
             */
            union
            {
                T w, //!< Cartesian w-dimension.
                  a; //!< Colour alpha-dimension.
            };


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept;
            constexpr inline Vec(T x_, T y_, T z_, T w_) noexcept;
            constexpr inline Vec(const Vec<T, 2>& vec_, T z_, T w_) noexcept;
            constexpr inline Vec(const Vec<T, 3>& vec_, T w_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 4>& vec_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Vec<T, 4>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, 4>& operator+=(const Vec<T, 4>& vec_) noexcept;
            constexpr inline Vec<T, 4>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, 4>& operator-=(const Vec<T, 4>& vec_) noexcept;
            constexpr inline Vec<T, 4>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, 4>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, 4>&      operator++() noexcept;
            constexpr inline const Vec<T, 4> operator++(int) noexcept;
            constexpr inline Vec<T, 4>&      operator--() noexcept;
            constexpr inline const Vec<T, 4> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, 4> operator+() const noexcept;
            constexpr inline Vec<T, 4> operator-() const noexcept;
            constexpr inline Vec<T, 4> operator+(T val_) const noexcept;
            constexpr inline Vec<T, 4> operator+(const Vec<T, 4>& vec_) const noexcept;
            constexpr inline Vec<T, 4> operator-(T val_) const noexcept;
            constexpr inline Vec<T, 4> operator-(const Vec<T, 4>& vec_) const noexcept;
            constexpr inline Vec<T, 4> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, 4>& vec_) const noexcept;
            constexpr inline Vec<T, 4> operator*(const Mat<T, 4>& mat_) const noexcept;
            constexpr inline Vec<T, 4> operator/(T val_) const noexcept;

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
            constexpr inline Vec<T, 4> normal() const noexcept;
            constexpr inline void      normalise() noexcept;
        };



    } // namespace math



    //  == ALIASES ==
    //  -- Float --
    using vec4f = math::Vec<float, 4>; //!< Four-dimensional float precision vec.

    //  -- Double --
    using vec4 = math::Vec<double, 4>; //!< Four-dimensional double precision vec.



} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/vec4.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_VEC4_HPP
