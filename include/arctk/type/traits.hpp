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
        //  -- Ranges --
        template <typename T, typename = void>
        struct is_rangeable : std::false_type
        {
        };

        template <typename T>
        struct is_rangeable<T, std::void_t<decltype(std::declval<T&>().begin()), decltype(std::declval<T&>().end()), typename T::value_type>> : std::true_type
        {
        };

        // TRAIT(is_rangeable,
        //     (
        //         decltype(std::declval<T&>().begin()),
        //         decltype(std::declval<T&>().end()),
        //         typename T::value_type
        //     )
        // )



    } // namespace type
} // namespace arc
