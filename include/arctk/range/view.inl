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
        constexpr inline View<R>::View(const R& range_) noexcept
          : _range{range_}
        {
        }



    } // namespace range
} // namespace arc
