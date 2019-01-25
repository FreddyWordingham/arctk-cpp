//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/math/power.hpp>



//  == IMPORTS ==
//  -- Arc --
#include <arctk/type/arithmetic.inl>



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



    } // namespace math
} // namespace arc
