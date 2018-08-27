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
            //  -- Probabilities --
            inline double reflection_prob(double ang_in_, double ref_index_in_, double ref_index_out_) noexcept;
            inline double refraction_prob(double ang_in_, double ref_index_in_, double ref_index_out_) noexcept;


            //  -- Directions --
            inline vec3 reflection_dir(const vec3& in_, const vec3& norm_) noexcept;
            inline vec3 refraction_dir(const vec3& in_, const vec3& norm_, double ref_index_in_, double ref_index_out_) noexcept;



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

            inline double refraction_prob(const double ang_in_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                PRE((ang_in_ >= 0.0) && (ang_in_ < consts::math::HALF_PI));
                PRE(ref_index_in_ >= 1.0);
                PRE(ref_index_out_ >= 1.0);

                return (1.0 - reflection_prob(ang_in_, ref_index_in_, ref_index_out_));
            }


            //  -- Directions --
            inline vec3 reflection_dir(const vec3& in_, const vec3& norm_) noexcept
            {
            }

            inline vec3 refraction_dir(const vec3& in_, const vec3& norm_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                PRE(in_.normalised());
                PRE(norm_.normalised());
                PRE((in_ * norm_) < 0.0);

                const double ref_index_ratio = ref_index_in_ / ref_index_out_;

                const double cos_ang_in     = -(in_ * norm_);
                const double sin_ang_out_sq = math::pow::sq(ref_index_ratio) * (1.0 - math::pow::sq(cos_ang_in));

                const vec3 out = (in_ * ref_index_ratio) + (norm_ * ((ref_index_ratio * cos_ang_in) - std::sqrt(1.0 - sin_ang_out_sq)));

                POST(out.normalised());

                return (out);
            }



        } // namespace optics
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_OPTICS_HPP
