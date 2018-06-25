/**
 *  @file   arctk/rng/distribution/math.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Math transformation distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_MATH_HPP
#define ARCTK_RNG_DISTRIBUTION_MATH_HPP



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
            inline T normal(Generator& rng_) noexcept; //!< Generate a random number drawn from the normal distribution. @tparam T Type to draw from normal distribution. @param  rng_    Generator used to draw base values from. @return Value randomly drawn
                                                       //!< from normal distribution.
            template <typename T>
            inline T guassian(Generator& rng_, const T mu_,
                              const T sigma_) noexcept; //!< Generate a random number drawn from a gaussian distribution.  @tparam T Type to draw from guassian distribution. @param  rng_    Generator used to draw base values from. @param  mu_     Average
                                                        //!< value of the gaussian distribution. @param  sigma_  Variance of the gaussian distribution. @return Value randomly drawn from the gaussian distribution.



            //  == FUNCTIONS ==
            //  -- Guassian --
            /**
             *  Generate a random number drawn from the normal distribution.
             *
             *  @param  rng_    Generator used to draw base values from.
             *
             *  @return Value randomly drawn from normal distribution.
             */
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

            /**
             *  Generate a random number drawn from a gaussian distribution.
             *
             *  @param  rng_    Generator used to draw base values from.
             *  @param  mu_     Average value of the gaussian distribution.
             *  @param  sigma_  Variance of the gaussian distribution.
             *
             *  @return Value randomly drawn from the gaussian distribution.
             */
            template <>
            inline double guassian(Generator& rng_, const double mu_, const double sigma_) noexcept
            {
                assert(sigma_ > 0.0);

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
#endif // ARCTK_RNG_DISTRIBUTION_MATH_HPP
