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
            constexpr inline Quat(const Vec3<double>& axis_, double theta_) noexcept;


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
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

        constexpr inline Quat::Quat(const Vec3<double>& axis_, const double theta_) noexcept
          : x(axis_.x * std::sin(theta_ / 2.0))
          , y(axis_.y * std::sin(theta_ / 2.0))
          , z(axis_.z * std::sin(theta_ / 2.0))
          , w(std::cos(theta_ / 2.0))
        {
            PRE(axis_.normalised());
        }



        //  == OPERATORS ==


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
