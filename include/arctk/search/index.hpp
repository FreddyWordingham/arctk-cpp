/**
 *  @file   arctk/search/index.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of index searching functions.
 */



//  == GUARD ==
#ifndef ARCTK_SEARCH_INDEX_HPP
#define ARCTK_SEARCH_INDEX_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>

//  -- Arctk --
#include <arctk/prop/contents.hpp>
#include <arctk/prop/order.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace search //! searching namespace
    {
        namespace index //! indexing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Index --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline size_t lower(const C& cont_, const T& val_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline size_t upper(const C& cont_, const T& val_) noexcept;



            //  == FUNCTIONS ==
            //  -- Index --
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
                assert(prop::order::ascending(cont_));
                assert(prop::contents::within(cont_, val_));

                const auto index = static_cast<size_t>(std::distance(std::begin(cont_), std::lower_bound(std::begin(cont_), std::end(cont_), val_)));

                return ((index == 0) ? index : (index - 1));
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
                assert(prop::order::ascending(cont_));
                assert(prop::contents::within(cont_, val_));

                const auto index = static_cast<size_t>(std::distance(std::begin(cont_), std::upper_bound(std::begin(cont_), std::end(cont_), val_)));

                return ((index == cont_.size()) ? (index - 1) : index);
            }



        } // namespace index
    }     // namespace search
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SEARCH_INDEX_HPP
