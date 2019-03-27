//  == IMPORTS ==
//  -- Unit --
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
namespace test
{



    //  == FREE FUNCTION TESTS ==
    //  -- Comparison --
    TEST(zero, true)
    {
        ASSERT_TRUE(math::zero(0.0f));
        ASSERT_TRUE(math::zero(-0.0f));
        ASSERT_TRUE(math::zero(0.0));
        ASSERT_TRUE(math::zero(-0.0));
        ASSERT_TRUE(math::zero(0.0l));
        ASSERT_TRUE(math::zero(-0.0l));
    }

    TEST(zero, false)
    {
        ASSERT_FALSE(math::zero(3.141f));
        ASSERT_FALSE(math::zero(-3.141f));
        ASSERT_FALSE(math::zero(3.141));
        ASSERT_FALSE(math::zero(-3.141));
        ASSERT_FALSE(math::zero(3.141l));
        ASSERT_FALSE(math::zero(-3.141l));
    }

    TEST(equal, true)
    {
        ASSERT_TRUE(math::equal(3.141f, 2.07f + 1.071f));
        ASSERT_TRUE(math::equal(-3.141f, -2.07f - 1.071f));
        ASSERT_TRUE(math::equal(3.141, 2.07 + 1.071));
        ASSERT_TRUE(math::equal(-3.141, -2.07 - 1.071));
        ASSERT_TRUE(math::equal(3.141l, 2.07l + 1.071l));
        ASSERT_TRUE(math::equal(-3.141l, -2.07l - 1.071l));
    }

    TEST(equal, false)
    {
        ASSERT_FALSE(math::equal(3.141f, 2.071f + 1.071f));
        ASSERT_FALSE(math::equal(-3.141f, -2.071f - 1.071f));
        ASSERT_FALSE(math::equal(3.141, 2.071 + 1.071));
        ASSERT_FALSE(math::equal(-3.141, -2.071 - 1.071));
        ASSERT_FALSE(math::equal(3.141l, 2.071l + 1.071l));
        ASSERT_FALSE(math::equal(-3.141l, -2.071l - 1.071l));
    }

    TEST(equal, epsilon_true)
    {
        ASSERT_TRUE(math::equal(3.141f, 2.071f + 1.071f, 0.001f));
        ASSERT_TRUE(math::equal(-3.141f, -2.071f - 1.071f, 0.001f));
        ASSERT_TRUE(math::equal(3.141, 2.071 + 1.071, 0.001));
        ASSERT_TRUE(math::equal(-3.141, -2.071 - 1.071, 0.001));
        ASSERT_TRUE(math::equal(3.141l, 2.071l + 1.071l, 0.001l));
        ASSERT_TRUE(math::equal(-3.141l, -2.071l - 1.071l, 0.001l));
    }

    TEST(equal, epsilon_false)
    {
        ASSERT_FALSE(math::equal(3.141f, 2.071f + 1.071f, 0.0001f));
        ASSERT_FALSE(math::equal(-3.141f, -2.071f - 1.071f, 0.0001f));
        ASSERT_FALSE(math::equal(3.141, 2.071 + 1.071, 0.0001));
        ASSERT_FALSE(math::equal(-3.141, -2.071 - 1.071, 0.0001));
        ASSERT_FALSE(math::equal(3.141l, 2.071l + 1.071l, 0.0001l));
        ASSERT_FALSE(math::equal(-3.141l, -2.071l - 1.071l, 0.0001l));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
