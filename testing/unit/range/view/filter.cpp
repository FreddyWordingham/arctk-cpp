//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/filter.inl"
#include "arctk/math/pure.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <iostream>



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
    //  -- Access --
    TEST(view, access) // NOLINT
    {
        std::array<int, 11>      arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        arc::range::view::Filter filt{arr, [](const int x_) { return (arc::math::is_prime(x_)); }};

        ASSERT_EQ(filt[0], 2);
        ASSERT_EQ(filt[1], 3);
        ASSERT_EQ(filt[2], 5);
        ASSERT_EQ(filt[3], 7);
    }


    //  -- Range --
    TEST(view, range) // NOLINT
    {
        std::array<int, 11> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int sum{0};
        for (const auto& v : arc::range::view::Filter{arr, [](const int x_) { return (arc::math::is_prime(x_)); }})
        {
            sum += v;
        }

        ASSERT_EQ(sum, 17);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
