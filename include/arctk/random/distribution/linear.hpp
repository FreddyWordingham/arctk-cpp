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



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/random/distribution.hpp>



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
                const std::vector<double> _fracs;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Linear(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept;

                //  -- Initialisation --
                inline std::vector<double> init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept;
                inline std::vector<double> init_fracs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::vector<T>&      vals() const noexcept;
                inline const std::vector<double>& probs() const noexcept;
                inline const std::vector<double>& cdfs() const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Linear<T>::Linear(const std::vector<T>& vals_, const std::vector<double>& probs_) noexcept
              : Distribution<T>(vals_.front(), vals_.back())
              , _vals(vals_)
              , _probs(probs_)
              , _cdfs(init_cdfs(vals_, probs_))
              , _fracs(init_fracs(vals_, probs))
            {
                PRE(vals_.size() >= 2);
                PRE(!probs_.empty());
                PRE(vals_.size() == (probs_.size() + 1));
                PRE(utl::properties::ascending(vals_));
                PRE(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));
            }


            //  -- Initialisation --
            template <typename T>
            inline std::vector<double> Linear<T>::init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept
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
                    cdfs[i + 1] = cdfs[i] + ((probs_[i + 1] + probs_[i]) * (vals_[i + 1] - vals_[i]));
                }

                for (size_t i = 0; i < cdfs.size(); ++i)
                {
                    cdfs[i] /= cdfs.back();
                }

                POST(math::compare::equal(cdfs.back(), 1.0));

                return (cdfs);
            }

            template <typename T>
            inline std::vector<double> Linear<T>::init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept
            {
                PRE(vals_.size() >= 2);
                PRE(!probs_.empty());
                PRE(vals_.size() == (probs_.size() + 1));
                PRE(utl::properties::ascending(vals_));
                PRE(utl::properties::always_greater_than_or_equal_to(probs_, 0.0));

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



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_LINEAR_HPP
