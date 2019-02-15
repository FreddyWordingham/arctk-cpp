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
        //  -- Comparison --
        template <typename C, typename T>
        constexpr inline bool operator==(const C& lhs_, const T& rhs_) noexcept
        {
            for (const T& l_ : lhs_)
            {
                if (!(l_ == rhs_))
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



    } // namespace range
} // namespace arc
