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



        //  == STRUCTURE ==
        template <typename Tl, typename Tr>
        struct result
        {
            //  == TYPES ==
          public:
            //  -- Arithmetic --
            using add  = decltype(std::declval<Tl>() + std::declval<Tr>());
            using sub  = decltype(std::declval<Tl>() - std::declval<Tr>());
            using mult = decltype(std::declval<Tl>() * std::declval<Tr>());
            using div  = decltype(std::declval<Tl>() / std::declval<Tr>());
        };



    } // namespace type
} // namespace arc
