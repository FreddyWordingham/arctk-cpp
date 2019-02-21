//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/compare.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wpadded"
#endif



//  == ALIASES ==
//  -- Using --



//  == NAMESPACE ==
namespace test
{



    //  == TESTS ==
    //  -- Array Int Comparison --
    class array_int_test : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 4>                _arr_0{1, 2, 3, 4};
        const std::array<int, 4>                _arr_1{1, 1, 1, 1};
        const std::array<int, 4>                _arr_2{9, 5, 2, 7};
        const std::array<int, 4>                _arr_3{-2, 3, 8, -4};
        const std::array<int, 4>                _arr_4{-3, -3, -2, -1};
        const std::array<int, 0>                _arr_5{};
        const std::array<int, 2>                _arr_6{-2, 2};
        const std::array<std::array<int, 3>, 4> _arr_a{{{-3, -4, -2}, {3, 2, -3}, {2, 1, 3}, {-2, -3, 0}}};
        const std::array<std::array<int, 0>, 4> _arr_b{{{}, {}, {}, {}}};
    };

    TEST_F(array_int_test, equal) // NOLINT
    {
        using namespace arc;

        ASSERT_FALSE(_arr_0 == 1);
        ASSERT_TRUE(_arr_1 == 1);
        ASSERT_FALSE(_arr_2 == 1);
        ASSERT_FALSE(_arr_3 == 1);
        ASSERT_FALSE(_arr_4 == 1);
        ASSERT_TRUE(_arr_5 == 1);
        ASSERT_FALSE(_arr_6 == 1);
        ASSERT_FALSE(_arr_a == 1);
        ASSERT_TRUE(_arr_b == 1);
    }

    TEST_F(array_int_test, not_equal) // NOLINT
    {
        ASSERT_FALSE(_arr_0 != 1);
        ASSERT_FALSE(_arr_1 != 1);
        ASSERT_TRUE(_arr_2 != 1);
        ASSERT_TRUE(_arr_3 != 1);
        ASSERT_TRUE(_arr_4 != 1);
        ASSERT_TRUE(_arr_5 != 1);
        ASSERT_TRUE(_arr_6 != 1);
        ASSERT_FALSE(_arr_a != 1);
        ASSERT_TRUE(_arr_b != 1);
    }

    TEST_F(array_int_test, less_than) // NOLINT
    {
        ASSERT_FALSE(_arr_0 < 4);
        ASSERT_TRUE(_arr_1 < 4);
        ASSERT_FALSE(_arr_2 < 4);
        ASSERT_FALSE(_arr_3 < 4);
        ASSERT_TRUE(_arr_4 < 4);
        ASSERT_TRUE(_arr_5 < 4);
        ASSERT_TRUE(_arr_6 < 4);
        ASSERT_TRUE(_arr_a < 4);
        ASSERT_TRUE(_arr_b < 4);
    }

    TEST_F(array_int_test, greater_than) // NOLINT
    {
        ASSERT_FALSE(_arr_0 > 4);
        ASSERT_FALSE(_arr_1 > 4);
        ASSERT_FALSE(_arr_2 > 4);
        ASSERT_FALSE(_arr_3 > 4);
        ASSERT_FALSE(_arr_4 > 4);
        ASSERT_TRUE(_arr_5 > 4);
        ASSERT_FALSE(_arr_6 > 4);
        ASSERT_FALSE(_arr_a > 4);
        ASSERT_TRUE(_arr_b > 4);
    }

    TEST_F(array_int_test, less_than_or_equal_to) // NOLINT
    {
        ASSERT_TRUE(_arr_0 <= 4);
        ASSERT_TRUE(_arr_1 <= 4);
        ASSERT_FALSE(_arr_2 <= 4);
        ASSERT_FALSE(_arr_3 <= 4);
        ASSERT_TRUE(_arr_4 <= 4);
        ASSERT_TRUE(_arr_5 <= 4);
        ASSERT_TRUE(_arr_6 <= 4);
        ASSERT_TRUE(_arr_a <= 4);
        ASSERT_TRUE(_arr_b <= 4);
    }

    TEST_F(array_int_test, greater_than_or_equal_to) // NOLINT
    {
        ASSERT_FALSE(_arr_0 >= 4);
        ASSERT_FALSE(_arr_1 >= 4);
        ASSERT_FALSE(_arr_2 >= 4);
        ASSERT_FALSE(_arr_3 >= 4);
        ASSERT_FALSE(_arr_4 >= 4);
        ASSERT_TRUE(_arr_5 >= 4);
        ASSERT_FALSE(_arr_6 >= 4);
        ASSERT_FALSE(_arr_a >= 4);
        ASSERT_TRUE(_arr_b >= 4);
    }


    //  -- Array Double Comparison --
    class array_double_test : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<double, 4>                _arr_0{1.0, 2.0, 3.0, 4.0};
        const std::array<double, 4>                _arr_1{1.0, 1.0, 1.0, 1.0};
        const std::array<double, 4>                _arr_2{9.0, 5.0, 2.0, 7.0};
        const std::array<double, 4>                _arr_3{-2.0, 3.0, 8.0, -4.0};
        const std::array<double, 4>                _arr_4{-3.0, -3.0, -2.0, -1.0};
        const std::array<double, 0>                _arr_5{};
        const std::array<double, 2>                _arr_6{-2.0, 2.0};
        const std::array<std::array<double, 3>, 4> _arr_a{{{-3.0, -4.0, -2.0}, {3.0, 2.0, -3.0}, {2.0, 1.0, 3.0}, {-2.0, -3.0, 0.0}}};
        const std::array<std::array<double, 0>, 4> _arr_b{{{}, {}, {}, {}}};
    };

    TEST_F(array_double_test, less_than) // NOLINT
    {
        ASSERT_FALSE(_arr_0 < 4);
        ASSERT_TRUE(_arr_1 < 4);
        ASSERT_FALSE(_arr_2 < 4);
        ASSERT_FALSE(_arr_3 < 4);
        ASSERT_TRUE(_arr_4 < 4);
        ASSERT_TRUE(_arr_5 < 4);
        ASSERT_TRUE(_arr_6 < 4);
        ASSERT_TRUE(_arr_a < 4);
        ASSERT_TRUE(_arr_b < 4);
    }

    TEST_F(array_double_test, greater_than) // NOLINT
    {
        ASSERT_FALSE(_arr_0 > 4);
        ASSERT_FALSE(_arr_1 > 4);
        ASSERT_FALSE(_arr_2 > 4);
        ASSERT_FALSE(_arr_3 > 4);
        ASSERT_FALSE(_arr_4 > 4);
        ASSERT_TRUE(_arr_5 > 4);
        ASSERT_FALSE(_arr_6 > 4);
        ASSERT_FALSE(_arr_a > 4);
        ASSERT_TRUE(_arr_b > 4);
    }

    TEST_F(array_double_test, less_than_or_equal_to) // NOLINT
    {
        ASSERT_TRUE(_arr_0 <= 4);
        ASSERT_TRUE(_arr_1 <= 4);
        ASSERT_FALSE(_arr_2 <= 4);
        ASSERT_FALSE(_arr_3 <= 4);
        ASSERT_TRUE(_arr_4 <= 4);
        ASSERT_TRUE(_arr_5 <= 4);
        ASSERT_TRUE(_arr_6 <= 4);
        ASSERT_TRUE(_arr_a <= 4);
        ASSERT_TRUE(_arr_b <= 4);
    }

    TEST_F(array_double_test, greater_than_or_equal_to) // NOLINT
    {
        ASSERT_FALSE(_arr_0 >= 4);
        ASSERT_FALSE(_arr_1 >= 4);
        ASSERT_FALSE(_arr_2 >= 4);
        ASSERT_FALSE(_arr_3 >= 4);
        ASSERT_FALSE(_arr_4 >= 4);
        ASSERT_TRUE(_arr_5 >= 4);
        ASSERT_FALSE(_arr_6 >= 4);
        ASSERT_FALSE(_arr_a >= 4);
        ASSERT_TRUE(_arr_b >= 4);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
