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
        namespace convert //! conversion namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Angle --
            template <typename T>
            inline T rad_to_deg(T val_) noexcept;
            template <typename T>
            inline T deg_to_rad(T val_) noexcept;

            //  -- Co-ordinate --
            template <typename T>
            inline Vec<T, 2> cart_to_polar(const Vec<T, 2>& cart_) noexcept;
            template <typename T>
            inline Vec<T, 2> cart_to_polar(const T x_, const T y_) noexcept;
            template <typename T>
            inline Vec<T, 3> cart_to_polar(const Vec<T, 3>& cart_) noexcept;
            template <typename T>
            inline Vec<T, 3> cart_to_polar(const T x_, const T y_, const T z_) noexcept;
            template <typename T>
            inline Vec<T, 2> polar_to_cart(const Vec<T, 2>& polar_) noexcept;
            template <typename T>
            inline Vec<T, 2> polar_to_cart(const T rho_, const T theta_) noexcept;
            template <typename T>
            inline Vec<T, 3> polar_to_cart(const Vec<T, 3>& polar_) noexcept;
            template <typename T>
            inline Vec<T, 3> polar_to_cart(const T rho_, const T theta_, const T phi_) noexcept;



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
            inline Vec<T, 2> cart_to_polar(const Vec<T, 2>& cart_) noexcept
            {
                Vec<T, 2> polar;

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
            inline Vec<T, 2> cart_to_polar(const T x_, const T y_) noexcept
            {
                return (cart_to_polar(Vec<T, 2>(x_, y_)));
            }

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
            inline Vec<T, 3> cart_to_polar(const T x_, const T y_, const T z_) noexcept
            {
                return (cart_to_polar(Vec<T, 3>(x_, y_, z_)));
            }

            /**
             *  Convert a two-dimensional spherical-polar vector to a two-dimensional cartesian vector.
             *
             *  @param  polar_  Spherical-polar vector to convert.
             *
             *  @return Cartesian vector.
             */
            template <typename T>
            inline Vec<T, 2> polar_to_cart(const Vec<T, 2>& polar_) noexcept
            {
                Vec<T, 2> cart;

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
            inline Vec<T, 2> polar_to_cart(const T rho_, const T theta_) noexcept
            {
                PRE(rho_ > 0.0);

                return (polar_to_cart(Vec<T, 2>(rho_, theta_)));
            }

            /**
             *  Convert a three-dimensional spherical-polar vector to a three-dimensional cartesian vector.
             *
             *  @param  polar_  Spherical-polar vector to convert.
             *
             *  @return Cartesian vector.
             */
            template <typename T>
            inline Vec<T, 3> polar_to_cart(const Vec<T, 3>& polar_) noexcept
            {
                Vec<T, 3> cart;

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
            inline Vec<T, 3> polar_to_cart(const T rho_, const T theta_, const T phi_) noexcept
            {
                PRE(rho_ > 0.0);

                return (polar_to_cart(Vec<T, 3>(rho_, theta_, phi_)));
            }



        } // namespace convert
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERT_HPP
