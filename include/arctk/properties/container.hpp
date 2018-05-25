/**
 *  @file   arctk/search/container.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Container property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROPERTIES_CONTAINER_HPP
#define ARCTK_PROPERTIES_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <algorithm>
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C>
        inline size_t size(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline bool contains(const C& cont_, const T& val_) noexcept;
        template <typename C, typename I = typename C::const_iterator>
        inline bool ascending(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator, typename T = typename C::value_type>
        inline bool always_less_than(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator, typename T = typename C::value_type>
        inline bool always_less_than_or_qual_to(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator, typename T = typename C::value_type>
        inline bool always_greater_than(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator, typename T = typename C::value_type>
        inline bool always_greater_than_or_qual_to(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Calculate the size of a container.
         *
         *  @tparam C   Container type.
         *
         *  @param  cont_   Container to determine the size of.
         *
         *  @return Size of the container.
         */
        template <typename C>
        inline size_t size(const C& cont_) noexcept
        {
            return (std::distance(std::begin(cont_), std::end(cont_)));
        }

        /**
         *  Determine if a container contains a value.
         *
         *  @tparam C   Container type.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to check.
         *  @param  val_    Value to check container for.
         *
         *  @return True if the container contains the value.
         */
        template <typename C, typename T>
        inline bool contains(const C& cont_, const T& val_) noexcept
        {
            return (std::find(std::begin(cont_), std::end(cont_), val_) != std::end(cont_));
        }

        /**
         *  Test if a containers elements are sorted in ascending order.
         *  Container is still considered ascending if consecutive values are equal.
         *
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *
         *  @param  cont_   Container to test.
         *
         *  @pre    cont_ must contain more than one element.
         *
         *  @return True if the containers elements are sorted in ascending order.
         */
        template <typename C, typename I>
        inline bool ascending(const C& cont_) noexcept
        {
            assert(size(cont_) > 1);

            for (I it = std::begin(cont_); it != std::prev(std::end(cont_)); ++it)
            {
                if (*it > *std::next(it))
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if all elements of a container are less than a given limit.
         *
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to test.
         *  @param  limit_  Limit to compare elements against.
         *
         *  @return True if all elements are less than the limit.
         */
        template <typename C, typename I, typename T>
        inline bool always_less_than(const C& cont_, const T limit_) noexcept
        {
            for (I it = std::begin(cont_); it != std::end(cont_); ++it)
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
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to test.
         *  @param  limit_  Limit to compare elements against.
         *
         *  @return True if all elements are less than, or equal to, the limit.
         */
        template <typename C, typename I, typename T>
        inline bool always_less_than_or_equal_to(const C& cont_, const T limit_) noexcept
        {
            for (I it = std::begin(cont_); it != std::end(cont_); ++it)
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
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to test.
         *  @param  limit_  Limit to compare elements against.
         *
         *  @return True if all elements are greater than the limit.
         */
        template <typename C, typename I, typename T>
        inline bool always_greater_than(const C& cont_, const T limit_) noexcept
        {
            for (I it = std::begin(cont_); it != std::end(cont_); ++it)
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
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to test.
         *  @param  limit_  Limit to compare elements against.
         *
         *  @return True if all elements are greater than, or equal to, the limit.
         */
        template <typename C, typename I, typename T>
        inline bool always_greater_than_or_equal_to(const C& cont_, const T limit_) noexcept
        {
            for (I it = std::begin(cont_); it != std::end(cont_); ++it)
            {
                if (!(*it >= limit_))
                {
                    return (false);
                }
            }

            return (true);
        }



    } // namespace prop
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PROPERTIES_CONTAINER_HPP
