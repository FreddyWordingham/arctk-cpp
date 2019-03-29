//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/compare.inl"

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
        TEST(compare, zero_x) // NOLINT
        {
            ASSERT_TRUE(math::zero(double{0.0}));

            ASSERT_FALSE(math::zero(double{-3.14159}));
        }

        TEST(compare, equal_x_epsilon) // NOLINT
        {
            ASSERT_TRUE(math::zero(double{-3.14159}, double{4.0}));

            ASSERT_FALSE(math::zero(double{-3.14159}, double{3.0}));
        }

        TEST(compare, equal_x_y) // NOLINT
        {
            ASSERT_TRUE(math::equal(double{-3.14159}, double{-3.14159}));

            ASSERT_FALSE(math::equal(double{-3.14159}, double{3.14159}));
        }

        TEST(compare, equal_x_y_epsilon) // NOLINT
        {
            ASSERT_TRUE(math::equal(double{-3.14159}, double{3.14159}, 2.0));

            ASSERT_FALSE(math::equal(double{-3.14159}, double{3.14159}, 1.9));
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
