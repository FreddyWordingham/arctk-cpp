//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <type_traits>
// #include "arctk/type/arithmetic.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Integral --
        template <typename T, typename R = decltype(std::declval<T>() * std::declval<T>())>
        constexpr inline R sq(const T& x_) noexcept;
        template <typename T, typename R = decltype(std::declval<T>() * std::declval<T>() * std::declval<T>())>
        constexpr inline R cube(const T& x_) noexcept;

        //  -- Power --
        template <typename T>
        constexpr inline T pow(const T& x_, int power_) noexcept;



    } // namespace math
} // namespace arc
