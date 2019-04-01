//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"
#include "arctk/test/constants.inl"
#include "arctk/test/types.inl"

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
        TEST(arc_math, sign_n) // NOLINT
        {
            ASSERT_EQ(math::sign(test::BOOL_CANON), test::Bool{1});

            ASSERT_EQ(math::sign(test::CHAR_CANON), test::Char{1});

            ASSERT_EQ(math::sign(test::INT_CANON), test::Int{-1});

            ASSERT_EQ(math::sign(test::SIZE_CANON), test::Size{1});

            ASSERT_EQ(math::sign(test::FLOAT_CANON), test::Float{-1.0});
        }

        TEST(arc_math, is_positive_n) // NOLINT
        {
            ASSERT_TRUE(math::is_positive(test::CHAR_POS));

            ASSERT_FALSE(math::is_positive(test::INT_POS));

            ASSERT_TRUE(math::is_positive(test::SIZE_POS));

            ASSERT_FALSE(math::is_positive(test::FLOAT_POS));


            ASSERT_TRUE(math::is_positive(test::BOOL_ZERO));

            ASSERT_TRUE(math::is_positive(test::CHAR_ZERO));

            ASSERT_FALSE(math::is_positive(test::INT_ZERO));

            ASSERT_TRUE(math::is_positive(test::SIZE_ZERO));

            ASSERT_FALSE(math::is_positive(test::FLOAT_ZERO));


            ASSERT_FALSE(math::is_positive(test::INT_NEG));

            ASSERT_FALSE(math::is_positive(test::FLOAT_NEG));
        }

        TEST(arc_math, is_negative_n) // NOLINT
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

        TEST(arc_math, is_even_n) // NOLINT
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

        TEST(arc_math, is_odd_n) // NOLINT
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

        TEST(arc_math, is_prime_n) // NOLINT
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
