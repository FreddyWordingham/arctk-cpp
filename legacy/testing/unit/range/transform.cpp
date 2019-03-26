//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/transform.inl"
#include "arctk/math/properties.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <vector>



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
    //  -- For Each --
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
    //  -- For Each --
    TEST_F(array_int, transform) // NOLINT
    {
        std::array<int, 8> arr_0{_arr_ascend};
        arc::range::for_each(&arr_0, [](int& x_) { x_ += 3; });
        ASSERT_EQ(arr_0, (std::array<int, 8>{3, 4, 5, 6, 7, 8, 9, 10}));

        int sum{0};
        arc::range::for_each(_arr_prime, [&](const int& x_) { sum += x_; });
        ASSERT_EQ(sum, 77);

        const std::array<int, 8> arr_1{3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<bool>        vec_is_prime{};
        arc::range::for_each(arr_1, [&](const int& x_) { vec_is_prime.emplace_back(arc::math::is_prime(x_)); });

        ASSERT_EQ(vec_is_prime, (std::vector<bool>{true, false, true, false, true, false, false, false}));
    }

    TEST_F(array_int, sort) // NOLINT
    {
        std::array<int, 8> arr_0{1, 7, 3, 6, 2, 4, 5, 0};
        arc::range::sort(&arr_0);
        ASSERT_EQ(_arr_ascend, arr_0);
    }

    TEST_F(array_int, reverse) // NOLINT
    {
        std::array<int, 8> arr_0{7, 6, 5, 4, 3, 2, 1, 0};
        arc::range::reverse(&arr_0);
        ASSERT_EQ(_arr_ascend, arr_0);
    }

    TEST_F(array_int, rotate) // NOLINT
    {
        std::array<int, 8> arr_0{5, 6, 7, 0, 1, 2, 3, 4};
        arc::range::rotate(&arr_0, 3);
        ASSERT_EQ(_arr_ascend, arr_0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
