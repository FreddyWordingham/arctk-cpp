//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <arctk/type/traits.hpp>

//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    // namespace range
    // {



    //  == OPERATORS ==
    //  -- Comparison --
    template <typename C, typename T, typename = std::enable_if_t<type::is_rangeable_v<C>>>
    constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T, typename = std::enable_if_t<type::is_rangeable_v<C>>>
    constexpr inline bool operator!=(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T, typename = std::enable_if_t<type::is_rangeable_v<C>>>
    constexpr inline bool operator<(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T, typename = std::enable_if_t<type::is_rangeable_v<C>>>
    constexpr inline bool operator>(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T, typename = std::enable_if_t<type::is_rangeable_v<C>>>
    constexpr inline bool operator<=(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T, typename = std::enable_if_t<type::is_rangeable_v<C>>>
    constexpr inline bool operator>=(const C& lhs_, const T& rhs_) noexcept;



    // } // namespace range
} // namespace arc
