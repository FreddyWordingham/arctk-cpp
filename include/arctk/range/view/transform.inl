//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export
                                // IWYU pragma: no_include "arctk/range/view.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/transform.hpp" // IWYU pragma: export, keep



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/transform.inl"
#include "arctk/range/preview/transform.inl"



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
            constexpr inline auto Transform<R, F>::begin() const noexcept
            {
                return (iterator::Transform{View<R>::_range.begin(), View<R>::_range.end(), _trans});
            }

            template <typename R, typename F>
            constexpr inline auto Transform<R, F>::end() const noexcept
            {
                return (iterator::Transform{View<R>::_range.end(), View<R>::_range.end(), _trans});
            }



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe --
    template <typename R, typename F>
    constexpr inline range::view::Transform<R, F> operator|(const R& range_, const range::preview::Transform<F>& trans_) noexcept
    {
        return (range::view::Transform<R, F>{range_, trans_.trans});
    }



} // namespace arc
