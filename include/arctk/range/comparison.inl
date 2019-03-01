//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/comparison.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/properties.inl"

//  -- Std --
#include <algorithm>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Comparison --
    template <typename RL, typename RR, typename>
    constexpr inline bool operator==(const RL& lhs_, const RR& rhs_) noexcept
    {
        return ((range::num_its(lhs_) == range::num_its(rhs_)) && std::equal(lhs_.begin(), lhs_.end(), rhs_.begin()));
    }

    template <typename RL, typename RR, typename>
    constexpr inline bool operator!=(const RL& lhs_, const RR& rhs_) noexcept
    {
        return (!(lhs_ == rhs_));
    }



} // namespace arc
