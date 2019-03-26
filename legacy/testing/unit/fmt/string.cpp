//  == IMPORTS ==
//  -- Arc --
#include "arctk/fmt/string.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <string>



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
    TEST(int, small) // NOLINT
    {
        ASSERT_EQ(arc::fmt::str(324), "324");
    }

    TEST(double, small) // NOLINT
    {
        ASSERT_EQ(arc::fmt::str(0.66666667), "0.666667");
    }

    TEST(string, small) // NOLINT
    {
        ASSERT_EQ(arc::fmt::str("This is a pine cone!\n"), "This is a pine cone!\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
