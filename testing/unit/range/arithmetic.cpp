//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/arithmetic.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <vector>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == TESTS ==
        TEST(array_test, equal)
        {
            ASSERT_TRUE((std::vector<int>{1, 2, 3} == std::vector<int>{1, 2, 3}));
        }



    } // namespace range
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
