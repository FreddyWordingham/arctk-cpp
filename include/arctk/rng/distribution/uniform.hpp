/**
 *  @file   arctk/rng/distribution/uniform.hpp
 *  @date   01/06/2018
 *  @author Freddy Wordingham
 *
 *  Uniform range probability distribution.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP
#define ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! random number generation namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == CLASS ==
            /**
             *  Form a random number drawn from a uniform probability distribution.
             *
             *  @tparam T   Type to be generated.
             */
            template <typename T>
            class Uniform : public Distribution<T>
            {
                //  == FIELDS ==
              public:
                //  -- Range --
                const T _min;
                const T _max;
                const T _range;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Uniform(T min_, T max_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Call --
                inline T operator()(Generator& gen_) noexcept override;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline T min() noexcept;
                inline T max() noexcept;

                //  -- Generation --
                static inline T gen(Generator& gen_, T min_, T max_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a uniform distribution which will return values uniformly over the given range.
             *
             *  @tparam T   Type to be generated.
             *
             *  @param  min_    Minimum value to be generated.
             *  @param  max_    Maximum value to be generated.
             *
             *  @pre    min_ must be less that max_.
             */
            template <typename T>
            inline Uniform<T>::Uniform(const T min_, const T max_) noexcept
              : _min(min_)
              , _max(max_)
              , _range(max_ - min_)
            {
                assert(min_ < max_);
            }



            //  == OPERATORS ==
            //  -- Call --
            /**
             *  Generate a value within the limits of the distribution.
             *
             *  @tparam T   Type to be generated.
             *
             *  @return Generated value within the distribution limits.
             */
            template <typename T>
            inline T Uniform<T>::operator()(Generator& gen_) noexcept
            {
                const double xi = gen_.gen();

                return (static_cast<T>(_min + (_range * xi)));
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the minimum bound of the distribution.
             *
             *  @return Minimum bound of the distribution.
             */
            template <typename T>
            inline T Uniform<T>::min() noexcept
            {
                return (_min);
            }

            /**
             *  Get the maximum bound of the distribution.
             *
             *  @return Maximum bound of the distribution.
             */
            template <typename T>
            inline T Uniform<T>::max() noexcept
            {
                return (_max);
            }


            //  -- Generation --
            /**
             *  Generate a value within given limits.
             *  Does not require an active uniform object instance.
             *
             *  @tparam T   Type to be generated.
             *
             *  @param  min_    Minimum value to be generated.
             *  @param  max_    Maximum value to be generated.
             *
             *  @pre    min_ must be less that max_.
             *
             *  @return Generated value within the given limits.
             */
            template <typename T>
            inline T Uniform<T>::gen(Generator& gen_, const T min_, const T max_) noexcept
            {
                assert(min_ < max_);

                const double xi = gen_.gen();

                return (static_cast<T>(min_ + ((max_ - min_) * xi)));
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP
