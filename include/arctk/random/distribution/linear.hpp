/**
 *  @file   arctk/random/distribution/linear.hpp
 *  @date   16/07/2018
 *  @author Freddy Wordingham
 *
 *  Linear probability random distribution.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_LINEAR_HPP
#define ARCTK_RANDOM_DISTRIBUTION_LINEAR_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <vector>

//  -- Arctk --
#include <arctk/prop/limits.hpp>
#include <arctk/prop/order.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/search/index.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {



            //  == CLASS ==
            /**
             *  Linear probability distribution class used to sample random numbers.
             *
             *  @tparam T   Type returned from sampling the distribution.
             */
            template <typename T>
            class Linear : public Distribution<T>
            {
                //  == FIELDS ==
              private:
                //  -- Values --
                const std::vector<T> _vals; //!< Distribution values.

                //  -- Probabilities --
                const std::vector<double> _probs; //!< Probability distribution.
                const std::vector<double> _cdfs;  //!< Cumulative distribution frequencies.
                const std::vector<double> _fracs; //!< Fraction of triangle areas of the probability distribution.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Linear(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept;

              private:
                //  -- Initialisation --
                inline std::vector<double> init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept;
                inline std::vector<double> init_fracs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::vector<T>&      vals() const noexcept;
                inline const std::vector<double>& probs() const noexcept;
                inline const std::vector<double>& cdfs() const noexcept;
                inline const std::vector<double>& fracs() const noexcept;

                //  -- Sampling --
                inline T sample(Generator* rng_) const noexcept override;
            };



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_LINEAR_HPP
