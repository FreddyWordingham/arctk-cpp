//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/math/compare.hpp>

//  -- Std --
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iterator>



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



    //  -- Comparison --
    template <typename T>
    constexpr inline bool operator==(const T& lhs_, const T& rhs_) noexcept
    {
        return (std::equal(std::begin(lhs_), std::end(lhs_), std::begin(rhs_), std::end(rhs_)));
    }

    template <typename T>
    constexpr inline bool operator!=(const T& lhs_, const T& rhs_) noexcept
    {
        return (!(lhs_ == rhs_));
    }



} // namespace arc
