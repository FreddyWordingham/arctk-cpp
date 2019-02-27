//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/comparison.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <algorithm>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Comparison --
    template <typename Rl, typename Rr>
    constexpr inline bool operator==(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        return ((lhs_.size() == rhs_.size()) && std::equal(lhs_.begin(), lhs_.end(), rhs_.begin()));
    }

    template <typename Rl, typename Rr>
    constexpr inline bool operator!=(const Rl& lhs_, const Rr& rhs_) noexcept
    {
        return (!(lhs_ == rhs_));
    }



} // namespace arc
