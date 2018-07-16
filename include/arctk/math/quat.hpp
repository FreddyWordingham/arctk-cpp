/**
 *  @file   arctk/math/quat.hpp
 *  @date   16/06/2018
 *  @author Freddy Wordingham
 *
 *  Quaternion mathematical class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_QUAT_HPP
#define ARCTK_MATH_QUAT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/math/vec3.hpp>
#include <arctk/settings.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Quaternion mathematical class.
         */
        class Quat : public str::Printable
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            double x; //!< Representation of rotation axis x-component.
            double y; //!< Representation of rotation axis y-component.
            double z; //!< Representation of rotation axis z-component.
            double w; //!< Representation of rotation angle.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Quat() noexcept;
            constexpr inline Quat(double x_, double y_, double z_, double w_) noexcept;
            constexpr inline Quat(const Vec<double, 3>& axis_, double angle_) noexcept;
            constexpr inline Quat(double yaw_, double pitch_, double roll_) noexcept;

          private:
            constexpr inline Quat(double cos_yaw_, double sin_yaw_, double cos_pitch_, double sin_pitch_, double cos_roll_, double sin_roll_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            constexpr inline double&       operator[](size_t index_) noexcept;
            constexpr inline const double& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr double         angle() const noexcept;
            constexpr Vec<double, 3> axis() const noexcept;

            //  -- Printing --
            inline std::string str() const noexcept override;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a unit quaternion.
         */
        constexpr inline Quat::Quat() noexcept
          : x(0.0)
          , y(0.0)
          , z(0.0)
          , w(1.0)
        {
        }

        /**
         *  Construct a quaternion directly.
         *
         *  @param  x_  Initial value of the x component.
         *  @param  y_  Initial value of the y component.
         *  @param  z_  Initial value of the z component.
         *  @param  w_  Initial value of the w component.
         */
        constexpr inline Quat::Quat(const double x_, const double y_, const double z_, const double w_) noexcept
          : x(x_)
          , y(y_)
          , z(z_)
          , w(w_)
        {
        }

        /**
         *  Construct a quaternion from a rotation axis and a rotation angle.
         *
         *  @param  axis_   Axis of rotation.
         *  @param  angle_  Angle of rotation.
         *
         *  @pre    axis_ must be normalised.
         */
        constexpr inline Quat::Quat(const Vec<double, 3>& axis_, const double angle_) noexcept
          : x(axis_.x * std::sin(angle_ * 0.5))
          , y(axis_.y * std::sin(angle_ * 0.5))
          , z(axis_.z * std::sin(angle_ * 0.5))
          , w(std::cos(angle_ * 0.5))
        {
            PRE(axis_.normalised());
        }

        /**
         *  Construct a quaternion from Euler rotations.
         *
         *  @param  yaw_    Angle to rotate around the up direction.
         *  @param  pitch_  Angle to rotate around side direction.
         *  @param  roll_   Angle to rotate around the forward direction.
         */
        constexpr inline Quat::Quat(const double yaw_, const double pitch_, const double roll_) noexcept
          : Quat(std::cos(yaw_ * 0.5), std::sin(yaw_ * 0.5), std::cos(pitch_ * 0.5), std::sin(pitch_ * 0.5), std::cos(roll_ * 0.5), std::sin(roll_ * 0.5))
        {
        }

        /**
         *  Construct a quaternion from Euler rotations helper method.
         *
         *  @param  sin_yaw_    Sine of the angle to rotate around the up direction.
         *  @param  cos_yaw_    Cosine of the angle to rotate around the up direction.
         *  @param  sin_pitch_  Sine of the angle to rotate around side direction.
         *  @param  cos_pitch_  Cosine of the angle to rotate around side direction.
         *  @param  sin_roll_   Sine of the angle to rotate around the forward direction.
         *  @param  cos_roll_   Cosine of the angle to rotate around the forward direction.
         */
        constexpr inline Quat::Quat(const double cos_yaw_, const double sin_yaw_, const double cos_pitch_, const double sin_pitch_, const double cos_roll_, const double sin_roll_) noexcept
          : x((((cos_yaw_ * cos_pitch_ * sin_roll_) - (sin_yaw_ * sin_pitch_ * cos_roll_))))
          , y((((cos_yaw_ * sin_pitch_ * cos_roll_) + (sin_yaw_ * cos_pitch_ * sin_roll_))))
          , z((((sin_yaw_ * cos_pitch_ * cos_roll_) - (cos_yaw_ * sin_pitch_ * sin_roll_))))
          , w(((cos_yaw_ * cos_pitch_ * cos_roll_) + (sin_yaw_ * sin_pitch_ * sin_roll_)))
        {
        }



        //  == OPERATORS ==
        //  -- Access --
        /**
         *  Access an element of the quat.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than four.
         *
         *  @return A reference to the element requested.
         */
        constexpr inline double& Quat::operator[](const size_t index_) noexcept
        {
            PRE(index_ < 4);

            return ((&x)[index_]);
        }

        /**
         *  Access an element of the quat.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than four.
         *
         *  @return A const reference to the element requested.
         */
        constexpr inline const double& Quat::operator[](const size_t index_) const noexcept
        {
            PRE(index_ < 4);

            return ((&x)[index_]);
        }



        //  == METHODS ==
        //  -- Printing --
        /**
         *  Create a human readable string of the quat.
         *
         *  @return Human readable string of the quat.
         */
        inline std::string Quat::str() const noexcept
        {
            std::stringstream stream;

            stream << settings::format::VEC_START;

            stream << std::setw(settings::format::PRINT_WIDTH) << x;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << y;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << z;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << w;

            stream << settings::format::VEC_END;

            return (stream.str());
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_QUAT_HPP
