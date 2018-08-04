/**
 *  @file   arctk/math/convert.hpp
 *  @date   07/07/2018
 *  @author Freddy Wordingham
 *
 *  Math conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONVERT_HPP
#define ARCTK_MATH_CONVERT_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace convert //! convertion namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Angle --
            template <typename T>
            inline T rad_to_deg(T val_) noexcept;
            template <typename T>
            inline T deg_to_rad(T val_) noexcept;

            //  -- Co-ordinate --
            template <typename T>
            inline Vec<T, 3> cart_to_polar(const Vec<T, 3>& cart_) noexcept;
            template <typename T>
            inline Vec<T, 3> polar_to_cart(const Vec<T, 3>& polar_) noexcept;



            //  == FUNCTIONS ==
            //  -- Angle --
            /**
             *  Convert a value in radians to a value in degrees.
             *
             *  @param  val_  Value to convert to radians.
             *
             *  @return Value in degrees.
             */
            template <typename T>
            inline T rad_to_deg(const T val_) noexcept
            {
                return (static_cast<T>(180.0 / consts::math::PI) * val_);
            }

            /**
             *  Convert a value in degrees to a value in radians.
             *
             *  @param  val_  Value to convert to degrees.
             *
             *  @return Value in radians.
             */
            template <typename T>
            inline T deg_to_rad(const T val_) noexcept
            {
                return (static_cast<T>(consts::math::PI / 180.0) * val_);
            }


            //  -- Co-ordinate --
            /**
             *  Convert a three-dimensional cartesian vector to a three-dimensional spherical-polar vector.
             *
             *  @param  cart_   Cartesian vector to convert.
             *
             *  @return Spherical-polar vector.
             */
            template <typename T>
            inline Vec<T, 3> cart_to_polar(const Vec<T, 3>& cart_) noexcept
            {
                Vec<T, 3> polar;

                polar.rho   = std::sqrt((cart_.x * cart_.x) + (cart_.y * cart_.y) + (cart_.z * cart_.z));
                polar.theta = std::atan2(cart_.y, cart_.x);
                polar.phi   = std::acos(cart_.z / polar.rho);

                return (polar);
            }

            template <typename T>
            inline Vec<T, 3> polar_to_cart(const Vec<T, 3>& polar_) noexcept
            {
                Vec<T, 3> cart;

                cart.x = polar_.rho * std::cos(polar_.theta) * std::sin(polar_.phi);
                cart.y = polar_.rho * std::sin(polar_.theta) * std::sin(polar_.phi);
                cart.z = polar_.rho * std::cos(polar_.phi);

                return (cart);
            }



        } // namespace convert
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERT_HPP
