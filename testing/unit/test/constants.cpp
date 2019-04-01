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



        //  == CONSTANT TESTS ==
        //  -- Zero --
        TEST(arc_test, BOOL_ZERO)
        {
            ASSERT_EQ(test::BOOL_ZERO, test::Bool{0});
        }

        TEST(arc_test, CHAR_ZERO)
        {
            ASSERT_EQ(test::CHAR_ZERO, test::Char{0});
        }

        TEST(arc_test, INT_ZERO)
        {
            ASSERT_EQ(test::INT_ZERO, test::Int{0});
        }

        TEST(arc_test, SIZE_ZERO)
        {
            ASSERT_EQ(test::SIZE_ZERO, test::Size{0});
        }

        TEST(arc_test, FLOAT_ZERO)
        {
            ASSERT_EQ(test::FLOAT_ZERO, test::Float{0});
        }


        //  -- Positive --
        TEST(arc_test, CHAR_POS)
        {
            ASSERT_GT(test::CHAR_POS, test::CHAR_ZERO);
        }

        TEST(arc_test, INT_POS)
        {
            ASSERT_GT(test::INT_POS, test::INT_ZERO);
        }

        TEST(arc_test, SIZE_POS)
        {
            ASSERT_GT(test::SIZE_POS, test::SIZE_ZERO);
        }

        TEST(arc_test, FLOAT_POS)
        {
            ASSERT_GT(test::FLOAT_POS, test::FLOAT_ZERO);
        }


        //  -- Negative --
        TEST(arc_test, INT_NEG)
        {
            ASSERT_LT(test::INT_NEG, test::INT_ZERO);
        }

        TEST(arc_test, FLOAT_NEG)
        {
            ASSERT_LT(test::FLOAT_NEG, test::FLOAT_ZERO);
        }


        //  -- Default --
        TEST(arc_test, BOOL_CANON) // NOLINT
        {
            ASSERT_EQ(test::BOOL_CANON, test::Bool{true});

            ASSERT_EQ(test::CHAR_CANON, test::Char{'a'});

            ASSERT_EQ(test::INT_CANON, test::Int{-32749});

            ASSERT_EQ(test::SIZE_CANON, test::Size{67280421310721});

            ASSERT_EQ(test::FLOAT_CANON, test::Float{-3.14159});

            ASSERT_EQ(test::C_STR_CANON, test::CStr{"Hello Arc::Torus\n"});
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
