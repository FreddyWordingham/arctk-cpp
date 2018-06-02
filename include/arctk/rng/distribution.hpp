/**
 *  @file   arctk/rng/generator.hpp
 *  @date   01/06/2018
 *  @author Freddy Wordingham
 *
 *  Distribution conversion
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_HPP
#define ARCTK_RNG_DISTRIBUTION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! random number generation namespace
    {



        //  == CLASS ==
        /**
         *  Distribution conversion class.
         *  Uses a pseudo random generator to draw a value from a probability distribution.
         */
        template <typename T>
        class Distribution
        {
            //  == INSTANTIATION ==
          public:
            //  -- Destructors --
            virtual inline ~Distribution() noexcept = default;


            //  == METHODS ==
          public:
            //  -- Sampling --
            virtual inline T sample(Generator& gen_) noexcept = 0;
        };



    } // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_HPP
