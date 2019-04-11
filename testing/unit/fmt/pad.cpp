//  == IMPORTS ==
//  -- Arc --
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



//  == NAMESPACE ==
namespace test::unit
{



    //  == TESTS ==
    //  -- Pad --
    TEST(arc_fmt, constructors) // NOLINT
    {
        arc::fmt::Pad{7};
        arc::fmt::Pad{7, '*'};
    }

    TEST(arc_fmt, width) // NOLINT
    {
        ASSERT_EQ(arc::fmt::Pad{7}.width(), 7);
        ASSERT_EQ(arc::fmt::Pad{12}.width(), 12);

        ASSERT_EQ((arc::fmt::Pad{7, '*'}).width(), 7);
        ASSERT_EQ((arc::fmt::Pad{12, '['}).width(), 12);
    }

    TEST(arc_fmt, fill) // NOLINT
    {
        ASSERT_EQ(arc::fmt::Pad{7}.fill(), ' ');
        ASSERT_EQ(arc::fmt::Pad{12}.fill(), ' ');

        ASSERT_EQ((arc::fmt::Pad{7, '*'}).fill(), '*');
        ASSERT_EQ((arc::fmt::Pad{12, '['}).fill(), '[');
    }


    //  -- Printing --
    TEST(, printing) // NOLINT
    {
        const auto lamb = [](const auto& pad_, const auto& val_) {
            std::ostringstream stream;

            stream << pad_ << val_;

            return (stream.str());
        };

        ASSERT_EQ(lamb(arc::fmt::Pad{7}, 3.14), "   3.14");
        ASSERT_EQ(lamb(arc::fmt::Pad{12}, 3.14), "        3.14");
        ASSERT_EQ(lamb(arc::fmt::Pad{7, '*'}, 3.14), "***3.14");
        ASSERT_EQ(lamb(arc::fmt::Pad{12, '['}, 3.14), "[[[[[[[[3.14");
    }



} // namespace test::unit



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
