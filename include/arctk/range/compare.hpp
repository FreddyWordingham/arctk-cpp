//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Compare --
    template <typename C, typename T>
    constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T>
    constexpr inline bool operator!=(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T>
    constexpr inline bool operator<(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T>
    constexpr inline bool operator>(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T>
    constexpr inline bool operator<=(const C& lhs_, const T& rhs_) noexcept;
    template <typename C, typename T>
    constexpr inline bool operator>=(const C& lhs_, const T& rhs_) noexcept;



} // namespace arc
