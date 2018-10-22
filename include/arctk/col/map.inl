/**
 *  @file   arctk/col/map.inl
 *  @date   17/10/2018
 *  @author Freddy Wordingham
 *
 *  Colour mapping functions.
 */



//  == GUARD ==
#ifndef ARCTK_COL_MAP_INL
#define ARCTK_COL_MAP_INL



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <cmath>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace col //! colour namespace
    {
        namespace map //! mapping namespace
        {



            //  == FUNCTIONS ==
            //  -- Matlab --
            /**
             *  Convert a scalar value between zero and one to a Matlab jet colour.
             *
             *  @param  x_  Scalar value to convert to a colour.
             *
             *  @pre    x_ must be non-negative.
             *  @pre    x_ must be less than unity.
             *
             *  @return Colour vec.
             */
            inline vec3 jet(const double x_) noexcept
            {
                assert(x_ >= 0.0);
                assert(x_ <= 1.0);

                vec3 col;

                if (x_ < 0.7)
                {
                    col.r = std::clamp((4.0 * x_) - 1.5, 0.0, 1.0);
                }
                else
                {
                    col.r = std::clamp((-4.0 * x_) + 4.5, 0.0, 1.0);
                }

                if (x_ < 0.5)
                {
                    col.g = std::clamp((4.0 * x_) - 0.5, 0.0, 1.0);
                }
                else
                {
                    col.g = std::clamp((-4.0 * x_) + 3.5, 0.0, 1.0);
                }

                if (x_ < 0.3)
                {
                    col.b = std::clamp((4.0 * x_) + 0.5, 0.0, 1.0);
                }
                else
                {
                    col.b = std::clamp((-4.0 * x_) + 2.5, 0.0, 1.0);
                }

                return (col);
            }

            /**
             *  Convert a scalar value between zero and one to a Matlab jet colour.
             *  Colour will be set to black when x_ % 0.1 < 0.01.
             *
             *  @param  x_  Scalar value to convert to a colour.
             *
             *  @pre    x_ must be non-negative.
             *  @pre    x_ must be less than unity.
             *
             *  @return Colour vec.
             */
            inline vec3 jet_line(const double x_) noexcept
            {
                assert(x_ >= 0.0);
                assert(x_ <= 1.0);

                if (std::fmod(x_, 0.1) < 0.01)
                {
                    return (vec3(0.0, 0.0, 0.0));
                }

                return (jet(x_));
            }

            /**
             *  Convert a scalar value between zero and one to a Matlab jet colour scale with discrete steps.
             *
             *  @param  x_      Scalar value to convert to a colour.
             *  @param  num_    Number of colour steps.
             *
             *  @pre    x_ must be non-negative.
             *  @pre    x_ must be less than unity.
             *  @pre    num_ must be positive.
             *
             *  @return Colour vec.
             */
            inline vec3 jet_block(const double x_, const unsigned int num_) noexcept
            {
                assert(x_ >= 0.0);
                assert(x_ <= 1.0);
                assert(num_ > 0);

                return (jet(x_ - std::fmod(x_, 1.0 / static_cast<double>(num_))));
            }



        } // namespace map
    }     // namespace col
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_COL_MAP_INL
