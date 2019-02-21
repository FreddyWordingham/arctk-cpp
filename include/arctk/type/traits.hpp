//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <type_traits>



//  == MACROS ==
//  -- Traits --
#define TRAIT(name_, ...)                                      \
    template <typename T, typename = void>                     \
    struct name_ : std::false_type                             \
    {                                                          \
    };                                                         \
                                                               \
    template <typename T>                                      \
    struct name_<T, std::void_t<__VA_ARGS__>> : std::true_type \
    {                                                          \
    };                                                         \
                                                               \
                                                               \
    //  == ALIASES ==                                          \
    //  -- Type --                                             \
    template <typename Condition, typename T = void>           \
    using name_##_t = typename name_<Condition, T>::type;      \
                                                               \
                                                               \
    //  -- Value --                                            \
    template <typename T>                                      \
    inline constexpr bool name_##_v = name_<T>::value;


//  == NAMESPACE ==
namespace arc
{
    namespace type
    {



        //  == STRUCTURES ==
        //  -- Ranges --
        TRAIT(is_rangeable,                         //
              decltype(std::declval<T&>().begin()), //
              decltype(std::declval<T&>().end()),   //
              typename T::value_type                //
        );



    } // namespace type
} // namespace arc



//  == CLEAN UP ==
//  -- Traits --
#undef TRAIT
