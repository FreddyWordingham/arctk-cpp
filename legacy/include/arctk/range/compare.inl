//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/compare.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Comparison --
    template <typename C, typename T>
    constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept
    {
        for (const auto& l : lhs_)
        {
            if (!(l == rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T>
    constexpr inline bool operator!=(const C& lhs_, const T& rhs_) noexcept
    {
        for (const auto& l : lhs_)
        {
            if (!(l != rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T>
    constexpr inline bool operator<(const C& lhs_, const T& rhs_) noexcept
    {
        for (const auto& l : lhs_)
        {
            if (!(l < rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T>
    constexpr inline bool operator>(const C& lhs_, const T& rhs_) noexcept
    {
        for (const auto& l : lhs_)
        {
            if (!(l > rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T>
    constexpr inline bool operator<=(const C& lhs_, const T& rhs_) noexcept
    {
        for (const auto& l : lhs_)
        {
            if (!(l <= rhs_))
            {
                return (false);
            }
        }

        return (true);
    }

    template <typename C, typename T>
    constexpr inline bool operator>=(const C& lhs_, const T& rhs_) noexcept
    {
        for (const auto& l : lhs_)
        {
            if (!(l >= rhs_))
            {
                return (false);
            }
        }

        return (true);
    }



} // namespace arc
