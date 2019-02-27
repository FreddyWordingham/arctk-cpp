//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export
                                // IWYU pragma: no_include "arctk/range/view.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/reverse.hpp" // IWYU pragma: export, keep



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
            constexpr inline Reverse<R>::Reverse(const R& range_) noexcept
              : View<R>{range_}
            {
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R>
            constexpr inline auto Reverse<R>::begin() noexcept
            {
                return (View<R>::_range.rbegin());
            }

            template <typename R>
            constexpr inline auto Reverse<R>::end() noexcept
            {
                return (View<R>::_range.rend());
            }



        } // namespace view
    }     // namespace range
} // namespace arc
