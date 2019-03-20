//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/col.hpp"

//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == FUNCTIONS ==
        //  -- Col --
        template <typename T, std::size_t N>
        constexpr inline auto begin(Col<T, N>& col_) noexcept;
        template <typename T, std::size_t N>
        constexpr inline auto begin(const Col<T, N>& col_) noexcept;
        template <typename T, std::size_t N>
        constexpr inline auto end(Col<T, N>& col_) noexcept;
        template <typename T, std::size_t N>
        constexpr inline auto end(const Col<T, N>& col_) noexcept;



    } // namespace alg
} // namespace arc
