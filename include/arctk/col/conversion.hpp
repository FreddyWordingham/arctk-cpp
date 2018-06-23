/**
 *  @file   arctk/col/conversion.hpp
 *  @date   23/06/2018
 *  @author Freddy Wordingham
 *
 *  Colour conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_COL_CONVERSION_HPP
#define ARCTK_COL_CONVERSION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>

//  -- Arctk --
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace col //! colour namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- HSV --
        inline vec3 hsv_to_rgb(double hue_, double sat_, double val_) noexcept;



        //  == FUNCTIONS ==
        //  -- HSV --
        /**
         *  Convert a HSV colour to its RGB equivalent.
         *  Hue values are modulated to fall between zero and 360.0 degrees.
         *
         *  @param  hue_    Colour hue.
         *  @param  sat_    Colour saturation.
         *  @param  val_    Colour value.
         *
         *  @pre    sat_ must be between zero and one.
         *  @pre    val_ must be between zero and one.
         *
         *  @return RGB equivalent of the HSV value.
         */
        inline vec3 hsv_to_rgb(double hue_, const double sat_, const double val_) noexcept
        {
            assert((sat_ >= 0.0) && (sat_ <= 1.0));
            assert((val_ >= 0.0) && (val_ <= 1.0));

            hue_ = std::fmod(hue_, 360.0);

            const double c = val_ * sat_;
            const double h = hue_ / 60.0;
            const double x = c * (1.0 - std::abs(std::fmod(h, 2.0) - 1.0));

            vec3 col;

            if ((h >= 0.0) && (h < 1.0))
            {
                col.r = c;
                col.g = x;
            }
            else if ((h >= 1.0) && (h < 2.0))
            {
                col.r = x;
                col.g = c;
            }
            else if ((h >= 2.0) && (h < 3.0))
            {
                col.g = c;
                col.b = x;
            }
            else if ((h >= 3.0) && (h < 4.0))
            {
                col.g = x;
                col.b = c;
            }
            else if ((h >= 4.0) && (h < 5.0))
            {
                col.r = x;
                col.b = c;
            }
            else
            {
                col.r = c;
                col.b = x;
            }

            return (col + (val_ - c));
        }



    } // namespace col
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_COL_CONVERSION_HPP
