//  == IMPORTS ==
//  -- Arc --
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
    //  -- Instantiation --
    TEST(col, construction) // NOLINT
    {
        arc::alg::Col<int, 0>    col_0{};
        const std::array<int, 0> ans_0{};
        ASSERT_EQ(col_0.elems(), ans_0);

        arc::alg::Col<int, 3>    col_1{};
        const std::array<int, 3> ans_1{0, 0, 0};
        ASSERT_EQ(col_1.elems(), ans_1);

        arc::alg::Col<int, 3>    col_2{1, 2, 3};
        const std::array<int, 3> ans_2{1, 2, 3};
        ASSERT_EQ(col_2.elems(), ans_2);

        arc::alg::Col<char, 7>    col_3{1, 1, 2, 3, 5, 8, 13};
        const std::array<char, 7> ans_3{1, 1, 2, 3, 5, 8, 13};
        ASSERT_EQ(col_3.elems(), ans_3);
    }


    //  -- Access --
    TEST(col, access) // NOLINT
    {
        const arc::alg::Col<int, 4> col_0{3, 5, 2, -9};
        ASSERT_EQ(col_0[0], 3);
        ASSERT_EQ(col_0[1], 5);
        ASSERT_EQ(col_0[2], 2);
        ASSERT_EQ(col_0[3], -9);

        arc::alg::Col<int, 4> col_1{3, 5, 2, -9};
        ASSERT_EQ(col_1[0], 3);
        ASSERT_EQ(col_1[1], 5);
        ASSERT_EQ(col_1[2], 2);
        ASSERT_EQ(col_1[3], -9);

        col_1[0] = 1;
        col_1[1] = 1;
        col_1[2] = 2;
        col_1[3] = 3;
        ASSERT_EQ(col_1[0], 1);
        ASSERT_EQ(col_1[1], 1);
        ASSERT_EQ(col_1[2], 2);
        ASSERT_EQ(col_1[3], 3);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
