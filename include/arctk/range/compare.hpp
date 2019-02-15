//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <type_traits>

//  -- Arc --
#include <arctk/type/is_iterable.hpp>



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == OPERATORS ==
        //  -- Compare --
        template <typename C, typename T, typename>
        constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept;
        template <typename C, typename T, typename>
        constexpr inline bool operator!=(const C& lhs_, const T& rhs_) noexcept;
        template <typename C, typename T, typename>
        constexpr inline bool operator<(const C& lhs_, const T& rhs_) noexcept;
        template <typename C, typename T, typename>
        constexpr inline bool operator>(const C& lhs_, const T& rhs_) noexcept;
        template <typename C, typename T, typename>
        constexpr inline bool operator<=(const C& lhs_, const T& rhs_) noexcept;
        template <typename C, typename T, typename>
        constexpr inline bool operator>=(const C& lhs_, const T& rhs_) noexcept;



    } // namespace range
} // namespace arc
