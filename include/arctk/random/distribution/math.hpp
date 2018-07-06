/**
 *  @file   arctk/random/distribution/math.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_MATH_HPP
#define ARCTK_RANDOM_DISTRIBUTION_MATH_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! utility namespace
    {
        namespace distribution //! distribution namespace
        {
            namespace math //! mathematics namespace
            {



                //  == FUNCTION PROTOTYPES ==
                //  -- Uniform --
                template <typename T>
                inline T uniform(Generator* rng_, T min_, T max_) noexcept; //!< Generate a random value between given limits. @tparam T   Type of value to generate. @param  rng_    Generator used to draw base values from. @param  min_    Lower bound of
                                                                            //!< the genration range. @param  max_    Upper bound of the genration range. @pre    min_ must be less than max_. @return Random uniform value.


                //  -- Gaussian --
                template <typename T>
                inline T normal(Generator* rng_) noexcept; //!< Generate a random number drawn from the normal distribution. @tparam T Type to draw from normal distribution. @param  rng_    Generator used to draw base values from. @return Value randomly
                                                           //!< drawn from normal distribution.
                template <typename T>
                inline T guassian(Generator* rng_, T mu_,
                                  T sigma_) noexcept; //!< Generate a random number drawn from a gaussian distribution.  @tparam T Type to draw from guassian distribution. @param  rng_    Generator used to draw base values from. @param mu_     Average
                                                      //!< value of the gaussian distribution. @param  sigma_  Variance of the gaussian distribution. @return Value randomly drawn from the gaussian distribution.



                //  == FUNCTIONS ==
                //  -- Uniform --
                /**
                 *  Generate a random value between given limits.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  min_    Lower bound of the genration range.
                 *  @param  max_    Upper bound of the genration range.
                 *
                 *  @pre    min_ must be less than max_.
                 *
                 *  @return Random uniform value.
                 */
                template <>
                inline size_t uniform(Generator* const rng_, const size_t min_, const size_t max_) noexcept
                {
                    PRE(min_ < max_);

                    return (static_cast<size_t>(rng_->gen() * static_cast<double>(max_ - min_ + 1)) + min_);
                }

                /**
                 *  Generate a random value between given limits.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  min_    Lower bound of the genration range.
                 *  @param  max_    Upper bound of the genration range.
                 *
                 *  @pre    min_ must be less than max_.
                 *
                 *  @return Random uniform value.
                 */
                template <>
                inline int uniform(Generator* const rng_, const int min_, const int max_) noexcept
                {
                    PRE(min_ < max_);

                    return (static_cast<int>(rng_->gen() * static_cast<double>(max_ - min_ + 1)) + min_);
                }

                /**
                 *  Generate a random value between given limits.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  min_    Lower bound of the genration range.
                 *  @param  max_    Upper bound of the genration range.
                 *
                 *  @pre    min_ must be less than max_.
                 *
                 *  @return Random uniform value.
                 */
                template <>
                inline double uniform(Generator* const rng_, const double min_, const double max_) noexcept
                {
                    PRE(min_ < max_);

                    return ((rng_->gen() * (max_ - min_)) + min_);
                }


                //  -- Gaussian --
                /**
                 *  Generate a random number drawn from the normal distribution.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *
                 *  @return Value randomly drawn from normal distribution.
                 */
                template <>
                inline double normal(Generator* const rng_) noexcept
                {
                    static bool   static_generate = false;
                    static double static_z1;

                    static_generate = !static_generate;
                    if (!static_generate)
                    {
                        return (static_z1);
                    }

                    const double u0 = rng_->gen();
                    const double u1 = rng_->gen();

                    const double m  = std::sqrt(-2.0 * std::log(u0));
                    const double z0 = m * std::cos(2.0 * constant::math::PI * u1);
                    static_z1       = m * std::sin(2.0 * constant::math::PI * u1);

                    return (z0);
                }

                /**
                 *  Generate a random number drawn from a gaussian distribution.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  mu_     Average value of the gaussian distribution.
                 *  @param  sigma_  Variance of the gaussian distribution.
                 *
                 *  @pre    sigma_ must be positive.
                 *
                 *  @return Value randomly drawn from the gaussian distribution.
                 */
                template <>
                inline double guassian(Generator* const rng_, const double mu_, const double sigma_) noexcept
                {
                    PRE(sigma_ > 0.0);

                    static bool   static_generate = false;
                    static double static_z1;

                    static_generate = !static_generate;
                    if (!static_generate)
                    {
                        return ((static_z1 * sigma_) + mu_);
                    }

                    const double u0 = rng_->gen();
                    const double u1 = rng_->gen();

                    const double m  = std::sqrt(-2.0 * std::log(u0));
                    const double z0 = m * std::cos(2.0 * constant::math::PI * u1);
                    static_z1       = m * std::sin(2.0 * constant::math::PI * u1);

                    return ((z0 * sigma_) + mu_);
                }



            } // namespace math
        }     // namespace distribution
    }         // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_MATH_HPP
