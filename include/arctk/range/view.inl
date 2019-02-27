//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename R>
        constexpr inline View<R>::View() noexcept
          : _range{nullptr}
        {
        }

        template <typename R>
        constexpr inline View<R>::View(R* const range_) noexcept
          : _range{range_}
        {
            assert(range_ != nullptr);
        }



        //  == METHODS ==
        //  -- Setters --
        template <typename R>
        constexpr inline void View<R>::set_range(R* const range_) noexcept
        {
            assert(range_ != nullptr);

            _range = range_;
        }



    } // namespace range
} // namespace arc
