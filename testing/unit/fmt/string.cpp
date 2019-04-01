//  == IMPORTS ==
//  -- Arc --
#include "arctk/fmt/string.inl"
#include "arctk/test/constants.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cstddef>



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
namespace testing
{
    namespace unit
    {



        //  == FREE FUNCTION TESTS ==
        //  -- Formatting --
        TEST(arc_fmt, str_val) // NOLINT
        {
            ASSERT_EQ(fmt::str(test::BOOL_CANON), "true");
            ASSERT_EQ(fmt::str(test::CHAR_CANON), "a");
            ASSERT_EQ(fmt::str(test::INT_CANON), "-32749");
            ASSERT_EQ(fmt::str(test::SIZE_CANON), "67280421310721");
            ASSERT_EQ(fmt::str(test::FLOAT_CANON), "-3.14159");
            ASSERT_EQ(fmt::str(test::C_STR_CANON), "Hello Arc::Torus!\n");
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
