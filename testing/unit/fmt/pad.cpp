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

        ASSERT_EQ(test(_immutable_small_width, bool{true}), "   1\n");
        ASSERT_EQ(test(_immutable_small_width, char{'a'}), "   a\n");
        ASSERT_EQ(test(_immutable_small_width, int{-32749}), "-32749\n");
        ASSERT_EQ(test(_immutable_small_width, std::size_t{67280421310721}), "67280421310721\n");
        ASSERT_EQ(test(_immutable_small_width, double{-3.14159265358979323846}), "-3.14159\n");
        ASSERT_EQ(test(_immutable_small_width, std::string{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");

        ASSERT_EQ(test(_mutable_small_width, bool{true}), "   1\n");
        ASSERT_EQ(test(_mutable_small_width, char{'a'}), "   a\n");
        ASSERT_EQ(test(_mutable_small_width, int{-32749}), "-32749\n");
        ASSERT_EQ(test(_mutable_small_width, std::size_t{67280421310721}), "67280421310721\n");
        ASSERT_EQ(test(_mutable_small_width, double{-3.14159265358979323846}), "-3.14159\n");
        ASSERT_EQ(test(_mutable_small_width, std::string{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");

        ASSERT_EQ(test(_immutable_width, bool{true}), "         1\n");
        ASSERT_EQ(test(_immutable_width, char{'a'}), "         a\n");
        ASSERT_EQ(test(_immutable_width, int{-32749}), "    -32749\n");
        ASSERT_EQ(test(_immutable_width, std::size_t{67280421310721}), "67280421310721\n");
        ASSERT_EQ(test(_immutable_width, double{-3.14159265358979323846}), "  -3.14159\n");
        ASSERT_EQ(test(_immutable_width, std::string{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");

        ASSERT_EQ(test(_mutable_width, bool{true}), "         1\n");
        ASSERT_EQ(test(_mutable_width, char{'a'}), "         a\n");
        ASSERT_EQ(test(_mutable_width, int{-32749}), "    -32749\n");
        ASSERT_EQ(test(_mutable_width, std::size_t{67280421310721}), "67280421310721\n");
        ASSERT_EQ(test(_mutable_width, double{-3.14159265358979323846}), "  -3.14159\n");
        ASSERT_EQ(test(_mutable_width, std::string{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");

        ASSERT_EQ(test(_immutable_width_fill, bool{true}), "******1\n");
        ASSERT_EQ(test(_immutable_width_fill, char{'a'}), "******a\n");
        ASSERT_EQ(test(_immutable_width_fill, int{-32749}), "*-32749\n");
        ASSERT_EQ(test(_immutable_width_fill, std::size_t{67280421310721}), "67280421310721\n");
        ASSERT_EQ(test(_immutable_width_fill, double{-3.14159265358979323846}), "-3.14159\n");
        ASSERT_EQ(test(_immutable_width_fill, std::string{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");

        ASSERT_EQ(test(_mutable_width_fill, bool{true}), "******1\n");
        ASSERT_EQ(test(_mutable_width_fill, char{'a'}), "******a\n");
        ASSERT_EQ(test(_mutable_width_fill, int{-32749}), "*-32749\n");
        ASSERT_EQ(test(_mutable_width_fill, std::size_t{67280421310721}), "67280421310721\n");
        ASSERT_EQ(test(_mutable_width_fill, double{-3.14159265358979323846}), "-3.14159\n");
        ASSERT_EQ(test(_mutable_width_fill, std::string{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
