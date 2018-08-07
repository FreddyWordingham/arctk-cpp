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
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {
            namespace col //! colour namespace
            {



                //  == FUNCTION PROTOTYPES ==
                //  -- Distribution --
                template <typename T>
                inline T sample(Generator* rng_) noexcept;



                //  == FUNCTIONS ==
                //  -- Distribution --
                /**
                 *  Sample a colour.
                 *
                 *  @tparam T   Type of colour generated.
                 *
                 *  @param  rng_    Random number generator.
                 *
                 *  @return Sampled colour.
                 */
                template <typename T>
                inline T sample(Generator* rng_) noexcept
                {
                    T col;

                    col.r = rng_->gen();
                    col.g = rng_->gen();
                    col.b = rng_->gen();

                    return (col);
                }



            } // namespace col
        }     // namespace distribution
    }         // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_COL_HPP
