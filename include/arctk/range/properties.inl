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
            const auto dist{std::distance(range_.begin(), range_.end())};

            assert(dist >= 0);

            return (static_cast<std::size_t>(dist));
        }

        template <typename R, typename F>
        constexpr inline bool all_of(const R& range_, const F& pred_) noexcept
        {
            return (std::all_of(range_.begin(), range_.end(), pred_));
        }

        template <typename R, typename F>
        constexpr inline bool any_of(const R& range_, const F& pred_) noexcept
        {
            return (std::any_of(range_.begin(), range_.end(), pred_));
        }

        template <typename R, typename F>
        constexpr inline bool none_of(const R& range_, const F& pred_) noexcept
        {
            return (std::none_of(range_.begin(), range_.end(), pred_));
        }

        template <typename R, typename T>
        constexpr inline auto count(const R& range_, const T& val_) noexcept
        {
            return (std::count(range_.begin(), range_.end(), val_));
        }

        template <typename R, typename F>
        constexpr inline auto count_if(const R& range_, const F& pred_) noexcept
        {
            return (std::count_if(range_.begin(), range_.end(), pred_));
        }


        //  -- Mathematical --
        template <typename R>
        constexpr inline auto min(const R& range_) noexcept
        {
            assert(!range_.empty());

            return (*std::min_element(range_.begin(), range_.end()));
        }

        template <typename R>
        constexpr inline auto max(const R& range_) noexcept
        {
            assert(!range_.empty());

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
