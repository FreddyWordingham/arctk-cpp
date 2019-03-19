//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/tuple/transform.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <tuple>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- For Each --
        template <template <typename...> typename T, typename... A, typename F>
        constexpr inline void for_each(const T<A...>& tuple_, const F& func_) noexcept
        {
            for_each_helper(tuple_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <template <typename...> typename T, typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(const T<A...>& tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(tuple_)), void(), int{})...};
        }

        template <template <typename...> typename T, typename... A, typename F>
        constexpr inline void for_each(T<A...>* const tuple_, const F& func_) noexcept
        {
            assert(tuple_ != nullptr);

            for_each_helper(tuple_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <template <typename...> typename T, typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(T<A...>* const tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            assert(tuple_ != nullptr);

            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(*tuple_)), void(), int{})...};
        }

        template <template <typename...> typename T, typename... A, typename... B, typename F, typename>
        constexpr inline void for_each_zip(const T<A...>& tuple_0_, const T<B...>& tuple_1_, const F& func_) noexcept
        {
            for_each_zip_helper(tuple_0_, tuple_1_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <template <typename...> typename T, typename... A, typename... B, typename F, typename std::size_t... I, typename>
        constexpr inline void for_each_zip_helper(const T<A...>& tuple_0_, const T<B...>& tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(tuple_0_), std::get<I>(tuple_1_)), void(), int{})...};
        }

        template <template <typename...> typename T, typename... A, typename... B, typename F, typename>
        constexpr inline void for_each_zip(T<A...>* const tuple_0_, T<B...>* const tuple_1_, const F& func_) noexcept
        {
            assert(tuple_0_ != nullptr);
            assert(tuple_1_ != nullptr);

            for_each_zip_helper(tuple_0_, tuple_1_, func_, std::make_index_sequence<sizeof...(A)>{});
        }

        template <template <typename...> typename T, typename... A, typename... B, typename F, typename std::size_t... I, typename>
        constexpr inline void for_each_zip_helper(T<A...>* const tuple_0_, T<B...>* const tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            assert(tuple_0_ != nullptr);
            assert(tuple_1_ != nullptr);

            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(*tuple_0_), std::get<I>(*tuple_1_)), void(), int{})...};
        }


        //  -- Transform --
        template <template <typename...> typename T, typename... A, typename F>
        constexpr auto transform(const T<A...>& tuple_, const F& func_) noexcept
        {
            return (transform_helper(tuple_, func_, std::make_index_sequence<sizeof...(A)>{}));
        }

        template <typename A, typename F, std::size_t... I>
        constexpr auto transform_helper(const A& arg_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            if constexpr (sizeof...(I) == 0) // NOLINT
            {                                // NOLINT
                return (std::tuple<>{});
            }

            if constexpr (std::is_same_v<decltype(func_(std::get<0>(arg_))), void>) // NOLINT
            {                                                                       // NOLINT
                (func_(std::get<I>(arg_)), ...);

                return;
            }

            if constexpr (std::is_lvalue_reference_v<decltype(func_(std::get<0>(arg_)))>) // NOLINT
            {                                                                             // NOLINT
                return (std::tie(func_(std::get<I>(arg_))...));
            }

            if constexpr (std::is_rvalue_reference_v<decltype(func_(std::get<0>(arg_)))>) // NOLINT
            {                                                                             // NOLINT
                return (std::forward_as_tuple(func_(std::get<I>(arg_))...));
            }

            return (std::tuple{func_(std::get<I>(arg_))...}); // NOLINT
        }



    } // namespace tuple
} // namespace arc
