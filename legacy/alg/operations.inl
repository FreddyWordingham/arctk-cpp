//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/operations.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == FUNCTIONS ==
        //  -- Transpose --
        template <typename T, std::size_t N>
        constexpr inline Row<T, N> transpose(const Col<T, N>& col_) noexcept
        {
            return (Row<T, N>{col_.elems()});
        }

        template <typename T, std::size_t N>
        constexpr inline Col<T, N> transpose(const Row<T, N>& row_) noexcept
        {
            return (Col<T, N>{row_.elems()});
        }



    } // namespace alg
} // namespace arc
