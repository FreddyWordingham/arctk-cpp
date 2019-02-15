//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == TESTS ==
        TEST(prime, special)
        {
            ASSERT_FALSE(is_prime(0));
            ASSERT_FALSE(is_prime(1));
            ASSERT_TRUE(is_prime(2));
            ASSERT_TRUE(is_prime(3));
        }

        TEST(prime, small)
        {
            ASSERT_TRUE(is_prime(43));
            ASSERT_FALSE(is_prime(343));
            ASSERT_TRUE(is_prime(863));
            ASSERT_FALSE(is_prime(999));
        }

        TEST(prime, large)
        {
            ASSERT_TRUE(is_prime(524287));
            ASSERT_FALSE(is_prime(834674));
            ASSERT_TRUE(is_prime(13703077));
            ASSERT_FALSE(is_prime(14232872));
        }



    } // namespace math
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
