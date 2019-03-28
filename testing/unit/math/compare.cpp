//  == IMPORTS ==
//  -- Unit --
#include "arctk/math/compare.inl"

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
    //  -- Compare --
    TEST(compare, zero_x)
    {
        ASSERT_TRUE(math::zero(double{0.0}));

        ASSERT_FALSE(math::zero(double{-3.14159265358979323846}));
    }

    TEST(compare, equal_x_epsilon)
    {
        ASSERT_TRUE(math::zero(double{-3.14159265358979323846}, double{4.0}));

        ASSERT_FALSE(math::zero(double{-3.14159265358979323846}, double{3.0}));
    }

    TEST(compare, equal_x_y)
    {
        ASSERT_TRUE(math::equal(double{-3.14159265358979323846}, double{-3.14159265358979323846}));

        ASSERT_FALSE(math::equal(double{-3.14159265358979323846}, double{3.14159265358979323846}));
    }

    TEST(compare, equal_x_y_epsilon)
    {
        ASSERT_TRUE(math::equal(double{-3.14159265358979323846}, double{3.14159265358979323846}, 7.0));

        ASSERT_FALSE(math::equal(double{-3.14159265358979323846}, double{3.14159265358979323846}, 6.0));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
