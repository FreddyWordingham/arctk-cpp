/**
 *  @file   arctk/phys/optical.inl
 *  @date   04/12/2018
 *  @author Freddy Wordingham
 *
 *  Physics optical functions.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_OPTICAL_INL
#define ARCTK_PHYS_OPTICAL_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>

//  -- Arctk --
#include <arctk/consts/math.hpp>
#include <arctk/math/pow.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace optical //! optical namespace
        {



            //  == FUNCTIONS ==
            //  -- Reflection and Refraction --
            /**
             *  Determine the probability of a reflection occuring.
             *
             *  @param  ang_in_         Angle of incidence.
             *  @param  ref_index_in_   Refractive index of inbound material.
             *  @param  ref_index_out_  Refractive index of outbound material.
             *
             *  @pre    ang_in_ must be non-negative.
             *  @pre    ang_in_ less than pi.
             *  @pre    ref_index_in_ must be greater than, or equal to, unity.
             *  @pre    ref_index_out_ must be greater than, or equal to, unity.
             *
             *  @post   ref_prob must be non-negative.
             *  @post   ref_prob must be less than, or equal to, unity.
             *
             *  @return Probability of reflection.
             */
            inline double reflection_prob(const double ang_in_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                assert(ang_in_ >= 0.0);
                assert(ang_in_ < consts::math::HALF_PI);
                assert(ref_index_in_ >= 1.0);
                assert(ref_index_out_ >= 1.0);

                if (ref_index_in_ > ref_index_out_)
                {
                    if (ang_in_ >= std::asin(ref_index_out_ / ref_index_in_))
                    {
                        return (1.0);
                    }
                }

                const double cos_ang_in  = std::cos(ang_in_);
                const double cos_ang_out = std::cos(std::asin(std::sin(ang_in_) * (ref_index_in_ / ref_index_out_)));

                const double ref_prob_s = math::pow::sq(((ref_index_in_ * cos_ang_in) - (ref_index_out_ * cos_ang_out)) / ((ref_index_in_ * cos_ang_in) + (ref_index_out_ * cos_ang_out)));
                const double ref_prob_p = math::pow::sq(((ref_index_in_ * cos_ang_out) - (ref_index_out_ * cos_ang_in)) / ((ref_index_in_ * cos_ang_out) + (ref_index_out_ * cos_ang_in)));

                const double ref_prob = 0.5 * (ref_prob_s + ref_prob_p);

                assert(ref_prob >= 0.0);
                assert(ref_prob <= 1.0);

                return (ref_prob);
            }

            /**
             *  Determine the probability of a refraction occuring.
             *
             *  @param  ang_in_         Angle of incidence.
             *  @param  ref_index_in_   Refractive index of inbound material.
             *  @param  ref_index_out_  Refractive index of outbound material.
             *
             *  @pre    ang_in_ must be non-negative.
             *  @pre    ang_in_ less than pi.
             *  @pre    ref_index_in_ must be greater than, or equal to, unity.
             *  @pre    ref_index_out_ must be greater than, or equal to, unity.
             *
             *  @post   ref_prob must be non-negative.
             *  @post   ref_prob must be less than, or equal to, unity.
             *
             *  @return Probability of refraction.
             */
            inline double refraction_prob(const double ang_in_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                assert(ang_in_ >= 0.0);
                assert(ang_in_ < consts::math::HALF_PI);
                assert(ref_index_in_ >= 1.0);
                assert(ref_index_out_ >= 1.0);

                const double ref_prob = 1.0 - reflection_prob(ang_in_, ref_index_in_, ref_index_out_);

                assert(ref_prob >= 0.0);
                assert(ref_prob <= 1.0);

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
             *  @post   Dot product of in_ and norm_ must be negative.
             *
             *  @post   out must be normalised.
             *  @post   Dot product of in_ and out must be positive.
             *
             *  @return Reflection direction.
             */
            inline vec3 reflection_dir(const vec3& in_, const vec3& norm_) noexcept
            {
                assert(in_.normalised());
                assert(norm_.normalised());
                assert((in_ * norm_) < 0.0);

                const vec3 out = (in_ - (norm_ * (2.0 * (in_ * norm_)))).normal();

                assert(out.normalised());
                assert((in_ * out) > 0.0);

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
             *  @post   Dot product of in_ and norm_ must be negative.
             *
             *  @post   out must be normalised.
             *  @post   Dot product of in_ and out must be positive.
             *
             *  @return Refraction direction.
             */
            inline vec3 refraction_dir(const vec3& in_, const vec3& norm_, const double ref_index_in_, const double ref_index_out_) noexcept
            {
                assert(in_.normalised());
                assert(norm_.normalised());
                assert((in_ * norm_) < 0.0);

                const double ref_index_ratio = ref_index_in_ / ref_index_out_;

                const double cos_ang_in     = -(in_ * norm_);
                const double sin_ang_out_sq = math::pow::sq(ref_index_ratio) * (1.0 - math::pow::sq(cos_ang_in));

                const vec3 out = (in_ * ref_index_ratio) + (norm_ * ((ref_index_ratio * cos_ang_in) - std::sqrt(1.0 - sin_ang_out_sq)));

                assert(out.normalised());
                assert((in_ * out) > 0.0);

                return (out);
            }



        } // namespace optical
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_OPTICAL_INL
