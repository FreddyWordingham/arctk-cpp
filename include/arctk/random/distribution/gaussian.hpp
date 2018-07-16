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
#include <cmath>
#include <limits>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/random/distribution/normal.hpp>



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
            class Gaussian : public Normal<T>
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
                //  -- Getters --
                inline T ave() const noexcept;
                inline T var() const noexcept;

                //  -- Sampling --
                inline T sample(Generator* const rng_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a gaussian distribution with a given average a variance.
             *
             *  @param  ave_    Average of the distribution.
             *  @param  var_    Variance of the distribution.
             *
             *  @pre    var_ must be positive.
             */
            template <typename T>
            inline Gaussian<T>::Gaussian(const T ave_, const T var_) noexcept
              : _ave(ave_)
              , _var(var_)
            {
                PRE(var_ > 0);
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename T>
            inline T Gaussian<T>::ave() const noexcept
            {
                return (_ave);
            }

            template <typename T>
            inline T Gaussian<T>::var() const noexcept
            {
                return (_var);
            }


            //  -- Sampling --
            /**
             *  Sample a value from the distribution.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Value sampled from the distribution.
             */
            template <typename T>
            inline T Gaussian<T>::sample(Generator* const rng_) const noexcept
            {
                return ((Normal<T>::sample(rng_) * _var) + _ave);
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_GAUSSIAN_HPP
