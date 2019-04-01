//  == IMPORTS ==
//  -- Arc --
#include "arctk/fmt/pad.inl"
#include "arctk/test/constants.inl"
#include "arctk/test/types.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cstddef>
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
namespace testing
{
    namespace unit
    {



        //  == FIXTURES ==
        //  -- Pad --
        class fmt_Pad : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Pads --
            fmt::Pad       _mutable_small_width{4};
            const fmt::Pad _immutable_small_width{4};
            fmt::Pad       _mutable_width{10};
            const fmt::Pad _immutable_width{10};
            fmt::Pad       _mutable_width_fill{7, '*'};
            const fmt::Pad _immutable_width_fill{7, '*'};
        };



        //  == METHOD TESTS ==
        //  -- Getters --
        TEST_F(fmt_Pad, width) // NOLINT
        {
            ASSERT_EQ(_mutable_small_width.width(), 4);
            ASSERT_EQ(_immutable_small_width.width(), 4);
            ASSERT_EQ(_mutable_width.width(), 10);
            ASSERT_EQ(_immutable_width.width(), 10);
            ASSERT_EQ(_mutable_width_fill.width(), 7);
            ASSERT_EQ(_immutable_width_fill.width(), 7);
        }

        TEST_F(fmt_Pad, fill) // NOLINT
        {
            ASSERT_EQ(_mutable_small_width.fill(), ' ');
            ASSERT_EQ(_immutable_small_width.fill(), ' ');
            ASSERT_EQ(_mutable_width.fill(), ' ');
            ASSERT_EQ(_immutable_width.fill(), ' ');
            ASSERT_EQ(_mutable_width_fill.fill(), '*');
            ASSERT_EQ(_immutable_width_fill.fill(), '*');
        }



        //  == FREE OPERATOR TESTS ==
        //  -- Printing --
        TEST_F(fmt_Pad, operator_stream_out) // NOLINT
        {
            auto test = [](const auto& pad_, const auto val_) {
                std::stringstream stream;
                stream << pad_ << val_ << '\n';
                return (stream.c_str());
            };

            ASSERT_STREQ(test(_mutable_small_width, test::BOOL_CANON), "   1\n");
            ASSERT_STREQ(test(_immutable_small_width, test::BOOL_CANON), "   1\n");
            ASSERT_STREQ(test(_mutable_width, test::BOOL_CANON), "         1\n");
            ASSERT_STREQ(test(_immutable_width, test::BOOL_CANON), "         1\n");
            ASSERT_STREQ(test(_mutable_width_fill, test::BOOL_CANON), "******1\n");
            ASSERT_STREQ(test(_immutable_width_fill, test::BOOL_CANON), "******1\n");

            ASSERT_STREQ(test(_mutable_small_width, test::CHAR_CANON), "   a\n");
            ASSERT_STREQ(test(_immutable_small_width, test::CHAR_CANON), "   a\n");
            ASSERT_STREQ(test(_mutable_width, test::CHAR_CANON), "         a\n");
            ASSERT_STREQ(test(_immutable_width, test::CHAR_CANON), "         a\n");
            ASSERT_STREQ(test(_mutable_width_fill, test::CHAR_CANON), "******a\n");
            ASSERT_STREQ(test(_immutable_width_fill, test::CHAR_CANON), "******a\n");

            ASSERT_STREQ(test(_mutable_small_width, test::INT_CANON), "-32749\n");
            ASSERT_STREQ(test(_immutable_small_width, test::INT_CANON), "-32749\n");
            ASSERT_STREQ(test(_mutable_width, test::INT_CANON), "    -32749\n");
            ASSERT_STREQ(test(_immutable_width, test::INT_CANON), "    -32749\n");
            ASSERT_STREQ(test(_mutable_width_fill, test::INT_CANON), "*-32749\n");
            ASSERT_STREQ(test(_immutable_width_fill, test::INT_CANON), "*-32749\n");

            ASSERT_STREQ(test(_mutable_small_width, test::SIZE_CANON), "67280421310721\n");
            ASSERT_STREQ(test(_immutable_small_width, test::SIZE_CANON), "67280421310721\n");
            ASSERT_STREQ(test(_mutable_width, test::SIZE_CANON), "67280421310721\n");
            ASSERT_STREQ(test(_immutable_width, test::SIZE_CANON), "67280421310721\n");
            ASSERT_STREQ(test(_mutable_width_fill, test::SIZE_CANON), "67280421310721\n");
            ASSERT_STREQ(test(_immutable_width_fill, test::SIZE_CANON), "67280421310721\n");

            ASSERT_STREQ(test(_mutable_small_width, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_immutable_small_width, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_mutable_width, test::FLOAT_CANON), "  -3.14159\n");
            ASSERT_STREQ(test(_immutable_width, test::FLOAT_CANON), "  -3.14159\n");
            ASSERT_STREQ(test(_mutable_width_fill, test::FLOAT_CANON), "-3.14159\n");
            ASSERT_STREQ(test(_immutable_width_fill, test::FLOAT_CANON), "-3.14159\n");

            ASSERT_STREQ(test(_mutable_small_width, test::C_STR_CANON{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");
            ASSERT_STREQ(test(_immutable_small_width, test::C_STR_CANON{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");
            ASSERT_STREQ(test(_mutable_width, test::C_STR_CANON{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");
            ASSERT_STREQ(test(_immutable_width, test::C_STR_CANON{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");
            ASSERT_STREQ(test(_mutable_width_fill, test::C_STR_CANON{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");
            ASSERT_STREQ(test(_immutable_width_fill, test::C_STR_CANON{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
