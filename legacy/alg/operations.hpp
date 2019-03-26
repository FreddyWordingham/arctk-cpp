//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.hpp"

//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == FUNCTIONS ==
        //  -- Transpose --
        template <typename T, std::size_t N>
        constexpr inline Row<T, N> transpose(const Col<T, N>& col_) noexcept;
        template <typename T, std::size_t N>
        constexpr inline Col<T, N> transpose(const Row<T, N>& row_) noexcept;



    } // namespace alg
} // namespace arc
