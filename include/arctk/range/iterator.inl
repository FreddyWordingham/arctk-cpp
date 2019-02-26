//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename I>
        constexpr inline Iterator<I>::Iterator(const I& start_, const I& end_) noexcept
          : _it{start_}
          , _end{end_}
        {
        }



        //  == OPERATORS ==
        //  -- Comparison --
        template <typename I>
        constexpr inline bool Iterator<I>::operator==(const Iterator<I>& rhs_) const noexcept
        {
            return (_it == rhs_._it);
        }

        template <typename I>
        constexpr inline bool Iterator<I>::operator!=(const Iterator<I>& rhs_) const noexcept
        {
            return (_it != rhs_._it);
        }



    } // namespace range
} // namespace arc
