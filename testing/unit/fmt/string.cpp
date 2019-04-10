//  == IMPORTS ==
//  -- Arc --
#include "arctk/fmt/string.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace test
{
    namespace unit
    {



        //  == TESTS ==
        //  -- Formatting --
        TEST(arc_fmt_string, handles_primitives) // NOLINT
        {
            ASSERT_EQ(arc::fmt::string(true), "true");
            ASSERT_EQ(arc::fmt::string(-7), "-7");
            ASSERT_EQ(arc::fmt::string(3.14), "3.14");
            ASSERT_EQ(arc::fmt::string("Hello arc::torus!\n"), "Hello arc::torus!\n");
        }



    } // namespace unit
} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
