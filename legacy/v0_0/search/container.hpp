/**
 *  @file   arctk/search/container.hpp
 *  @date   29/05/2018
 *  @author Freddy Wordingham
 *
 *  Container search functions.
 */



//  == GUARD ==
#ifndef ARCTK_SEARCH_CONTAINER_HPP
#define ARCTK_SEARCH_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iterator>

//  -- Arctk --
#include <arctk/prop.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace search //! search namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Limits --
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline size_t min_index(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline size_t max_index(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline T min(const C& cont_) noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline T max(const C& cont_) noexcept;

        //  -- Placement --
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline size_t lower(const C& cont_, const T& val_) noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline size_t upper(const C& cont_, const T& val_) noexcept;



        //  == FUNCTIONS ==
        //  -- Limits --
        /**
         *  Find the index of the minimum element within a container.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to determine the minimum element index of.
         *
         *  @pre    cont_ must not be empty.
         *
         *  @return Index of the minimum element within the container.
         */
        template <typename C, typename T, typename I>
        inline size_t min_index(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            I min_index = std::begin(cont_);

            for (I it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
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
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to determine the maximum element index of.
         *
         *  @pre    cont_ must not be empty.
         *
         *  @return Index of the maximum element within the container.
         */
        template <typename C, typename T, typename I>
        inline size_t max_index(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            I max_index = std::begin(cont_);

            for (I it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
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
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to determine the minimum element of.
         *
         *  @pre    cont_ must not be empty.
         *
         *  @return Value of the minimum element within the container.
         */
        template <typename C, typename T, typename I>
        inline T min(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            return (cont_[min_index(cont_)]);
        }

        /**
         *  Find the maximum element within a container.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to determine the maximum element of.
         *
         *  @return Value of the maximum element within the container.
         */
        template <typename C, typename T, typename I>
        inline T max(const C& cont_) noexcept
        {
            assert(!cont_.empty());

            return (cont_[max_index(cont_)]);
        }


        //  -- Placement --
        /**
         *  Find the index of the first element of the container that is not greater than or equal to the value given.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
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
        template <typename C, typename T, typename I>
        inline size_t lower(const C& cont_, const T& val_) noexcept
        {
            assert(!cont_.empty());
            assert(prop::ascending(cont_));
            assert(prop::within(cont_, val_));

            const size_t index = std::distance(std::begin(cont_), std::lower_bound(std::begin(cont_), std::end(cont_), val_));

            return (index == 0 ? index : (index - 1));
        }

        /**
         *  Find the index of the first element of the container that is greater than the value given.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to search.
         *  @param  val_    Value to place.
         *
         *  @pre    cont_ must not be empty.
         *  @pre    cont_ must be sorted in ascending order.
         *  @pre    val_ must be within the range of cont_.
         *
         *  @return Index of the first element of the container that is greater than the value given.
         */
        template <typename C, typename T, typename I>
        inline size_t upper(const C& cont_, const T& val_) noexcept
        {
            assert(!cont_.empty());
            assert(prop::ascending(cont_));
            assert(prop::within(cont_, val_));

            const size_t index = std::distance(std::begin(cont_), std::upper_bound(std::begin(cont_), std::end(cont_), val_));

            return (index == cont_.size() ? (index - 1) : index);
        }



    } // namespace search
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SEARCH_CONTAINER_HPP
