/**
 *  @file   arctk/random/distribution/henyey_greenstein.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Henyey-Greenstein phase function sampling.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_HENYEYGREENSTEIN_HPP
#define ARCTK_RANDOM_DISTRIBUTION_HENYEYGREENSTEIN_HPP



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
            namespace henyey_greenstein //! Henyey-Greenstein namespace
            {



                //  == FUNCTION PROTOTYPES ==
                //  -- Distribution --
                inline double phase(Generator* rng_, double g_) noexcept;



                //  == FUNCTIONS ==
                //  -- Distribution --
                inline double phase(Generator* rng_, const double g_) noexcept
                {
                    return ((1.0 + (g_ * g_) - math::pow::sq((1.0 - (g_ * g_)) / (1.0 + (g_ * rng->gen())))) / (2.0 * g_));
                }



            } // namespace henyey_greenstein
        }     // namespace distribution
    }         // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_HENYEYGREENSTEIN_HPP
