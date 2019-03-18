//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/arithmetic.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename R, typename>
    constexpr inline auto operator+(const R& range_) noexcept
    {
        auto range{range_};

        for (auto& r : range)
        {
            r = +r;
        }

        return (range);
    }

    template <typename R, typename>
    constexpr inline auto operator-(const R& range_) noexcept
    {
        auto range{range_};

        for (auto& r : range)
        {
            r = -r;
        }

        return (range);
    }



} // namespace arc
