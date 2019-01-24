//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <limits>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Zero --
        template <typename T>
        constexpr inline bool zero(T x_, T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;

        //  -- Equal --
        template <typename T>
        constexpr inline bool equal(T x_, T y_, T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;



    } // namespace math
} // namespace arc
