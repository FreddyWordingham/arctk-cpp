//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/search.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == FIXTURES ==
    //  -- Search --
    class array_int : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 8> _arr_ascend{0, 1, 2, 3, 4, 5, 6, 7};
        const std::array<int, 8> _arr_prime{2, 3, 5, 7, 11, 13, 17, 19};
        const std::array<int, 8> _arr_non_prime{0, 1, 4, 6, 8, 9, 10, 12};
    };



    //  == TESTS ==
    //  -- Search --
    TEST_F(array_int, bounded) // NOLINT
    {
        ASSERT_TRUE(arc::range::bounded(_arr_ascend, 5.5));
        ASSERT_FALSE(arc::range::bounded(_arr_ascend, 7.2));
        ASSERT_TRUE(arc::range::bounded(_arr_prime, 9.3));
        ASSERT_FALSE(arc::range::bounded(_arr_prime, 1.6));
        ASSERT_TRUE(arc::range::bounded(_arr_non_prime, 11.4));
        ASSERT_FALSE(arc::range::bounded(_arr_non_prime, -3.4));
    }

    TEST_F(array_int, lower_index) // NOLINT
    {
        ASSERT_EQ(arc::range::lower_index(_arr_ascend, 5.5), 5);
        ASSERT_EQ(arc::range::lower_index(_arr_prime, 5.5), 2);
        ASSERT_EQ(arc::range::lower_index(_arr_non_prime, 5.5), 2);
    }

    TEST_F(array_int, upper_index) // NOLINT
    {
        ASSERT_EQ(arc::range::upper_index(_arr_ascend, 5.5), 6);
        ASSERT_EQ(arc::range::upper_index(_arr_prime, 5.5), 3);
        ASSERT_EQ(arc::range::upper_index(_arr_non_prime, 5.5), 3);
    }

    TEST_F(array_int, find_index) // NOLINT
    {
        ASSERT_EQ(arc::range::find_index(_arr_ascend, 3).has_value(), true);
        ASSERT_EQ(arc::range::find_index(_arr_ascend, 3).value(), 3);
        ASSERT_EQ(arc::range::find_index(_arr_prime, 11).has_value(), true);
        ASSERT_EQ(arc::range::find_index(_arr_prime, 11).value(), 4);
        ASSERT_EQ(arc::range::find_index(_arr_prime, 12).has_value(), false);
        ASSERT_EQ(arc::range::find_index(_arr_non_prime, 9).has_value(), true);
        ASSERT_EQ(arc::range::find_index(_arr_non_prime, 9).value(), 5);
    }

    TEST_F(array_int, find_index_if) // NOLINT
    {
        const auto even_and_gt_five = [](const int& i_) { return (((i_ % 2) == 0) && (i_ > 5)); };

        ASSERT_EQ(arc::range::find_index_if(_arr_ascend, even_and_gt_five).has_value(), true);
        ASSERT_EQ(arc::range::find_index_if(_arr_ascend, even_and_gt_five).value(), 6);
        ASSERT_EQ(arc::range::find_index_if(_arr_prime, even_and_gt_five).has_value(), false);
        ASSERT_EQ(arc::range::find_index_if(_arr_non_prime, even_and_gt_five).has_value(), true);
        ASSERT_EQ(arc::range::find_index_if(_arr_non_prime, even_and_gt_five).value(), 3);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
