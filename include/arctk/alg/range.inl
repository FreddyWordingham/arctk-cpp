//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/range.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/col.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == FUNCTIONS ==
        //  -- Col --
        template <typename T, std::size_t N>
        constexpr inline auto begin(Col<T, N>& col_) noexcept
        {
            return (std::begin(col_._elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto begin(const Col<T, N>& col_) noexcept
        {
            return (std::begin(col_.elems()));
        }

        template <typename T, std::size_t N>
        constexpr inline auto end(Col<T, N>& col_) noexcept
        {
            return (std::end(col_._elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto end(const Col<T, N>& col_) noexcept
        {
            return (std::end(col_.elems()));
        }



    } // namespace alg
} // namespace arc
