//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"

//  -- Std --
#include <type_traits>
#include <vector>


//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Lists --
        template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
        constexpr inline std::vector<T> list(const T first_, const T last_) noexcept;
        template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
        constexpr inline std::vector<T> list(const T first_, const T last_, const T spacing_) noexcept;



    } // namespace range
} // namespace arc
