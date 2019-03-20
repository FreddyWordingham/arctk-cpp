//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/search.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/properties.inl"

//  -- Std --
#include <algorithm>
#include <cassert>
#include <iterator>
#include <optional>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Search --
        template <typename R, typename T>
        constexpr inline bool bounded(const R& range_, const T& x_) noexcept
        {
            assert(!range_.empty());
            assert(is_sorted(range_));

            return ((*std::begin(range_) <= x_) && (*std::prev(std::end(range_)) >= x_));
        }

        template <typename R, typename T>
        constexpr inline auto lower_index(const R& range_, const T& x_) noexcept
        {
            assert(bounded(range_, x_));

            return (std::distance(std::begin(range_), std::lower_bound(std::begin(range_), std::end(range_), x_)) - 1);
        }

        template <typename R, typename T>
        constexpr inline auto upper_index(const R& range_, const T& x_) noexcept
        {
            assert(bounded(range_, x_));

            return (std::distance(std::begin(range_), std::upper_bound(std::begin(range_), std::end(range_), x_)));
        }

        template <typename R, typename T>
        constexpr inline auto find_index(const R& range_, const T& val_) noexcept
        {
            const auto it{std::find(std::begin(range_), std::end(range_), val_)};

            return (it == std::end(range_) ? std::nullopt : std::make_optional(std::distance(std::begin(range_), it)));
        }

        template <typename R, typename F>
        constexpr inline auto find_index_if(const R& range_, const F& pred_) noexcept
        {
            const auto it{std::find_if(std::begin(range_), std::end(range_), pred_)};

            return (it == std::end(range_) ? std::nullopt : std::make_optional(std::distance(std::begin(range_), it)));
        }

        template <typename R, typename F>
        constexpr inline auto find_index_if_not(const R& range_, const F& pred_) noexcept
        {
            const auto it{std::find_if_not(std::begin(range_), std::end(range_), pred_)};

            return (it == std::end(range_) ? std::nullopt : std::make_optional(std::distance(std::begin(range_), it)));
        }



    } // namespace range
} // namespace arc
