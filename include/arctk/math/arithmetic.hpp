//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <arctk/type/arithmetic.hpp>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <typename T>
    constexpr inline const T operator++(T& rhs_) noexcept;
    template <typename T>
    constexpr inline const T operator--(T& rhs_) noexcept;
    template <typename T>
    constexpr inline const T operator++(T& lhs_, int) noexcept;
    template <typename T>
    constexpr inline const T operator--(T& lhs_, int) noexcept;

    //  -- Arithmetic --
    template <typename T>
    constexpr inline const T operator+(const T& rhs_) noexcept;
    template <typename T>
    constexpr inline const T operator-(const T& rhs_) noexcept;



} // namespace arc
