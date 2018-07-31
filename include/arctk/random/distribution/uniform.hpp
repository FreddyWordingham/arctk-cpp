/**
 *  @file   arctk/random/distribution/uniform.hpp
 *  @date   15/07/2018
 *  @author Freddy Wordingham
 *
 *  Random uniform probability distribution function sampling.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_UNIFORM_HPP
#define ARCTK_RANDOM_DISTRIBUTION_UNIFORM_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/random/distribution.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {



            //  == CLASS ==
            /**
             *  Uniform probability distribution class used to sample random numbers.
             *
             *  @tparam T   Type returned from sampling the distribution.
             */
            template <typename T>
            class Uniform : public Distribution<T>
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Uniform(T min_, T max_) noexcept;


                //  == METHODS ==
              public:
                //  -- Sampling --
                inline T sample(Generator* rng_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a uniform distribution with given bounds.
             *
             *  @param  min_    Minimum bound of the uniform distribution.
             *  @param  max_    Maximum bound of the uniform distribution.
             *
             *  @pre    min_ must be less than max_.
             */
            template <typename T>
            inline Uniform<T>::Uniform(const T min_, const T max_) noexcept
              : Distribution<T>(min_, max_)
            {
                PRE(min_ < max_);
            }



            //  == METHODS ==
            //  -- Sampling --
            /**
             *  Sample a value from the distribution.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Value sampled from the distribution.
             */
            template <typename T>
            inline T Uniform<T>::sample(Generator* const rng_) const noexcept
            {
                return (Distribution<T>::_min + (rng_->gen() * (Distribution<T>::_max - Distribution<T>::_min)));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_UNIFORM_HPP
