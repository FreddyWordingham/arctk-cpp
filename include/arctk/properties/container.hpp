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
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C>
        inline size_t size(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator, typename T = typename C::value_type>
        inline bool always_less_than(const C& cont_) noexcept;



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



    } // namespace prop
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PROPERTIES_CONTAINER_HPP
