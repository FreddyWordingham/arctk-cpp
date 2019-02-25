//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/properties.inl"
#include "arctk/math/properties.inl"

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
    //  -- Properties --
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
    //  -- Properties --
    TEST_F(array_int, all_of) // NOLINT
    {
        ASSERT_FALSE(arc::range::all_of(_arr_ascend, [](const int& x_) { return (arc::math::is_prime(x_)); }));
        ASSERT_TRUE(arc::range::all_of(_arr_prime, [](const int& x_) { return (arc::math::is_prime(x_)); }));
        ASSERT_FALSE(arc::range::all_of(_arr_non_prime, [](const int& x_) { return (arc::math::is_prime(x_)); }));
    }

    TEST_F(array_int, any_of) // NOLINT
    {
        ASSERT_TRUE(arc::range::any_of(_arr_ascend, [](const int& x_) { return (arc::math::is_prime(x_)); }));
        ASSERT_TRUE(arc::range::any_of(_arr_prime, [](const int& x_) { return (arc::math::is_prime(x_)); }));
        ASSERT_FALSE(arc::range::any_of(_arr_non_prime, [](const int& x_) { return (arc::math::is_prime(x_)); }));
    }

    TEST_F(array_int, none_of) // NOLINT
    {
        ASSERT_FALSE(arc::range::none_of(_arr_ascend, [](const int& x_) { return (arc::math::is_prime(x_)); }));
        ASSERT_FALSE(arc::range::none_of(_arr_prime, [](const int& x_) { return (arc::math::is_prime(x_)); }));
        ASSERT_TRUE(arc::range::none_of(_arr_non_prime, [](const int& x_) { return (arc::math::is_prime(x_)); }));
    }

    TEST_F(array_int, count) // NOLINT
    {
        ASSERT_EQ(arc::range::count(_arr_ascend, 4), 1);
        ASSERT_EQ(arc::range::count(_arr_prime, 4), 0);
        ASSERT_EQ(arc::range::count(_arr_non_prime, 4), 1);
    }

    TEST_F(array_int, count_if) // NOLINT
    {
        const auto result_0{arc::range::count_if(_arr_ascend, [](const int& x_) { return (arc::math::is_prime(x_)); })};
        ASSERT_EQ(result_0, 4);

        const auto result_1{arc::range::count_if(_arr_prime, [](const int& x_) { return (arc::math::is_prime(x_)); })};
        ASSERT_EQ(result_1, 8);

        const auto result_2{arc::range::count_if(_arr_non_prime, [](const int& x_) { return (arc::math::is_prime(x_)); })};
        ASSERT_EQ(result_2, 0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
