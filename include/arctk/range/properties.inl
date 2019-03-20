//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/properties.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename R>
        constexpr inline std::size_t num_its(const R& range_) noexcept
        {
            const auto dist{std::distance(std::begin(range_), std::end(range_))};

            assert(dist >= 0);

            return (static_cast<std::size_t>(dist));
        }

        template <typename R, typename F>
        constexpr inline bool all_of(const R& range_, const F& pred_) noexcept
        {
            return (std::all_of(std::begin(range_), std::end(range_), pred_));
        }

        template <typename R, typename F>
        constexpr inline bool any_of(const R& range_, const F& pred_) noexcept
        {
            return (std::any_of(std::begin(range_), std::end(range_), pred_));
        }

        template <typename R, typename F>
        constexpr inline bool none_of(const R& range_, const F& pred_) noexcept
        {
            return (std::none_of(std::begin(range_), std::end(range_), pred_));
        }

        template <typename R, typename T>
        constexpr inline auto count(const R& range_, const T& val_) noexcept
        {
            return (std::count(std::begin(range_), std::end(range_), val_));
        }

        template <typename R, typename F>
        constexpr inline auto count_if(const R& range_, const F& pred_) noexcept
        {
            return (std::count_if(std::begin(range_), std::end(range_), pred_));
        }


        //  -- Mathematical --
        template <typename R>
        constexpr inline auto min(const R& range_) noexcept
        {
            assert(!range_.empty());

            return (*std::min_element(std::begin(range_), std::end(range_)));
        }

        template <typename R>
        constexpr inline auto max(const R& range_) noexcept
        {
            assert(!range_.empty());

            return (*std::max_element(std::begin(range_), std::end(range_)));
        }


        //  -- Order --
        template <typename R>
        constexpr inline bool is_sorted(const R& range_) noexcept
        {
            return (std::is_sorted(std::begin(range_), std::end(range_)));
        }



    } // namespace range
} // namespace arc
