//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == OPERATORS ==
        //  -- Comparison --
        template <typename C, typename T>
        constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept;
        template <typename C, typename T>
        constexpr inline bool operator!=(const C& lhs_, const T& rhs_) noexcept;



    } // namespace range
} // namespace arc
