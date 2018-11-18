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



        } // namespace container
    }     // namespace math
} // namespace arc



//  == OPERATORS ==
//  -- Assignment --
/**
 *  Add a value to each element of a container.
 * 
 *  @tparam T   Type of container.
 *  @tparam S   Type to be added to the container.
 * 
 *  @param  cont_   Container to be added to.
 *  @param  val_    Value to be added.
 * 
 *  @return Reference to the container.
 */
template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T& operator+=(T& cont_, const S& val_)
{
    for (typename T::iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
    {
        *it += val_;
    }

    return (cont_);
}

/**
 *  Subtract a value to each element of a container.
 * 
 *  @tparam T   Type of container.
 *  @tparam S   Type to be subtracted from the container.
 * 
 *  @param  cont_   Container to be subtracted from.
 *  @param  val_    Value to be subtracted.
 * 
 *  @return Reference to the container.
 */
template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T& operator-=(T& cont_, const S& val_)
{
    for (typename T::iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
    {
        *it -= val_;
    }

    return (cont_);
}

/**
 *  Multiply each element of a container by a value.
 * 
 *  @tparam T   Type of container.
 *  @tparam S   Type used to multiply elements of the container.
 * 
 *  @param  cont_   Container to be multiplied.
 *  @param  val_    Value used to multiply.
 * 
 *  @return Reference to the container.
 */
template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T& operator*=(T& cont_, const S& val_)
{
    for (typename T::iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
    {
        *it *= val_;
    }

    return (cont_);
}

/**
 *  Divide each element of a container by a value.
 * 
 *  @tparam T   Type of container.
 *  @tparam S   Type used to divide elements of the container.
 * 
 *  @param  cont_   Container to be divided.
 *  @param  val_    Value used to divide.
 * 
 *  @return Reference to the container.
 */
template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T& operator/=(T& cont_, const S& val_)
{
    for (typename T::iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
    {
        *it /= val_;
    }

    return (cont_);
}

/**
 *  Modulate each element of a container by a value.
 * 
 *  @tparam T   Type of container.
 *  @tparam S   Type used to modulate elements of the container.
 * 
 *  @param  cont_   Container to be modulated.
 *  @param  val_    Value used to modulate.
 * 
 *  @return Reference to the container.
 */
template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T& operator%=(T& cont_, const S& val_)
{
    for (typename T::iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
    {
        *it %= val_;
    }

    return (cont_);
}


//  -- Increment / Decrement --
/**
 *  Increment the elements of a container.
 *  Return a reference to the container post-increment.
 * 
 *  @tparam T   Type of container.
 * 
 *  @param  cont_   Container to be incremented.
 *  
 *  @return Reference to the container post-increment.
 */
template <typename T, typename>
inline T& operator++(T& cont_)
{
    for (typename T::iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
    {
        ++*it;
    }

    return (cont_);
}

/**
 *  Decrement the elements of a container.
 *  Return a reference to the container post-decrement.
 * 
 *  @tparam T   Type of container.
 * 
 *  @param  cont_   Container to be decremented.
 *  
 *  @return Reference to the container post-decrement.
 */
template <typename T, typename>
inline T& operator--(T& cont_)
{
    for (typename T::iterator it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
    {
        --*it;
    }

    return (cont_);
}

/**
 *  Increment the elements of a container.
 *  Return a copy of the container pre-increment.
 * 
 *  @tparam T   Type of container.
 * 
 *  @param  cont_   Container to be incremented.
 *  
 *  @return Copy of the container pre-increment.
 */
template <typename T, typename>
inline T operator++(const T& cont_, const int /*unused*/)
{
    T cont = cont_;

    ++cont;

    return (cont);
}

/**
 *  Decrement the elements of a container.
 *  Return a copy of the container pre-decrement.
 * 
 *  @tparam T   Type of container.
 * 
 *  @param  cont_   Container to be decremented.
 *  
 *  @return Copy of the container pre-decrement.
 */
template <typename T, typename>
inline T operator--(const T& cont_, const int /*unused*/)
{
    T cont = cont_;

    --cont;

    return (cont);
}



//  -- Arithmetic --
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

/**
 *  Create a container by adding a value to a container.
 * 
 *  @tparam T   Type of container.
 *  @tparam S   Type of value to be added.
 * 
 *  @param  cont_   Container to be added to.
 *  @param  val_    Value to be added.
 * 
 *  @return Container formed by adding a value to a container.
 */
template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T operator+(const T& cont_, const S val_)
{
    T cont = cont_;

    for (typename T::iterator it = std::begin(cont); it != std::end(cont); std::advance(it, 1))
    {
        *it += val_;
    }

    return (cont);
}

template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T operator-(const T& cont_, const S val_)
{
    T cont = cont_;

    for (typename T::iterator it = std::begin(cont); it != std::end(cont); std::advance(it, 1))
    {
        *it -= val_;
    }

    return (cont);
}

template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T operator*(const T& cont_, const S val_)
{
    T cont = cont_;

    for (typename T::iterator it = std::begin(cont); it != std::end(cont); std::advance(it, 1))
    {
        *it *= val_;
    }

    return (cont);
}

template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T operator/(const T& cont_, const S val_)
{
    T cont = cont_;

    for (typename T::iterator it = std::begin(cont); it != std::end(cont); std::advance(it, 1))
    {
        *it /= val_;
    }

    return (cont);
}

template <typename T, typename S, typename = std::enable_if_t<arc::type::temp::is_iterable<T>::value>>
inline T operator%(const T& cont_, const S val_)
{
    T cont = cont_;

    for (typename T::iterator it = std::begin(cont); it != std::end(cont); std::advance(it, 1))
    {
        *it %= val_;
    }

    return (cont);
}



//  == GUARD END ==
#endif // ARCTK_MATH_CONTAINER_INL
