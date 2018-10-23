/**
 *  @file   arctk/math/vec3.hpp
 *  @date   10/07/2018
 *  @author Freddy Wordingham
 *
 *  Three-dimensional mathematical vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC3_HPP
#define ARCTK_MATH_VEC3_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <limits>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS PROTOTYPES ==
        template <typename T>
        class Mat<T, 3>;



        //  == CLASS ==
        /**
         *  Three-dimensional mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 3>
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
                  rho, //!< Polar radial-dimension.
                  r;   //!< Colour red-dimension.
            };

            /**
             *  Second vec element.
             */
            union
            {
                T y,     //!< Cartesian y-dimension.
                  theta, //!< Polar inclination-dimension.
                  g;     //!< Colour green-dimension.
            };

            /**
             *  Third vec element.
             */
            union
            {
                T z,   //!< Cartesian z-dimension.
                  phi, //!< Polar azimuthal-dimension.
                  b;   //!< Colour blue-dimension.
            };


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept;
            constexpr inline Vec(T x_, T y_, T z_) noexcept;
            constexpr inline Vec(const Vec<T, 2>& vec_, T z_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Printing --
            template <typename S>
            friend constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 3>& vec_) noexcept; // NOLINT

            //  -- Assignment --
            constexpr inline Vec<T, 3>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator+=(const Vec<T, 3>& vec_) noexcept;
            constexpr inline Vec<T, 3>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator-=(const Vec<T, 3>& vec_) noexcept;
            constexpr inline Vec<T, 3>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator/=(T val_) noexcept;
            constexpr inline Vec<T, 3>& operator^=(const Vec<T, 3>& vec_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, 3>&      operator++() noexcept;
            constexpr inline const Vec<T, 3> operator++(int) noexcept;
            constexpr inline Vec<T, 3>&      operator--() noexcept;
            constexpr inline const Vec<T, 3> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, 3> operator+() const noexcept;
            constexpr inline Vec<T, 3> operator-() const noexcept;
            constexpr inline Vec<T, 3> operator+(T val_) const noexcept;
            constexpr inline Vec<T, 3> operator+(const Vec<T, 3>& vec_) const noexcept;
            constexpr inline Vec<T, 3> operator-(T val_) const noexcept;
            constexpr inline Vec<T, 3> operator-(const Vec<T, 3>& vec_) const noexcept;
            constexpr inline Vec<T, 3> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, 3>& vec_) const noexcept;
            constexpr inline Vec<T, 3> operator*(const Mat<T, 3>& mat_) const noexcept;
            constexpr inline Vec<T, 3> operator/(T val_) const noexcept;
            constexpr inline Vec<T, 3> operator^(const Vec<T, 3>& vec_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::sqrt(std::numeric_limits<T>::epsilon())) const noexcept;

            //  -- Mathematical --
            constexpr inline T         sum() const noexcept;
            constexpr inline T         mag() const noexcept;
            constexpr inline T         mag_sq() const noexcept;
            constexpr inline Vec<T, 3> normal() const noexcept;
            constexpr inline void      normalise() noexcept;
            constexpr inline void      rotate(const math::Vec<T, 3>& axis_, T ang_) noexcept;
        };



    } // namespace math



    //  == ALIASES ==
    //  -- Float --
    using vec3f = math::Vec<float, 3>; //!< Three-dimensional float precision vec.

    //  -- Double --
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.



} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/vec3.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_VEC3_HPP
