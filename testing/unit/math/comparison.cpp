//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/comparison.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <vector>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wpadded"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == TESTS ==
    //  -- Comparison --
    TEST(zero, double) // NOLINT
    {
        ASSERT_FALSE(arc::math::zero(-2.0));
        ASSERT_FALSE(arc::math::zero(-1.0));
        ASSERT_TRUE(arc::math::zero(0.0));
        ASSERT_FALSE(arc::math::zero(1.0));
        ASSERT_FALSE(arc::math::zero(2.0));
    }

    TEST(equal, double) // NOLINT
    {
        ASSERT_FALSE(arc::math::equal(-2.0, 1.0));
        ASSERT_FALSE(arc::math::equal(-1.0, 1.0));
        ASSERT_FALSE(arc::math::equal(0.0, 1.0));
        ASSERT_TRUE(arc::math::equal(1.0, 1.0));
        ASSERT_FALSE(arc::math::equal(2.0, 1.0));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
