/**
 *  @file   arctk/random/distribution.inl
 *  @date   13/07/2018
 *  @author Freddy Wordingham
 *
 *  Probability distribution base class used to sample random numbers.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_INL
#define ARCTK_RANDOM_DISTRIBUTION_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>
#include <type_traits>

//  -- Arctk --
#include <arctk/consts/math.hpp>
#include <arctk/math/compare.hpp>
#include <arctk/math/convert.hpp>
#include <arctk/math/pow.hpp>
#include <arctk/random/generator.hpp>
#include <arctk/type/temp.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a distribution which will sample values between given bounds.
         *
         *  @param  min_    Minimum possible sampled value.
         *  @param  max_    Maximum possible sampled value.
         *
         *  @pre    min_ must be less than max_.
         */
        template <typename T>
        inline Distribution<T>::Distribution(T min_, T max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            assert(min_ < max_);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the distribution sampling range.
         *
         *  @return Minimum bound of the distribution sampling range.
         */
        template <typename T>
        inline T Distribution<T>::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum bound of the distribution sampling range.
         *
         *  @return Maximum bound of the distribution sampling range.
         */
        template <typename T>
        inline T Distribution<T>::max() const noexcept
        {
            return (_max);
        }



        namespace distribution //! distribution namespace
        {



            //  == FUNCTIONS ==
            //  -- Sampling --
            /**
             *  Generate a random number sampled from a uniform distribution between zero and a maximum bound.
             *
             *  @tparam T   Type to be uniformly generated.
             *
             *  @param  rng_    Random number generator.
             *  @param  max_    Maximum bound of the generated value.
             *
             *  @pre    T   Must be an arithmetic type.
             *  @pre    rng_ may not be nullptr.
             *  @pre    max_ must be positive.
             *
             *  @return Random number sampled from a uniform distribution.
             */
            template <typename T>
            inline T uniform(Generator* const rng_, const T max_) noexcept // NOLINT
            {
                static_assert(std::is_arithmetic<T>::value);
                assert(rng_ != nullptr);
                assert(max_ > 0.0);

                if constexpr (std::is_integral<T>::value) // NOLINT
                {                                         // NOLINT
                    return (std::floor(rng_->gen() * (max_ + 1)));
                }

                return (rng_->gen() * max_); // NOLINT
            }

            /**
             *  Generate a random number sampled from a uniform distribution between given minimum and maximum bounds.
             *
             *  @tparam T   Type to be uniformly generated.
             *
             *  @param  rng_    Random number generator.
             *  @param  min_    Minimum bound of the generated value.
             *  @param  max_    Maximum bound of the generated value.
             *
             *  @pre    T   Must be an arithmetic type.
             *  @pre    rng_ may not be nullptr.
             *  @pre    min_ must be less than max_.
             *
             *  @return Random number sampled from a uniform distribution.
             */
            template <typename T>
            inline T uniform(Generator* const rng_, const T min_, const T max_) noexcept // NOLINT
            {
                static_assert(std::is_arithmetic<T>::value);
                assert(rng_ != nullptr);
                assert(min_ < max_);

                if constexpr (std::is_integral<T>::value) // NOLINT
                {                                         // NOLINT
                    return (std::floor((rng_->gen() * (max_ - min_ + 1)) + min_));
                }

                return ((rng_->gen() * (max_ - min_)) + min_); // NOLINT
            }

            /**
             *  Generate a random number sampled from a uniform normal distribution.
             *
             *  @tparam T   Type to be uniformly generated.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    T   Must be an arithmetic type.
             *  @pre    T   May not be an integral type.
             *  @pre    rng_ may not be nullptr.
             *
             *  @return Random number sampled from a uniform normal distribution.
             */
            template <typename T>
            inline T normal(Generator* const rng_) noexcept
            {
                static_assert(std::is_arithmetic<T>::value);
                static_assert(!std::is_integral<T>::value);
                assert(rng_ != nullptr);

                static bool static_gen = false;
                static_gen             = !static_gen;

                static double static_z1;

                if (!static_gen)
                {
                    return (static_z1);
                }

                const double xi_0 = rng_->gen();
                const double xi_1 = rng_->gen();

                const double m  = std::sqrt(-2.0 * std::log(xi_0));
                const double z0 = m * std::cos(consts::math::TWO_PI * xi_1);
                static_z1       = m * std::sin(consts::math::TWO_PI * xi_1);

                return (z0);
            }

            /**
             *  Generate a random number sampled from a gaussian distribution with a given mean and variance.
             *
             *  @tparam T   Type to be uniformly generated.
             *
             *  @param  rng_    Random number generator.
             *  @param  ave_    Average of the gaussian distribution.
             *  @param  var_    Variance of the gaussian distribution.
             *
             *  @pre    T   Must be an arithmetic type.
             *  @pre    T   May not be an integral type.
             *  @pre    rng_ may not be nullptr.
             *  @pre    var_ must be positive.
             *
             *  @return Random number sampled from a gaussian distribution.
             */
            template <typename T>
            inline T gaussian(Generator* const rng_, const T ave_, const T var_) noexcept
            {
                static_assert(std::is_arithmetic<T>::value);
                static_assert(!std::is_integral<T>::value);
                assert(rng_ != nullptr);
                assert(var_ > 0.0);

                return ((normal<T>(rng_) * var_) + ave_);
            }

            /**
             *  Generate a random number sampled from the Henyey-Greenstein phase function with a given asymmetry factor.
             *  Mathematics adapted from https://www.astro.umd.edu/~jph/HG_note.pdf.
             *
             *  @tparam T   Type to be uniformly generated.
             *
             *  @param  rng_    Random number generator.
             *  @param  g_      Asymmetry parameter.
             *
             *  @pre    T   Must be an arithmetic type.
             *  @pre    T   May not be an integral type.
             *  @pre    rng_ may not be nullptr.
             *  @pre    g_ must be greater than, or equal to, minus one.
             *  @pre    g_ must be less than, or equal to, unity.
             *
             *  @return Random number sampled from a Henyey-Greenstein distribution.
             */
            template <typename T>
            inline T henyey_greenstein(Generator* const rng_, const T g_) noexcept
            {
                static_assert(std::is_arithmetic<T>::value);
                static_assert(!std::is_integral<T>::value);
                assert(rng_ != nullptr);
                assert(g_ >= -1.0);
                assert(g_ <= 1.0);

                if (math::compare::zero(g_))
                {
                    return (std::acos(uniform(rng_, -1.0, 1.0)));
                }

                return (std::acos((1.0 + (g_ * g_) - math::pow::sq((1.0 - (g_ * g_)) / (1.0 + (g_ * uniform(rng_, -1.0, 1.0))))) / (2.0 * g_)));
            }

            /**
             *  Generate a random isotropic direction vec.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    rng_ may not be nullptr.
             *
             *  @return Random isotropic direction vec.
             */
            template <typename T>
            inline vec3 isotropic(Generator* const rng_) noexcept
            {
                assert(rng_ != nullptr);

                const double phi   = uniform(rng_, consts::math::TWO_PI);
                const double theta = std::acos(uniform(rng_, -1.0, 1.0));

                return (math::convert::polar_to_cart<double>(1.0, theta, phi));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_INL
