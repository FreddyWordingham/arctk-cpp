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
        //  -- Immutable --
        template <typename... A, typename F>
        constexpr inline void for_each(const std::tuple<A...>& tuple_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(const std::tuple<A...>& tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F, typename R>
        constexpr inline void for_each(const std::tuple<A...>& tuple_, const F& func_, R* res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_helper(const std::tuple<A...>& tuple_, const F& func_, R* res_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F>
        constexpr inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F, typename R>
        inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, R* res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, R* res_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename A, typename F, std::size_t... I>
        auto transform_helper(const A& arg_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F>
        auto transform(const std::tuple<A...>& tuple_, const F& func_) noexcept;

        //  -- Mutable --
        template <typename... A, typename F>
        constexpr inline void for_each(std::tuple<A...>* tuple_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F, typename R>
        constexpr inline void for_each(std::tuple<A...>* tuple_, const F& func_, R* res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* tuple_, const F& func_, R* res_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F>
        constexpr inline void for_each_zip(std::tuple<A...>* tuple_0_, std::tuple<A...>* tuple_1_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* tuple_0_, std::tuple<A...>* tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F, typename R>
        constexpr inline void for_each_zip(std::tuple<A...>* tuple_0_, std::tuple<A...>* tuple_1_, const F& func_, R* res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* tuple_0_, std::tuple<A...>* tuple_1_, const F& func_, R* res_, std::index_sequence<I...> /*unused*/) noexcept;



    } // namespace tuple
} // namespace arc
