//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/print.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include <arctk/range/over.inl>



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Print --
    template <typename S, typename C, typename T>
    constexpr inline S& operator<<(S& lhs_, const C& rhs_) noexcept
    {
        lhs_ << '[' << rhs_.front();
        for (const auto& r : range::over(rhs_, 1, 0))
        {
            lhs_ << ",\t" << r;
        }
        lhs_ << "]\n";

        return (lhs_);
    }



} // namespace arc
