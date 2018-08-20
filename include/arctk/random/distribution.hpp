/**
 *  @file   arctk/random/distribution.hpp
 *  @date   13/07/2018
 *  @author Freddy Wordingham
 *
 *  Probability distribution base class used to sample random numbers.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_HPP
#define ARCTK_RANDOM_DISTRIBUTION_HPP



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {



        //  == CLASS ==
        /**
         *  Probability distribution base class used to sample random numbers.
         *
         *  @tparam T   Type returned from sampling the distribution.
         */
        template <typename T>
        class Distribution
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            const T _min; //!< Minimum value returned by the distribution.
            const T _max; //!< Maximum value returned by the distribution.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Distribution(T min_, T max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline T min() const noexcept;
            inline T max() const noexcept;

            //  -- Sampling --
            virtual inline T sample(Generator* rng_) const noexcept = 0; //!< Sample a value from the distribution.   @param  rng_    Random number generator.    @return Value sampled from the distribution.
        };



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
            PRE(min_ < max_);
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



            //  == FUNCTION PROTOTYPES ==
            //  -- Sampling --
            template <typename T>
            inline T uniform(Generator* rng_, const T min_, const T max_) noexcept;
            template <typename T = double>
            inline T normal(Generator* rng_) noexcept;
            template <typename T = double>
            inline T gaussian(Generator* rng_, const T ave_, const T var_) noexcept;
            template <typename T = double>
            inline T henyey_greenstein(Generator* rng_, const T g_) noexcept;
            template <typename T = vec3>
            inline T isotropic(Generator* rng_) noexcept;



            //  == FUNCTIONS ==
            //  -- Sampling --
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
             *  @pre    min_ must be less than, or equal to, max_.
             *
             *  @return Random number sampled from a uniform distribution.
             */
            template <typename T>
            inline T uniform(Generator* rng_, const T min_, const T max_) noexcept
            {
                static_assert(std::is_arithmetic<T>::value);

                PRE(min_ <= max_);

                if constexpr (std::is_integral<T>::value)
                {
                    return (std::floor((rng_->gen() * (max_ - min_ + 1)) + min_));
                }
                else
                {
                    return ((rng_->gen() * (max_ - min_)) + min_);
                }
            }

            template <typename T>
            inline T normal(Generator* rng_) noexcept
            {
                static_assert(std::is_arithmetic<T>::value);
                static_assert(!std::is_integral<T>::value);

                static bool _gen = false;
                _gen             = !_gen;

                static double _z1;

                if (!_gen)
                {
                    return (_z1);
                }

                const double xi_0 = rng_->gen();
                const double xi_1 = rng_->gen();

                const double m  = std::sqrt(-2.0 * std::log(xi_0));
                const double z0 = m * std::cos(2.0 * consts::math::PI * xi_1);
                _z1             = m * std::sin(2.0 * consts::math::PI * xi_1);

                return (z0);
            }

            template <typename T>
            inline T gaussian(Generator* rng_, const T ave_, const T var_) noexcept
            {
                static_assert(std::is_arithmetic<T>::value);
                static_assert(!std::is_integral<T>::value);

                return ((normal<T>(rng_) * var_) + ave_);
            }

            template <typename T>
            inline T henyey_greenstein(Generator* rng_, const T g_) noexcept
            {
                static_assert(std::is_arithmetic<T>::value);
                static_assert(!std::is_integral<T>::value);

                PRE((g_ >= -1.0) && (g_ <= 1.0));

                if (math::compare::zero(g_))
                {
                    return (std::acos((rng_->gen() * 2.0) - 1.0));
                }

                return (std::acos((1.0 + (g_ * g_) - math::pow::sq((1.0 - (g_ * g_)) / (1.0 + (g_ * ((2.0 * rng_->gen()) - 1.0))))) / (2.0 * g_)));
            }

            template <typename T>
            inline T isotropic(Generator* rng_) noexcept
            {
                static_assert(math::is_vec<T>::value);

                const double phi   = rng_->gen() * 2.0 * consts::math::PI;
                const double theta = std::acos((rng_->gen() * 2.0) - 1.0);

                return (math::convert::polar_to_cart(T(1.0, theta, phi)));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_HPP
