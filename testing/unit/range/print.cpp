//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/print.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == TESTS ==
        TEST(array_int_test, equal) // NOLINT
        {
            const std::array<int, 4> arr{1, 2, 3, 4};

            std::cout << arr << '\n';
        }



    } // namespace range
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
