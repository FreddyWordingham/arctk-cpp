//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <tuple>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <template <typename...> typename T, typename... A, typename... B, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline bool any_equal_elems(const T<A...>& tup_0_, const T<B...>& tup_1_) noexcept;
        template <template <typename...> typename T, typename... A, typename... B, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline std::size_t num_equal_elems(const T<A...>& tup_0_, const T<B...>& tup_1_) noexcept;



    } // namespace tuple
} // namespace arc
