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
#include <cstddef>
#include <tuple>
#include <vector>
// IWYU pragma: no_include <__bit_reference>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename... A, typename... B, typename>
        constexpr inline auto any_equal_elems(const std::tuple<A...>& tup_0_, const std::tuple<B...>& tup_1_) noexcept
        {
            bool equal{false};

            for_each_zip(tup_0_, tup_1_, [&](const auto& t_0_, const auto& t_1_) { equal = ((!equal) && (t_0_ == t_1_)); });

            return (equal);
        }

        template <typename... A, typename... B, typename>
        constexpr inline auto num_equal_elems(const std::tuple<A...>& tup_0_, const std::tuple<B...>& tup_1_) noexcept
        {
            std::size_t num_equal{};
            for_each_zip(tup_0_, tup_1_, [&](const auto& t_0_, const auto& t_1_) { num_equal += (t_0_ == t_1_) ? 1 : 0; });

            return (num_equal);
        }



    } // namespace tuple
} // namespace arc
