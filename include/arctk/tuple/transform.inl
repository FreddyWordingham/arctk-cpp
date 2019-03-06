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
        //  -- Immutable --
        template <typename... A, typename F>
        constexpr inline void for_each(const std::tuple<A...>& tuple_, const F& func_) noexcept
        {
            const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};

            for_each_helper(tuple_, func_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(const std::tuple<A...>& tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(tuple_)), void(), int{})...};
        }

        template <typename... A, typename F, typename R>
        constexpr inline void for_each(const std::tuple<A...>& tuple_, const F& func_, R* const res_) noexcept
        {
            const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};
            res_->reserve(size);

            for_each_helper(tuple_, func_, res_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_helper(const std::tuple<A...>& tuple_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (res_->emplace_back(func_(std::get<I>(tuple_))), void(), int{})...};
        }

        template <typename... A, typename... B, typename F>
        constexpr inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<B...>& tuple_1_, const F& func_) noexcept
        {
            const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};
            assert(std::tuple_size_v<std::remove_reference_t<std::tuple<B...>>> == size);

            for_each_zip_helper(tuple_0_, tuple_1_, func_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename... B, typename F, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<B...>& tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(tuple_0_), std::get<I>(tuple_1_)), void(), int{})...};
        }

        template <typename... A, typename F, typename R>
        inline void for_each_zip(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, R* const res_) noexcept
        {
            try
            {
                const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};
                res_->reserve(size);

                for_each_zip_helper(tuple_0_, tuple_1_, func_, res_, std::make_index_sequence<size>{});
            }
            catch (...)
            {
                std::exit(1);
            }
        }

        template <typename... A, typename F, typename R, typename std::size_t... I>
        inline void for_each_zip_helper(const std::tuple<A...>& tuple_0_, const std::tuple<A...>& tuple_1_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept
        {
            try
            {
                using swallow = int[];
                (void)swallow{1, (res_->emplace_back(func_(std::get<I>(tuple_0_), std::get<I>(tuple_1_))), void(), int{})...};
            }
            catch (...)
            {
                std::exit(1);
            }
        }

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


        //  -- Mutable --
        template <typename... A, typename F>
        constexpr inline void for_each(std::tuple<A...>* const tuple_, const F& func_) noexcept
        {
            const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};

            for_each_helper(tuple_, func_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* const tuple_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(*tuple_)), void(), int{})...};
        }

        template <typename... A, typename F, typename R>
        constexpr inline void for_each(std::tuple<A...>* const tuple_, const F& func_, R* const res_) noexcept
        {
            const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};
            res_->reserve(size);

            for_each_helper(tuple_, func_, res_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_helper(std::tuple<A...>* const tuple_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (res_->emplace_back(func_(std::get<I>(*tuple_))), void(), int{})...};
        }

        template <typename... A, typename F>
        constexpr inline void for_each_zip(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_) noexcept
        {
            const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};

            for_each_zip_helper(tuple_0_, tuple_1_, func_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename F, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (func_(std::get<I>(*tuple_0_), std::get<I>(*tuple_1_)), void(), int{})...};
        }

        template <typename... A, typename F, typename R>
        constexpr inline void for_each_zip(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_, R* const res_) noexcept
        {
            const auto size{std::tuple_size_v<std::remove_reference_t<std::tuple<A...>>>};
            res_->reserve(size);

            for_each_zip_helper(tuple_0_, tuple_1_, func_, res_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (res_->emplace_back(func_(std::get<I>(*tuple_0_), std::get<I>(*tuple_1_))), void(), int{})...};
        }



    } // namespace tuple
} // namespace arc
