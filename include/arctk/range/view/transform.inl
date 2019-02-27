//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/transform.hpp" // IWYU pragma: export, keep



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/transform.inl" // IWYU pragma: keep



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
            constexpr inline Transform<R, F>::Transform(const R& range_, const F& trans_) noexcept
              : View<R>{range_}
              , _trans{trans_}
            {
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R, typename F>
            constexpr inline auto Transform<R, F>::begin() noexcept
            {
                return (iterator::Transform{View<R>::_range.begin(), View<R>::_range.end(), _trans});
            }

            template <typename R, typename F>
            constexpr inline auto Transform<R, F>::end() noexcept
            {
                return (iterator::Transform{View<R>::_range.end(), View<R>::_range.end(), _trans});
            }



        } // namespace view
    }     // namespace range
} // namespace arc
