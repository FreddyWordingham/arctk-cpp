/**
 *  @file   arctk/random/distribution/gaussian.hpp
 *  @date   15/07/2018
 *  @author Freddy Wordingham
 *
 *  Random gaussian probability distribution function sampling.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_GAUSSIAN_HPP
#define ARCTK_RANDOM_DISTRIBUTION_GAUSSIAN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <limits>

//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {



            //  == CLASS ==
            /**
             *  Gaussian probability distribution base class used to sample random numbers.
             *
             *  @tparam T   Type returned from sampling the distribution.
             */
            template <typename T>
            class Gaussian : public Distribution<T>
            {
                //  == FIELDS ==
              protected:
                //  -- Bounds --
                const T _ave; //!< Average of the distribution.
                const T _var; //!< Variance of the distribution.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Gaussian(const T ave_, const T var_) noexcept;


                //  == METHODS ==
              public:
                //  -- Sampling --
                inline T sample(Generator* const rng_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Gaussian<T>::Gaussian(const T ave_, const T var_) noexcept
              : Distribution<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::max())
              , _ave(ave_)
              , _var(var_)
            {
            }



            //  == METHODS ==
            //  -- Sampling --
            template <typename T>
            inline T Gaussian<T>::Gaussian(Generator* const rng_) const noexcept
            {
                return (Distribution<T>::_min + (rng_->gen() * (Distribution<T>::_max - Distribution<T>::_min)));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_GAUSSIAN_HPP
