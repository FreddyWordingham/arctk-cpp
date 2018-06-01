/**
 *  @file   arctk/rng/distribution/uniform.hpp
 *  @date   01/06/2018
 *  @author Freddy Wordingham
 *
 *  Uniform range probability distribution.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP
#define ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! random number generation namespace
    {
        namespace generator //! random number generator engine
        {



            //  == CLASS ==
            /**
             *  Form a random number drawn from a uniform probability distribution.
             */
            template <typename T>
            class Uniform : public Distribution<T>
            {
                //  == FIELDS ==
              public:
                //  -- Generation --

                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Generation --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==



        } // namespace generator
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_UNIFORM_HPP
