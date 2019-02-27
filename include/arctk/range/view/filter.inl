//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/filter.hpp" // IWYU pragma: export, keep



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/filter.inl" // IWYU pragma: keep



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename R, typename F>
            constexpr inline Filter<R, F>::Filter(R* const range_, const F& pred_) noexcept
              : View<R>{range_}
              , _pred{pred_}
            {
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R, typename F>
            constexpr inline auto Filter<R, F>::begin() noexcept
            {
                return (iterator::Filter{View<R>::_range->begin(), View<R>::_range->end(), _pred});
            }

            template <typename R, typename F>
            constexpr inline auto Filter<R, F>::end() noexcept
            {
                return (iterator::Filter{View<R>::_range->end(), View<R>::_range->end(), _pred});
            }



        } // namespace view
    }     // namespace range
} // namespace arc
