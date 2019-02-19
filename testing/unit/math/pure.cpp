//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/pure.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == TESTS ==
        //  -- Prime --
        TEST(prime, special) // NOLINT
        {
            ASSERT_FALSE(is_prime(0));
            ASSERT_FALSE(is_prime(1));
            ASSERT_TRUE(is_prime(2));
            ASSERT_TRUE(is_prime(3));
            ASSERT_FALSE(is_prime(4));
        }

        TEST(prime, small) // NOLINT
        {
            ASSERT_TRUE(is_prime(43));
            ASSERT_FALSE(is_prime(343));
            ASSERT_TRUE(is_prime(863));
            ASSERT_FALSE(is_prime(999));
        }

        TEST(prime, large) // NOLINT
        {
            ASSERT_TRUE(is_prime(524287));
            ASSERT_FALSE(is_prime(834674));
            ASSERT_TRUE(is_prime(13703077));
            ASSERT_FALSE(is_prime(14232872));
        }



    } // namespace test
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
