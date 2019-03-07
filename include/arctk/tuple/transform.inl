//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/tuple/transform.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <tuple>
#include <type_traits>
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- For Each --
        template <typename... A, typename F>
        constexpr inline void for_each(const std::tuple<A...>& tuple_, const F& func_) noexcept
        {
            for_each_helper(tuple_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(const std::tuple<A...>& tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(tuple_)), void(), int{})...};
        }

        template <typename... A, typename F>
        constexpr inline void for_each(std::tuple<A...>* const tuple_, const F& func_) noexcept
        {
            assert(tuple_ != nullptr);

            for_each_helper(tuple_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* const tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            assert(tuple_ != nullptr);

            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(*tuple_)), void(), int{})...};
        }

        template <typename... A, typename... B, typename F, typename>
        constexpr inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<B...>& tuple_1_, const F& func_) noexcept
        {
            for_each_zip_helper(tuple_0_, tuple_1_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <typename... A, typename... B, typename F, typename std::size_t... I, typename>
        constexpr inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<B...>& tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(tuple_0_), std::get<I>(tuple_1_)), void(), int{})...};
        }

        template <typename... A, typename... B, typename F, typename>
        constexpr inline void for_each_zip(std::tuple<A...>* const tuple_0_, std::tuple<B...>* const tuple_1_, const F& func_) noexcept
        {
            assert(tuple_0_ != nullptr);
            assert(tuple_1_ != nullptr);

            for_each_zip_helper(tuple_0_, tuple_1_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <typename... A, typename... B, typename F, typename std::size_t... I, typename>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* const tuple_0_, std::tuple<B...>* const tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            assert(tuple_0_ != nullptr);
            assert(tuple_1_ != nullptr);

            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(*tuple_0_), std::get<I>(*tuple_1_)), void(), int{})...};
        }


        //  -- Transform --
        template <typename... A, typename F>
        auto transform(const std::tuple<A...>& tuple_, const F& func_) noexcept
        {
            return (transform_helper(tuple_, func_, std::make_index_sequence<sizeof...(A)>{}));
        }

        template <typename A, typename F, std::size_t... I>
        auto transform_helper(const A& arg_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            if constexpr (sizeof...(I) == 0)
            {
                return (std::tuple<>{});
            }

            if constexpr (std::is_same_v<decltype(func_(std::get<0>(arg_))), void>)
            {
                (func_(std::get<I>(arg_)), ...);

                return;
            }

            if constexpr (std::is_lvalue_reference_v<decltype(func_(std::get<0>(arg_)))>)
            {
                return (std::tie(func_(std::get<I>(arg_))...));
            }

            if constexpr (std::is_rvalue_reference_v<decltype(func_(std::get<0>(arg_)))>)
            {
                return (std::forward_as_tuple(func_(std::get<I>(arg_))...));
            }

            return (std::tuple{func_(std::get<I>(arg_))...});
        }



    } // namespace tuple
} // namespace arc
