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
//  -- Arctk --
#include <arctk/constant.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Angle --
        inline double rad_to_deg(double val_) noexcept;
        inline double deg_to_rad(double val_) noexcept;



        //  == FUNCTIONS ==
        //  -- Angle --
        /**
         *  Convert a value in radians to a value in degrees.
         *
         *  @param  val_  Value to convert to radians.
         *
         *  @return Value in degrees.
         */
        inline double rad_to_deg(const double val_) noexcept
        {
            return (180.0 / constant::PI * val_);
        }

        /**
         *  Convert a value in degrees to a value in radians.
         *
         *  @param  val_  Value to convert to degrees.
         *
         *  @return Value in radians.
         */
        inline double deg_to_rad(const double val_) noexcept
        {
            return (constant::PI / 180.0 * val_);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERSION_HPP
