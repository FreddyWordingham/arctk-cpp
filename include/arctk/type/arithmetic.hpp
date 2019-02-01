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
            using add = decltype(std::declval<TL>() + std::declval<TR>());
            template <typename TL, typename TR>
            using sub = decltype(std::declval<TL>() - std::declval<TR>());
            template <typename TL, typename TR>
            using mult = decltype(std::declval<TL>() * std::declval<TR>());
            template <typename TL, typename TR>
            using div = decltype(std::declval<TL>() / std::declval<TR>());
        };



    } // namespace type
} // namespace arc
