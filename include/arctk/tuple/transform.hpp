//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <tuple>
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- For Each --
        template <typename... A, typename F>
        constexpr inline void for_each(const std::tuple<A...>& tuple_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(const std::tuple<A...>& tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F>
        constexpr inline void for_each(std::tuple<A...>* tuple_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename... B, typename F, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<B...>& tuple_1_, const F& func_) noexcept;
        template <typename... A, typename... B, typename F, typename std::size_t... I, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<B...>& tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename... B, typename F, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip(std::tuple<A...>* tuple_0_, std::tuple<B...>* tuple_1_, const F& func_) noexcept;
        template <typename... A, typename... B, typename F, typename std::size_t... I, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* tuple_0_, std::tuple<B...>* tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;

        //  -- Transform --
        template <typename... A, typename F>
        constexpr auto transform(const std::tuple<A...>& tuple_, const F& func_) noexcept;
        template <typename A, typename F, std::size_t... I>
        constexpr auto transform_helper(const A& arg_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;



    } // namespace tuple
} // namespace arc
