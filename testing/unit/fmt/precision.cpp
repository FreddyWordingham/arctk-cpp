//  == IMPORTS ==
//  -- Arc --
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



//  == NAMESPACE ==
namespace test::unit
{



    //  == TESTS ==
    //  -- Precision --
    TEST(arc_fmt, constructors) // NOLINT
    {
        arc::fmt::Precision{12};
    }

    TEST(arc_fmt, precision) // NOLINT
    {
        ASSERT_EQ(arc::fmt::Precision{7}.precision(), 7);
        ASSERT_EQ(arc::fmt::Precision{12}.precision(), 12);
    }


    //  -- Printing --
    TEST(, printing) // NOLINT
    {
        const auto test = [](const auto& prec_, const auto& val_) {
            std::ostringstream stream;

            stream << prec_ << val_;

            return (stream.str());
        };

        ASSERT_EQ(test(arc::fmt::Precision{7}, 1.1111 * 1.1111), "1.234543");
        ASSERT_EQ(test(arc::fmt::Precision{12}, 1.1111 * 1.1111), "1.23454321");
        ASSERT_EQ(test(arc::fmt::Precision{12}, 1.111111 * 1.111111), "1.23456765432");
    }



} // namespace test::unit



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
