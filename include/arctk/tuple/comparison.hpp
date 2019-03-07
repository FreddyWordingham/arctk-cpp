//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <tuple>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename... A, typename... B, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline auto any_equal_elems(const std::tuple<A...>& tup_0_, const std::tuple<B...>& tup_1_) noexcept;
        template <typename... A, typename... B, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline auto num_equal_elems(const std::tuple<A...>& tup_0_, const std::tuple<B...>& tup_1_) noexcept;



    } // namespace tuple
} // namespace arc
