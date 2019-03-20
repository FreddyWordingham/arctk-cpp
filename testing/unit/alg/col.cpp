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
    //  -- Prime --
    TEST(col, construction) // NOLINT
    {
        arc::alg::Col<int, 0>    col_0{};
        const std::array<int, 0> ans_0{};
        ASSERT_TRUE(col_0.elems() == ans_0);

        arc::alg::Col<int, 3>    col_1{};
        const std::array<int, 3> ans_1{0, 0, 0};
        ASSERT_TRUE(col_1.elems() == ans_1);

        arc::alg::Col<int, 3>    col_2{1, 2, 3};
        const std::array<int, 3> ans_2{1, 2, 3};
        ASSERT_TRUE(col_2.elems() == ans_2);

        arc::alg::Col<char, 7>    col_3{1, 1, 2, 3, 5, 8, 13};
        const std::array<char, 7> ans_3{1, 1, 2, 3, 5, 8, 13};
        ASSERT_TRUE(col_3.elems() == ans_3);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
