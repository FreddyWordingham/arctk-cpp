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
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec3
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

            //  -- Increment / Decrement --
            constexpr inline Vec3<T>&      operator++() noexcept;
            constexpr inline const Vec3<T> operator++(int) noexcept;
            constexpr inline Vec3<T>&      operator--() noexcept;
            constexpr inline const Vec3<T> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec3<T>& operator+() const noexcept;
            constexpr inline Vec3<T>& operator-() const noexcept;
            constexpr inline Vec3<T>& operator+(T val_) const noexcept;
            constexpr inline Vec3<T>& operator+(const Vec3<T>& vec_) const noexcept;
            constexpr inline Vec3<T>& operator-(T val_) const noexcept;
            constexpr inline Vec3<T>& operator-(const Vec3<T>& vec_) const noexcept;
            constexpr inline Vec3<T>& operator*(T val_) const noexcept;
            constexpr inline T        operator*(const Vec3<T>& vec_) const noexcept;
            constexpr inline Vec3<T>& operator/(T val_) const noexcept;
            constexpr inline Vec3<T>& operator^(const Vec3<T>& vec_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;
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
         *  @tparam T   Type stored by the vec.
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
         *  @tparam T   Type stored by the vec.
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
        /**
         *  Add a value to all elements of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value to add to each vec element.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator+=(const T val_) noexcept
        {
            x += val_;
            y += val_;
            z += val_;

            return (*this);
        }

        /**
         *  Add another vec's elements to each corresponding element of the vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to add to this vec.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& vec_) noexcept
        {
            x += vec_.x;
            y += vec_.y;
            z += vec_.z;

            return (*this);
        }

        /**
         *  Subtract a value from all elements of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value to subtract from each vec element.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator-=(const T val_) noexcept
        {
            x -= val_;
            y -= val_;
            z -= val_;

            return (*this);
        }

        /**
         *  Subtract another vec's elements from each corresponding element of the vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to subtract from this vec.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& vec_) noexcept
        {
            x -= vec_.x;
            y -= vec_.y;
            z -= vec_.z;

            return (*this);
        }

        /**
         *  Multiply all elements of the vec by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to multiply each vec element by.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator*=(const T val_) noexcept
        {
            x *= val_;
            y *= val_;
            z *= val_;

            return (*this);
        }

        /**
         *  Divide all elements of the vec by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to divide each vec element by.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator/=(const T val_) noexcept
        {
            x /= val_;
            y /= val_;
            z /= val_;

            return (*this);
        }

        /**
         *  Perform the cross product using another vec.
         *  This vec forms the left-hand-side of the cross operator.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  vec_    Vec used to perform the cross product with.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator^=(const Vec3<T>& vec_) noexcept
        {
            const T pre_x{x};
            const T pre_y{y};
            const T pre_z{z};

            x = (pre_y * vec_.z) - (pre_z * vec_.y);
            y = (pre_z * vec_.x) - (pre_x * vec_.z);
            z = (pre_x * vec_.y) - (pre_y * vec_.x);

            return (*this);
        }


        //  -- Increment / Decrement --
        /**
         *  Increment each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A reference to this vec post-increment.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator++() noexcept
        {
            ++x;
            ++y;
            ++z;

            return (*this);
        }

        /**
         *  Increment each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A copy of this vec pre-increment.
         */
        template <typename T>
        constexpr inline const Vec3<T> Vec3<T>::operator++(int) noexcept
        {
            const Vec3 vec = *this;

            ++x;
            ++y;
            ++z;

            return (vec);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A reference to this vec post-decrement.
         */
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator--() noexcept
        {
            --x;
            --y;
            --z;

            return (*this);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A copy of this vec pre-decrement.
         */
        template <typename T>
        constexpr inline const Vec3<T> Vec3<T>::operator--(int) noexcept
        {
            const Vec3 vec = *this;

            --x;
            --y;
            --z;

            return (vec);
        }


        //  -- Arithmetic --
        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator+() const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator-() const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator+(T val_) const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator+(const Vec3<T>& vec_) const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator-(T val_) const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator-(const Vec3<T>& vec_) const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator*(T val_) const noexcept
        {
        }

        template <typename T>
        constexpr inline T operatoVec3<T>::r*(const Vec3<T>& vec_) const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator/(T val_) const noexcept
        {
        }

        template <typename T>
        constexpr inline Vec3<T>& Vec3<T>::operator^(const Vec3<T>& vec_) const noexcept
        {
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
        constexpr inline T& Vec3<T>::operator[](const size_t index_) noexcept
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
        constexpr inline const T& Vec3<T>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 3);

            return ((&x)[index_]);
        }



        //  == FUNCTIONS ==
        //  -- Mathematical --
        /**
         *  Determine the sum of a vec's elements.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  vec_    Vector to find the sum of.
         *
         *  @return Sum of vec's elements.
         */
        template <typename T>
        inline T sum(const Vec3<T>& vec_) noexcept
        {
            return (vec_.x + vec_.y + vec_.z);
        }

        /**
         *  Determine the magnitude of a vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  vec_    Vector to find the magnitude of.
         *
         *  @return Magnitude of vec's elements.
         */
        template <typename T>
        inline double mag(const Vec3<T>& vec_) noexcept
        {
            return (std::sqrt(static_cast<double>(vec_.x * vec_.x) + static_cast<double>(vec_.y * vec_.y) + static_cast<double>(vec_.z * vec_.z)));
        }

        /**
         *  Normalise a vec.
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
