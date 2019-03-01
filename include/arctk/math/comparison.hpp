//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <limits>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
        constexpr inline bool zero(T x_, T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;
        template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
        constexpr inline bool equal(T x_, T y_, T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;



    } // namespace math
} // namespace arc
