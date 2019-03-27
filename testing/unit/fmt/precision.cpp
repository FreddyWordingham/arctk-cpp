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
#pragma clang diagnostic ignored "-Wglobal-constructors"
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
        //  -- Immutable --
        const fmt::Precision _immutable_precision{8};

        //  -- Mutable --
        fmt::Precision _mutable_precision{8};
    };



    //  == METHOD TESTS ==
    //  -- Getters --
    TEST_F(Precision, precision) // NOLINT
    {
        ASSERT_EQ(_immutable_precision.precision(), 8);

        ASSERT_EQ(_mutable_precision.precision(), 8);
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

        ASSERT_EQ(test(_immutable_precision, 100.0f / 3.0f), "33.333332\n");
        ASSERT_EQ(test(_immutable_precision, 100.0 / 3.0), "33.333333\n");
        ASSERT_EQ(test(_immutable_precision, 100.0l / 3.0l), "33.333333\n");

        ASSERT_EQ(test(_mutable_precision, 100.0f / 3.0f), "33.333332\n");
        ASSERT_EQ(test(_mutable_precision, 100.0 / 3.0), "33.333333\n");
        ASSERT_EQ(test(_mutable_precision, 100.0l / 3.0l), "33.333333\n");
    }

    TEST_F(Precision, print_operator_large) // NOLINT
    {
        auto test = [&](const auto& prec_, const auto& val_) {
            std::stringstream stream;

            stream << prec_ << val_ << '\n';

            return (stream.str());
        };

        ASSERT_EQ(test(_immutable_precision, (1.0e4f / 9.0f) * (1.0e4f / 9.0f)), "1234567.9\n");
        ASSERT_EQ(test(_immutable_precision, (1.0e4 / 9.0) * (1.0e4 / 9.0)), "1234567.9\n");
        ASSERT_EQ(test(_immutable_precision, (1.0e4l / 9.0l) * (1.0e4l / 9.0l)), "1234567.9\n");

        ASSERT_EQ(test(_mutable_precision, (1.0e4f / 9.0f) * (1.0e4f / 9.0f)), "1234567.9\n");
        ASSERT_EQ(test(_mutable_precision, (1.0e4 / 9.0) * (1.0e4 / 9.0)), "1234567.9\n");
        ASSERT_EQ(test(_mutable_precision, (1.0e4l / 9.0l) * (1.0e4l / 9.0l)), "1234567.9\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
