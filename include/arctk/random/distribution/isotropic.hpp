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
                inline double sample(Generator* rng_) noexcept;



                //  == FUNCTIONS ==
                //  -- Distribution --
                inline double sample(Generator* rng_) noexcept
                {
                    return ((1.0 + (g_ * g_) - math::pow::sq((1.0 - (g_ * g_)) / (1.0 + (g_ * rng->gen())))) / (2.0 * g_));
                }



            } // namespace isotropic
        }     // namespace distribution
    }         // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_ISOTROPIC_HPP
