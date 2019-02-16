//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <functional>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Properties --
        template <typename C, typename S = typename C::value_type, typename F>
        constexpr inline bool true_for_all(const C& cont_, F&& func_) noexcept;



    } // namespace range
} // namespace arc
