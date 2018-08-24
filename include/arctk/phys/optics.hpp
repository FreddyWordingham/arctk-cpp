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
            inline double reflection_prob(double ang_in_, double ref_index_in_, double ref_index_out_) noexcept;



            //  == FUNCTIONS ==
            //  -- Reflection and Refraction --
            inline double reflection_prob(const double ang_in_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                PRE((ang_in_ >= 0.0) && (ang_in_ < consts::math::HALF_PI));
                PRE(ref_index_in_ >= 1.0);
                PRE(ref_index_out_ >= 1.0);

                const double cos_ang_in  = std::cos(ang_in);
                const double cos_ang_out = std::cos(std::asin(std::sin(ang_in_) * (ref_index_in_ / ref_index_out_)));

                const double ref_prob_s = math::pow::sq(((ref_index_in_ * cos_ang_in) - (ref_index_out_ * cos_ang_out)) / ((ref_index_in_ * cos_ang_in) + (ref_index_out_ * cos_ang_out)));
                const double ref_prob_p = math::pow::sq(((ref_index_in_ * cos_ang_out) - (ref_index_out_ * cos_ang_in)) / ((ref_index_in_ * cos_ang_out) + (ref_index_out_ * cos_ang_in)));

                return (0.5 * (ref_prob_s + ref_prob_p));
            }



        } // namespace optics
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_OPTICS_HPP
