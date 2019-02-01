//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/math/compare.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include <cassert>
#include <cmath>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Compare --
        template <typename T>
        constexpr inline bool zero(T x_, T epsilon_) noexcept
        {
            static_assert(std::is_floating_point<T>::value);
            assert(epsilon_ > 0.0);

            return (std::abs(x_) <= epsilon_);
        }

        template <typename T>
        constexpr inline bool equal(T x_, T y_, T epsilon_) noexcept
        {
            static_assert(std::is_floating_point<T>::value);
            assert(epsilon_ > 0.0);

            return (std::abs(x_ - y_) <= (std::abs(x_) < std::abs(y_) ? std::abs(y_) : std::abs(x_)) * epsilon_);
        }



    } // namespace math
} // namespace arc
