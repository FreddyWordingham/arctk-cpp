//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Print --
    template <typename S, typename C, typename T = typename C::value_type>
    constexpr inline S& operator<<(S& lhs_, const C& rhs_) noexcept;



} // namespace arc
