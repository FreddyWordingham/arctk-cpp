/**
 *  @file   arctk/random/distribution/discrete.hpp
 *  @date   13/07/2018
 *  @author Freddy Wordingham
 *
 *  Discrete probability random distribution.
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
#include <arctk/math.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {



            //  == CLASS ==
            /**
             */
            template <typename T>
            class Discrete : public Distribution<T>
            {
                //  == FIELDS ==
              private:
                //  -- Values --
                const std::vector<T> _vals; //!< Distribution values.

                //  -- Probabilities --
                const std::vector<double> _cdfs; //!< Cumulative distribution frequencies.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Discrete(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept;

                //  -- Initialisation --
                inline std::vector<double> init_cdfs(const std::vector<double>& probs_) noexcept;


                //  == METHODS ==
              public:
                //  -- Sampling --
                inline T sample(Generator* const rng_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Discrete<T>::Discrete(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept
              : Distribution<T>(vals_.front(), vals_.back())
              , _vals(vals_)
              , _cdfs(init_cdfs(probs_))
            {
                PRE(utl::properties::ascending(vals_));
                PRE(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));
            }


            //  -- Initialisation --
            template <typename T>
            inline std::vector<double> Discrete<T>::init_cdfs(const std::vector<double>& probs_) noexcept
            {
                PRE(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));

                std::vector<double> cdfs(probs_.size());

                cdfs[0] = probs_[0];
                for (size_t i = 1; i < probs_.size(); ++i)
                {
                    cdfs[i] = cdfs[i - 1] + probs_[i];
                }

                for (size_t i = 0; i < cdfs.size(); ++i)
                {
                    cdfs[i] /= cdfs.back();
                }

                POST(math::compare::equal(cdfs.back(), 1.0));

                return (cdfs);
            }



            //  == METHODS ==
            //  -- Sampling --
            template <typename T>
            inline T Discrete<T>::sample(Generator* const rng_) noexcept
            {
                const double xi = rng_->gen();

                return (_vals[utl::search::lower(_cdfs, xi)]);
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_DISCRETE_HPP
