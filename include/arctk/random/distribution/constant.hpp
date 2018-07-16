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
             */
            template <typename T>
            class Constant : public Distribution<T>
            {
                //  == FIELDS ==
              private:
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP
