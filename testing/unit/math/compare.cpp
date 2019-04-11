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



//  == NAMESPACE ==
namespace test::unit
{



    //  == TESTS ==
    //  -- Comparison --
    TEST(arc_math, zero) // NOLINT
    {
        ASSERT_FALSE(arc::math::zero(-2.79));
        ASSERT_TRUE(arc::math::zero(0.0));
        ASSERT_FALSE(arc::math::zero(3.14));

        ASSERT_FALSE(arc::math::zero(-2.79F));
        ASSERT_TRUE(arc::math::zero(0.0F));
        ASSERT_FALSE(arc::math::zero(3.14F));

        ASSERT_FALSE(arc::math::zero(-2.79, 1.0));
        ASSERT_TRUE(arc::math::zero(0.0, 2.5));
        ASSERT_TRUE(arc::math::zero(3.14, 5.0));

        ASSERT_TRUE(arc::math::zero(-2.79F, 3.0F));
        ASSERT_TRUE(arc::math::zero(0.0F, 0.5F));
        ASSERT_FALSE(arc::math::zero(3.14F, 2.0F));
    }

    TEST(arc_math, equal) // NOLINT
    {
        ASSERT_TRUE(arc::math::equal(-2.79, 2.79 * -1));
        ASSERT_FALSE(arc::math::equal(-2.79, 1.0e6 - 1000002.79));
        ASSERT_FALSE(arc::math::equal(-2.79, 2.79));
        ASSERT_TRUE(arc::math::equal(1.0348e6, 1034800.0));

        ASSERT_TRUE(arc::math::equal(3.14F, 2.79F + 0.35F));
        ASSERT_TRUE(arc::math::equal(3.14F, 200.96F / 64.0F));
        ASSERT_FALSE(arc::math::equal(3.14F, -3.14F));
        ASSERT_TRUE(arc::math::equal(-5.653e6F, -5653000.0F));

        ASSERT_TRUE(arc::math::equal(-2.79, 2.80 * -1, 0.05));
        ASSERT_TRUE(arc::math::equal(-2.79, 1.0e6 - 1000002.79, 1.0e-3));
        ASSERT_FALSE(arc::math::equal(-2.79, 2.79, 1.0));
        ASSERT_TRUE(arc::math::equal(1.0347e6, 1034800.0, 2e2));

        ASSERT_FALSE(arc::math::equal(3.14F, 2.79F + 0.30F, 0.01F));
        ASSERT_TRUE(arc::math::equal(3.14F, 200.96F / 64.0F, 0.1F));
        ASSERT_TRUE(arc::math::equal(3.14F, -3.14F, 7.0F));
        ASSERT_FALSE(arc::math::equal(-5.653e6F, -5653007.0F, 1.0e-6F));
    }



} // namespace test::unit



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
