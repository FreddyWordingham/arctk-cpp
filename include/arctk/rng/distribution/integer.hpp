/**
 *  @file   arctk/rng/distribution/integer.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Integer random number distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_INTEGER_HPP
#define ARCTK_RNG_DISTRIBUTION_INTEGER_HPP



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
            template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
            inline T uniform_integral(Generator& rng_, const T min_, const T max_) noexcept;



            //  == FUNCTIONS ==
            //  -- Floating Point --
            template <typename T, typename>
            inline T uniform_integral(Generator& rng_, const T min_, const T max_) noexcept
            {
                return (static_cast<T>(rng_.gen() * (max_ - min_ + 1)) + min_);
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_INTEGER_HPP
