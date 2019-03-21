//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export
                                // IWYU pragma: no_include "arctk/range/view.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/reverse.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/reverse.inl"



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
            constexpr inline Reverse<R>::Reverse(R& range_) noexcept
              : View<R>{range_}
            {
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R>
            constexpr inline auto Reverse<R>::begin() const noexcept
            {
                return (View<R>::_range.rbegin());
            }

            template <typename R>
            constexpr inline auto Reverse<R>::end() const noexcept
            {
                return (View<R>::_range.rend());
            }



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe --
    template <typename R>
    constexpr inline range::view::Reverse<R> operator|(R& range_, const range::preview::Reverse& /*unused*/) noexcept
    {
        return (range::view::Reverse<R>{range_});
    }



} // namespace arc
