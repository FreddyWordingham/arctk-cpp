//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/transform.inl"

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



    //  == TESTS ==
    //  -- Access --
    TEST(view, access) // NOLINT
    {
        std::array<int, 4>          arr{0, 1, 2, 3};
        arc::range::view::Transform trans{arr, [](const int x_) { return (x_ * 2); }};

        ASSERT_EQ(trans[0], 0);
        ASSERT_EQ(trans[1], 2);
        ASSERT_EQ(trans[2], 4);
        ASSERT_EQ(trans[3], 6);
    }


    //  -- Range --
    TEST(view, range) // NOLINT
    {
        std::array<int, 4> arr{0, 1, 2, 3};

        int sum{0};
        for (const auto& v : arc::range::view::Transform{arr, [](const int x_) { return (x_ * 2); }})
        {
            sum += v;
        }

        ASSERT_EQ(sum, 12);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
