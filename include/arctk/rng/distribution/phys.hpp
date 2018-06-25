/**
 *  @file   arctk/rng/distribution/phys.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Physics transformation distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_SCIENTIFIC_HPP
#define ARCTK_RNG_DISTRIBUTION_SCIENTIFIC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
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
            //  -- Henyey-Greenstein --
            inline double henyey_greenstein(Generator& rng_, double g_) noexcept;



            //  == FUNCTIONS ==
            //  -- Henyey-Greenstein --
            inline double henyey_greenstein(Generator& rng_, const double g_) noexcept
            {
                assert((g_ >= -1.0) && (g_ <= 1.0));

                if (math::is_zero(g_))
                {
                    return (uniform<double>(rng_, 0.0, constant::PI));
                }

                const double s = uniform<double>(rng_, -1.0, 1.0);
                return ((1.0 + math::sq(g_) - math::sq((1.0 - math::sq(g_)) / (1.0 + (g_ * s)))) / (2.0 * g_));
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_SCIENTIFIC_HPP
