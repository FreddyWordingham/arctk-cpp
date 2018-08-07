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
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/settings.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Two-dimensional mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         */
        template <typename T>
        class Vec<T, 2> : public str::Printable
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
            //  -- Conversion --
            constexpr inline explicit operator std::array<T, 2>() const noexcept;

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
            constexpr inline T         sum() const noexcept;
            constexpr inline T         mag() const noexcept;
            constexpr inline T         mag_sq() const noexcept;
            constexpr inline Vec<T, 2> normal() const noexcept;
            constexpr inline void      normalise() noexcept;

            //  -- Printing --
            inline std::string str() const noexcept override;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a two-dimensional vec with elements of zero.
         */
        template <typename T>
        constexpr inline Vec<T, 2>::Vec() noexcept
          : x(0)
          , y(0)
        {
        }

        /**
         *  Construct a two-dimensional vec with initial element values.
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
        /**
         *  Convert the vec to a std::array.
         *
         *  @return Converted std::array object.
         */
        template <typename T>
        constexpr inline Vec<T, 2>::operator std::array<T, 2>() const noexcept
        {
            return (std::array<T, 2>({{x, y}}));
        }


        //  -- Assignment --
        /**
         *  Add a value to all elements of the vec.
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
            PRE(index_ < 2);

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
            PRE(index_ < 2);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Properties --
        /**
         *  Determine if a vec is normalised to within a given tolerance.
         *
         *  @param  tol_    Maximum tolerance of normalisation value.
         *
         *  @pre    tol_ must be positive.
         *
         *  @return True if the vec is normalised.
         */
        template <typename T>
        constexpr inline bool Vec<T, 2>::normalised(const T tol_) const noexcept
        {
            PRE(tol_ > 0);

            return (std::fabs(T{1.0} - mag_sq()) <= tol_);
        }


        //  -- Mathematical --
        /**
         *  Calculate the sum of the vec elements.
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
         *  @return Magnitude-squared of the vec.
         */
        template <typename T>
        constexpr inline T Vec<T, 2>::mag_sq() const noexcept
        {
            return ((x * x) + (y * y));
        }

        /**
         *  Get the normalised form of the vec.
         *
         *  @return Normalised form of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 2> Vec<T, 2>::normal() const noexcept
        {
            Vec<T, 2> normal(x, y);

            normal.normalise();

            return (normal);
        }

        /**
         *  Normalise the vec.
         *
         *  @post   Vec must be normalised.
         */
        template <typename T>
        constexpr inline void Vec<T, 2>::normalise() noexcept
        {
            const T m = T{1.0} / mag();

            x *= m;
            y *= m;

            POST(normalised());
        }


        //  -- Printing --
        /**
         *  Create a human readable string of the vec.
         *
         *  @return Human readable string of the vec.
         */
        template <typename T>
        inline std::string Vec<T, 2>::str() const noexcept
        {
            std::stringstream stream;

            stream << settings::format::VEC_START;

            stream << std::setw(settings::format::PRINT_WIDTH) << x;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << y;

            stream << settings::format::VEC_END;

            return (stream.str());
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_VEC2_HPP
