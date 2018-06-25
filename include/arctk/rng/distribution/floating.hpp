/**
 *  @file   arctk/rng/distribution/floating.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Floating point random number distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_FLOAT_HPP
#define ARCTK_RNG_DISTRIBUTION_FLOAT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/constant.hpp>
#include <arctk/math.hpp>
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! utility namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Floating Point --
            template <typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
            inline T      uniform_floating(Generator& rng_, const T min_, const T max_) noexcept;
            inline double henyey_greenstein(Generator& rng_, double g_) noexcept;


            //  == FUNCTIONS ==
            //  -- Floating Point --
            template <typename T, typename>
            inline T uniform_floating(Generator& rng_, const T min_, const T max_) noexcept
            {
                assert(min_ < max_);

                return ((static_cast<T>(rng_.gen()) * (max_ - min_)) + min_);
            }

            inline double henyey_greenstein(Generator& rng_, const double g_) noexcept
            {
                assert((g_ >= -1.0) && (g_ <= 1.0));

                if (math::is_zero(g_))
                {
                    return (uniform_floating<double>(rng_, 0.0, constant::PI));
                }

                const double s = uniform_floating<double>(rng_, -1.0, 1.0);
                return ((1.0 + math::sq(g_) - math::sq((1.0 - math::sq(g_)) / (1.0 + (g_ * s)))) / (2.0 * g_));
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_FLOAT_HPP
