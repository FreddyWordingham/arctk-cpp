//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/compare.inl"
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



        //  == FREE FUNCTION TESTS ==
        //  -- Compare --
        TEST(arc_compare, zero_x) // NOLINT
        {
            ASSERT_TRUE(math::zero(test::FLOAT_ZERO));


            ASSERT_FALSE(math::zero(test::FLOAT_CANON));
        }

        TEST(arc_compare, equal_x_epsilon) // NOLINT
        {
            ASSERT_TRUE(math::zero(test::FLOAT_CANON, test::FLOAT_CANON + 0.1));


            ASSERT_FALSE(math::zero(test::FLOAT_CANON, test::FLOAT_CANON - 0.1));
        }

        TEST(arc_compare, equal_x_y) // NOLINT
        {
            ASSERT_TRUE(math::equal(test::FLOAT_CANON, test::FLOAT_CANON));


            ASSERT_FALSE(math::equal(test::FLOAT_POS, test::FLOAT_NEG));
        }

        TEST(arc_compare, equal_x_y_epsilon) // NOLINT
        {
            ASSERT_TRUE(math::equal(test::FLOAT_POS, test::FLOAT_NEG, 2.0));


            ASSERT_FALSE(math::equal(test::FLOAT_POS, test::FLOAT_NEG, 1.9));
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
