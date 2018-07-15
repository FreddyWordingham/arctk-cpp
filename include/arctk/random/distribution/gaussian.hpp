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

                //  -- Generation --
                bool _gen; //!< If true, generate a new pair of values next time sample is called.


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
            template <typename T>
            inline Gaussian<T>::Gaussian(const T ave_, const T var_) noexcept
              : Distribution<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::max())
              , _ave(ave_)
              , _var(var_)
            {
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
            template <typename T>
            inline T Gaussian<T>::Gaussian(Generator* const rng_) const noexcept
            {
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
                const double z0 = m * std::cos(2.0 * constant::PI * u1);
                static_z1       = m * std::sin(2.0 * constant::PI * u1);

                return ((z0 * sigma_) + mu_);
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_GAUSSIAN_HPP
