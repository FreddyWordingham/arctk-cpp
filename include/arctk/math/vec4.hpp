/**
 *  @file   arctk/math/vec4.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical size four vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC4_HPP
#define ARCTK_MATH_VEC4_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Graphical --
#ifdef ARCTK_MOD_GUI
#include <glm/glm.hpp>
#endif



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Size four mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec4
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
            constexpr inline Vec4() noexcept;
            constexpr inline Vec4(T x_, T y_, T z_, T w_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Conversion --
#ifdef ARCTK_MOD_GUI
            constexpr inline operator glm::vec4() const noexcept; // NOLINT
#endif

            //  -- Stream --
            template <typename S, typename L>
            friend inline S& operator<<(S& stream_, const Vec4<T>& vec_) noexcept;

            //  -- Assignment --
            constexpr inline Vec4<T>& operator+=(T val_) noexcept;
            constexpr inline Vec4<T>& operator+=(const Vec4<T>& vec_) noexcept;
            constexpr inline Vec4<T>& operator-=(T val_) noexcept;
            constexpr inline Vec4<T>& operator-=(const Vec4<T>& vec_) noexcept;
            constexpr inline Vec4<T>& operator*=(T val_) noexcept;
            constexpr inline Vec4<T>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec4<T>&      operator++() noexcept;
            constexpr inline const Vec4<T> operator++(int) noexcept;
            constexpr inline Vec4<T>&      operator--() noexcept;
            constexpr inline const Vec4<T> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec4<T> operator+() const noexcept;
            constexpr inline Vec4<T> operator-() const noexcept;
            constexpr inline Vec4<T> operator+(T val_) const noexcept;
            constexpr inline Vec4<T> operator+(const Vec4<T>& vec_) const noexcept;
            constexpr inline Vec4<T> operator-(T val_) const noexcept;
            constexpr inline Vec4<T> operator-(const Vec4<T>& vec_) const noexcept;
            constexpr inline Vec4<T> operator*(T val_) const noexcept;
            constexpr inline T       operator*(const Vec4<T>& vec_) const noexcept;
            constexpr inline Vec4<T> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Mathematical --
            constexpr inline T      sum() const noexcept;
            constexpr inline double mag() const noexcept;
            constexpr inline void   normalise() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a vec4 with initial element values of zero.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        constexpr inline Vec4<T>::Vec4() noexcept
          : x({})
          , y({})
          , z({})
          , w({})
        {
        }

        /**
         *  Construct a vec4 with initial element values.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  x_  Initial value of the x component.
         *  @param  y_  Initial value of the y component.
         *  @param  z_  Initial value of the z component.
         *  @param  w_  Initial value of the w component.
         */
        template <typename T>
        constexpr inline Vec4<T>::Vec4(const T x_, const T y_, const T z_, const T w_) noexcept
          : x(x_)
          , y(y_)
          , z(z_)
          , w(w_)
        {
        }



        //  == OPERATORS ==
        //  -- Conversion --
#ifdef ARCTK_MOD_GUI
        /**
         *  Convert the vec4 to a glm::vec4.
         *  Elements are converted to float type.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Converted glm::vec4 object.
         */
        template <typename T>
        constexpr inline Vec4<T>::operator glm::vec4() const noexcept
        {
            return (glm::vec4(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z), static_cast<float>(w)));
        }
#endif

        //  -- Stream --
        /**
         *  Print a vec4 as a human-readable string.
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
        inline S& operator<<(S& stream_, const Vec4<T>& vec_) noexcept
        {
            stream_ << '{' << vec_.x << ", " << vec_.y << ", " << vec_.z << ", " << vec_.w << '}';

            return (stream_);
        }


        //  -- Assignment --
        /**
         *  Add a value to all elements of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value to add to each vec element.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator+=(const T val_) noexcept
        {
            x += val_;
            y += val_;
            z += val_;
            w += val_;

            return (*this);
        }

        /**
         *  Add another vec's elements to each corresponding element of the vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to add to this vec.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator+=(const Vec4<T>& vec_) noexcept
        {
            x += vec_.x;
            y += vec_.y;
            z += vec_.z;
            w += vec_.w;

            return (*this);
        }

        /**
         *  Subtract a value from all elements of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value to subtract from each vec element.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator-=(const T val_) noexcept
        {
            x -= val_;
            y -= val_;
            z -= val_;
            w -= val_;

            return (*this);
        }

        /**
         *  Subtract another vec's elements from each corresponding element of the vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to subtract from this vec.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator-=(const Vec4<T>& vec_) noexcept
        {
            x -= vec_.x;
            y -= vec_.y;
            z -= vec_.z;
            w -= vec_.w;

            return (*this);
        }

        /**
         *  Multiply all elements of the vec by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to multiply each vec element by.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator*=(const T val_) noexcept
        {
            x *= val_;
            y *= val_;
            z *= val_;
            w *= val_;

            return (*this);
        }

        /**
         *  Divide all elements of the vec by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to divide each vec element by.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator/=(const T val_) noexcept
        {
            x /= val_;
            y /= val_;
            z /= val_;
            w /= val_;

            return (*this);
        }


        //  -- Increment / Decrement --
        /**
         *  Increment each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A reference to this vec pre-increment.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator++() noexcept
        {
            ++x;
            ++y;
            ++z;
            ++w;

            return (*this);
        }

        /**
         *  Increment each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A copy of this vec post-increment.
         */
        template <typename T>
        constexpr inline const Vec4<T> Vec4<T>::operator++(int) noexcept
        {
            const Vec4 vec = *this;

            ++x;
            ++y;
            ++z;
            ++w;

            return (vec);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A reference to this vec pre-decrement.
         */
        template <typename T>
        constexpr inline Vec4<T>& Vec4<T>::operator--() noexcept
        {
            --x;
            --y;
            --z;
            --w;

            return (*this);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return A copy of this vec post-decrement.
         */
        template <typename T>
        constexpr inline const Vec4<T> Vec4<T>::operator--(int) noexcept
        {
            const Vec4 vec = *this;

            --x;
            --y;
            --z;
            --w;

            return (vec);
        }


        //  -- Arithmetic --
        /**
         *  Positive copy the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Positive copy of the vec.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator+() const noexcept
        {
            return (Vec4(+x, +y, +z, +w));
        }

        /**
         *  Negative copy the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Negative copy of the vec.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator-() const noexcept
        {
            return (Vec4(-x, -y, -z, -w));
        }

        /**
         *  Add a value to a vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value to add to the vec.
         *
         *  @return Vec formed by adding the value to the vec.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator+(T val_) const noexcept
        {
            return (Vec4(x + val_, y + val_, z + val_, w + val_));
        }

        /**
         *  Add a vec to a vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to add to the vec.
         *
         *  @return Vec formed by adding the vec to the vec.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator+(const Vec4<T>& vec_) const noexcept
        {
            return (Vec4(x + vec_.x, y + vec_.y, z + vec_.z, w + vec_.w));
        }

        /**
         *  Subtract a value from a vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value to subtract from the vec.
         *
         *  @return Vec formed by subtracting the value from the vec.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator-(T val_) const noexcept
        {
            return (Vec4(x - val_, y - val_, z - val_, w - val_));
        }

        /**
         *  Subtract a vec from a vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to subtract from the vec.
         *
         *  @return Vec formed by subtracting the vec from the vec.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator-(const Vec4<T>& vec_) const noexcept
        {
            return (Vec4(x - vec_.x, y - vec_.y, z - vec_.z, w - vec_.w));
        }

        /**
         *  Multiply a vecs elements by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to multiply the vec elements.
         *
         *  @return Vec formed by multiplying the vec elements by the value.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator*(T val_) const noexcept
        {
            return (Vec4(x * val_, y * val_, z * val_, w * val_));
        }

        /**
         *  Calculate the dot-product of two vecs.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to perform the dot-product with.
         *
         *  @return Dot-product of the vecs.
         */
        template <typename T>
        constexpr inline T Vec4<T>::operator*(const Vec4<T>& vec_) const noexcept
        {
            return ((x * vec_.x) + (y * vec_.y) + (z * vec_.z) + (w * vec_.w));
        }

        /**
         *  Divide a vecs elements by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to divide the vec elements.
         *
         *  @return Vec formed by dividing the vec elements by the value.
         */
        template <typename T>
        constexpr inline Vec4<T> Vec4<T>::operator/(T val_) const noexcept
        {
            return (Vec4(x / val_, y / val_, z / val_, w / val_));
        }


        //  -- Access --
        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than four.
         *
         *  @return A reference to the element requested.
         */
        template <typename T>
        constexpr inline T& Vec4<T>::operator[](const size_t index_) noexcept
        {
            assert(index_ < 4);

            return ((&x)[index_]);
        }

        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than four.
         *
         *  @return A const reference to the element requested.
         */
        template <typename T>
        constexpr inline const T& Vec4<T>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 4);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Mathematical --
        /**
         *  Calculate the sum of the vec elements.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Sum of the vec elements.
         */
        template <typename T>
        constexpr inline T Vec4<T>::sum() const noexcept
        {
            return (x + y + z + w);
        }

        template <typename T>
        constexpr inline double Vec4<T>::mag() const noexcept
        {
            return (std::sqrt(static_cast<double>((x * x) + (y * y) + (z * z) + (w * w))));
        }

        template <typename T>
        constexpr inline void Vec4<T>::normalise() const noexcept
        {
            const double m = 1.0 / mag();

            x *= m;
            y *= m;
            z *= m;
            w *= m;
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC4_HPP
