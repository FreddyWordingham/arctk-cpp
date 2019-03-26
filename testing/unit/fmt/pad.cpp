//  == IMPORTS ==
//  -- Unit --
#include "arctk/fmt/pad.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <sstream>
#include <string>



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



    //  == METHOD TESTS ==
    //  -- Getters --
    TEST_F(Pad, width) // NOLINT
    {
        ASSERT_EQ(_immutable_width.width(), 10);

        ASSERT_EQ(_immutable_width_fill.width(), 8);

        ASSERT_EQ(_mutable_width.width(), 10);

        ASSERT_EQ(_mutable_width_fill.width(), 8);
    }

    TEST_F(Pad, fill) // NOLINT
    {
        ASSERT_EQ(_immutable_width.fill(), ' ');

        ASSERT_EQ(_immutable_width_fill.fill(), '*');

        ASSERT_EQ(_mutable_width.fill(), ' ');

        ASSERT_EQ(_mutable_width_fill.fill(), '*');
    }



    //  == FREE OPERATOR TESTS ==
    //  -- Printing --
    TEST_F(Pad, print_operator) // NOLINT
    {
        auto test = [&](const auto& pad_) {
            std::stringstream stream;

            stream << pad_ << 3.141 << '\n';

            return (stream.str());
        };

        ASSERT_EQ(test(_immutable_width), "     3.141\n");
        ASSERT_EQ(test(_immutable_width_fill), "***3.141\n");
        ASSERT_EQ(test(_mutable_width), "     3.141\n");
        ASSERT_EQ(test(_mutable_width_fill), "***3.141\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
