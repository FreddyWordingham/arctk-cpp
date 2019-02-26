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
        template <typename R, typename T>
        constexpr inline bool bounded(const R& range_, const T& x_) noexcept
        {
            assert(!range_.empty());
            assert(is_sorted(range_));

            return ((range_.front() <= x_) && (range_.back() >= x_));
        }

        template <typename R, typename T>
        constexpr inline auto lower_index(const R& range_, const T& x_) noexcept
        {
            assert(bounded(range_, x_));

            return (std::distance(range_.begin(), std::lower_bound(range_.begin(), range_.end(), x_)) - 1);
        }

        template <typename R, typename T>
        constexpr inline auto upper_index(const R& range_, const T& x_) noexcept
        {
            assert(bounded(range_, x_));

            return (std::distance(range_.begin(), std::upper_bound(range_.begin(), range_.end(), x_)));
        }

        template <typename R, typename T>
        constexpr inline auto find_index(const R& range_, const T& x_) noexcept
        {
            const auto it{std::find(range_.begin(), range_.end(), x_)};

            return (it == range_.end() ? std::nullopt : std::make_optional(std::distance(range_.begin(), it)));
        }



    } // namespace range
} // namespace arc
