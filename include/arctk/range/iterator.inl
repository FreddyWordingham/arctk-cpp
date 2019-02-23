//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename I>
        constexpr inline Iterator<I>::Iterator(I&& it_) noexcept
          : _it{std::move(it_)}
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
        inline bool Iterator<I>::operator!=(const Iterator<I>& rhs_) const noexcept
        {
            return (_it != rhs_._it);
        }

        template <typename I>
        constexpr inline bool Iterator<I>::operator<(const Iterator& rhs_) const noexcept
        {
            return (_it < rhs_._it);
        }

        template <typename I>
        constexpr inline bool Iterator<I>::operator>(const Iterator& rhs_) const noexcept
        {
            return (_it > rhs_._it);
        }

        template <typename I>
        constexpr inline bool Iterator<I>::operator<=(const Iterator& rhs_) const noexcept
        {
            return (_it <= rhs_._it);
        }

        template <typename I>
        constexpr inline bool Iterator<I>::operator>=(const Iterator& rhs_) const noexcept
        {
            return (_it >= rhs_._it);
        }



    } // namespace range
} // namespace arc
