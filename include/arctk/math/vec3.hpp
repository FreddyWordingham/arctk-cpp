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
#include <cassert>
#include <cmath>
#include <iomanip>
#include <ostream>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/math/vec.hpp>



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
            //  -- Conversion --
            constexpr inline explicit operator std::array<T, 3>() const noexcept;

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



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a three-dimensional vec with elements of zero.
         */
        template <typename T>
        constexpr inline Vec<T, 3>::Vec() noexcept
          : x(0)
          , y(0)
          , z(0)
        {
        }

        /**
         *  Construct a three-dimensional with initial element values.
         *
         *  @param  x_  Initial value of the x component.
         *  @param  y_  Initial value of the y component.
         *  @param  z_  Initial value of the z component.
         */
        template <typename T>
        constexpr inline Vec<T, 3>::Vec(const T x_, const T y_, const T z_) noexcept
          : x(x_)
          , y(y_)
          , z(z_)
        {
        }

        /**
         *  Construct a vec using a smaller vec and given values.
         *
         *  @param  vec_    Vec of values to initialise vec elements.
         *  @param  z_      Initial value of the z component.
         */
        template <typename T>
        constexpr inline Vec<T, 3>::Vec(const Vec<T, 2>& vec_, const T z_) noexcept
          : x(vec_.x)
          , y(vec_.y)
          , z(z_)
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
        constexpr inline Vec<T, 3>::operator std::array<T, 3>() const noexcept
        {
            return (std::array<T, 3>({{x, y, z}}));
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
        constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, 3>& vec_) noexcept
        {
            stream_ << consts::format::OPENERS[consts::format::container::VEC] << vec_.x << consts::format::DELIM << vec_.y << consts::format::DELIM << vec_.z << consts::format::CLOSERS[consts::format::container::VEC];

            return (stream_);
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
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator+=(const T val_) noexcept
        {
            x += val_;
            y += val_;
            z += val_;

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
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator+=(const Vec<T, 3>& vec_) noexcept
        {
            x += vec_.x;
            y += vec_.y;
            z += vec_.z;

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
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator-=(const T val_) noexcept
        {
            x -= val_;
            y -= val_;
            z -= val_;

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
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator-=(const Vec<T, 3>& vec_) noexcept
        {
            x -= vec_.x;
            y -= vec_.y;
            z -= vec_.z;

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
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator*=(const T val_) noexcept
        {
            x *= val_;
            y *= val_;
            z *= val_;

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
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator/=(const T val_) noexcept
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
         *  @param  vec_    Vec used to perform the cross product with.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T>
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator^=(const Vec<T, 3>& vec_) noexcept
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
         *  @return A reference to this vec pre-increment.
         */
        template <typename T>
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator++() noexcept
        {
            ++x;
            ++y;
            ++z;

            return (*this);
        }

        /**
         *  Increment each element of the vec.
         *
         *  @return A copy of this vec post-increment.
         */
        template <typename T>
        constexpr inline const Vec<T, 3> Vec<T, 3>::operator++(int) noexcept
        {
            const Vec vec = *this;

            ++x;
            ++y;
            ++z;

            return (vec);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @return A reference to this vec pre-decrement.
         */
        template <typename T>
        constexpr inline Vec<T, 3>& Vec<T, 3>::operator--() noexcept
        {
            --x;
            --y;
            --z;

            return (*this);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @return A copy of this vec post-decrement.
         */
        template <typename T>
        constexpr inline const Vec<T, 3> Vec<T, 3>::operator--(int) noexcept
        {
            const Vec vec = *this;

            --x;
            --y;
            --z;

            return (vec);
        }


        //  -- Arithmetic --
        /**
         *  Positive copy the vec.
         *
         *  @return Positive copy of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator+() const noexcept
        {
            return (Vec(+x, +y, +z));
        }

        /**
         *  Negative copy the vec.
         *
         *  @return Negative copy of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator-() const noexcept
        {
            return (Vec(-x, -y, -z));
        }

        /**
         *  Add a value to a vec.
         *
         *  @param  val_    Value to add to the vec.
         *
         *  @return Vec formed by adding the value to the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator+(T val_) const noexcept
        {
            return (Vec(x + val_, y + val_, z + val_));
        }

        /**
         *  Add a vec to a vec.
         *
         *  @param  vec_    Vec to add to the vec.
         *
         *  @return Vec formed by adding the vec to the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator+(const Vec<T, 3>& vec_) const noexcept
        {
            return (Vec(x + vec_.x, y + vec_.y, z + vec_.z));
        }

        /**
         *  Subtract a value from a vec.
         *
         *  @param  val_    Value to subtract from the vec.
         *
         *  @return Vec formed by subtracting the value from the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator-(T val_) const noexcept
        {
            return (Vec(x - val_, y - val_, z - val_));
        }

        /**
         *  Subtract a vec from a vec.
         *
         *  @param  vec_    Vec to subtract from the vec.
         *
         *  @return Vec formed by subtracting the vec from the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator-(const Vec<T, 3>& vec_) const noexcept
        {
            return (Vec(x - vec_.x, y - vec_.y, z - vec_.z));
        }

        /**
         *  Multiply a vecs elements by a value.
         *
         *  @param  val_    Value used to multiply the vec elements.
         *
         *  @return Vec formed by multiplying the vec elements by the value.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator*(T val_) const noexcept
        {
            return (Vec(x * val_, y * val_, z * val_));
        }

        /**
         *  Calculate the dot-product of two vecs.
         *
         *  @param  vec_    Vec to perform the dot-product with.
         *
         *  @return Dot-product of the vecs.
         */
        template <typename T>
        constexpr inline T Vec<T, 3>::operator*(const Vec<T, 3>& vec_) const noexcept
        {
            return ((x * vec_.x) + (y * vec_.y) + (z * vec_.z));
        }

        /**
         *  Multiply the vec by a mat.
         *
         *  @param  mat_    Mat to multiply this vec by.
         *
         *  @return Vec formed by multiplying the vec by the mat.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator*(const Mat<T, 3>& mat_) const noexcept
        {
            return (Vec((x * mat_.x.x) + (y * mat_.y.x) + (z * mat_.z.x), (x * mat_.x.y) + (y * mat_.y.y) + (z * mat_.z.y), (x * mat_.x.z) + (y * mat_.y.z) + (z * mat_.z.z)));
        }

        /**
         *  Divide a vecs elements by a value.
         *
         *  @param  val_    Value used to divide the vec elements.
         *
         *  @return Vec formed by dividing the vec elements by the value.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator/(T val_) const noexcept
        {
            return (Vec(x / val_, y / val_, z / val_));
        }

        /**
         *  Calculate the cross-product of two vecs.
         *
         *  @param  vec_    Vec to perform the cross-product with.
         *
         *  @return Cross-product of the vecs.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::operator^(const Vec<T, 3>& vec_) const noexcept
        {
            return (Vec((y * vec_.z) - (z * vec_.y), (z * vec_.x) - (x * vec_.z), (x * vec_.y) - (y * vec_.x)));
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
        constexpr inline T& Vec<T, 3>::operator[](const size_t index_) noexcept
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
        constexpr inline const T& Vec<T, 3>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < 3);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Properties --
        /**
         *  Determine if a vec is normalised to within a given tolerance.
         *
         *  @param  tol_    Square root of the maximum tolerance of normalisation value.
         *
         *  @return True if the vec is normalised.
         */
        template <typename T>
        constexpr inline bool Vec<T, 3>::normalised(const T tol_) const noexcept
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
        constexpr inline T Vec<T, 3>::sum() const noexcept
        {
            return (x + y + z);
        }

        /**
         *  Calculate the magnitude of the vec.
         *
         *  @return Magnitude of the vec.
         */
        template <typename T>
        constexpr inline T Vec<T, 3>::mag() const noexcept
        {
            return (std::sqrt(mag_sq()));
        }

        /**
         *  Calculate the magnitude-squared of the vec.
         *
         *  @return Magnitude-squared of the vec.
         */
        template <typename T>
        constexpr inline T Vec<T, 3>::mag_sq() const noexcept
        {
            return ((x * x) + (y * y) + (z * z));
        }

        /**
         *  Get the normalised form of the vec.
         *
         *  @return Normalised form of the vec.
         */
        template <typename T>
        constexpr inline Vec<T, 3> Vec<T, 3>::normal() const noexcept
        {
            Vec<T, 3> normal(x, y, z);

            normal.normalise();

            return (normal);
        }

        /**
         *  Normalise the vec.
         *
         *  @post   Vec must be normalised.
         */
        template <typename T>
        constexpr inline void Vec<T, 3>::normalise() noexcept
        {
            const T m = T{1.0} / mag();

            x *= m;
            y *= m;
            z *= m;

            POST(normalised());
        }

        /**
         *  Rotate the vec around a given axis by a given angle.
         *  Right hand rule applies.
         *
         *  @param  axis_   Axis to rotate around.
         *  @param  ang_    Angle to rotate by.
         *
         *  @pre    axis_ must be normalised.
         */
        template <typename T>
        constexpr inline void Vec<T, 3>::rotate(const math::Vec<T, 3>& axis_, const T ang_) noexcept
        {
            assert(axis_.normalised());

            const double cos_theta = std::cos(ang_);
            const double sin_theta = std::sin(ang_);

            *this = (*this * cos_theta) + ((axis_ ^ *this) * sin_theta) + ((axis_ * (axis_ * *this)) * (1.0 - cos_theta));
        }



        namespace vec //! vector namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Utility --
            template <typename T>
            constexpr inline Vec<T, 3> axis(size_t dim_) noexcept;



            //  == FUNCTIONS ==
            //  -- Utility --
            /**
             *  Construct a unit-axis for a given dimension.
             *
             *  @tparam T   Type stored by the vec.
             *
             *  @param  dim_    Dimension to create a unit-axis for.
             *
             *  @pre    dim_ must be less than 3.
             *
             *  @return Unit-axis for a given dimension.
             */
            template <typename T>
            constexpr inline Vec<T, 3> axis(const size_t dim_) noexcept
            {
                assert(dim_ < 3);

                Vec<T, 3> vec;

                vec[dim_] = 1.0;

                return (vec);
            }



        } // namespace vec
    }     // namespace math



    //  == ALIASES ==
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.



} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_VEC3_HPP
