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



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <vector>

//  -- Arctk --
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
             *  Discrete probability distribution class used to sample random numbers.
             *
             *  @tparam T   Type returned from sampling the distribution.
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

              private:
                //  -- Initialisation --
                inline std::vector<double> init_cdfs(const std::vector<double>& probs_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::vector<T>&      vals() const noexcept;
                inline const std::vector<double>& cdfs() const noexcept;

                //  -- Sampling --
                inline T sample(Generator* rng_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a discrete distribution from a vector of values and their corresponding relative probabilities.
             *
             *  @param  vals_   Values generated from the distribution.
             *  @param  probs_  Corresponding relative probabilities of the values.
             *
             *  @pre    vals_ may not be empty.
             *  @pre    probs_ may not be empty.
             *  @pre    vals_ size must match probs_ size.
             *  @pre    vals_ must be sorted in ascending order.
             *  @pre    probs_ must always be greater than, or equal to, zero.
             */
            template <typename T>
            inline Discrete<T>::Discrete(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept
              : Distribution<T>(vals_.front(), vals_.back())
              , _vals(vals_)
              , _cdfs(init_cdfs(probs_))
            {
                assert(!vals_.empty());
                assert(!probs_.empty());
                assert(vals_.size() == probs_.size());
                assert(utl::properties::ascending(vals_));
                assert(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));
            }


            //  -- Initialisation --
            /**
             *  Initialise the vector of cumulative distribution frequency values.
             *
             *  @param  probs_  Corresponding relative probabilities of the values.
             *
             *  @pre    probs_ may not be empty.
             *  @pre    probd_ values must all be non-negative.
             *
             *  @post   cdfs back value must equal unity.
             *
             *  @return Initialised vector of cumulative distribution frequency values.
             */
            template <typename T>
            inline std::vector<double> Discrete<T>::init_cdfs(const std::vector<double>& probs_) const noexcept
            {
                assert(!probs_.empty());
                assert(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));

                std::vector<double> cdfs(probs_.size() + 1);

                cdfs[0] = 0.0;
                for (size_t i = 0; i < probs_.size(); ++i)
                {
                    cdfs[i + 1] = cdfs[i] + probs_[i];
                }

                for (size_t i = 0; i < cdfs.size(); ++i)
                {
                    cdfs[i] /= cdfs.back();
                }

                assert(math::compare::equal(cdfs.back(), 1.0));

                return (cdfs);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the vector of values generated from the distribution.
             *
             *  @return Vector of values generated from the distribution.
             */
            template <typename T>
            inline const std::vector<T>& Discrete<T>::vals() const noexcept
            {
                return (_vals);
            }

            /**
             *  Get the vector of cumulative distribution frequency values.
             *
             *  @return Vector of cumulative distribution frequency values.
             */
            template <typename T>
            inline const std::vector<double>& Discrete<T>::cdfs() const noexcept
            {
                return (_cdfs);
            }


            //  -- Sampling --
            /**
             *  Sample a value from the distribution.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    rng_ may not be nullptr.
             *
             *  @return Value sampled from the distribution.
             */
            template <typename T>
            inline T Discrete<T>::sample(Generator* const rng_) const noexcept
            {
                assert(rng_ != nullptr);

                return (_vals[utl::search::lower(_cdfs, rng_->gen())]);
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_DISCRETE_HPP
