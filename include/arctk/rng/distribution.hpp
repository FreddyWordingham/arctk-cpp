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
         *  Converts a uniform floating point number between zero and unity to a random value of the probability distribution.
         */
        class Distribution
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  -- Call --
            virtual inline double operator()(Generator& gen_) noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==



    } // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_HPP
