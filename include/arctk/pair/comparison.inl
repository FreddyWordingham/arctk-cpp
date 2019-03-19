//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/pair/comparison.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace pair
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <typename A0, typename A1, typename B0, typename B1>
        constexpr inline bool any_equal_elems(const std::pair<A0, A1>& pair_0_, const std::pair<B0, B1>& pair_1_) noexcept
        {
            return ((pair_0_.first == pair_1_.first) && (pair_0_.first == pair_1_.first));
        }

        template <typename A0, typename A1, typename B0, typename B1>
        constexpr inline std::size_t num_equal_elems(const std::pair<A0, A1>& pair_0_, const std::pair<B0, B1>& pair_1_) noexcept
        {
            std::size_t num_equal{};

            num_equal += (pair_0_.first == pair_1_.first) ? 1 : 0;
            num_equal += (pair_0_.second == pair_1_.second) ? 1 : 0;

            return (num_equal);
        }



    } // namespace pair
} // namespace arc
