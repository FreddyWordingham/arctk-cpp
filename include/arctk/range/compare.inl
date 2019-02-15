//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/compare.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == OPERATORS ==
        //  -- Container-Element Comparison --
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
            return (!(lhs_ == rhs_));
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


        //  -- Container-Container Comparison --
        template <typename C, typename D>
        constexpr inline bool operator==(const C& lhs_, const D& rhs_) noexcept
        {
            return (std::equal(std::begin(lhs_), std::end(lhs_), std::begin(rhs_), std::end(rhs_)));
        }

        template <typename C, typename D>
        constexpr inline bool operator!=(const C& lhs_, const D& rhs_) noexcept
        {
            return (!(lhs_ == rhs_));
        }

        template <typename C, typename D>
        constexpr inline bool operator<(const C& lhs_, const D& rhs_) noexcept
        {
            for (const auto& [l, r] : (lhs_, rhs_))
            {
                if (!(l < r))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename D>
        constexpr inline bool operator>(const C& lhs_, const D& rhs_) noexcept
        {
            for (const auto& [l, r] : (lhs_, rhs_))
            {
                if (!(l > r))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename D>
        constexpr inline bool operator<=(const C& lhs_, const D& rhs_) noexcept
        {
            for (const auto& [l, r] : (lhs_, rhs_))
            {
                if (!(l <= r))
                {
                    return (false);
                }
            }

            return (true);
        }

        template <typename C, typename D>
        constexpr inline bool operator>=(const C& lhs_, const D& rhs_) noexcept
        {
            for (const auto& [l, r] : (lhs_, rhs_))
            {
                if (!(l >= r))
                {
                    return (false);
                }
            }

            return (true);
        }



    } // namespace range
} // namespace arc
