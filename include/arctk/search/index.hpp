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
#include <iterator>



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



        } // namespace index
    }     // namespace search
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/search/index.inl>



//  == GUARD END ==
#endif // ARCTK_SEARCH_INDEX_HPP
