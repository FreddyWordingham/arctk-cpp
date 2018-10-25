/**
 *  @file   arctk/search/value.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of value searching functions.
 */



//  == GUARD ==
#ifndef ARCTK_SEARCH_VALUE_HPP
#define ARCTK_SEARCH_VALUE_HPP



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace search //! searching namespace
    {
        namespace value //! value namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Value --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline size_t min_index(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline size_t max_index(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline T min(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline T max(const C& cont_) noexcept;



        } // namespace value
    }     // namespace search
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/search/value.inl>



//  == GUARD END ==
#endif // ARCTK_SEARCH_VALUE_HPP
