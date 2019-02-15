//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <iterator>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == STRUCTURES ==
        //  -- Properties --
        template <typename T, typename = void>
        struct is_iterable
        {
        };



        //  == SPECIALISATIONS ==
        //  -- True --
        template <typename T>
        struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : std::true_type
        {
        };



    } // namespace range
} // namespace arc
