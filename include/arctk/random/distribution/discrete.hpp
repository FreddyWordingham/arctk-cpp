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
             */
            class Discrete
            {
                //  == FIELDS ==
              private:
                //  -- Values --
                const std::vector<double> _vals; //!< Values which may be generated.

                //  -- Probabilities --
                const std::vector<double> _cums; //!< Cumulative probabilities of each value.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Discrete(const std::vector<double>& vals_, const std::vector<double>& probs_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==



            //  == METHODS ==



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_DISCRETE_HPP
