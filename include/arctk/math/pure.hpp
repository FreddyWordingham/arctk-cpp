//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
        constexpr inline bool is_prime(T n_) noexcept;



    } // namespace math
} // namespace arc
