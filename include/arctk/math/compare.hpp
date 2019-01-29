//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <limits>



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == FUNCTIONS ==
        //  -- Compare --
        template <typename T>
        constexpr inline bool zero(T x_, T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;
        template <typename T>
        constexpr inline bool equal(T x_, T y_, T epsilon_ = std::numeric_limits<T>::epsilon()) noexcept;



    } // namespace math



    //  == OPERATORS ==
    //  -- Comparison --
    template <typename T>
    constexpr inline bool operator==(const T& lhs_, const T& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator!=(const T& lhs_, const T& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator<(const T& lhs_, const T& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator>(const T& lhs_, const T& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator<=(const T& lhs_, const T& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator>=(const T& lhs_, const T& rhs_) noexcept;



} // namespace arc
