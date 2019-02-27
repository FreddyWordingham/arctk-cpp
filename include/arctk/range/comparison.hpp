//  == GUARD ==
#pragma once



//  == IMPORTS
//  -- Std --
#include <utility>



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
    template <typename Condition, typename T = void>           \
    using name_##_t = typename name_<Condition, T>::type;      \
                                                               \
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



    //  == OPERATORS ==
    //  -- Comparison --
    template <typename Rl, typename Rr, typename = typename std::enable_if_t<type::is_rangeable_v<Rl> && type::is_rangeable_v<Rr>>>
    constexpr inline bool operator==(const Rl& lhs_, const Rr& rhs_) noexcept;
    template <typename Rl, typename Rr, typename = typename std::enable_if_t<type::is_rangeable_v<Rl> && type::is_rangeable_v<Rr>>>
    constexpr inline bool operator!=(const Rl& lhs_, const Rr& rhs_) noexcept;



} // namespace arc
