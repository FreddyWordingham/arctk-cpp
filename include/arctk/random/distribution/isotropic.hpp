/**
 *  @file   arctk/random/distribution/isotropic.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Isotropic direction function sampling.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_ISOTROPIC_HPP
#define ARCTK_RANDOM_DISTRIBUTION_ISOTROPIC_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {
            namespace isotropic //! isotropic namespace
            {



                //  == FUNCTION PROTOTYPES ==
                //  -- Distribution --
                inline vec3 sample(Generator* rng_) noexcept;



                //  == FUNCTIONS ==
                //  -- Distribution --
                /**
                 *  Sample an isotropic unit vector.
                 *
                 *  @param  rng_    Random number generator.
                 *
                 *  @return Sampled isotropic unit vector.
                 */
                inline vec3 sample(Generator* rng_) noexcept
                {
                    const double phi   = rng_->gen() * 2.0 * consts::math::PI;
                    const double theta = std::acos((rng_->gen() * 2.0) - 1.0);

                    return (math::convert::polar_to_cart(vec3(1.0, theta, phi)));
                }



            } // namespace isotropic
        }     // namespace distribution
    }         // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_ISOTROPIC_HPP
