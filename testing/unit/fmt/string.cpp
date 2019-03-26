//  == IMPORTS ==
//  -- Unit --
#include "arctk/fmt/string.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == ALIASES ==
//  -- Namespaces --
using namespace arc; // NOLINT



//  == NAMESPACE ==
namespace test
{



    //  == FREE FUNCTION TESTS ==
    //  -- Formatting --
    TEST(str, simple) // NOLINT
    {
        ASSERT_EQ(fmt::str(true), "true");
        ASSERT_EQ(fmt::str('a'), "a");
        ASSERT_EQ(fmt::str(-'a'), "-97");
        ASSERT_EQ(fmt::str(97U), "97");
        ASSERT_EQ(fmt::str(-97), "-97");
        ASSERT_EQ(fmt::str(97UL), "97");
        ASSERT_EQ(fmt::str(-97L), "-97");
        ASSERT_EQ(fmt::str(97ULL), "97");
        ASSERT_EQ(fmt::str(-97LL), "-97");
        ASSERT_EQ(fmt::str(3.141f), "3.141");
        ASSERT_EQ(fmt::str(-3.141f), "-3.141");
        ASSERT_EQ(fmt::str(3.141), "3.141");
        ASSERT_EQ(fmt::str(-3.141), "-3.141");
        ASSERT_EQ(fmt::str("I love pi!\n"), "I love pi!\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
