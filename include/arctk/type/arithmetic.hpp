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
        //  -- Result --
        template <typename TL, typename TR>
        struct result
        {
            //  == TYPES ==
          public:
            //  -- Arithmetic --
            using add  = decltype(std::declval<TL>() + std::declval<TR>());
            using sub  = decltype(std::declval<TL>() - std::declval<TR>());
            using mult = decltype(std::declval<TL>() * std::declval<TR>());
            using div  = decltype(std::declval<TL>() / std::declval<TR>());
        };



    } // namespace type
} // namespace arc
