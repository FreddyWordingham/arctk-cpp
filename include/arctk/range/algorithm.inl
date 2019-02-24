//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/algorithm.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <numeric>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Mathematical --
        template <typename C, typename T, typename>
        constexpr inline T accumulate(const C& cont_) noexcept
        {
            return (std::accumulate(cont_.begin(), cont_.end(), 0));
        }



    } // namespace range
} // namespace arc
