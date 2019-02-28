//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <tuple>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename... A>
        inline auto num_equal_elems(const std::tuple<A...>& tup_0_, const std::tuple<A...>& tup_1_) noexcept;



    } // namespace tuple
} // namespace arc
