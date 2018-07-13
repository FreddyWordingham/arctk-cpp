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



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {



        //  == CLASS ==
        /**
         *  Probability distribution base class used to sample random numbers.
         */
        template <typename T>
        class Distribution
        {
            //  == FIELDS ==
          private:
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
            inline T min() noexcept;
            inline T max() noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Distribution::Distribution(T min_, T max_) noexcept
          : _min(min_)
          , _max(max_)
        {
        }


        //  == METHODS ==
        //  -- Getters --
        inline T Distribution::min() noexcept
        {
            return (_min);
        }

        inline T Distribution::max() noexcept
        {
            return (_max);
        }



    } // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_HPP
