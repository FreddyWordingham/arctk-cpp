//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename R>
        constexpr inline View<R>::View(const R& range_) noexcept
          : _range{range_}
        {
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename R>
        constexpr inline typename View<R>::size_type View<R>::size() const noexcept
        {
            return (_range.size());
        }



    } // namespace range
} // namespace arc
