//  == IMPORTS ==
//  -- Arc --
#include "arctk/fmt/precision.inl"
#include "arctk/test/constants.inl"
#include "arctk/test/types.inl"

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
namespace testing
{
    namespace unit
    {



        //  == FIXTURES ==
        //  -- Precision --
        class Precision : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Precs --
            fmt::Precision       _mutable_precision_low{6};
            const fmt::Precision _immutable_precision_low{6};
            fmt::Precision       _mutable_precision{8};
            const fmt::Precision _immutable_precision{8};
            fmt::Precision       _mutable_precision_high{12};
            const fmt::Precision _immutable_precision_high{12};
        };



        //  == METHOD TESTS ==
        //  -- Getters --
        TEST_F(Precision, precision) // NOLINT
        {
            ASSERT_EQ(_mutable_precision_low.precision(), 6);
            ASSERT_EQ(_immutable_precision_low.precision(), 6);
            ASSERT_EQ(_mutable_precision.precision(), 8);
            ASSERT_EQ(_immutable_precision.precision(), 8);
            ASSERT_EQ(_mutable_precision_high.precision(), 12);
            ASSERT_EQ(_immutable_precision_high.precision(), 12);
        }



        //  == FREE OPERATOR TESTS ==
        //  -- Printing --
        TEST_F(Precision, print_operator) // NOLINT
        {
            auto test = [](const auto& prec_, const auto val_) {
                std::stringstream stream;
                stream << prec_ << val_ << '\n';
                return (stream.str());
            };

            ASSERT_STREQ(test(_mutable_precision_low, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_immutable_precision_low, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_mutable_precision, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_immutable_precision, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_mutable_precision_high, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_immutable_precision_high, test::FLOAT_CANON), "-3.14159\n");
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
