//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename I>
        constexpr inline Iterator<I>::Iterator(I&& it_) noexcept
          : _it{it_}
        {
        }



        //  == OPERATORS ==
        //  -- Increment / Decrement --
        template <typename I>
        constexpr inline Iterator<I>& Iterator<I>::operator++() noexcept
        {
            ++_it;

            return (*this);
        }

        template <typename I>
        constexpr inline Iterator<I> Iterator<I>::operator++(const int /*unused*/) noexcept
        {
            Iterator<I> it{*this};

            ++_it;

            return (it);
        }


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


        //  -- Member Access --
        template <typename I>
        constexpr inline typename Iterator<I>::reference Iterator<I>::operator*() noexcept
        {
            return (*_it);
        }

        template <typename I>
        constexpr inline typename Iterator<I>::pointer Iterator<I>::operator->() noexcept
        {
            return (&_it);
        }



    } // namespace range
} // namespace arc
