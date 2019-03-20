//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/range.inl"
#include "arctk/alg/col.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == TESTS ==
    //  -- Col --
    TEST(col, range) // NOLINT
    {
        const arc::alg::Col<int, 4> col_0{3, 5, 2, -9};
        int                         total_0{0};

        for (const auto& x : col_0)
        {
            total_0 += x;
        }

        ASSERT_EQ(total_0, 1);

        arc::alg::Col<int, 4> col_1{3, 5, 2, -9};
        int                   total_1{0};

        for (auto& x : col_1)
        {
            x = 0;
        }
        for (const auto& x : col_1)
        {
            total_1 += x;
        }

        ASSERT_EQ(total_1, 0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
