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
        //  -- Compare --
        template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
        constexpr inline bool zero(const T x_, const T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;
        template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
        constexpr inline bool equal(const T x_, const T y_, const T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;



    } // namespace math
} // namespace arc
