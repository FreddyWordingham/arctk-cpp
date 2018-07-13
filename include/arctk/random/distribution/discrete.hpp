/**
 *  @file   arctk/random/distribution/discrete.hpp
 *  @date   13/07/2018
 *  @author Freddy Wordingham
 *
 *  Discrete distribution class.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_DISCRETE_HPP
#define ARCTK_RANDOM_DISTRIBUTION_DISCRETE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == CLASS ==
            /**
             *  Discrete distribution class.
             *
             *  @tparam Type of value generated.
             */
            template <typename T>
            class Discrete
            {
                //  == FIELDS ==
              private:
                //  -- Values --
                const std::vector<T> _vals; //!< Values which may be generated.

                //  -- Probabilities --
                const std::vector<double> _cums; //!< Cumulative probabilities of each value.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Discrete(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Discrete(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept
              : _vals(vals_)
              , _cums(init_cums(probs_))
            {
                PRE(utl::properties::always_greater_than_or_equal_to(probs, 0.0));
            }



            //  == METHODS ==



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_DISCRETE_HPP
