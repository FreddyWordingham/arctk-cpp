//  == IMPORTS ==
//  -- Unit --
#include "arctk/math/properties.inl"

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
    TEST(sign, positive)
    {
        ASSERT_EQ(math::sign('a'), 1);
        ASSERT_EQ(math::sign(97), 1);
        ASSERT_EQ(math::sign(97U), 1U);
        ASSERT_EQ(math::sign(97L), 1L);
        ASSERT_EQ(math::sign(97UL), 1UL);
        ASSERT_EQ(math::sign(97LL), 1LL);
        ASSERT_EQ(math::sign(97ULL), 1ULL);
        ASSERT_EQ(math::sign(3.141f), 1.0f);
        ASSERT_EQ(math::sign(3.141), 1.0);
        ASSERT_EQ(math::sign(3.141l), 1.0l);
    }

    TEST(sign, zero)
    {
        ASSERT_EQ(math::sign(0), 0);
        ASSERT_EQ(math::sign(-0), 0);
        ASSERT_EQ(math::sign(0), 0);
        ASSERT_EQ(math::sign(-0), 0);
        ASSERT_EQ(math::sign(0L), 0L);
        ASSERT_EQ(math::sign(-0L), 0L);
        ASSERT_EQ(math::sign(0LL), 0LL);
        ASSERT_EQ(math::sign(-0LL), 0LL);
        ASSERT_EQ(math::sign(0.0f), 0.0f);
        ASSERT_EQ(math::sign(-0.0f), 0.0f);
        ASSERT_EQ(math::sign(0.0), 0.0);
        ASSERT_EQ(math::sign(-0.0), 0.0);
        ASSERT_EQ(math::sign(0.0l), 0.0l);
        ASSERT_EQ(math::sign(-0.0l), 0.0l);
    }

    TEST(sign, negative)
    {
        ASSERT_EQ(math::sign(-'a'), -1);
        ASSERT_EQ(math::sign(-97), -1);
        ASSERT_EQ(math::sign(-97L), -1L);
        ASSERT_EQ(math::sign(-97LL), -1LL);
        ASSERT_EQ(math::sign(-3.141f), -1.0f);
        ASSERT_EQ(math::sign(-3.141), -1.0);
        ASSERT_EQ(math::sign(-3.141l), -1.0l);
    }

    TEST(is_positive, true)
    {
        ASSERT_TRUE(math::is_positive('a'));
        ASSERT_TRUE(math::is_positive(97U));
        ASSERT_TRUE(math::is_positive(-97U));
        ASSERT_TRUE(math::is_positive(97UL));
        ASSERT_TRUE(math::is_positive(-97UL));
        ASSERT_TRUE(math::is_positive(97ULL));
        ASSERT_TRUE(math::is_positive(-97ULL));
        ASSERT_TRUE(math::is_positive(3.141f));
        ASSERT_TRUE(math::is_positive(3.141));
        ASSERT_TRUE(math::is_positive(3.141l));
    }

    TEST(is_positive, false)
    {
        ASSERT_FALSE(math::is_positive(-'a'));
        ASSERT_FALSE(math::is_positive(0U));
        ASSERT_FALSE(math::is_positive(0UL));
        ASSERT_FALSE(math::is_positive(0ULL));
        ASSERT_FALSE(math::is_positive(0.0f));
        ASSERT_FALSE(math::is_positive(-3.141f));
        ASSERT_FALSE(math::is_positive(0.0));
        ASSERT_FALSE(math::is_positive(-3.141));
        ASSERT_FALSE(math::is_positive(0.0l));
        ASSERT_FALSE(math::is_positive(-3.141l));
    }

    TEST(is_negative, true)
    {
        ASSERT_TRUE(math::is_negative(-'a'));
        ASSERT_TRUE(math::is_negative(-97));
        ASSERT_TRUE(math::is_negative(-97L));
        ASSERT_TRUE(math::is_negative(-97LL));
        ASSERT_TRUE(math::is_negative(-3.141f));
        ASSERT_TRUE(math::is_negative(-3.141));
        ASSERT_TRUE(math::is_negative(-3.141l));
    }

    TEST(is_negative, false)
    {
        ASSERT_FALSE(math::is_negative('a'));
        ASSERT_FALSE(math::is_negative(0U));
        ASSERT_FALSE(math::is_negative(0UL));
        ASSERT_FALSE(math::is_negative(0ULL));
        ASSERT_FALSE(math::is_negative(0.0f));
        ASSERT_FALSE(math::is_negative(3.141f));
        ASSERT_FALSE(math::is_negative(0.0));
        ASSERT_FALSE(math::is_negative(3.141));
        ASSERT_FALSE(math::is_negative(0.0l));
        ASSERT_FALSE(math::is_negative(3.141l));
    }

    TEST(is_even, true)
    {
        ASSERT_TRUE(math::is_even('b'));
        ASSERT_TRUE(math::is_even(-'b'));
        ASSERT_TRUE(math::is_even(0));
        ASSERT_TRUE(math::is_even(-0));
        ASSERT_TRUE(math::is_even(98));
        ASSERT_TRUE(math::is_even(-98));
        ASSERT_TRUE(math::is_even(0L));
        ASSERT_TRUE(math::is_even(-0L));
        ASSERT_TRUE(math::is_even(98L));
        ASSERT_TRUE(math::is_even(-98L));
        ASSERT_TRUE(math::is_even(0LL));
        ASSERT_TRUE(math::is_even(-0LL));
        ASSERT_TRUE(math::is_even(98LL));
        ASSERT_TRUE(math::is_even(-98LL));
    }

    TEST(is_even, false)
    {
        ASSERT_FALSE(math::is_even('a'));
        ASSERT_FALSE(math::is_even(-'a'));
        ASSERT_FALSE(math::is_even(97));
        ASSERT_FALSE(math::is_even(-97));
        ASSERT_FALSE(math::is_even(97L));
        ASSERT_FALSE(math::is_even(-97L));
        ASSERT_FALSE(math::is_even(97LL));
        ASSERT_FALSE(math::is_even(-97LL));
    }

    TEST(is_odd, true)
    {
        ASSERT_TRUE(math::is_odd('a'));
        ASSERT_TRUE(math::is_odd(-'a'));
        ASSERT_TRUE(math::is_odd(97));
        ASSERT_TRUE(math::is_odd(-97));
        ASSERT_TRUE(math::is_odd(97L));
        ASSERT_TRUE(math::is_odd(-97L));
        ASSERT_TRUE(math::is_odd(97LL));
        ASSERT_TRUE(math::is_odd(-97LL));
    }

    TEST(is_odd, false)
    {
        ASSERT_FALSE(math::is_odd('b'));
        ASSERT_FALSE(math::is_odd(-'b'));
        ASSERT_FALSE(math::is_odd(0));
        ASSERT_FALSE(math::is_odd(-0));
        ASSERT_FALSE(math::is_odd(98));
        ASSERT_FALSE(math::is_odd(-98));
        ASSERT_FALSE(math::is_odd(0L));
        ASSERT_FALSE(math::is_odd(-0L));
        ASSERT_FALSE(math::is_odd(98L));
        ASSERT_FALSE(math::is_odd(-98L));
        ASSERT_FALSE(math::is_odd(0LL));
        ASSERT_FALSE(math::is_odd(-0LL));
        ASSERT_FALSE(math::is_odd(98LL));
        ASSERT_FALSE(math::is_odd(-98LL));
    }

    TEST(is_prime, true)
    {
        ASSERT_TRUE(math::is_prime(2));
        ASSERT_TRUE(math::is_prime(3));
        ASSERT_TRUE(math::is_prime(5));
        ASSERT_TRUE(math::is_prime(7));
        ASSERT_TRUE(math::is_prime(11));
        ASSERT_TRUE(math::is_prime(13));
        ASSERT_TRUE(math::is_prime(17));
        ASSERT_TRUE(math::is_prime(19));
        ASSERT_TRUE(math::is_prime(23));
    }

    TEST(is_prime, false)
    {
        ASSERT_FALSE(math::is_prime(int{0}));
        ASSERT_FALSE(math::is_prime(int{1}));
        ASSERT_FALSE(math::is_prime(int{4}));
        ASSERT_FALSE(math::is_prime(int{6}));
        ASSERT_FALSE(math::is_prime(int{8}));
        ASSERT_FALSE(math::is_prime(int{9}));
        ASSERT_FALSE(math::is_prime(int{10}));
        ASSERT_FALSE(math::is_prime(int{12}));
        ASSERT_FALSE(math::is_prime(int{14}));
        ASSERT_FALSE(math::is_prime(int{15}));
        ASSERT_FALSE(math::is_prime(int{16}));
        ASSERT_FALSE(math::is_prime(int{18}));
        ASSERT_FALSE(math::is_prime(int{20}));
        ASSERT_FALSE(math::is_prime(int{21}));
        ASSERT_FALSE(math::is_prime(int{22}));
        ASSERT_FALSE(math::is_prime(int{24}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
