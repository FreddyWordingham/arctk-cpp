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



//  == BASE ==
//  -- Arctk --
#include <arctk/math/vec.hpp>



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
         *  Size two mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 2>
        {
            //  == ASSERTIONS ==
            //  -- Type --
            static_assert(std::is_floating_point<T>::value);


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
            constexpr inline Vec() noexcept = default;
            constexpr inline Vec(T x_, T y_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Conversion --

            //  -- Stream --
            template <typename S, typename L>
            friend inline S& operator<<(S& stream_, const Vec<T, 2>& vec_) noexcept;

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
            constexpr inline Vec<T, 2> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline T&       operator[](size_t index_) noexcept;
            constexpr inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::numeric_limits<T>::epsilon()) const noexcept;

            //  -- Mathematical --
            constexpr inline T    sum() const noexcept;
            constexpr inline T    mag() const noexcept;
            constexpr inline T    mag_sq() const noexcept;
            constexpr inline void normalise() const noexcept;

            //  -- Co-ordinate --
            constexpr inline Vec<T, 2> to_polar() const noexcept;
            constexpr inline Vec<T, 2> to_cart() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a vec2 with initial element values.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  x_  Initial value of the x component.
         *  @param  y_  Initial value of the y component.
         */
        template <typename T>
        constexpr inline Vec<T, 2>::Vec(const T x_, const T y_) noexcept
          : x(x_)
          , y(y_)
        {
        }



        //  == OPERATORS ==
        //  -- Conversion --

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
        inline S& operator<<(S& stream_, const Vec<T, 2>& vec_) noexcept
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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator+=(const T val_) noexcept
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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator+=(const Vec<T, 2>& vec_) noexcept
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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator-=(const T val_) noexcept
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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator-=(const Vec<T, 2>& vec_) noexcept
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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator*=(const T val_) noexcept
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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator/=(const T val_) noexcept
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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator++() noexcept
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
        constexpr inline const Vec<T, 2> Vec<T, 2>::operator++(int) noexcept
        {
            const Vec vec = *this;

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
        constexpr inline Vec<T, 2>& Vec<T, 2>::operator--() noexcept
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
        constexpr inline const Vec<T, 2> Vec<T, 2>::operator--(int) noexcept
        {
            const Vec vec = *this;

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
        constexpr inline Vec<T, 2> Vec<T, 2>::operator+() const noexcept
        {
            return (Vec(+x, +y));
        }

        /**
         *  Negative copy the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Negative copy of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 2> Vec<T, 2>::operator-() const noexcept
        {
            return (Vec(-x, -y));
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
        constexpr inline Vec<T, 2> Vec<T, 2>::operator+(T val_) const noexcept
        {
            return (Vec(x + val_, y + val_));
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
        constexpr inline Vec<T, 2> Vec<T, 2>::operator+(const Vec<T, 2>& vec_) const noexcept
        {
            return (Vec(x + vec_.x, y + vec_.y));
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
        constexpr inline Vec<T, 2> Vec<T, 2>::operator-(T val_) const noexcept
        {
            return (Vec(x - val_, y - val_));
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
        constexpr inline Vec<T, 2> Vec<T, 2>::operator-(const Vec<T, 2>& vec_) const noexcept
        {
            return (Vec(x - vec_.x, y - vec_.y));
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
        constexpr inline Vec<T, 2> Vec<T, 2>::operator*(T val_) const noexcept
        {
            return (Vec(x * val_, y * val_));
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
        constexpr inline T Vec<T, 2>::operator*(const Vec<T, 2>& vec_) const noexcept
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
        constexpr inline Vec<T, 2> Vec<T, 2>::operator/(T val_) const noexcept
        {
            return (Vec(x / val_, y / val_));
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
        constexpr inline T& Vec<T, 2>::operator[](const size_t index_) noexcept
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
        constexpr inline const T& Vec<T, 2>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 2);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Properties --
        /**
         *  Determine if a vec is normalised to within a given tolerance.
         *
         *  @param  tol_    Maximum tolerance of normalisation value.
         *
         *  @return True if the vec is normalised.
         */
        template <typename T>
        constexpr inline bool Vec<T, 2>::normalised(const T tol_) const noexcept
        {
            return (std::fabs(1.0 - mag()) <= tol_);
        }


        //  -- Mathematical --
        /**
         *  Calculate the sum of the vec elements.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Sum of the vec elements.
         */
        template <typename T>
        constexpr inline T Vec<T, 2>::sum() const noexcept
        {
            return (x + y);
        }

        /**
         *  Calculate the magnitude of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Magnitude of the vec.
         */
        template <typename T>
        constexpr inline T Vec<T, 2>::mag() const noexcept
        {
            return (std::sqrt(mag_sq()));
        }

        /**
         *  Calculate the magnitude-squared of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @return Magnitude-squared of the vec.
         */
        template <typename T>
        constexpr inline T Vec<T, 2>::mag_sq() const noexcept
        {
            return ((x * x) + (y * y));
        }

        /**
         *  Normalise the vec.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        constexpr inline void Vec<T, 2>::normalise() const noexcept
        {
            const T m = T{1.0} / mag();

            x *= m;
            y *= m;
        }


        //  -- Co-ordinate --
        /**
         *  Convert the cartesian vector to a polar vector.
         *
         *  @return Vec in polar co-ordinate form.
         */
        template <typename T>
        constexpr inline Vec<T, 2> Vec<T, 2>::to_polar() const noexcept
        {
            Vec<T, 2> polar;

            polar.rho   = std::sqrt((x * x) + (y * y));
            polar.theta = std::atan2(y, x);

            return (polar);
        }

        /**
         *  Convert the polar vector to a cartesian vector.
         *
         *  @return Vec in cartesian co-ordinate form.
         */
        template <typename T>
        constexpr inline Vec<T, 2> Vec<T, 2>::to_cart() const noexcept
        {
            Vec<T, 2> cart;

            cart.x = rho * std::cos(theta);
            cart.y = rho * std::sin(theta);

            return (cart);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC2_HPP
