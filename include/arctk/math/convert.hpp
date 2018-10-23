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
#include <arctk/math/vec2.hpp>
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
            inline vec2 cart_to_polar(const vec2& cart_) noexcept;
            template <typename T>
            inline vec2 cart_to_polar(T x_, T y_) noexcept;
            template <typename T>
            inline vec3 cart_to_polar(const vec3& cart_) noexcept;
            template <typename T>
            inline vec3 cart_to_polar(T x_, T y_, T z_) noexcept;
            template <typename T>
            inline vec2 polar_to_cart(const vec2& polar_) noexcept;
            template <typename T>
            inline vec2 polar_to_cart(T rho_, T theta_) noexcept;
            template <typename T>
            inline vec3 polar_to_cart(const vec3& polar_) noexcept;
            template <typename T>
            inline vec3 polar_to_cart(T rho_, T theta_, T phi_) noexcept;



        } // namespace convert
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERT_HPP
