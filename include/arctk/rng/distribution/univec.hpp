/**
 *  @file   arctk/rng/distribution/univec3.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Uniform three-dimensional vector distribution.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_UNIVEC3_HPP
#define ARCTK_RNG_DISTRIBUTION_UNIVEC3_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/rng/distribution.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! random number generation namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == CLASS ==
            /**
             */
            template <typename T>
            class Vec : public Distribution<T>
            {
                //  == FIELDS ==
              private:
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Getters --



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_UNIVEC3_HPP
