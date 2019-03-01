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
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Transform --
        template <typename R, typename F>
        constexpr inline void transform(R* const range_, const F& trans_) noexcept
        {
            assert(range_ != nullptr);

            std::for_each((*range_).begin(), (*range_).end(), trans_);
        }

        template <typename R, typename F>
        constexpr inline void transform(const R& range_, const F& trans_) noexcept
        {
            std::for_each(range_.begin(), range_.end(), trans_);
        }

        template <typename R, typename F, typename RO>
        constexpr inline void transform(const R& range_, const F& trans_, RO* const range_out_) noexcept
        {
            assert(range_out_ != nullptr);

            try
            {
                std::transform(range_.begin(), range_.end(), std::back_inserter(*range_out_), trans_);
            }
            catch (...)
            {
                std::exit(1);
            }
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
