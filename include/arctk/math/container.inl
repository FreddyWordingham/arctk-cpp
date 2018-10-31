/**
 *  @file   arctk/math/container.inl
 *  @date   07/10/2018
 *  @author Freddy Wordingham
 *
 *  Math container functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONTAINER_INL
#define ARCTK_MATH_CONTAINER_INL



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace container //! container namespace
        {



            //  == FUNCTIONS ==
            //  -- Iterator --
            /**
             *  Determine the sum of all elements within a container.
             *
             *  @tparam T   Type of container.
             *
             *  @param  cont_   Container to sum.
             *
             *  @return Sum of all elements.
             */
            template <typename T, typename>
            inline typename T::value_type sum(const T& cont_) noexcept
            {
                typename T::value_type total{};

                for (typename T::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    total += *it;
                }

                return (total);
            }

            /**
             *  Determine the average of all elements within a container.
             *
             *  @tparam T   Type of container.
             *
             *  @param  cont_   Container to determine the average of.
             *
             *  @return Average of all elements.
             */
            template <typename T, typename>
            inline double ave(const T& cont_) noexcept
            {
                return (static_cast<double>(sum(cont_)) / cont_.size());
            }



        } // namespace container
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_INL
