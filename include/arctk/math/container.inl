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

//  -- Arctk --
#include <arctk/type/temp.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace container //! container namespace
        {



            //  == FUNCTIONS ==
            //  -- Iterator --
            template <typename C>
            inline size_t size(const C& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<C>::value)
                {
                    size_t total = 0;

                    for (typename C::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        total += size(*it);
                    }

                    return (total);
                }

                return (1);
            }

            /**
             *  Determine the sum of all elements within a container.
             *
             *  @tparam T   Type of container.
             *
             *  @param  cont_   Container to sum.
             *
             *  @return Sum of all elements.
             */
            template <typename T, typename C>
            inline T sum(const C& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<C>::value)
                {
                    T total{};

                    for (typename C::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        total += sum<T>(*it);
                    }

                    return (total);
                }

                return (cont_);
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
            template <typename T, typename C>
            inline T ave(const C& cont_) noexcept
            {
                return (sum(cont_) / size(cont_));
            }



        } // namespace container
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_INL
