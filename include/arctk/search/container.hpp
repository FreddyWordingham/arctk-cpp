/**
 *  @file   arctk/search/container.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Search container functions.
 */



//  == GUARD ==
#ifndef ARCTK_SEARCH_CONTAINER_HPP
#define ARCTK_SEARCH_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cassert>
#include <iterator>

#include <arctk/properties.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace search //! search namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename I = typename C::const_iterator>
        inline size_t min_index(const C& cont_) noexcept;
        template <typename C, typename I = typename C::const_iterator>
        inline size_t max_index(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline T min(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline T max(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type>
        inline size_t lower(const C& cont_, const T& val_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Find the index of the minimum element within a container.
         *
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *
         *  @param  cont_   Container to determine the minimum element index of.
         *
         *  @pre    cont_ must not be empty.
         *
         *  @return Index of the minimum element within the container.
         */
        template <typename C, typename I>
        inline size_t min_index(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            I min_index = std::begin(cont_);

            for (I it = min_index + 1; it != std::end(cont_); ++it)
            {
                if (*it < *min_index)
                {
                    min_index = it;
                }
            }

            return (std::distance(std::begin(cont_), min_index));
        }

        /**
         *  Find the index of the maximum element within a container.
         *
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *
         *  @param  cont_   Container to determine the maximum element index of.
         *
         *  @pre    cont_ must not be empty.
         *
         *  @return Index of the maximum element within the container.
         */
        template <typename C, typename I>
        inline size_t max_index(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            I max_index = std::begin(cont_);

            for (I it = max_index + 1; it != std::end(cont_); ++it)
            {
                if (*it > *max_index)
                {
                    max_index = it;
                }
            }

            return (std::distance(std::begin(cont_), max_index));
        }

        /**
         *  Find the minimum element within a container.
         *
         *  @tparam C   Container type.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to determine the minimum element of.
         *
         *  @pre    cont_ must not be empty.
         *
         *  @return Value of the minimum element within the container.
         */
        template <typename C, typename T>
        inline T min(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            return (cont_[min_index(cont_)]);
        }

        /**
         *  Find the maximum element within a container.
         *
         *  @tparam C   Container type.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to determine the maximum element of.
         *
         *  @return Value of the maximum element within the container.
         */
        template <typename C, typename T>
        inline T max(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            return (cont_[max_index(cont_)]);
        }

        /**
         *  Find the index of the first element of the container that is not greater than or equal to the value given.
         *
         *  @tparam C   Container type.
         *  @tparam T   Type stored by C.
         *
         *  @param  cont_   Container to search.
         *  @param  val_    Value to place.
         *
         *  @pre    cont_ must not be empty.
         *  @pre    cont_ must be sorted in ascending order.
         *  @pre    val_ must be within the range of cont_.
         *
         *  @return Index of the first element of the container that is not greater than or equal to the value given.
         */
        template <typename C, typename T>
        inline size_t lower(const C& cont_, const T& val_) noexcept
        {
            assert(!cont_.empty());
            assert(prop::ascending(cont_));
            assert(prop::within(cont_, val_));

            return (std::distance(std::begin(cont_), std::lower_bound(std::begin(cont_), std::end(cont_), val_)));
        }



    } // namespace search
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SEARCH_CONTAINER_HPP
