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
        constexpr inline View<R>::View(R* const range_) noexcept
          : _range{range_}
        {
            assert(range_ != nullptr);
        }



    } // namespace range
} // namespace arc
