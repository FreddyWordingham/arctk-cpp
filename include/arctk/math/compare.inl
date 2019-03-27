//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/math/compare.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include <cassert>
#include <cmath>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename T, typename>
        constexpr inline bool zero(const T x_, const T epsilon_) noexcept
        {
            assert(epsilon_ > T{0});

            return (std::abs(x_) <= epsilon_);
        }

        template <typename T, typename>
        constexpr inline bool equal(const T x_, const T y_, const T epsilon_) noexcept
        {
            assert(epsilon_ > T{0});

            return (std::abs(x_ - y_) <= (std::abs(x_) < std::abs(y_) ? std::abs(y_) : std::abs(x_)) * epsilon_);
        }



    } // namespace math
} // namespace arc
