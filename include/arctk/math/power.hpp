//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <type_traits>



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



    } // namespace math
} // namespace arc
