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
#include <limits>

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
            template <typename T>
            inline size_t num_elem(const T& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<T>::value)
                {
                    size_t total = 0;

                    for (typename T::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        total += num_elem(*it);
                    }

                    return (total);
                }
                else
                {
                    return (1);
                }
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
            template <typename T>
            inline typename type::temp::core_type<T>::type sum(const T& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<T>::value)
                {
                    typename type::temp::core_type<T>::type total{};

                    for (typename T::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        total += sum(*it);
                    }

                    return (total);
                }
                else
                {
                    return (cont_);
                }
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
            template <typename T>
            inline typename type::temp::core_type<T>::type ave(const T& cont_) noexcept
            {
                return (sum(cont_) / num_elem(cont_));
            }

            template <typename T>
            inline typename type::temp::core_type<T>::type min(const T& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<T>::value)
                {
                    typename type::temp::core_type<T>::type min = std::numeric_limits<typename type::temp::core_type<T>::type>::max();

                    for (typename T::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        typename type::temp::core_type<T>::type val = min(*it);

                        if (val < min)
                        {
                            min = val;
                        }
                    }

                    return (min);
                }
                else
                {
                    return (cont_);
                }
            }

            template <typename T>
            inline typename type::temp::core_type<T>::type max(const T& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<T>::value)
                {
                    typename type::temp::core_type<T>::type max = std::numeric_limits<typename type::temp::core_type<T>::type>::min();

                    for (typename T::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        typename type::temp::core_type<T>::type val = max(*it);

                        if (val > max)
                        {
                            max = val;
                        }
                    }

                    return (max);
                }
                else
                {
                    return (cont_);
                }
            }



        } // namespace container
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_INL
