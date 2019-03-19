//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <type_traits>
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace pair
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename A0, typename A1, typename B0, typename B1>
        constexpr inline bool any_equal_elems(const std::pair<A0, A1>& pair_0_, const std::pair<B0, B1>& pair_1_) noexcept;
        template <typename A0, typename A1, typename B0, typename B1>
        constexpr inline std::size_t num_equal_elems(const std::pair<A0, A1>& pair_0_, const std::pair<B0, B1>& pair_1_) noexcept;



    } // namespace pair
} // namespace arc
