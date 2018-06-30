/**
 *  @file   arctk/rng/distribution/phys.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Physics transformation distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_PHYS_HPP
#define ARCTK_RNG_DISTRIBUTION_PHYS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/rng/distribution/uniform.hpp>
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! utility namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Scattering --
            inline vec3   isotropic(Generator* const rng_) noexcept;
            inline double henyey_greenstein(Generator* rng_, double g_) noexcept;



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
                const double theta = arc::rng::distribution::uniform<double>(rng_, 0.0, 2.0 * arc::constant::PI);
                const double z     = arc::rng::distribution::uniform<double>(rng_, -1.0, 1.0);

                return (vec3(std::sqrt(1.0 - arc::math::sq(z)) * std::cos(theta), std::sqrt(1.0 - arc::math::sq(z)) * std::sin(theta), z));
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
                assert((g_ >= -1.0) && (g_ <= 1.0));

                const double s = uniform<double>(rng_, -1.0, 1.0);

                if (math::zero(g_))
                {
                    return (s);
                }

                return ((1.0 + math::sq(g_) - math::sq((1.0 - math::sq(g_)) / (1.0 + (g_ * s)))) / (2.0 * g_));
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_PHYS_HPP
