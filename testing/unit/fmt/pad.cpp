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
    //  -- Pad --
    class Pad : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Pads --
        const fmt::Pad _immutable_small_width{4};
        fmt::Pad       _mutable_small_width{4};
        const fmt::Pad _immutable_width{10};
        fmt::Pad       _mutable_width{10};
        const fmt::Pad _immutable_width_fill{7, '*'};
        fmt::Pad       _mutable_width_fill{7, '*'};
    };



    //  == METHOD TESTS ==
    //  -- Getters --
    TEST_F(Pad, width) // NOLINT
    {
        ASSERT_EQ(_immutable_small_width.width(), 4);

        ASSERT_EQ(_mutable_small_width.width(), 4);

        ASSERT_EQ(_immutable_width.width(), 10);

        ASSERT_EQ(_mutable_width.width(), 10);

        ASSERT_EQ(_immutable_width_fill.width(), 7);

        ASSERT_EQ(_mutable_width_fill.width(), 7);
    }

    TEST_F(Pad, fill) // NOLINT
    {
        ASSERT_EQ(_immutable_small_width.fill(), ' ');

        ASSERT_EQ(_mutable_small_width.fill(), ' ');

        ASSERT_EQ(_immutable_width.fill(), ' ');

        ASSERT_EQ(_mutable_width.fill(), ' ');

        ASSERT_EQ(_immutable_width_fill.fill(), '*');

        ASSERT_EQ(_mutable_width_fill.fill(), '*');
    }



    //  == FREE OPERATOR TESTS ==
    //  -- Printing --
    TEST_F(Pad, print_operator) // NOLINT
    {
        auto test = [&](const auto& pad_, const auto val_) {
            std::stringstream stream;

            stream << pad_ << val_ << '\n';

            return (stream.str());
        };

        ASSERT_EQ(test(_immutable_small_width, true), "   1\n");
        ASSERT_EQ(test(_immutable_small_width, 'a'), "   a\n");
        ASSERT_EQ(test(_immutable_small_width, -'a'), " -97\n");
        ASSERT_EQ(test(_immutable_small_width, 97U), "  97\n");
        ASSERT_EQ(test(_immutable_small_width, -97), " -97\n");
        ASSERT_EQ(test(_immutable_small_width, 97UL), "  97\n");
        ASSERT_EQ(test(_immutable_small_width, -97L), " -97\n");
        ASSERT_EQ(test(_immutable_small_width, 97ULL), "  97\n");
        ASSERT_EQ(test(_immutable_small_width, -97LL), " -97\n");
        ASSERT_EQ(test(_immutable_small_width, 3.141f), "3.141\n");
        ASSERT_EQ(test(_immutable_small_width, -3.141f), "-3.141\n");
        ASSERT_EQ(test(_immutable_small_width, 3.141), "3.141\n");
        ASSERT_EQ(test(_immutable_small_width, -3.141), "-3.141\n");
        ASSERT_EQ(test(_immutable_small_width, 3.141l), "3.141\n");
        ASSERT_EQ(test(_immutable_small_width, -3.141l), "-3.141\n");
        ASSERT_EQ(test(_immutable_small_width, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_small_width, true), "   1\n");
        ASSERT_EQ(test(_mutable_small_width, 'a'), "   a\n");
        ASSERT_EQ(test(_mutable_small_width, -'a'), " -97\n");
        ASSERT_EQ(test(_mutable_small_width, 97U), "  97\n");
        ASSERT_EQ(test(_mutable_small_width, -97), " -97\n");
        ASSERT_EQ(test(_mutable_small_width, 97UL), "  97\n");
        ASSERT_EQ(test(_mutable_small_width, -97L), " -97\n");
        ASSERT_EQ(test(_mutable_small_width, 97ULL), "  97\n");
        ASSERT_EQ(test(_mutable_small_width, -97LL), " -97\n");
        ASSERT_EQ(test(_mutable_small_width, 3.141f), "3.141\n");
        ASSERT_EQ(test(_mutable_small_width, -3.141f), "-3.141\n");
        ASSERT_EQ(test(_mutable_small_width, 3.141), "3.141\n");
        ASSERT_EQ(test(_mutable_small_width, -3.141), "-3.141\n");
        ASSERT_EQ(test(_mutable_small_width, 3.141l), "3.141\n");
        ASSERT_EQ(test(_mutable_small_width, -3.141l), "-3.141\n");
        ASSERT_EQ(test(_mutable_small_width, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_immutable_width, true), "         1\n");
        ASSERT_EQ(test(_immutable_width, 'a'), "         a\n");
        ASSERT_EQ(test(_immutable_width, -'a'), "       -97\n");
        ASSERT_EQ(test(_immutable_width, 97U), "        97\n");
        ASSERT_EQ(test(_immutable_width, -97), "       -97\n");
        ASSERT_EQ(test(_immutable_width, 97UL), "        97\n");
        ASSERT_EQ(test(_immutable_width, -97L), "       -97\n");
        ASSERT_EQ(test(_immutable_width, 97ULL), "        97\n");
        ASSERT_EQ(test(_immutable_width, -97LL), "       -97\n");
        ASSERT_EQ(test(_immutable_width, 3.141f), "     3.141\n");
        ASSERT_EQ(test(_immutable_width, -3.141f), "    -3.141\n");
        ASSERT_EQ(test(_immutable_width, 3.141), "     3.141\n");
        ASSERT_EQ(test(_immutable_width, -3.141), "    -3.141\n");
        ASSERT_EQ(test(_immutable_width, 3.141l), "     3.141\n");
        ASSERT_EQ(test(_immutable_width, -3.141l), "    -3.141\n");
        ASSERT_EQ(test(_immutable_width, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_width, true), "         1\n");
        ASSERT_EQ(test(_mutable_width, 'a'), "         a\n");
        ASSERT_EQ(test(_mutable_width, -'a'), "       -97\n");
        ASSERT_EQ(test(_mutable_width, 97U), "        97\n");
        ASSERT_EQ(test(_mutable_width, -97), "       -97\n");
        ASSERT_EQ(test(_mutable_width, 97UL), "        97\n");
        ASSERT_EQ(test(_mutable_width, -97L), "       -97\n");
        ASSERT_EQ(test(_mutable_width, 97ULL), "        97\n");
        ASSERT_EQ(test(_mutable_width, -97LL), "       -97\n");
        ASSERT_EQ(test(_mutable_width, 3.141f), "     3.141\n");
        ASSERT_EQ(test(_mutable_width, -3.141f), "    -3.141\n");
        ASSERT_EQ(test(_mutable_width, 3.141), "     3.141\n");
        ASSERT_EQ(test(_mutable_width, -3.141), "    -3.141\n");
        ASSERT_EQ(test(_mutable_width, 3.141l), "     3.141\n");
        ASSERT_EQ(test(_mutable_width, -3.141l), "    -3.141\n");
        ASSERT_EQ(test(_mutable_width, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_immutable_width_fill, true), "******1\n");
        ASSERT_EQ(test(_immutable_width_fill, 'a'), "******a\n");
        ASSERT_EQ(test(_immutable_width_fill, -'a'), "****-97\n");
        ASSERT_EQ(test(_immutable_width_fill, 97U), "*****97\n");
        ASSERT_EQ(test(_immutable_width_fill, -97), "****-97\n");
        ASSERT_EQ(test(_immutable_width_fill, 97UL), "*****97\n");
        ASSERT_EQ(test(_immutable_width_fill, -97L), "****-97\n");
        ASSERT_EQ(test(_immutable_width_fill, 97ULL), "*****97\n");
        ASSERT_EQ(test(_immutable_width_fill, -97LL), "****-97\n");
        ASSERT_EQ(test(_immutable_width_fill, 3.141f), "**3.141\n");
        ASSERT_EQ(test(_immutable_width_fill, -3.141f), "*-3.141\n");
        ASSERT_EQ(test(_immutable_width_fill, 3.141), "**3.141\n");
        ASSERT_EQ(test(_immutable_width_fill, -3.141), "*-3.141\n");
        ASSERT_EQ(test(_immutable_width_fill, 3.141l), "**3.141\n");
        ASSERT_EQ(test(_immutable_width_fill, -3.141l), "*-3.141\n");
        ASSERT_EQ(test(_immutable_width_fill, "I love pi!\n"), "I love pi!\n\n");

        ASSERT_EQ(test(_mutable_width_fill, true), "******1\n");
        ASSERT_EQ(test(_mutable_width_fill, 'a'), "******a\n");
        ASSERT_EQ(test(_mutable_width_fill, -'a'), "****-97\n");
        ASSERT_EQ(test(_mutable_width_fill, 97U), "*****97\n");
        ASSERT_EQ(test(_mutable_width_fill, -97), "****-97\n");
        ASSERT_EQ(test(_mutable_width_fill, 97UL), "*****97\n");
        ASSERT_EQ(test(_mutable_width_fill, -97L), "****-97\n");
        ASSERT_EQ(test(_mutable_width_fill, 97ULL), "*****97\n");
        ASSERT_EQ(test(_mutable_width_fill, -97LL), "****-97\n");
        ASSERT_EQ(test(_mutable_width_fill, 3.141f), "**3.141\n");
        ASSERT_EQ(test(_mutable_width_fill, -3.141f), "*-3.141\n");
        ASSERT_EQ(test(_mutable_width_fill, 3.141), "**3.141\n");
        ASSERT_EQ(test(_mutable_width_fill, -3.141), "*-3.141\n");
        ASSERT_EQ(test(_mutable_width_fill, 3.141l), "**3.141\n");
        ASSERT_EQ(test(_mutable_width_fill, -3.141l), "*-3.141\n");
        ASSERT_EQ(test(_mutable_width_fill, "I love pi!\n"), "I love pi!\n\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
