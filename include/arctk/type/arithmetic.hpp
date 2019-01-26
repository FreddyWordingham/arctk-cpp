//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <arctk/si/dimension.hpp>

//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace type
    {



        //  == STRUCTURES ==
        //  -- Arithmetic --
        struct arithmetic
        {
            //  == ALIASES ==
          public:
            //  -- Operations --
            template <typename TL, typename TR>
            using add = decltype(std::declval<TL>() + std::declval<TR>()); // NOLINT
            template <typename TL, typename TR>
            using sub = decltype(std::declval<TL>() - std::declval<TR>()); // NOLINT
            template <typename TL, typename TR>
            using mult = decltype(std::declval<TL>() * std::declval<TR>()); // NOLINT
            template <typename TL, typename TR>
            using div = decltype(std::declval<TL>() / std::declval<TR>()); // NOLINT
        };



    } // namespace type
} // namespace arc
