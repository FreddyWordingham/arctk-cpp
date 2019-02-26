//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/transform.hpp" // IWYU pragma: export



//  == IMPORTS ==
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
        //  -- Transform --
        template <typename R, typename F>
        constexpr inline void transform(R* const range_, F func_) noexcept
        {
            assert(range_ != nullptr);

            std::for_each((*range_).begin(), (*range_).end(), func_);
        }

        template <typename R, typename F>
        constexpr inline void transform(const R& range_, F func_) noexcept
        {
            std::for_each(range_.begin(), range_.end(), func_);
        }

        template <typename R, typename F, typename Ro>
        constexpr inline void transform(const R& range_, F func_, Ro* const range_out_) noexcept
        {
            assert(range_out_ != nullptr);

            std::transform(range_.begin(), range_.end(), std::back_inserter(*range_out_), func_);
        }


        //  -- Order --
        template <typename R>
        constexpr inline void sort(R* const range_) noexcept
        {
            std::sort((*range_).begin(), (*range_).end());
        }

        template <typename R>
        constexpr inline void reverse(R* const range_) noexcept
        {
            std::reverse((*range_).begin(), (*range_).end());
        }

        template <typename R, typename I>
        constexpr inline void rotate(R* const range_, const I n_) noexcept
        {
            assert(n_ >= 0);

            std::rotate((*range_).begin(), (*range_).begin() + n_, (*range_).end());
        }



    } // namespace range
} // namespace arc
