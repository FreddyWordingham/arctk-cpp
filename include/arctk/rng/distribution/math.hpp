/**
 *  @file   arctk/rng/distribution/mathematical.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Math transformation distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_MATHEMATICAL_HPP
#define ARCTK_RNG_DISTRIBUTION_MATHEMATICAL_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! utility namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Guassian --
            template <typename T>
            inline T normal(Generator& rng_) noexcept;
            template <typename T>
            inline T guassian(Generator& rng_, const T mu_, const T sigma_) noexcept;



            //  == FUNCTIONS ==
            //  -- Guassian --
            template <>
            inline double normal(Generator& rng_) noexcept
            {
                static bool   generate = false;
                static double z1;

                generate = !generate;
                if (!generate)
                {
                    return (z1);
                }

                const double u0 = rng_.gen();
                const double u1 = rng_.gen();

                const double m  = std::sqrt(-2.0 * std::log(u0));
                const double z0 = m * std::cos(2.0 * constant::PI * u1);
                z1              = m * std::sin(2.0 * constant::PI * u1);

                return (z0);
            }

            template <>
            inline double guassian(Generator& rng_, const double mu_, const double sigma_) noexcept
            {
                static bool   generate = false;
                static double z1;

                generate = !generate;
                if (!generate)
                {
                    return ((z1 * sigma_) + mu_);
                }

                const double u0 = rng_.gen();
                const double u1 = rng_.gen();

                const double m  = std::sqrt(-2.0 * std::log(u0));
                const double z0 = m * std::cos(2.0 * constant::PI * u1);
                z1              = m * std::sin(2.0 * constant::PI * u1);

                return ((z0 * sigma_) + mu_);
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_MATHEMATICAL_HPP
