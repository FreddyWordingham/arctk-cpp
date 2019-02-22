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
    //  -- Prime --
    TEST(view, array_int) // NOLINT
    {
        std::array<int, 4> arr{0, 1, 2, 3};
        arc::range::View   view{arr};

        ASSERT_EQ(view[0], 0);
        ASSERT_EQ(view[1], 1);
        ASSERT_EQ(view[2], 2);
        ASSERT_EQ(view[3], 3);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
