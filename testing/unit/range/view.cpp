//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view.inl"

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
        std::array<int, 4> arr{0, 1, 2, 3};
        arc::range::View   view{arr};

        ASSERT_EQ(view[0], 0);
        ASSERT_EQ(view[1], 1);
        ASSERT_EQ(view[2], 2);
        ASSERT_EQ(view[3], 3);
    }


    //  -- Range --
    TEST(view, range) // NOLINT
    {
        std::array<int, 4> arr{0, 1, 2, 3};
        arc::range::View   view{arr};

        int sum{0};
        for (const auto& v : view)
        {
            sum += v;
        }

        ASSERT_EQ(sum, 6);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
