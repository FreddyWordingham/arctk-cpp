/**
 *  @file   arctk/rng/distribution/float.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Floating point random number distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_FLOAT_HPP
#define ARCTK_RNG_DISTRIBUTION_FLOAT_HPP



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
            //  -- Floating Point --
            template <typename T>
            inline T uniform(Generator& rng_, const T min_, const T max_) noexcept;



            //  == FUNCTIONS ==
            //  -- Floating Point --
            template <typename T>
            inline T uniform(Generator& rng_, const T min_, const T max_) noexcept
            {
                return ((static_cast<T>(rng_.gen()) * (max_ - min_)) + min_);
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_FLOAT_HPP
