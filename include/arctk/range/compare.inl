//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/compare.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Compare --
    template <typename C, typename T, typename S>
    constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept
    {
        for (const S& l : lhs_)
        {
            if (!(l == rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T, typename S>
    constexpr inline bool operator!=(const C& lhs_, const T& rhs_) noexcept
    {
        for (const S& l : lhs_)
        {
            if (!(l != rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T, typename S>
    constexpr inline bool operator<(const C& lhs_, const T& rhs_) noexcept
    {
        for (const S& l : lhs_)
        {
            if (!(l < rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T, typename S>
    constexpr inline bool operator>(const C& lhs_, const T& rhs_) noexcept
    {
        for (const S& l : lhs_)
        {
            if (!(l > rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T, typename S>
    constexpr inline bool operator<=(const C& lhs_, const T& rhs_) noexcept
    {
        for (const S& l : lhs_)
        {
            if (!(l <= rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T, typename S>
    constexpr inline bool operator>=(const C& lhs_, const T& rhs_) noexcept
    {
        for (const S& l : lhs_)
        {
            if (!(l >= rhs_))
            {
                return (false);
            }
        }

        return (true);
    }



} // namespace arc
