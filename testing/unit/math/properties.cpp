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
        TEST(arc_math_sign, zero) // NOLINT
        {
            ASSERT_EQ(arc::math::sign(0.0), 0.0);
            ASSERT_EQ(arc::math::sign(-0), 0);
        }

        TEST(arc_math_sign, positive) // NOLINT
        {
            ASSERT_EQ(arc::math::sign(243), 1);
            ASSERT_EQ(arc::math::sign(3.142), 1.0);
            ASSERT_EQ(arc::math::sign(0.15f), 1.0f);
        }

        TEST(arc_math_sign, negative) // NOLINT
        {
            ASSERT_EQ(arc::math::sign(-324), -1);
            ASSERT_EQ(arc::math::sign(-4.6237e5), -1.0);
            ASSERT_EQ(arc::math::sign(-85.3f), -1.0f);
        }

        TEST(arc_math_is_prime, special_cases) // NOLINT
        {
            ASSERT_FALSE(arc::math::is_prime(0));
            ASSERT_FALSE(arc::math::is_prime(1));
            ASSERT_TRUE(arc::math::is_prime(2));
            ASSERT_TRUE(arc::math::is_prime(3));
            ASSERT_FALSE(arc::math::is_prime(4));
        }

        TEST(arc_math_is_prime, small_numbers) // NOLINT
        {
            ASSERT_FALSE(arc::math::is_prime(49));
            ASSERT_TRUE(arc::math::is_prime(53));
            ASSERT_FALSE(arc::math::is_prime(77));
            ASSERT_TRUE(arc::math::is_prime(101));
            ASSERT_FALSE(arc::math::is_prime(129));
        }

        TEST(arc_math_is_prime, large_numbers) // NOLINT
        {
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
