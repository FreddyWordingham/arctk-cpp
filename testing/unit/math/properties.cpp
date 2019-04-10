//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"

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
        //  -- Properties --
        TEST(arc_math, sign) // NOLINT
        {
            ASSERT_EQ(arc::math::sign(0.0), 0.0);
            ASSERT_EQ(arc::math::sign(-0), 0);

            ASSERT_EQ(arc::math::sign(-324), -1);
            ASSERT_EQ(arc::math::sign(243), 1);

            ASSERT_EQ(arc::math::sign(-85.3f), -1.0f);
            ASSERT_EQ(arc::math::sign(0.15f), 1.0f);

            ASSERT_EQ(arc::math::sign(-4.6237e5), -1.0);
            ASSERT_EQ(arc::math::sign(3.142), 1.0);
        }

        TEST(arc_math, is_positive) // NOLINT
        {
            ASSERT_FALSE(arc::math::is_positive(-3));
            ASSERT_TRUE(arc::math::is_positive(745));

            ASSERT_FALSE(arc::math::is_positive(-3.14f));
            ASSERT_TRUE(arc::math::is_positive(73.34f));

            ASSERT_FALSE(arc::math::is_positive(-82e3));
            ASSERT_TRUE(arc::math::is_positive(32.324));
        }

        TEST(arc_math, is_negative) // NOLINT
        {
            ASSERT_TRUE(arc::math::is_negative(-3));
            ASSERT_FALSE(arc::math::is_negative(745));

            ASSERT_TRUE(arc::math::is_negative(-3.14f));
            ASSERT_FALSE(arc::math::is_negative(73.34f));

            ASSERT_TRUE(arc::math::is_negative(-82e3));
            ASSERT_FALSE(arc::math::is_negative(32.324));
        }

        TEST(arc_math, is_even) // NOLINT
        {
            ASSERT_TRUE(arc::math::is_even(-348));
            ASSERT_FALSE(arc::math::is_even(-3));
            ASSERT_TRUE(arc::math::is_even(0));
            ASSERT_TRUE(arc::math::is_even(2));
            ASSERT_FALSE(arc::math::is_even(65337));
            ASSERT_TRUE(arc::math::is_even(32947832));
        }

        TEST(arc_math, is_odd) // NOLINT
        {
            ASSERT_FALSE(arc::math::is_odd(-348));
            ASSERT_TRUE(arc::math::is_odd(-3));
            ASSERT_FALSE(arc::math::is_odd(0));
            ASSERT_FALSE(arc::math::is_odd(2));
            ASSERT_TRUE(arc::math::is_odd(65337));
            ASSERT_FALSE(arc::math::is_odd(32947832));
        }

        TEST(arc_math, is_prime) // NOLINT
        {
            ASSERT_FALSE(arc::math::is_prime(0));
            ASSERT_FALSE(arc::math::is_prime(1));
            ASSERT_TRUE(arc::math::is_prime(2));
            ASSERT_TRUE(arc::math::is_prime(3));
            ASSERT_FALSE(arc::math::is_prime(4));

            ASSERT_FALSE(arc::math::is_prime(49));
            ASSERT_TRUE(arc::math::is_prime(53));
            ASSERT_FALSE(arc::math::is_prime(77));
            ASSERT_TRUE(arc::math::is_prime(101));
            ASSERT_FALSE(arc::math::is_prime(129));

            ASSERT_TRUE(arc::math::is_prime(6653));
            ASSERT_FALSE(arc::math::is_prime(6655));
            ASSERT_FALSE(arc::math::is_prime(7917));
            ASSERT_TRUE(arc::math::is_prime(7919));
            ASSERT_FALSE(arc::math::is_prime(7920));
        }



    } // namespace unit
} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
