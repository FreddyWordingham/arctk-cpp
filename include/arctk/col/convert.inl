/**
 *  @file   arctk/col/convert.inl
 *  @date   17/10/2018
 *  @author Freddy Wordingham
 *
 *  Colour conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_COL_CONVERT_INL
#define ARCTK_COL_CONVERT_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace col //! colour namespace
    {
        namespace convert //! convertsion namespace
        {



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
             *  @pre    sat_ must be non-negative.
             *  @pre    sat_ must be less than, or equal to, unity.
             *  @pre    val_ must be non-negative.
             *  @pre    val_ must be less than, or equal to, unity.
             *
             *  @return RGB equivalent of the HSV value.
             */
            inline vec3 hsv_to_rgb(double hue_, const double sat_, const double val_) noexcept
            {
                assert(sat_ >= 0.0);
                assert(sat_ <= 1.0);
                assert(val_ >= 0.0);
                assert(val_ <= 1.0);

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



        } // namespace convert
    }     // namespace col
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_COL_CONVERT_INL
