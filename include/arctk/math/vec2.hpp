/**
 *  @file   arctk/math/vec2.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical size two vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC2_HPP
#define ARCTK_MATH_VEC2_HPP



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
         *  Size two mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec2
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
            constexpr inline Vec2() noexcept;
            constexpr inline Vec2(T x_, T y_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Conversion --
#ifdef ARCTK_MOD_GUI
            constexpr inline operator glm::vec2() const noexcept; // NOLINT
#endif

            //  -- Stream --
            template <typename S, typename L>
            friend inline S& operator<<(S& stream_, const Vec2<T>& vec_) noexcept;

            //  -- Assignment --
            constexpr inline Vec2<T>& operator+=(T val_) noexcept;
            constexpr inline Vec2<T>& operator+=(const Vec2<T>& vec_) noexcept;
            constexpr inline Vec2<T>& operator-=(T val_) noexcept;
            constexpr inline Vec2<T>& operator-=(const Vec2<T>& vec_) noexcept;
            constexpr inline Vec2<T>& operator*=(T val_) noexcept;
            constexpr inline Vec2<T>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec2<T>&      operator++() noexcept;
            constexpr inline const Vec2<T> operator++(int) noexcept;
            constexpr inline Vec2<T>&      operator--() noexcept;
            constexpr inline const Vec2<T> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec2<T> operator+() const noexcept;
            constexpr inline Vec2<T> operator-() const noexcept;
            constexpr inline Vec2<T> operator+(T val_) const noexcept;
            constexpr inline Vec2<T> operator+(const Vec2<T>& vec_) const noexcept;
            constexpr inline Vec2<T> operator-(T val_) const noexcept;
            constexpr inline Vec2<T> operator-(const Vec2<T>& vec_) const noexcept;
            constexpr inline Vec2<T> operator*(T val_) const noexcept;
            constexpr inline T       operator*(const Vec2<T>& vec_) const noexcept;
            constexpr inline Vec2<T> operator/(T val_) const noexcept;

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
         *  Construct a vec2 with initial element values of zero.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        constexpr inline Vec2<T>::Vec2() noexcept
          : x({})
          , y({})
        {
        }

        /**
         *  Construct a vec2 with initial element values.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  x_  Initial value of the x component.
         *  @param  y_  Initial value of the y component.
         */
        template <typename T>
        constexpr inline Vec2<T>::Vec2(const T x_, const T y_) noexcept
          : x(x_)
          , y(y_)
        {
        }



        //  == OPERATORS ==
        //  -- Conversion --
#ifdef ARCTK_MOD_GUI
        /**
         *  Convert the vec2 to a glm::vec2.
         *  Elements are converted to float type.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Converted glm::vec2 object.
         */
        template <typename T>
        constexpr inline Vec2<T>::operator glm::vec2() const noexcept
        {
            return (glm::vec2(static_cast<float>(x), static_cast<float>(y)));
        }
#endif

        //  -- Stream --
        /**
         *  Print a vec2 as a human-readable string.
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
        inline S& operator<<(S& stream_, const Vec2<T>& vec_) noexcept
        {
            stream_ << '{' << vec_.x << ", " << vec_.y << '}';

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
        constexpr inline Vec2<T>& Vec2<T>::operator+=(const T val_) noexcept
        {
            x += val_;
            y += val_;

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
        constexpr inline Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& vec_) noexcept
        {
            x += vec_.x;
            y += vec_.y;

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
        constexpr inline Vec2<T>& Vec2<T>::operator-=(const T val_) noexcept
        {
            x -= val_;
            y -= val_;

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
        constexpr inline Vec2<T>& Vec2<T>::operator-=(const Vec2<T>& vec_) noexcept
        {
            x -= vec_.x;
            y -= vec_.y;

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
        constexpr inline Vec2<T>& Vec2<T>::operator*=(const T val_) noexcept
        {
            x *= val_;
            y *= val_;

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
        constexpr inline Vec2<T>& Vec2<T>::operator/=(const T val_) noexcept
        {
            x /= val_;
            y /= val_;

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
        constexpr inline Vec2<T>& Vec2<T>::operator++() noexcept
        {
            ++x;
            ++y;

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
        constexpr inline const Vec2<T> Vec2<T>::operator++(int) noexcept
        {
            const Vec2 vec = *this;

            ++x;
            ++y;

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
        constexpr inline Vec2<T>& Vec2<T>::operator--() noexcept
        {
            --x;
            --y;

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
        constexpr inline const Vec2<T> Vec2<T>::operator--(int) noexcept
        {
            const Vec2 vec = *this;

            --x;
            --y;

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
        constexpr inline Vec2<T> Vec2<T>::operator+() const noexcept
        {
            return (Vec2(+x, +y));
        }

        /**
         *  Negative copy the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Negative copy of the vec.
         */
        template <typename T>
        constexpr inline Vec2<T> Vec2<T>::operator-() const noexcept
        {
            return (Vec2(-x, -y));
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
        constexpr inline Vec2<T> Vec2<T>::operator+(T val_) const noexcept
        {
            return (Vec2(x + val_, y + val_));
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
        constexpr inline Vec2<T> Vec2<T>::operator+(const Vec2<T>& vec_) const noexcept
        {
            return (Vec2(x + vec_.x, y + vec_.y));
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
        constexpr inline Vec2<T> Vec2<T>::operator-(T val_) const noexcept
        {
            return (Vec2(x - val_, y - val_));
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
        constexpr inline Vec2<T> Vec2<T>::operator-(const Vec2<T>& vec_) const noexcept
        {
            return (Vec2(x - vec_.x, y - vec_.y));
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
        constexpr inline Vec2<T> Vec2<T>::operator*(T val_) const noexcept
        {
            return (Vec2(x * val_, y * val_));
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
        constexpr inline T Vec2<T>::operator*(const Vec2<T>& vec_) const noexcept
        {
            return ((x * vec_.x) + (y * vec_.y));
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
        constexpr inline Vec2<T> Vec2<T>::operator/(T val_) const noexcept
        {
            return (Vec2(x / val_, y / val_));
        }


        //  -- Access --
        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than two.
         *
         *  @return A reference to the element requested.
         */
        template <typename T>
        constexpr inline T& Vec2<T>::operator[](const size_t index_) noexcept
        {
            assert(index_ < 2);

            return ((&x)[index_]);
        }

        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than two.
         *
         *  @return A const reference to the element requested.
         */
        template <typename T>
        constexpr inline const T& Vec2<T>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 2);

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
        constexpr inline T Vec2<T>::sum() const noexcept
        {
            return (x + y);
        }

        template <typename T>
        constexpr inline double Vec2<T>::mag() const noexcept
        {
            return (std::sqrt(static_cast<double>((x * x) + (y * y))));
        }

        template <typename T>
        constexpr inline void Vec2<T>::normalise() const noexcept
        {
            const double m = 1.0 / mag();

            x *= m;
            y *= m;
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC2_HPP
