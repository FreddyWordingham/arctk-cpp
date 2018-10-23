/**
 *  @file   arctk/math/convert.inl
 *  @date   07/07/2018
 *  @author Freddy Wordingham
 *
 *  Math conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONVERT_INL
#define ARCTK_MATH_CONVERT_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>

//  -- Arctk --
#include <arctk/consts/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace convert //! conversion namespace
        {



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
             *  Convert a two-dimensional cartesian vector to a two-dimensional spherical-polar vector.
             *
             *  @param  cart_   Cartesian vector to convert.
             *
             *  @return Spherical-polar vector.
             */
            template <typename T>
            inline vec2 cart_to_polar(const vec2& cart_) noexcept
            {
                vec2 polar;

                polar.rho   = std::sqrt((cart_.x * cart_.x) + (cart_.y * cart_.y));
                polar.theta = std::atan2(cart_.y, cart_.x);

                return (polar);
            }

            /**
             *  Construct and convert a two-dimensional cartesian vector to a two-dimensional spherical-polar vector.
             *
             *  @param  x_  Value of the x-component.
             *  @param  y_  Value of the y-component.
             *
             *  @return Spherical-polar vector.
             */
            template <typename T>
            inline vec2 cart_to_polar(const T x_, const T y_) noexcept
            {
                return (cart_to_polar(vec2(x_, y_)));
            }

            /**
             *  Convert a three-dimensional cartesian vector to a three-dimensional spherical-polar vector.
             *
             *  @param  cart_   Cartesian vector to convert.
             *
             *  @return Spherical-polar vector.
             */
            template <typename T>
            inline vec3 cart_to_polar(const vec3& cart_) noexcept
            {
                vec3 polar;

                polar.rho   = std::sqrt((cart_.x * cart_.x) + (cart_.y * cart_.y) + (cart_.z * cart_.z));
                polar.theta = std::acos(cart_.z / polar.rho);
                polar.phi   = std::atan2(cart_.y, cart_.x);

                return (polar);
            }

            /**
             *  Construct and convert a three-dimensional cartesian vector to a three-dimensional spherical-polar vector.
             *
             *  @param  x_  Value of the x-component.
             *  @param  y_  Value of the y-component.
             *  @param  z_  Value of the z-component.
             *
             *  @return Spherical-polar vector.
             */
            template <typename T>
            inline vec3 cart_to_polar(const T x_, const T y_, const T z_) noexcept
            {
                return (cart_to_polar(vec3(x_, y_, z_)));
            }

            /**
             *  Convert a two-dimensional spherical-polar vector to a two-dimensional cartesian vector.
             *
             *  @param  polar_  Spherical-polar vector to convert.
             *
             *  @return Cartesian vector.
             */
            template <typename T>
            inline vec2 polar_to_cart(const vec2& polar_) noexcept
            {
                vec2 cart;

                cart.x = polar_.rho * std::sin(polar_.theta);
                cart.y = polar_.rho * std::cos(polar_.theta);

                return (cart);
            }

            /**
             *  Construct and convert a two-dimensional spherical-polar vector to a two-dimensional cartesian vector.
             *
             *  @param  rho_    Value of the rho-component.
             *  @param  theta_  Value of the theta-component.
             *
             *  @pre    rho_ must be non-negative.
             *
             *  @return Cartesian vector.
             */
            template <typename T>
            inline vec2 polar_to_cart(const T rho_, const T theta_) noexcept
            {
                assert(rho_ > 0.0);

                return (polar_to_cart(vec2(rho_, theta_)));
            }

            /**
             *  Convert a three-dimensional spherical-polar vector to a three-dimensional cartesian vector.
             *
             *  @param  polar_  Spherical-polar vector to convert.
             *
             *  @return Cartesian vector.
             */
            template <typename T>
            inline vec3 polar_to_cart(const vec3& polar_) noexcept
            {
                vec3 cart;

                cart.x = polar_.rho * std::sin(polar_.theta) * std::cos(polar_.phi);
                cart.y = polar_.rho * std::sin(polar_.theta) * std::sin(polar_.phi);
                cart.z = polar_.rho * std::cos(polar_.theta);

                return (cart);
            }

            /**
             *  Construct and convert a three-dimensional spherical-polar vector to a three-dimensional cartesian vector.
             *
             *  @param  rho_    Value of the rho-component.
             *  @param  theta_  Value of the theta-component.
             *  @param  phi_    Value of the phi-component.
             *
             *  @pre    rho_ must be non-negative.
             *
             *  @return Cartesian vector.
             */
            template <typename T>
            inline vec3 polar_to_cart(const T rho_, const T theta_, const T phi_) noexcept
            {
                assert(rho_ > 0.0);

                return (polar_to_cart(vec3(rho_, theta_, phi_)));
            }



        } // namespace convert
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERT_INL
