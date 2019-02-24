//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/type/traits.hpp"

//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Mathematical --
        template <typename C, typename T = typename C::value_type, typename = std::enable_if_t<type::is_rangeable_v<C>>>
        constexpr inline T accumulate(const C& cont_) noexcept;



    } // namespace range
} // namespace arc
