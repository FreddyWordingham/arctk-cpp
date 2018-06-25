/**
 *  @file   arctk/rng/distribution/uniform.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Uniform transformation distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP
#define ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! utility namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Uniform --
            template <typename T>
            inline T uniform(Generator& rng_, const T min_, const T max_) noexcept;



            //  == FUNCTIONS ==
            //  -- Uniform --
            template <>
            inline size_t uniform(Generator& rng_, const size_t min_, const size_t max_) noexcept
            {
                assert(min_ < max_);

                return (static_cast<size_t>(rng_.gen() * static_cast<double>(max_ - min_ + 1)) + min_);
            }

            template <>
            inline int uniform(Generator& rng_, const int min_, const int max_) noexcept
            {
                assert(min_ < max_);

                return (static_cast<int>(rng_.gen() * static_cast<double>(max_ - min_ + 1)) + min_);
            }

            template <>
            inline double uniform(Generator& rng_, const double min_, const double max_) noexcept
            {
                assert(min_ < max_);

                return ((rng_.gen() * (max_ - min_)) + min_);
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP
