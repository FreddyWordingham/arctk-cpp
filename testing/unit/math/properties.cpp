//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cstddef>



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
        //  -- Properties --
        TEST(properties, sign) // NOLINT
        {
            ASSERT_EQ(math::sign(bool{true}), bool{true});
            ASSERT_EQ(math::sign(char{'a'}), char{1});
            ASSERT_EQ(math::sign(int{-32749}), int{-1});
            ASSERT_EQ(math::sign(std::size_t{67280421310721}), std::size_t{1});
            ASSERT_EQ(math::sign(double{-3.14159}), double{-1.0});
        }

        TEST(properties, is_positive) // NOLINT
        {
            ASSERT_TRUE(math::is_positive(bool{true}));
            ASSERT_FALSE(math::is_positive(bool{false}));
            ASSERT_TRUE(math::is_positive(char{'a'}));
            ASSERT_FALSE(math::is_positive(char{0}));
            ASSERT_FALSE(math::is_positive(int{-32749}));
            ASSERT_FALSE(math::is_positive(int{0}));
            ASSERT_TRUE(math::is_positive(std::size_t{67280421310721}));
            ASSERT_FALSE(math::is_positive(std::size_t{0}));
            ASSERT_FALSE(math::is_positive(double{-3.14159}));
            ASSERT_FALSE(math::is_positive(double{0.0}));
        }

        TEST(properties, is_negative) // NOLINT
        {
            ASSERT_FALSE(math::is_negative(bool{true}));
            ASSERT_FALSE(math::is_negative(bool{false}));
            ASSERT_FALSE(math::is_negative(char{'a'}));
            ASSERT_FALSE(math::is_negative(char{0}));
            ASSERT_TRUE(math::is_negative(int{-32749}));
            ASSERT_FALSE(math::is_negative(int{0}));
            ASSERT_FALSE(math::is_negative(std::size_t{67280421310721}));
            ASSERT_FALSE(math::is_negative(std::size_t{0}));
            ASSERT_TRUE(math::is_negative(double{-3.14159}));
            ASSERT_FALSE(math::is_negative(double{0.0}));
        }

        TEST(properties, is_even) // NOLINT
        {
            ASSERT_FALSE(math::is_even(bool{true}));
            ASSERT_TRUE(math::is_even(bool{false}));
            ASSERT_FALSE(math::is_even(char{'a'}));
            ASSERT_TRUE(math::is_even(char{0}));
            ASSERT_FALSE(math::is_even(int{-32749}));
            ASSERT_TRUE(math::is_even(int{0}));
            ASSERT_FALSE(math::is_even(std::size_t{67280421310721}));
            ASSERT_TRUE(math::is_even(std::size_t{0}));
        }

        TEST(properties, is_odd) // NOLINT
        {
            ASSERT_TRUE(math::is_odd(bool{true}));
            ASSERT_FALSE(math::is_odd(bool{false}));
            ASSERT_TRUE(math::is_odd(char{'a'}));
            ASSERT_FALSE(math::is_odd(char{0}));
            ASSERT_TRUE(math::is_odd(int{-32749}));
            ASSERT_FALSE(math::is_odd(int{0}));
            ASSERT_TRUE(math::is_odd(std::size_t{67280421310721}));
            ASSERT_FALSE(math::is_odd(std::size_t{0}));
        }

        TEST(properties, is_prime) // NOLINT
        {
            ASSERT_TRUE(math::is_prime(char{'a'}));
            ASSERT_FALSE(math::is_prime(char{0}));
            ASSERT_TRUE(math::is_prime(int{-32749}));
            ASSERT_FALSE(math::is_prime(int{0}));
            ASSERT_TRUE(math::is_prime(std::size_t{67280421310721}));
            ASSERT_FALSE(math::is_prime(std::size_t{0}));
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
