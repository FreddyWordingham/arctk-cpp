//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/skip.hpp" // IWYU pragma: export, keep



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename R>
            constexpr inline Skip<R>::Skip(const R& range_, const size_type skip_first_, const size_type skip_last_) noexcept
              : View<R>{range_}
              , _skip_first{skip_first_}
              , _skip_last{skip_last_}
            {
                assert(range_.size() >= (skip_first_ + skip_last_));
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R>
            constexpr inline auto Skip<R>::begin() noexcept
            {
                return (View<R>::_range.begin() + _skip_first + 1);
            }

            template <typename R>
            constexpr inline auto Skip<R>::end() noexcept
            {
                return (View<R>::_range.end() - _skip_last);
            }



        } // namespace view
    }     // namespace range
} // namespace arc
