//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/properties.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <algorithm>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename R, typename F>
        constexpr inline bool all_of(const R& range_, F pred_) noexcept
        {
            return (std::all_of(range_.begin(), range_.end(), pred_));
        }

        template <typename R, typename F>
        constexpr inline bool any_of(const R& range_, F pred_) noexcept
        {
            return (std::any_of(range_.begin(), range_.end(), pred_));
        }

        template <typename R, typename F>
        constexpr inline bool none_of(const R& range_, F pred_) noexcept
        {
            return (std::none_of(range_.begin(), range_.end(), pred_));
        }

        template <typename R, typename T>
        constexpr inline auto count(const R& range_, const T& val_) noexcept
        {
            return (std::count(range_.begin(), range_.end(), val_));
        }

        template <typename R, typename F>
        constexpr inline auto count_if(const R& range_, F pred_) noexcept
        {
            return (std::count_if(range_.begin(), range_.end(), pred_));
        }


        //  -- Mathematical --
        template <typename R>
        constexpr inline auto min(const R& range_) noexcept
        {
            return (*std::min_element(range_.begin(), range_.end()));
        }

        template <typename R>
        constexpr inline auto max(const R& range_) noexcept
        {
            return (*std::max_element(range_.begin(), range_.end()));
        }


        //  -- Order --
        template <typename R>
        constexpr inline bool is_sorted(const R& range_) noexcept
        {
            return (std::is_sorted(range_.begin(), range_.end()));
        }



    } // namespace range
} // namespace arc
