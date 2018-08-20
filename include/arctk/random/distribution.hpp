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
#include <arctk/debug.hpp>
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
            inline T    uniform(Generator* rng_, const T min_, const T max_);
            inline vec3 isotropic(Generator* rng_) noexcept;



            //  == FUNCTIONS ==
            //  -- Sampling --
            template <typename T>
            inline T uniform(Generator* rng_, const T min_, const T max_)
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

            inline vec3 isotropic(Generator* rng_) noexcept
            {
                const double phi   = rng_->gen() * 2.0 * consts::math::PI;
                const double theta = std::acos((rng_->gen() * 2.0) - 1.0);

                return (math::convert::polar_to_cart(vec3(1.0, theta, phi)));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_HPP
