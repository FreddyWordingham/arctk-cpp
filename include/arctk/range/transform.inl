//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/transform.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- For Each --
        template <typename R, typename F>
        constexpr inline void for_each(R* const range_, const F& trans_) noexcept
        {
            assert(range_ != nullptr);

            std::for_each((*range_).begin(), (*range_).end(), trans_);
        }

        template <typename R, typename F>
        constexpr inline void for_each(const R& range_, const F& trans_) noexcept
        {
            std::for_each(range_.begin(), range_.end(), trans_);
        }


        //  -- Order --
        template <typename R>
        constexpr inline void sort(R* const range_) noexcept
        {
            assert(range_ != nullptr);

            std::sort((*range_).begin(), (*range_).end());
        }

        template <typename R>
        constexpr inline void reverse(R* const range_) noexcept
        {
            assert(range_ != nullptr);

            std::reverse((*range_).begin(), (*range_).end());
        }

        template <typename R, typename I>
        constexpr inline void rotate(R* const range_, const I n_) noexcept
        {
            assert(range_ != nullptr);
            assert(n_ >= 0);

            std::rotate((*range_).begin(), (*range_).begin() + n_, (*range_).end());
        }



    } // namespace range
} // namespace arc
