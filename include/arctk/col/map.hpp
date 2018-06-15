/**
 *  @file   arctk/col/map.hpp
 *  @date   15/06/2018
 *  @author Freddy Wordingham
 *
 *  Colour mapping functions.
 */



//  == GUARD ==
#ifndef ARCTK_COL_MAP_HPP
#define ARCTK_COL_MAP_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <algorithm>

//  -- Arctk --
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace col //! colour namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Matlab --
        inline vec3 jet(double x_) noexcept;



        //  == FUNCTIONS ==
        //  -- Matlab --
        inline vec3 jet(const double x_) noexcept
        {
            assert((x_ >= 0.0) && (x_ <= 1.0));

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



    } // namespace col
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_COL_MAP_HPP
