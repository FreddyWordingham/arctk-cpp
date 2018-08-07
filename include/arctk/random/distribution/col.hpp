/**
 *  @file   arctk/random/distribution/col.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Random colour function.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_COL_HPP
#define ARCTK_RANDOM_DISTRIBUTION_COL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/random/distribution.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {



            //  == CLASS ==
            /**
             *  Random colour distribution.
             */
            class Col : public Distribution<vec3>
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Col() noexcept = default;


                //  == METHODS ==
              public:
                //  -- Sampling --
                inline vec3 sample(Generator* rng_) const noexcept override;
            };



            //  == METHODS ==
            //  -- Sampling --
            /**
             *  Sample a value from the distribution.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Value sampled from the distribution.
             */
            template <typename T>
            inline T Uniform<T>::sample(Generator* const rng_) const noexcept
            {
                return (Distribution<T>::_min + (rng_->gen() * (Distribution<T>::_max - Distribution<T>::_min)));
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_COL_HPP
