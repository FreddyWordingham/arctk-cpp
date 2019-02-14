//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/prime.inl"

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
        TEST(is_prime, less_than_ten)
        {
            ASSERT_TRUE(is_prime(2));
            ASSERT_TRUE(is_prime(3));
            ASSERT_FALSE(is_prime(4));
            ASSERT_TRUE(is_prime(5));
            ASSERT_FALSE(is_prime(6));
            ASSERT_TRUE(is_prime(7));
            ASSERT_FALSE(is_prime(8));
            ASSERT_FALSE(is_prime(9));
        }



    } // namespace math
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
