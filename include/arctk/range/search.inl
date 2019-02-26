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



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        template <typename R, typename T>
        constexpr inline bool bounded(const R& range_, const T& x_) noexcept
        {
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
        constexpr inline auto find(const R& range_, const T& x_) noexcept
        {
            return (std::find(range_.begin(), range_.end(), x_));
        }



    } // namespace range
} // namespace arc
