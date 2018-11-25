/**
 *  @file   arctk/math/vec4.inl
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  Four-dimensional mathematical vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC4_INL
#define ARCTK_MATH_VEC4_INL



//  == IMPORTS ==
//  -- Std --
#include <cmath>
#include <ostream>

//  -- Arctk --
#include <arctk/consts/format.hpp>
#include <arctk/math/mat.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a four-dimensional vec with elements of zero.
         */
        template <typename T>
        constexpr inline Vec<T, 4>::Vec() noexcept
          : x(0)
          , y(0)
          , z(0)
          , w(0)
        {
        }

        /**
         *  Construct a four-dimensional vec with initial element values.
         *
         *  @param  x_  Initial value of the x component.
         *  @param  y_  Initial value of the y component.
         *  @param  z_  Initial value of the z component.
         *  @param  w_  Initial value of the w component.
         */
        template <typename T>
        constexpr inline Vec<T, 4>::Vec(const T x_, const T y_, const T z_, const T w_) noexcept
          : x(x_)
          , y(y_)
          , z(z_)
          , w(w_)
        {
        }

        /**
         *  Construct a vec using a smaller vec and given values.
         *
         *  @param  vec_    Vec of values to initialise vec elements.
         *  @param  z_      Initial value of the z component.
         *  @param  w_      Initial value of the w component.
         */
        template <typename T>
        constexpr inline Vec<T, 4>::Vec(const Vec<T, 2>& vec_, const T z_, const T w_) noexcept
          : x(vec_.x)
          , y(vec_.y)
          , z(z_)
          , w(w_)
        {
        }

        /**
         *  Construct a vec using a smaller vec and given values.
         *
         *  @param  vec_    Vec of values to initialise vec elements.
         *  @param  w_      Initial value of the w component.
         */
        template <typename T>
        constexpr inline Vec<T, 4>::Vec(const Vec<T, 3>& vec_, const T w_) noexcept
          : x(vec_.x)
          , y(vec_.y)
          , z(vec_.z)
          , w(w_)
        {
        }



        //  == OPERATORS ==
        //  -- Assignment --
        /**
         *  Add a value to all elements of the vec.
         *
         *  @param  val_    Value to add to each vec element.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator+=(const T val_) noexcept
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
         *  @param  vec_    Vec to add to this vec.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator+=(const Vec<T, 4>& vec_) noexcept
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
         *  @param  val_    Value to subtract from each vec element.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator-=(const T val_) noexcept
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
         *  @param  vec_    Vec to subtract from this vec.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator-=(const Vec<T, 4>& vec_) noexcept
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
         *  @param  val_    Value used to multiply each vec element by.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator*=(const T val_) noexcept
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
         *  @param  val_    Value used to divide each vec element by.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator/=(const T val_) noexcept
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
         *  @return A reference to this vec pre-increment.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator++() noexcept
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
         *  @return A copy of this vec post-increment.
         */
        template <typename T>
        constexpr inline const Vec<T, 4> Vec<T, 4>::operator++(int) noexcept
        {
            const Vec vec = *this;

            ++x;
            ++y;
            ++z;
            ++w;

            return (vec);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @return A reference to this vec pre-decrement.
         */
        template <typename T>
        constexpr inline Vec<T, 4>& Vec<T, 4>::operator--() noexcept
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
         *  @return A copy of this vec post-decrement.
         */
        template <typename T>
        constexpr inline const Vec<T, 4> Vec<T, 4>::operator--(int) noexcept
        {
            const Vec vec = *this;

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
         *  @return Positive copy of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator+() const noexcept
        {
            return (Vec(+x, +y, +z, +w));
        }

        /**
         *  Negative copy the vec.
         *
         *  @return Negative copy of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator-() const noexcept
        {
            return (Vec(-x, -y, -z, -w));
        }

        /**
         *  Add a value to a vec.
         *
         *  @param  val_    Value to add to the vec.
         *
         *  @return Vec formed by adding the value to the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator+(T val_) const noexcept
        {
            return (Vec(x + val_, y + val_, z + val_, w + val_));
        }

        /**
         *  Add a vec to a vec.
         *
         *  @param  vec_    Vec to add to the vec.
         *
         *  @return Vec formed by adding the vec to the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator+(const Vec<T, 4>& vec_) const noexcept
        {
            return (Vec(x + vec_.x, y + vec_.y, z + vec_.z, w + vec_.w));
        }

        /**
         *  Subtract a value from a vec.
         *
         *  @param  val_    Value to subtract from the vec.
         *
         *  @return Vec formed by subtracting the value from the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator-(T val_) const noexcept
        {
            return (Vec(x - val_, y - val_, z - val_, w - val_));
        }

        /**
         *  Subtract a vec from a vec.
         *
         *  @param  vec_    Vec to subtract from the vec.
         *
         *  @return Vec formed by subtracting the vec from the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator-(const Vec<T, 4>& vec_) const noexcept
        {
            return (Vec(x - vec_.x, y - vec_.y, z - vec_.z, w - vec_.w));
        }

        /**
         *  Multiply a vecs elements by a value.
         *
         *  @param  val_    Value used to multiply the vec elements.
         *
         *  @return Vec formed by multiplying the vec elements by the value.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator*(T val_) const noexcept
        {
            return (Vec(x * val_, y * val_, z * val_, w * val_));
        }

        /**
         *  Calculate the dot-product of two vecs.
         *
         *  @param  vec_    Vec to perform the dot-product with.
         *
         *  @return Dot-product of the vecs.
         */
        template <typename T>
        constexpr inline T Vec<T, 4>::operator*(const Vec<T, 4>& vec_) const noexcept
        {
            return ((x * vec_.x) + (y * vec_.y) + (z * vec_.z) + (w * vec_.w));
        }

        /**
         *  Multiply the vec by a mat.
         *
         *  @param  mat_    Mat to multiply this vec by.
         *
         *  @return Vec formed by multiplying the vec by the mat.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator*(const Mat<T, 4>& mat_) const noexcept
        {
            return (Vec((x * mat_.x.x) + (y * mat_.y.x) + (z * mat_.z.x) + (w * mat_.w.x), (x * mat_.x.y) + (y * mat_.y.y) + (z * mat_.z.y) + (w * mat_.w.y), (x * mat_.x.z) + (y * mat_.y.z) + (z * mat_.z.z) + (w * mat_.w.z),
                        (x * mat_.x.w) + (y * mat_.y.w) + (z * mat_.z.w) + (w * mat_.w.w)));
        }

        /**
         *  Divide a vecs elements by a value.
         *
         *  @param  val_    Value used to divide the vec elements.
         *
         *  @return Vec formed by dividing the vec elements by the value.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::operator/(T val_) const noexcept
        {
            return (Vec(x / val_, y / val_, z / val_, w / val_));
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
        constexpr inline T& Vec<T, 4>::operator[](const size_t index_) noexcept
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
        constexpr inline const T& Vec<T, 4>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 4);

            return ((&x)[index_]);
        }


        //  -- Printing --
        /**
         *  Print the vec to a stream.
         *
         *  @tparam S   Type stored by the vec.
         *
         *  @param  stream_ Stream to print to.
         *  @param  vec_    Vec to be printed.
         *
         *  @return Reference to the vec post-print.
         */
        template <typename S>
        constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 4>& vec_) noexcept
        {
            stream_ << consts::format::OPENERS[consts::format::container::VEC] << vec_.x << consts::format::DELIM << vec_.y << consts::format::DELIM << vec_.z << consts::format::DELIM << vec_.w << consts::format::CLOSERS[consts::format::container::VEC];

            return (stream_);
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
        constexpr inline bool Vec<T, 4>::normalised(const T tol_) const noexcept
        {
            return (std::fabs(T{1.0} - mag_sq()) <= tol_);
        }


        //  -- Mathematical --
        /**
         *  Calculate the sum of the vec elements.
         *
         *  @return Sum of the vec elements.
         */
        template <typename T>
        constexpr inline T Vec<T, 4>::sum() const noexcept
        {
            return (x + y + z + w);
        }

        /**
         *  Calculate the magnitude of the vec.
         *
         *  @return Magnitude of the vec.
         */
        template <typename T>
        constexpr inline T Vec<T, 4>::mag() const noexcept
        {
            return (std::sqrt(mag_sq()));
        }

        /**
         *  Calculate the magnitude-squared of the vec.
         *
         *  @return Magnitude-squared of the vec.
         */
        template <typename T>
        constexpr inline T Vec<T, 4>::mag_sq() const noexcept
        {
            return ((x * x) + (y * y) + (z * z) + (w * w));
        }

        /**
         *  Get the normalised form of the vec.
         *
         *  @return Normalised form of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 4> Vec<T, 4>::normal() const noexcept
        {
            Vec<T, 4> normal(x, y, z, w);

            normal.normalise();

            return (normal);
        }

        /**
         *  Normalise the vec.
         *
         *  @post   Vec must be normalised.
         */
        template <typename T>
        constexpr inline void Vec<T, 4>::normalise() noexcept
        {
            const T m = T{1.0} / mag();

            x *= m;
            y *= m;
            z *= m;
            w *= m;

            assert(normalised());
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_VEC4_INL
