//  == GUARD ==
#pragma once



//  == IMPORTS ==
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
            //  == TYPES ==
          public:
            //  -- Operations --
            template <typename TL, typename TR>
            using Add = decltype(std::declval<TL>() + std::declval<TR>());
            template <typename TL, typename TR>
            using Sub = decltype(std::declval<TL>() - std::declval<TR>());
            template <typename TL, typename TR>
            using Mult = decltype(std::declval<TL>() * std::declval<TR>());
            template <typename TL, typename TR>
            using Div = decltype(std::declval<TL>() / std::declval<TR>());
        };



    } // namespace type
} // namespace arc
