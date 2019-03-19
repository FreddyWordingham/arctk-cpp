//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <type_traits>
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- For Each --
        template <template <typename...> typename T, typename... A, typename F>
        constexpr inline void for_each(const T<A...>& tuple_, const F& func_) noexcept;
        template <template <typename...> typename T, typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(const T<A...>& tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <template <typename...> typename T, typename... A, typename F>
        constexpr inline void for_each(T<A...>* tuple_, const F& func_) noexcept;
        template <template <typename...> typename T, typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(T<A...>* tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <template <typename...> typename T, typename... A, typename... B, typename F, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip(const T<A...>& tuple_0_, const T<B...>& tuple_1_, const F& func_) noexcept;
        template <template <typename...> typename T, typename... A, typename... B, typename F, typename std::size_t... I, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip_helper(const T<A...>& tuple_0_, const T<B...>& tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <template <typename...> typename T, typename... A, typename... B, typename F, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip(T<A...>* tuple_0_, T<B...>* tuple_1_, const F& func_) noexcept;
        template <template <typename...> typename T, typename... A, typename... B, typename F, typename std::size_t... I, typename = typename std::enable_if_t<sizeof...(A) == sizeof...(B)>>
        constexpr inline void for_each_zip_helper(T<A...>* tuple_0_, T<B...>* tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;

        //  -- Transform --
        template <template <typename...> typename T, typename... A, typename F>
        constexpr auto transform(const T<A...>& tuple_, const F& func_) noexcept;
        template <typename A, typename F, std::size_t... I>
        constexpr auto transform_helper(const A& arg_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;



    } // namespace tuple
} // namespace arc
