//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/tuple/comparison.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/tuple/transform.inl"

//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == FUNCTIONS ==
        //  -- Comparison --
        template <template <typename...> typename T, typename... A, typename... B, typename>
        constexpr inline bool any_equal_elems(const T<A...>& tup_0_, const T<B...>& tup_1_) noexcept
        {
            bool equal{false};

            for_each_zip(tup_0_, tup_1_, [&](const auto& t_0_, const auto& t_1_) { equal = ((!equal) && (t_0_ == t_1_)); });

            return (equal);
        }

        template <template <typename...> typename T, typename... A, typename... B, typename>
        constexpr inline std::size_t num_equal_elems(const T<A...>& tup_0_, const T<B...>& tup_1_) noexcept
        {
            std::size_t num_equal{};
            for_each_zip(tup_0_, tup_1_, [&](const auto& t_0_, const auto& t_1_) { num_equal += (t_0_ == t_1_) ? 1 : 0; });

            return (num_equal);
        }



    } // namespace tuple
} // namespace arc
