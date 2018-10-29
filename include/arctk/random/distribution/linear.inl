/**
 *  @file   arctk/random/distribution/linear.inl
 *  @date   16/07/2018
 *  @author Freddy Wordingham
 *
 *  Linear probability random distribution.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_LINEAR_INL
#define ARCTK_RANDOM_DISTRIBUTION_LINEAR_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>

//  -- Arctk --
#include <arctk/math/compare.hpp>
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



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a linear distribution from a vector of values and their corresponding relative probabilities.
             *
             *  @param  vals_   Values generated from the distribution.
             *  @param  probs_  Corresponding relative intermediate probabilities of the values.
             *
             *  @pre    vals_ must contain at least two values.
             *  @pre    probs_ must contain at least two values.
             *  @pre    vals_ size must match probs_ size.
             *  @pre    vals_ must be sorted in ascending order.
             *  @pre    probs_ must always be greater than, or equal to, zero.
             */
            template <typename T>
            inline Linear<T>::Linear(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept
              : Distribution<T>(vals_.front(), vals_.back())
              , _vals(vals_)
              , _probs(probs_)
              , _cdfs(init_cdfs(vals_, probs_))
              , _fracs(init_fracs(vals_, probs_))
            {
                assert(vals_.size() >= 2);
                assert(probs_.size() >= 2);
                assert(vals_.size() == probs_.size());
                assert(prop::order::ascending(vals_));
                assert(prop::limits::always_greater_than_or_equal_to(probs_, 0.0));
            }


            //  -- Initialisation --
            /**
             *  Initialise the vector of cumulative distribution frequency values.
             *
             *  @param  vals_   Values generated from the distribution.
             *  @param  probs_  Corresponding relative probabilities of the values.
             *
             *  @pre    vals_ must contain at least two values.
             *  @pre    probs_ must contain at least two values.
             *  @pre    vals_ size must match probs_ size.
             *  @pre    vals_ must be sorted in ascending order.
             *  @pre    probs_ must always be greater than, or equal to, zero.
             *
             *  @post   cdfs back value must equal unity.
             *
             *  @return Initialised vector of cumulative distribution frequency values.
             */
            template <typename T>
            inline std::vector<double> Linear<T>::init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept
            {
                assert(vals_.size() >= 2);
                assert(probs_.size() >= 2);
                assert(vals_.size() == probs_.size());
                assert(prop::order::ascending(vals_));
                assert(prop::limits::always_greater_than_or_equal_to(probs_, 0.0));

                std::vector<double> cdfs(probs_.size());

                cdfs[0] = 0.0;
                for (size_t i = 1; i < cdfs.size(); ++i)
                {
                    cdfs[i] = cdfs[i - 1] + ((probs_[i] + probs_[i - 1]) * std::fabs(vals_[i] - vals_[i - 1]));
                }

                for (size_t i = 0; i < cdfs.size(); ++i)
                {
                    cdfs[i] /= cdfs.back();
                }

                assert(math::compare::equal(cdfs.back(), 1.0));

                return (cdfs);
            }

            /**
             *  Initialise the vector of triangle fractions.
             *  The triangle fraction is the ratio of triangle to rectangle of the trapezium forming the area under the probability distribution function.
             *
             *  @param  vals_   Values generated from the distribution.
             *  @param  probs_  Corresponding relative probabilities of the values.
             *
             *  @pre    vals_ must contain at least two values.
             *  @pre    probs_ must contain at least two values.
             *  @pre    vals_ size must match probs_ size.
             *  @pre    vals_ must be sorted in ascending order.
             *  @pre    probs_ must always be greater than, or equal to, zero.
             *
             *  @return Initialised vector of triangle fractions.
             */
            template <typename T>
            inline std::vector<double> Linear<T>::init_fracs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept
            {
                assert(vals_.size() >= 2);
                assert(probs_.size() >= 2);
                assert(vals_.size() == probs_.size());
                assert(prop::order::ascending(vals_));
                assert(prop::limits::always_greater_than_or_equal_to(probs_, 0.0));

                std::vector<double> fracs(probs_.size() - 1);

                for (size_t i = 0; i < fracs.size(); ++i)
                {
                    const double above = (std::fabs(probs_[i + 1] - probs_[i]) * (vals_[i + 1] - vals_[i])) / 2.0;
                    const double below = ((probs_[i] + probs_[i + 1]) / 2.0) * (vals_[i + 1] - vals_[i]);

                    fracs[i] = above / below;
                }

                return (fracs);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the vector of values generated from the distribution.
             *
             *  @return Vector of values generated from the distribution.
             */
            template <typename T>
            inline const std::vector<T>& Linear<T>::vals() const noexcept
            {
                return (_vals);
            }

            /**
             *  Get the vector of probabilities of the distribution.
             *
             *  @return Vector of probabilities of the distribution.
             */
            template <typename T>
            inline const std::vector<double>& Linear<T>::probs() const noexcept
            {
                return (_probs);
            }

            /**
             *  Get the vector of cumulative distribution frequency values.
             *
             *  @return Vector of cumulative distribution frequency values.
             */
            template <typename T>
            inline const std::vector<double>& Linear<T>::cdfs() const noexcept
            {
                return (_cdfs);
            }

            /**
             *  Get the vector of triangle fractions.
             *
             *  @return Vector of triangle fractions.
             */
            template <typename T>
            inline const std::vector<double>& Linear<T>::fracs() const noexcept
            {
                return (_fracs);
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
            inline T Linear<T>::sample(Generator* const rng_) const noexcept
            {
                assert(rng_ != nullptr);

                const size_t index = search::index::lower(_cdfs, rng_->gen());

                const double xi = rng_->gen();
                if (xi <= _fracs[index])
                {
                    if (_probs[index] < _probs[index + 1])
                    {
                        return (_vals[index] + (std::sqrt(rng_->gen()) * (_vals[index + 1] - _vals[index])));
                    }

                    return (_vals[index + 1] - (std::sqrt(rng_->gen()) * (_vals[index + 1] - _vals[index])));
                }

                return (random::distribution::uniform(rng_, _vals[index], _vals[index + 1]));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_LINEAR_INL
