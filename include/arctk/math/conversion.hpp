/**
 *  @file   arctk/math/conversion.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Math conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONVERSION_HPP
#define ARCTK_MATH_CONVERSION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/constant.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Angle --
        template <typename T>
        inline T rad_to_deg(T val_) noexcept;
        template <typename T>
        inline T deg_to_rad(T val_) noexcept;

        //  -- Co-ordinate --
        template <typename T>
        inline T polar_to_cart(const Vec2<T>& polar_) noexcept;



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
            return (static_cast<T>(180.0 / constant::PI) * val_);
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
            return (static_cast<T>(constant::PI / 180.0) * val_);
        }


        //  -- Co-ordinate --
        template <typename T>
        inline T polar_to_cart(const Vec2<T>& polar_) noexcept
        {
            return (Vec2<T>(polar_.rho * std::cos(polar_.theta), polar_.rho * std::sin(polar_.theta)));
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERSION_HPP
