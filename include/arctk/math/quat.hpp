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
            double _x; //!< Representation of rotation axis x-component.
            double _y; //!< Representation of rotation axis y-component.
            double _z; //!< Representation of rotation axis z-component.
            double _w; //!< Representation of rotation angle.


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
            //  -- Assignment --
            constexpr inline Quat& operator+=(const Quat& quat_) noexcept;
            constexpr inline Quat& operator-=(const Quat& quat_) noexcept;

            //  -- Arithmetic --
            constexpr inline Quat operator+(const Quat& quat_) const noexcept;
            constexpr inline Quat operator-(const Quat& quat_) const noexcept;

            //  -- Access --
            constexpr inline double&       operator[](size_t index_) noexcept;
            constexpr inline const double& operator[](size_t index_) const noexcept;



            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline double angle() const noexcept;
            inline Vec<double, 3>   axis() const noexcept;

            //  -- Printing --
            inline std::string str() const noexcept override;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a unit quaternion.
         */
        constexpr inline Quat::Quat() noexcept
          : _x(0.0)
          , _y(0.0)
          , _z(0.0)
          , _w(1.0)
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
          : _x(x_)
          , _y(y_)
          , _z(z_)
          , _w(w_)
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
          : _x(axis_.x * std::sin(angle_ * 0.5))
          , _y(axis_.y * std::sin(angle_ * 0.5))
          , _z(axis_.z * std::sin(angle_ * 0.5))
          , _w(std::cos(angle_ * 0.5))
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
          : _x((((cos_yaw_ * cos_pitch_ * sin_roll_) - (sin_yaw_ * sin_pitch_ * cos_roll_))))
          , _y((((cos_yaw_ * sin_pitch_ * cos_roll_) + (sin_yaw_ * cos_pitch_ * sin_roll_))))
          , _z((((sin_yaw_ * cos_pitch_ * cos_roll_) - (cos_yaw_ * sin_pitch_ * sin_roll_))))
          , _w(((cos_yaw_ * cos_pitch_ * cos_roll_) + (sin_yaw_ * sin_pitch_ * sin_roll_)))
        {
        }



        //  == OPERATORS ==
        //  -- Access --
        /**
         *  Add another quat's elements to each corresponding element of the quat.
         *
         *  @param  quat_    Quat to add to this quat.
         *
         *  @return Reference to this quat post-operation.
         */
        constexpr inline Quat& Quat::operator+=(const Quat& quat_) noexcept
        {
            _x += quat_._x;
            _y += quat_._y;
            _z += quat_._z;
            _w += quat_._w;

            return (*this);
        }


        //  -- Arithmetic --
        /**
         *  Add a quat to a quat.
         *
         *  @param  quat_   Quat to add to the quat.
         *
         *  @return Quat formed by adding the vec to the quat.
         */
        constexpr inline Quat Quat::operator+(const Quat& quat_) const noexcept
        {
            return (Quat(_x + quat_._x, _y + quat_._y, _z + quat_._z, _w + quat_._w));
        }

        /**
         *  Subtract a quat from a quat.
         *
         *  @param  quat_   Quat to subtract from the quat.
         *
         *  @return Quat formed by subtracting the vec from the quat.
         */
        constexpr inline Quat Quat::operator-(const Quat& quat_) const noexcept
        {
            return (Quat(_x - quat_._x, _y - quat_._y, _z - quat_._z, _w - quat_._w));
        }


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

            return ((&_x)[index_]);
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

            return ((&_x)[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the rotation angle of the quat.
         *
         *  @return Rotation angle of the quat.
         */
        constexpr inline double Quat::angle() const noexcept
        {
            return (2.0 * std::acos(_w));
        }

        /**
         *  Get the rotation axis of the quat.
         *
         *  @return Rotation axis of the quat.
         */
        inline Vec<double, 3> Quat::axis() const noexcept
        {
            const double m = 1.0 / std::sqrt(1.0 - (_w * _w));

            return (Vec<double, 3>(_x * m, _y * m, _z * m));
        }


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

            stream << std::setw(settings::format::PRINT_WIDTH) << _x;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << _y;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << _z;
            stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << _w;

            stream << settings::format::VEC_END;

            return (stream.str());
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_QUAT_HPP
