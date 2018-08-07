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
             *
             *  @tparam T   Type returned from sampling the distribution.
             */
            template <typename T>
            class Col : public Distribution<T>
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Col() noexcept = default;


                //  == METHODS ==
              public:
                //  -- Sampling --
                inline T sample(Generator* rng_) const noexcept override;
            };



            //  == METHODS ==
            //  -- Sampling --
            template <typename T>
            inline T Col::sample(Generator* const rng_) const noexcept
            {
                T col;

                col.r = rng_->gen();
                col.g = rng_->gen();
                col.b = rng_->gen();

                return (col);
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_COL_HPP
