/**
 *  @file   arctk/random/distribution/phys.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Physics distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_PHYS_HPP
#define ARCTK_RANDOM_DISTRIBUTION_PHYS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/random/distribution/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! utility namespace
    {
        namespace distribution //! distribution namespace
        {
            namespace phys //! physics namespace
            {



                //  == FUNCTION PROTOTYPES ==
                //  -- Scattering --
                inline vec3   isotropic(Generator* const rng_) noexcept;
                inline double henyey_greenstein(Generator* const rng_, double g_) noexcept;



                //  == FUNCTIONS ==
                //  -- Scattering --
                /**
                 *  Generate a random isotropic unit vector.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *
                 *  @return Random isotropic unit vector.
                 */
                inline vec3 isotropic(Generator* const rng_) noexcept
                {
                    const double theta = random::distribution::math::uniform<double>(rng_, 0.0, 2.0 * consts::math::PI);
                    const double z     = random::distribution::math::uniform<double>(rng_, -1.0, 1.0);

                    return (vec3(std::sqrt(1.0 - math::pow::sq(z)) * std::cos(theta), std::sqrt(1.0 - math::sq(z)) * std::sin(theta), z));
                }

                /**
                 *  Draw a value from the Henyey-Greenstein phase function.
                 *  Function description can be found at: https://www.astro.umd.edu/~jph/HG_note.pdf
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  g_      Asymmetry-parameter.
                 *
                 *  @pre    g_ must be between -1.0 and +1.0 inclusively.
                 *
                 *  @return Angle drawn from Henyey-Greenstein phase function.
                 */
                inline double henyey_greenstein(Generator* const rng_, const double g_) noexcept
                {
                    PRE((g_ >= -1.0) && (g_ <= 1.0));

                    const double s = math::uniform<double>(rng_, -1.0, 1.0);

                    if (math::compare::zero(g_))
                    {
                        return (s);
                    }

                    return ((1.0 + math::pow::sq(g_) - math::pow::sq((1.0 - math::pow::sq(g_)) / (1.0 + (g_ * s)))) / (2.0 * g_));
                }



            } // namespace phys
        }     // namespace distribution
    }         // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_PHYS_HPP
