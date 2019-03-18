//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/type/traits.hpp"

//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Comparison --
    template <typename RL, typename RR, typename = typename std::enable_if_t<type::is_rangeable_v<RL> && type::is_rangeable_v<RR>>>
    constexpr inline bool operator==(const RL& lhs_, const RR& rhs_) noexcept;
    template <typename RL, typename RR, typename = typename std::enable_if_t<type::is_rangeable_v<RL> && type::is_rangeable_v<RR>>>
    constexpr inline bool operator!=(const RL& lhs_, const RR& rhs_) noexcept;



} // namespace arc
