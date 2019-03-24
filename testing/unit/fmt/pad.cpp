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
namespace test
{



    //  == TESTS ==
    //  -- Prime --
    TEST(string, small) // NOLINT
    {
        using namespace arc;

        std::ostringstream stream;
        stream << arc::fmt::Pad{8} << "Hello!";

        const auto str{stream.str()};

        ASSERT_EQ(str, "  Hello!");
    }

    TEST(int, small) // NOLINT
    {
        using namespace arc;

        std::ostringstream stream;
        stream << arc::fmt::Pad{8, '*'} << 374;

        const auto str{stream.str()};

        ASSERT_EQ(str, "*****374");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
