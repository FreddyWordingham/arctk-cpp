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
        constexpr inline void for_each(const std::tuple<A...>& tuple_, const F& func_, R* const res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_helper(const std::tuple<A...>& tuple_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F>
        constexpr inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F, typename R>
        constexpr inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, R* const res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept;

        //  -- Mutable --
        template <typename... A, typename F>
        constexpr inline void for_each(std::tuple<A...>* const tuple_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* const tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F, typename R>
        constexpr inline void for_each(std::tuple<A...>* const tuple_, const F& func_, R* const res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* const tuple_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F>
        constexpr inline void for_each_zip(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_) noexcept;
        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept;
        template <typename... A, typename F, typename R>
        constexpr inline void for_each_zip(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_, R* const res_) noexcept;
        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept;


        template <typename Fn, typename Argument, std::size_t... Ns>
        auto tuple_transform_impl(Fn&& fn, Argument&& argument, std::index_sequence<Ns...>)
        {
            if constexpr (sizeof...(Ns) == 0)
                return std::tuple<>(); // empty tuple
            else if constexpr (std::is_same_v<decltype(fn(std::get<0>(argument))), void>)
            {
                (fn(std::get<Ns>(argument)), ...); // no return value expected
                return;
            }
            // then dispatch lvalue, rvalue ref, temporary
            else if constexpr (std::is_lvalue_reference_v<decltype(fn(std::get<0>(argument)))>)
            {
                return std::tie(fn(std::get<Ns>(argument))...);
            }
            else if constexpr (std::is_rvalue_reference_v<decltype(fn(std::get<0>(argument)))>)
            {
                return std::forward_as_tuple(fn(std::get<Ns>(argument))...);
            }
            else
            {
                return std::tuple(fn(std::get<Ns>(argument))...);
            }
        }

        template <typename Fn, typename... Ts>
        auto tuple_transform(Fn&& fn, const std::tuple<Ts...>& tuple)
        {
            return tuple_transform_impl(std::forward<Fn>(fn), tuple, std::make_index_sequence<sizeof...(Ts)>());
        }



    } // namespace tuple
} // namespace arc
