//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/math/arithmetic.hpp>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <typename T>
    constexpr inline const T operator++(T& rhs_) noexcept
    {
        for (auto n : rhs_)
        {
            ++n;
        }

        return (rhs_);
    }

    template <typename T>
    constexpr inline const T operator--(T& rhs_) noexcept
    {
        for (auto n : rhs_)
        {
            --n;
        }

        return (rhs_);
    }

    template <typename T>
    constexpr inline const T operator++(T& lhs_, int) noexcept
    {
        const T cont{lhs_};

        for (auto n : lhs_)
        {
            ++n;
        }

        return (cont);
    }

    template <typename T>
    constexpr inline const T operator--(T& lhs_, int) noexcept
    {
        const T cont{lhs_};

        for (auto n : lhs_)
        {
            --n;
        }

        return (cont);
    }


    //  -- Arithmetic --
    template <typename T>
    constexpr inline const T operator+(const T& rhs_) noexcept
    {
        const T cont{rhs_};

        for (auto n : cont)
        {
            n = +n;
        }

        return (cont);
    }

    template <typename T>
    constexpr inline const T operator-(const T& rhs_) noexcept
    {
        const T cont{rhs_};

        for (auto n : cont)
        {
            n = -n;
        }

        return (cont);
    }



} // namespace arc
