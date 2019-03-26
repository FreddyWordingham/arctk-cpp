//  == IMPORTS ==
//  -- Unit --
#include "arctk/fmt/string.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --



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



    //  == FIXTURES ==
    //  -- Filter --
    template <typename T>
    class Pad : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Immutable --
        const fmt::Pad _immutable_width{10};
        const fmt::Pad _immutable_width_fill{8, '*'};

        //  -- Mutable --
        fmt::Pad _mutable_width{10};
        fmt::Pad _mutable_width_fill{8, '*'};
    };


    //  -- Type List --
    using T = ::testing::Types<char, int, unsigned int>;
    TYPED_TEST_SUITE(Pad, T);



    //  == FREE FUNCTION TESTS ==
    //  -- Formatting --
    TEST_F(str, width) // NOLINT
    {
        ASSERT_EQ(_immutable_width.width(), 10);

        ASSERT_EQ(_immutable_width_fill.width(), 8);

        ASSERT_EQ(_mutable_width.width(), 10);

        ASSERT_EQ(_mutable_width_fill.width(), 8);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
