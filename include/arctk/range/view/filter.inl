//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export
                                // IWYU pragma: no_include "arctk/range/view.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/filter.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/filter.inl" // IWYU pragma: keep
#include "arctk/range/preview/filter.inl"  // IWYU pragma: keep



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
            constexpr inline Filter<R, F>::Filter(const R& range_, const F& pred_) noexcept
              : View<R>{range_}
              , _pred{pred_}
            {
            }

            template <typename R, typename F>
            constexpr inline Filter<R, F>::Filter(const R& range_, const preview::Filter<F>& filt_) noexcept
              : Filter{range_, filt_.pred}
            {
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R, typename F>
            constexpr inline auto Filter<R, F>::begin() const noexcept
            {
                return (iterator::Filter{View<R>::_range.begin(), View<R>::_range.end(), _pred});
            }

            template <typename R, typename F>
            constexpr inline auto Filter<R, F>::end() const noexcept
            {
                return (iterator::Filter{View<R>::_range.end(), View<R>::_range.end(), _pred});
            }



        } // namespace view
    }     // namespace range
} // namespace arc
