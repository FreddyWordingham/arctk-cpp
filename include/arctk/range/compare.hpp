//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == OPERATORS ==
        //  -- Container-Element Comparison --
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

        //  -- Container-Container Comparison --
        template <typename C, typename D>
        constexpr inline bool operator==(const C& lhs_, const D& rhs_) noexcept;
        template <typename C, typename D>
        constexpr inline bool operator!=(const C& lhs_, const D& rhs_) noexcept;
        template <typename C, typename D>
        constexpr inline bool operator<(const C& lhs_, const D& rhs_) noexcept;
        template <typename C, typename D>
        constexpr inline bool operator>(const C& lhs_, const D& rhs_) noexcept;
        template <typename C, typename D>
        constexpr inline bool operator<=(const C& lhs_, const D& rhs_) noexcept;
        template <typename C, typename D>
        constexpr inline bool operator>=(const C& lhs_, const D& rhs_) noexcept;



    } // namespace range
} // namespace arc
