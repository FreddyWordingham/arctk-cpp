//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc::math
{



    //  == FUNCTIONS ==
    //  -- Properties --
    template <typename T>
    constexpr inline T sign(T n_) noexcept;
    template <typename T>
    constexpr inline bool is_positive(T n_) noexcept;
    template <typename T>
    constexpr inline bool is_negative(T n_) noexcept;
    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    constexpr inline bool is_even(T n_) noexcept;
    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    constexpr inline bool is_odd(T n_) noexcept;
    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    constexpr bool is_prime(T n_) noexcept;



} // namespace arc::math
