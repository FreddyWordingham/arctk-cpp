/**
 *  @file   arctk/phys/optics.hpp
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Optical physics functions.
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
            /**
             *  Determine the probability of a reflection occuring.
             *
             *  @param  ang_in_         Angle of incidence.
             *  @param  ref_index_in_   Refractive index of inbound material.
             *  @param  ref_index_out_  Refractive index of outbound material.
             *
             *  @pre    ang_in_ must between zero and half Pi.
             *  @pre    ref_index_in_ must be greater than, or equal to, unity.
             *  @pre    ref_index_out_ must be greater than, or equal to, unity.
             *
             *  @post   ref_prob must be between zero and unity.
             *
             *  @return Probability of reflection.
             */
            inline double reflection_prob(const double ang_in_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                PRE((ang_in_ >= 0.0) && (ang_in_ < consts::math::HALF_PI));
                PRE(ref_index_in_ >= 1.0);
                PRE(ref_index_out_ >= 1.0);

                const double cos_ang_in  = std::cos(ang_in_);
                const double cos_ang_out = std::cos(std::asin(std::sin(ang_in_) * (ref_index_in_ / ref_index_out_)));

                const double ref_prob_s = math::pow::sq(((ref_index_in_ * cos_ang_in) - (ref_index_out_ * cos_ang_out)) / ((ref_index_in_ * cos_ang_in) + (ref_index_out_ * cos_ang_out)));
                const double ref_prob_p = math::pow::sq(((ref_index_in_ * cos_ang_out) - (ref_index_out_ * cos_ang_in)) / ((ref_index_in_ * cos_ang_out) + (ref_index_out_ * cos_ang_in)));

                const double ref_prob = 0.5 * (ref_prob_s + ref_prob_p);

                POST((ref_prob >= 0.0) && (ref_prob <= 1.0));

                return (ref_prob);
            }

            /**
             *  Determine the probability of a refraction occuring.
             *
             *  @param  ang_in_         Angle of incidence.
             *  @param  ref_index_in_   Refractive index of inbound material.
             *  @param  ref_index_out_  Refractive index of outbound material.
             *
             *  @pre    ang_in_ must between zero and half Pi.
             *  @pre    ref_index_in_ must be greater than, or equal to, unity.
             *  @pre    ref_index_out_ must be greater than, or equal to, unity.
             *
             *  @post   ref_prob must be between zero and unity.
             *
             *  @return Probability of refraction.
             */
            inline double refraction_prob(const double ang_in_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                PRE((ang_in_ >= 0.0) && (ang_in_ < consts::math::HALF_PI));
                PRE(ref_index_in_ >= 1.0);
                PRE(ref_index_out_ >= 1.0);

                const double ref_prob = 1.0 - reflection_prob(ang_in_, ref_index_in_, ref_index_out_);

                POST((ref_prob >= 0.0) && (ref_prob <= 1.0));

                return (ref_prob);
            }


            //  -- Directions --
            /**
             *  Determine the direction of reflection.
             *
             *  @param  in_     Incident direction.
             *  @param  norm_   Surface normal.
             *
             *  @pre    in_ must be normalised.
             *  @pre    norm_ must be normalised.
             *  @pre    Dot product of in_ and norm_ must be negative.
             *
             *  @post   out must be normalised.
             *
             *  @return Reflection direction.
             */
            inline vec3 reflection_dir(const vec3& in_, const vec3& norm_) noexcept
            {
                PRE(in_.normalised());
                PRE(norm_.normalised());
                PRE((in_ * norm_) < 0.0);

                const vec3 out = (in_ - (norm_ * (2.0 * (in_ * norm_)))).normal();

                POST(out.normalised());

                return (out);
            }

            /**
             *  Determine the direction of refraction.
             *
             *  @param  in_             Incident direction.
             *  @param  norm_           Surface normal.
             *  @param  ref_index_in_   Refractive index of inbound material.
             *  @param  ref_index_out_  Refractive index of outbound material.
             *
             *  @pre    in_ must be normalised.
             *  @pre    norm_ must be normalised.
             *  @pre    Dot product of in_ and norm_ must be negative.
             *
             *  @post   out must be normalised.
             *
             *  @return Refraction direction.
             */
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
