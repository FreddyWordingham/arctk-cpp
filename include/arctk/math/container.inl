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
            /**
             *  Determine the number of end elements in a multi-dimensional container.
             *
             *  @tparam T   Type of container.
             *
             *  @param  cont_   Container to test.
             *
             *  @return Number of end elements within the multi-dimensional container.
             */
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

            /**
             *  Determine the minimum value of all elements within a multi-dimensional container.
             *
             *  @tparam T   Type of container.
             *
             *  @param  cont_   Container to test.
             *
             *  @return Minimum element value within the multi-dimensional container.
             */
            template <typename T>
            inline typename type::temp::core_type<T>::type min(const T& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<T>::value)
                {
                    typename type::temp::core_type<T>::type min_val = std::numeric_limits<typename type::temp::core_type<T>::type>::max();

                    for (typename T::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        typename type::temp::core_type<T>::type val = min(*it);

                        if (val < min_val)
                        {
                            min_val = val;
                        }
                    }

                    return (min_val);
                }
                else
                {
                    return (cont_);
                }
            }

            /**
             *  Determine the maximum value of all elements within a multi-dimensional container.
             *
             *  @tparam T   Type of container.
             *
             *  @param  cont_   Container to test.
             *
             *  @return Maximum element value within the multi-dimensional container.
             */
            template <typename T>
            inline typename type::temp::core_type<T>::type max(const T& cont_) noexcept
            {
                if constexpr (type::temp::is_iterable<T>::value)
                {
                    typename type::temp::core_type<T>::type max_val = std::numeric_limits<typename type::temp::core_type<T>::type>::min();

                    for (typename T::const_iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                    {
                        typename type::temp::core_type<T>::type val = max(*it);

                        if (val > max_val)
                        {
                            max_val = val;
                        }
                    }

                    return (max_val);
                }
                else
                {
                    return (cont_);
                }
            }


            //  -- Vector --
            // template <typename T, size_t N>
            // inline multi::vector<double, N> normalise(const multi::vector<T, N>& data_) noexcept
            // {
            //     const T min_val = min(data_);
            //     const T min_val = max(data_);


            // }



        } // namespace container
    }     // namespace math
} // namespace arc



//  == OPERATORS ==
//  -- Mathematical --
/**
 *  Create a positive copy of a multi-dimensional container.
 *
 *  @tparam T   Type of container.
 *
 *  @param  cont_   Container to positive copy.
 *
 *  @return Positive copy of the multi-dimensional container.
 */
template <typename T, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T operator+(const T& cont_) noexcept
{
    T cont = cont_;

    for (typename T::iterator it = std::begin(cont); it != std::end(cont); std::advance(it, 1))
    {
        *it = +*it;
    }

    return (cont);
}

/**
 *  Create a negative copy of a multi-dimensional container.
 *
 *  @tparam T   Type of container.
 *
 *  @param  cont_   Container to negative copy.
 *
 *  @return Negative copy of the multi-dimensional container.
 */
template <typename T, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T operator-(const T& cont_) noexcept
{
    T cont = cont_;

    for (typename T::iterator it = std::begin(cont); it != std::end(cont); std::advance(it, 1))
    {
        *it = -*it;
    }

    return (cont);
}



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_INL
