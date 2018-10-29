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



//  == BASE ==
#include <arctk/random/distribution.hpp>



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



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

              private:
                //  -- Initialisation --
                inline std::vector<double> init_cdfs(const std::vector<T>& vals_, const std::vector<double>& probs_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::vector<T>&      vals() const noexcept;
                inline const std::vector<double>& cdfs() const noexcept;

                //  -- Sampling --
                inline T sample(Generator* rng_) const noexcept override;
            };



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/random/distribution/constant.inl>



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP
