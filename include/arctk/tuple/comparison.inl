//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/tuple/comparison.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/properties.inl"
#include "arctk/tuple/transform.inl"

//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename... A>
        inline auto num_equal_elems(const std::tuple<A...>& tup_0_, const std::tuple<A...>& tup_1_) noexcept
        {
            std::vector<bool> res{};
            for_each_zip(tup_0_, tup_1_, [](const auto& t_0_, const auto& t_1_) { return (t_0_ == t_1_); }, &res);

            return (range::count(res, true));
        }



    } // namespace tuple
} // namespace arc
