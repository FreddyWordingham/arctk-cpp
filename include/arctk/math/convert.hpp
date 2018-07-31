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



        } // namespace convert
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERT_HPP
