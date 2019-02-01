//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/math/power.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Integral --
        template <typename T, typename R>
        constexpr inline R sq(const T& x_) noexcept
        {
            return (x_ * x_);
        }

        template <typename T, typename R>
        constexpr inline R cube(const T& x_) noexcept
        {
            return ((x_ * x_) * x_);
        }


        //  -- Power --
        template <typename T>
        constexpr inline T pow(const T& x_, const int power_) noexcept
        {
            if (power_ == 0)
            {
                return (1);
            }

            if (power_ < 0)
            {
                return (pow(x_, -power_));
            }

            if (power_ == 1)
            {
                return (x_);
            }

            return (x_ * pow(x_, power_ - 1));
        }



    } // namespace math
} // namespace arc
