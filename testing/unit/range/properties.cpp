//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"
#include "arctk/range/properties.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wpadded"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == TESTS ==
        //  -- Array Int Comparison --
        class array_int_test : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const std::array<int, 4> _arr_0{1, 2, 3, 4};
            const std::array<int, 4> _arr_1{1, 1, 1, 1};
            const std::array<int, 4> _arr_2{11, 5, 2, 7};
        };

        TEST_F(array_int_test, true_for_all) // NOLINT
        {
            ASSERT_FALSE(true_for_all(_arr_0, [](const int& x_) { return (math::is_prime(x_)); }));
            ASSERT_FALSE(true_for_all(_arr_1, [](const int& x_) { return (math::is_prime(x_)); }));
            ASSERT_TRUE(true_for_all(_arr_2, [](const int& x_) { return (math::is_prime(x_)); }));
        }



    } // namespace range
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
