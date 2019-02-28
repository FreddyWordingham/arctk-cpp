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
        //  -- Transform --
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

            for_each_zip_helper_helper(tuple_0_, tuple_1_, func_, std::make_index_sequence<size>{});
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

            for_each_zip_helper_helper(tuple_0_, tuple_1_, func_, res_, std::make_index_sequence<size>{});
        }

        template <typename... A, typename F, typename R, typename std::size_t... I>
        constexpr inline void for_each_zip_helper(std::tuple<A...>* const tuple_0_, std::tuple<A...>* const tuple_1_, const F& func_, R* const res_, std::index_sequence<I...> /*unused*/) noexcept
        {
            using swallow = int[];
            (void)swallow{1, (res_->emplace_back(func_(std::get<I>(*tuple_0_), std::get<I>(*tuple_1_))), void(), int{})...};
        }



    } // namespace tuple
} // namespace arc
