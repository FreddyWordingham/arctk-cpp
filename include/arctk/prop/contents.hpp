/**
 *  @file   arctk/prop/contents.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of contents property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_CONTENTS_HPP
#define ARCTK_PROP_CONTENTS_HPP



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace contents //! contents namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Contents --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool contains(const C& cont_, const T& val_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool within(const C& cont_, const T& val_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool distinct(const C& cont_) noexcept;



        } // namespace contents
    }     // namespace prop
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/prop/contents.inl>



//  == GUARD END ==
#endif // ARCTK_PROP_CONTENTS_HPP
