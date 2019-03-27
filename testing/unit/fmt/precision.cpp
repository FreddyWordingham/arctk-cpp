//  == IMPORTS ==
//  -- Unit --
#include "arctk/fmt/precision.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <sstream>
#include <string>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#pragma clang diagnostic ignored "-Wused-but-marked-unused"
#endif



//  == ALIASES ==
//  -- Namespaces --
using namespace arc; // NOLINT



//  == NAMESPACE ==
namespace test
{



    //  == FIXTURES ==
    //  -- Precision --
    class Precision : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Precs --
        const fmt::Precision _immutable_precision_low{6};
        fmt::Precision       _mutable_precision_low{6};
        const fmt::Precision _immutable_precision{8};
        fmt::Precision       _mutable_precision{8};
        const fmt::Precision _immutable_precision_high{12};
        fmt::Precision       _mutable_precision_high{12};
    };



    //  == METHOD TESTS ==
    //  -- Getters --
    TEST_F(Precision, precision) // NOLINT
    {
        ASSERT_EQ(_immutable_precision_low.precision(), 6);

        ASSERT_EQ(_mutable_precision_low.precision(), 6);

        ASSERT_EQ(_immutable_precision.precision(), 8);

        ASSERT_EQ(_mutable_precision.precision(), 8);

        ASSERT_EQ(_immutable_precision_high.precision(), 12);

        ASSERT_EQ(_mutable_precision_high.precision(), 12);
    }



    //  == FREE OPERATOR TESTS ==
    //  -- Printing --
    TEST_F(Precision, print_operator_small) // NOLINT
    {
        auto test = [&](const auto& prec_, const auto& val_) {
            std::stringstream stream;

            stream << prec_ << val_ << '\n';

            return (stream.str());
        };

        ASSERT_EQ(test(_immutable_precision_low, true / 3), "0\n");
        ASSERT_EQ(test(_immutable_precision_low, 'a' / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 97U / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -97 / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 97UL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -97L / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 3.141f / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, -3.141f / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_precision_low, true / 3), "0\n");
        ASSERT_EQ(test(_mutable_precision_low, 'a' / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 97U / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -97 / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 97UL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -97L / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 3.141f / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, -3.141f / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_immutable_precision, true / 3), "0\n");
        ASSERT_EQ(test(_immutable_precision, 'a' / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 97U / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -97 / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 97UL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -97L / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 3.141f / 3), "1.0470001\n");
        ASSERT_EQ(test(_immutable_precision, -3.141f / 3), "-1.0470001\n");
        ASSERT_EQ(test(_immutable_precision, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_precision, true / 3), "0\n");
        ASSERT_EQ(test(_mutable_precision, 'a' / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 97U / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -97 / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 97UL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -97L / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 3.141f / 3), "1.0470001\n");
        ASSERT_EQ(test(_mutable_precision, -3.141f / 3), "-1.0470001\n");
        ASSERT_EQ(test(_mutable_precision, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_immutable_precision_high, true / 3), "0\n");
        ASSERT_EQ(test(_immutable_precision_high, 'a' / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 97U / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -97 / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 97UL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -97L / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 3.141f / 3), "1.04700005054\n");
        ASSERT_EQ(test(_immutable_precision_high, -3.141f / 3), "-1.04700005054\n");
        ASSERT_EQ(test(_immutable_precision_high, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_precision_high, true / 3), "0\n");
        ASSERT_EQ(test(_mutable_precision_high, 'a' / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 97U / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -97 / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 97UL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -97L / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 3.141f / 3), "1.04700005054\n");
        ASSERT_EQ(test(_mutable_precision_high, -3.141f / 3), "-1.04700005054\n");
        ASSERT_EQ(test(_mutable_precision_high, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, "I love pi!\n"), "I love pi!\n\n");
    }

    TEST_F(Precision, print_operator_large) // NOLINT
    {
        auto test = [&](const auto& prec_, const auto& val_) {
            std::stringstream stream;

            stream << prec_ << val_ << '\n';

            return (stream.str());
        };

        ASSERT_EQ(test(_immutable_precision_low, true / 3), "0\n");
        ASSERT_EQ(test(_immutable_precision_low, 'a' / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 97U / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -97 / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 97UL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -97L / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_low, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_low, 3.141f / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, -3.141f / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_low, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_precision_low, true / 3), "0\n");
        ASSERT_EQ(test(_mutable_precision_low, 'a' / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 97U / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -97 / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 97UL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -97L / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_low, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_low, 3.141f / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, -3.141f / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_low, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_immutable_precision, true / 3), "0\n");
        ASSERT_EQ(test(_immutable_precision, 'a' / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 97U / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -97 / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 97UL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -97L / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision, 3.141f / 3), "1.0470001\n");
        ASSERT_EQ(test(_immutable_precision, -3.141f / 3), "-1.0470001\n");
        ASSERT_EQ(test(_immutable_precision, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_precision, true / 3), "0\n");
        ASSERT_EQ(test(_mutable_precision, 'a' / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 97U / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -97 / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 97UL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -97L / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision, 3.141f / 3), "1.0470001\n");
        ASSERT_EQ(test(_mutable_precision, -3.141f / 3), "-1.0470001\n");
        ASSERT_EQ(test(_mutable_precision, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_immutable_precision_high, true / 3), "0\n");
        ASSERT_EQ(test(_immutable_precision_high, 'a' / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 97U / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -97 / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 97UL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -97L / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_immutable_precision_high, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_immutable_precision_high, 3.141f / 3), "1.04700005054\n");
        ASSERT_EQ(test(_immutable_precision_high, -3.141f / 3), "-1.04700005054\n");
        ASSERT_EQ(test(_immutable_precision_high, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_immutable_precision_high, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_precision_high, true / 3), "0\n");
        ASSERT_EQ(test(_mutable_precision_high, 'a' / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -'a' / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 97U / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -97 / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 97UL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -97L / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 97ULL / 3), "32\n");
        ASSERT_EQ(test(_mutable_precision_high, -97LL / 3), "-32\n");
        ASSERT_EQ(test(_mutable_precision_high, 3.141f / 3), "1.04700005054\n");
        ASSERT_EQ(test(_mutable_precision_high, -3.141f / 3), "-1.04700005054\n");
        ASSERT_EQ(test(_mutable_precision_high, 3.141 / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, -3.141 / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, 3.141l / 3), "1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, -3.141l / 3), "-1.047\n");
        ASSERT_EQ(test(_mutable_precision_high, "I love pi!\n"), "I love pi!\n\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
