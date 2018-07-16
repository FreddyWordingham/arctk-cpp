/**
 *  @file   arctk/random/distribution/constant.hpp
 *  @date   16/07/2018
 *  @author Freddy Wordingham
 *
 *  Constant probability random distribution.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP
#define ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>

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
             *  Constant (step) probability distribution class used to sample random numbers.
             *
             *  @tparam T   Type returned from sampling the distribution.
             */
            template <typename T>
            class Constant : public Distribution<T>
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
                inline Constant(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept;

                //  -- Initialisation --
                inline std::vector<double> init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::vector<T>&      vals() const noexcept;
                inline const std::vector<double>& cdfs() const noexcept;

                //  -- Sampling --
                inline T sample(Generator* const rng_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a constant (step) distribution from a vector of values and their corresponding relative intermediate probabilities.
             *
             *  @param  vals_   Values generated from the distribution.
             *  @param  probs_  Corresponding relative intermediate probabilities of the values.
             *
             *  @pre    vals_ must contain at least two values.
             *  @pre    probs_ may not be empty.
             *  @pre    vals_ size must match probs_ size plus one.
             *  @pre    vals_ must be sorted in ascending order.
             *  @pre    probs_ must always be greater than, or equal to, zero.
             */
            template <typename T>
            inline Constant<T>::Constant(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept
              : Distribution<T>(vals_.front(), vals_.back())
              , _vals(vals_)
              , _cdfs(init_cdfs(vals_, probs_))
            {
                PRE(vals_.size() >= 2);
                PRE(!probs_.empty());
                PRE(vals_.size() == (probs_.size() + 1));
                PRE(utl::properties::ascending(vals_));
                PRE(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));
            }


            //  -- Initialisation --
            template <typename T>
            inline std::vector<double> Constant<T>::init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept
            {
                PRE(vals_.size() >= 2);
                PRE(!probs_.empty());
                PRE(vals_.size() == (probs_.size() + 1));
                PRE(utl::properties::ascending(vals_));
                PRE(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));

                std::vector<double> cdfs(probs_.size() + 1);

                cdfs[0] = 0.0;
                for (size_t i = 0; i < probs_.size(); ++i)
                {
                    cdfs[i + 1] = cdfs[i] + (probs_[i] * (vals_[i + 1] - vals_[i]));
                }

                for (size_t i = 0; i < cdfs.size(); ++i)
                {
                    cdfs[i] /= cdfs.back();
                }

                POST(math::compare::equal(cdfs.back(), 1.0));

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
            inline const std::vector<T>& Constant<T>::vals() const noexcept
            {
                return (_vals);
            }

            /**
             *  Get the vector of cumulative distribution frequency values.
             *
             *  @return Vector of cumulative distribution frequency values.
             */
            template <typename T>
            inline const std::vector<double>& Constant<T>::cdfs() const noexcept
            {
                return (_cdfs);
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
            inline T Constant<T>::sample(Generator* const rng_) const noexcept
            {
                const size_t index = utl::search::lower(_cdfs, rng_->gen());

                return (_vals[index] + (rng_->gen() * (_vals[index + 1] - _vals[index])));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP
