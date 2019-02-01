//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Integral --
        template <typename T, typename R = type::arithmetic::mult<T, T>>
        constexpr inline R sq(const T& x_) noexcept;
        template <typename T, typename R = type::arithmetic::mult<type::arithmetic::mult<T, T>, T>>
        constexpr inline R cube(const T& x_) noexcept;

        //  -- Power --
        template <typename T>
        constexpr inline T pow(const T& x_, const int power_) noexcept;



    } // namespace math
} // namespace arc
