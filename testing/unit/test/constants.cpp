//  == IMPORTS ==
//  -- Arc --
#include "arctk/test/constants.inl"

//  -- GTest --
#include <gtest/gtest.h>



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



        //  == TESTS ==
        //  -- Primitives --
        TEST(arc_test, CHAR) // NOLINT
        {
            ASSERT_EQ(test::CHAR, 'a');
        }

        TEST(arc_test, INT) // NOLINT
        {
            ASSERT_EQ(test::INT, -32749);
        }

        TEST(arc_test, SIZE) // NOLINT
        {
            ASSERT_EQ(test::SIZE, 67280421310721);
        }

        TEST(arc_test, FLOAT) // NOLINT
        {
            ASSERT_EQ(test::FLOAT, -3.14159);
        }

        TEST(arc_test, CSTR) // NOLINT
        {
            ASSERT_STREQ(test::CSTR, "Hello Arc::Torus!\n");
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
