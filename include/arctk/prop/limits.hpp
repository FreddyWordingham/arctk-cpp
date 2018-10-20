/**
 *  @file   arctk/prop/limits.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of limits property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_LIMITS_HPP
#define ARCTK_PROP_LIMITS_HPP



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace limits //! limits namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Limits --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_less_than(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_less_than_or_equal_to(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_greater_than(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_greater_than_or_equal_to(const C& cont_, const T& limit_) noexcept;



            //  == FUNCTIONS ==
            //  -- Limits --
            /**
             *  Determine if all elements of a container are less than a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are less than the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_less_than(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it < limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if all elements of a container are less than, or equal to, a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are less than, or equal to, the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_less_than_or_equal_to(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it <= limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if all elements of a container are greater than a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are greater than the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_greater_than(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it > limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if all elements of a container are greater than, or equal to, a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are greater than, or equal to, the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_greater_than_or_equal_to(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it >= limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }



        } // namespace limits
    }     // namespace prop
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PROP_LIMITS_HPP
