//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/transform.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <algorithm>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Transform --
        template <typename R, typename F>
        constexpr inline void transform(R& range_, F func_) noexcept
        {
            std::for_each(range_.begin(), range_.end(), func_);
        }

        template <typename R, typename F, typename Ro>
        constexpr inline void transform(R& range_, F func_, Ro& range_out_) noexcept
        {
            std::transform(range_.begin(), range_.end(), std::back_inserter(range_out_), func_);
        }



    } // namespace range
} // namespace arc
