//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/math/compare.hpp>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Zero --
        template <typename T>
        constexpr inline bool zero(T x_, T epsilon_) noexcept
        {
            static_assert(std::is_floating_point<T>::value);
            assert(epsilon_ > 0.0);

            return (std::abs(x_) <= epsilon_);
        }


        //  -- Equal --
        template <typename T>
        constexpr inline bool equal(T x_, T y_, T epsilon_) noexcept
        {
            static_assert(std::is_floating_point<T>::value);
            assert(epsilon_ > 0.0);

            return (std::abs(x_ - y_) <= (std::abs(x_) < std::abs(y_) ? std::abs(y_) : std::abs(x_)) * epsilon_);
        }



    } // namespace math
} // namespace arc
