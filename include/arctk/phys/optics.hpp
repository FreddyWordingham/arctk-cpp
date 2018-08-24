/**
 *  @file   arctk/phys/optics.hpp
 *  @date   24/08/2018
 *  @author Freddy Wordingham
 *
 *  Optical physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_OPTICS_HPP
#define ARCTK_PHYS_OPTICS_HPP



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace optics //! optical namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Reflection and Refraction --
            inline double reflection_prob(double incident_ang_, double ref_index_in_, double ref_index_out_) noexcept;



            //  == FUNCTIONS ==
            //  -- Reflection and Refraction --
            inline double reflection_prob(const double incident_ang_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                PRE((incident_ang_ >= 0.0) && (incident_ang_ < consts::math::HALF_PI));
                PRE(ref_index_in_ >= 1.0);
                PRE(ref_index_out_ >= 1.0);
            }



        } // namespace optics
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_OPTICS_HPP
