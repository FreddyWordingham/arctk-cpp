/**
 *  @file   arctk/random/distribution/uniform.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Uniform transformation distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_UNIFORM_HPP
#define ARCTK_RANDOM_DISTRIBUTION_UNIFORM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! utility namespace
    {
        namespace distribution //! distribution namespace
        {
            namespace math //! mathematics namespace
            {



                //  == FUNCTION PROTOTYPES ==
                //  -- Uniform --
                template <typename T>
                inline T uniform(Generator* rng_, T min_, T max_) noexcept; //!< Generate a random value between given limits. @tparam T   Type of value to generate. @param  rng_    Generator used to draw base values from. @param  min_    Lower bound of
                                                                            //!< the genration range. @param  max_    Upper bound of the genration range. @pre    min_ must be less than max_. @return Random uniform value.



                //  == FUNCTIONS ==
                //  -- Uniform --
                /**
                 *  Generate a random value between given limits.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  min_    Lower bound of the genration range.
                 *  @param  max_    Upper bound of the genration range.
                 *
                 *  @pre    min_ must be less than max_.
                 *
                 *  @return Random uniform value.
                 */
                template <>
                inline size_t uniform(Generator* const rng_, const size_t min_, const size_t max_) noexcept
                {
                    assert(min_ < max_);

                    return (static_cast<size_t>(rng_->gen() * static_cast<double>(max_ - min_ + 1)) + min_);
                }

                /**
                 *  Generate a random value between given limits.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  min_    Lower bound of the genration range.
                 *  @param  max_    Upper bound of the genration range.
                 *
                 *  @pre    min_ must be less than max_.
                 *
                 *  @return Random uniform value.
                 */
                template <>
                inline int uniform(Generator* const rng_, const int min_, const int max_) noexcept
                {
                    assert(min_ < max_);

                    return (static_cast<int>(rng_->gen() * static_cast<double>(max_ - min_ + 1)) + min_);
                }

                /**
                 *  Generate a random value between given limits.
                 *
                 *  @param  rng_    Generator used to draw base values from.
                 *  @param  min_    Lower bound of the genration range.
                 *  @param  max_    Upper bound of the genration range.
                 *
                 *  @pre    min_ must be less than max_.
                 *
                 *  @return Random uniform value.
                 */
                template <>
                inline double uniform(Generator* const rng_, const double min_, const double max_) noexcept
                {
                    assert(min_ < max_);

                    return ((rng_->gen() * (max_ - min_)) + min_);
                }



            } // namespace math
        }     // namespace distribution
    }         // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_UNIFORM_HPP
