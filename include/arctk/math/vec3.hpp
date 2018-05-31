/**
 *  @file   arctk/math/vec3.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical size three vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC3_HPP
#define ARCTK_MATH_VEC3_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Size three mathematical vector class.
         *
         *  @tparam T   Type stored by the vector.
         */
        template <typename T>
        class Vec3
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            /**
             *  First vector element.
             */
            union
            {
                T x,   //!< Cartesian x-dimension.
                  rho, //!< Polar radial-dimension.
                  r;   //!< Colour red-dimension.
            };

            /**
             *  Second vector element.
             */
            union
            {
                T y,     //!< Cartesian y-dimension.
                  theta, //!< Polar inclination-dimension.
                  g;     //!< Colour green-dimension.
            };

            /**
             *  Third vector element.
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
            constexpr inline Vec3() noexcept;
            constexpr inline Vec3(T x_, T y_, T z_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename L>
            friend inline S& operator<<(S& stream_, const Vec3<T>& vec_) noexcept;

            //  -- Assignment --
            constexpr inline Vec3<T>& operator+=(T val_) noexcept;
            constexpr inline Vec3<T>& operator+=(const Vec3<T>& vec_) noexcept;
            constexpr inline Vec3<T>& operator-=(T val_) noexcept;
            constexpr inline Vec3<T>& operator-=(const Vec3<T>& vec_) noexcept;
            constexpr inline Vec3<T>& operator*=(T val_) noexcept;
            constexpr inline Vec3<T>& operator/=(T val_) noexcept;
            constexpr inline Vec3<T>& operator^=(const Vec3<T>& vec_) noexcept;
        };



        //  == FUNCTION PROTOTYPES ==
        //  -- Mathematical --
        template <typename T>
        inline T sum(const Vec3<T>& vec_) noexcept;
        template <typename T>
        inline double mag(const Vec3<T>& vec_) noexcept;
        template <typename T>
        inline void normalise(Vec3<T>& vec_) noexcept;



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a vec3 with initial element values of zero.
         *
         *  @tparam T   Type stored by the vector.
         */
        template <typename T>
        constexpr inline Vec3<T>::Vec3() noexcept
          : x({})
          , y({})
          , z({})
        {
        }

        /**
         *  Construct a vec3 with initial element values.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  x_  Initial value of the x component.
         *  @param  y_  Initial value of the y component.
         *  @param  z_  Initial value of the z component.
         */
        template <typename T>
        constexpr inline Vec3<T>::Vec3(const T x_, const T y_, const T z_) noexcept
          : x(x_)
          , y(y_)
          , z(z_)
        {
        }



        //  == OPERATORS ==
        //  -- Stream --
        /**
         *  Print a vec3 as a human-readable string.
         *
         *  @tparam S   Type of stream to print to.
         *  @tparam T   Type stored by the vec.
         *
         *  @param  stream_ Stream to print to.
         *  @param  vec_    Vector to print.
         *
         *  @return A reference to the stream post-print.
         */
        template <typename S, typename T>
        inline S& operator<<(S& stream_, const Vec3<T>& vec_) noexcept
        {
            stream_ << '{' << vec_.x << ", " << vec_.y << ", " << vec_.z << '}';

            return (stream_);
        }


        //  -- Assignment --
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator+=(const T val_) noexcept
        {
            x += val_;
            y += val_;
            z += val_;

            return (*this);
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& vec_) noexcept
        {
            x += vec_.x;
            y += vec_.y;
            z += vec_.z;

            return (*this);
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator-=(const T val_) noexcept
        {
            x -= val_;
            y -= val_;
            z -= val_;

            return (*this);
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& vec_) noexcept
        {
            x -= vec_.x;
            y -= vec_.y;
            z -= vec_.z;

            return (*this);
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator*=(const T val_) noexcept
        {
            x *= val_;
            y *= val_;
            z *= val_;

            return (*this);
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator/=(const T val_) noexcept
        {
            x /= val_;
            y /= val_;
            z /= val_;

            return (*this);
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator^=(const Vec3<T>& vec_) noexcept
        {
        }



        //  == FUNCTIONS ==
        //  -- Mathematical --
        /**
         *  Determine the sum of a vector's elements.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  vec_    Vector to find the sum of.
         *
         *  @return Sum of vector's elements.
         */
        template <typename T>
        inline T sum(const Vec3<T>& vec_) noexcept
        {
            return (vec_.x + vec_.y + vec_.z);
        }

        /**
         *  Determine the magnitude of a vector.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  vec_    Vector to find the magnitude of.
         *
         *  @return Magnitude of vector's elements.
         */
        template <typename T>
        inline double mag(const Vec3<T>& vec_) noexcept
        {
            return (std::sqrt(static_cast<double>(vec_.x * vec_.x) + static_cast<double>(vec_.y * vec_.y) + static_cast<double>(vec_.z * vec_.z)));
        }

        /**
         *  Normalise a vector.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  vec_    Vector to normalise.
         */
        template <typename T>
        inline void normalise(Vec3<T>& vec_) noexcept
        {
            const double m = 1.0 / mag(vec_);

            vec_.x *= m;
            vec_.y *= m;
            vec_.z *= m;
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC3_HPP
