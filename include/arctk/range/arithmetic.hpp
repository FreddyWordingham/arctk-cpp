//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/type/traits.hpp"

//  -- Std --
#include <iterator>
#include <type_traits>
#include <vector>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Assignment --
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline R& operator+=(R& lhs_, const T& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline R& operator-=(R& lhs_, const T& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline R& operator*=(R& lhs_, const T& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline R& operator/=(R& lhs_, const T& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline R& operator%=(R& lhs_, const T& rhs_) noexcept;

    //  -- Arithmetic --
    template <typename R, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    constexpr inline auto operator+(const R& range_) noexcept;
    template <typename R, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    constexpr inline auto operator-(const R& range_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) + std::declval<T>())> operator+(const R& lhs_, const T& rhs_) noexcept;
    template <typename Rl, typename Rr, typename = typename std::enable_if_t<type::is_rangeable_v<Rl> && type::is_rangeable_v<Rr>>>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) + *(std::begin(std::declval<Rr>())))> operator+(const Rl& lhs_, const Rr& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) - std::declval<T>())> operator-(const R& lhs_, const T& rhs_) noexcept;
    template <typename Rl, typename Rr, typename = typename std::enable_if_t<type::is_rangeable_v<Rl> && type::is_rangeable_v<Rr>>>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) - *(std::begin(std::declval<Rr>())))> operator-(const Rl& lhs_, const Rr& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) * std::declval<T>())> operator*(const R& lhs_, const T& rhs_) noexcept;
    template <typename Rl, typename Rr, typename = typename std::enable_if_t<type::is_rangeable_v<Rl> && type::is_rangeable_v<Rr>>>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) * *(std::begin(std::declval<Rr>())))> operator*(const Rl& lhs_, const Rr& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) / std::declval<T>())> operator/(const R& lhs_, const T& rhs_) noexcept;
    template <typename Rl, typename Rr, typename = typename std::enable_if_t<type::is_rangeable_v<Rl> && type::is_rangeable_v<Rr>>>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) / *(std::begin(std::declval<Rr>())))> operator/(const Rl& lhs_, const Rr& rhs_) noexcept;
    template <typename R, typename T, typename = typename std::enable_if_t<type::is_rangeable_v<R>>>
    inline std::vector<decltype(*(std::begin(std::declval<R>())) % std::declval<T>())> operator%(const R& lhs_, const T& rhs_) noexcept;
    template <typename Rl, typename Rr, typename = typename std::enable_if_t<type::is_rangeable_v<Rl> && type::is_rangeable_v<Rr>>>
    inline std::vector<decltype(*(std::begin(std::declval<Rl>())) % *(std::begin(std::declval<Rr>())))> operator%(const Rl& lhs_, const Rr& rhs_) noexcept;



} // namespace arc
