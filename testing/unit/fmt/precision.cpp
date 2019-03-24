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
namespace test
{



    //  == TESTS ==
    //  -- Prime --
    TEST(int, small) // NOLINT
    {
        using namespace arc;

        std::ostringstream stream;
        stream << arc::fmt::Precision{5} << 324;

        const auto str{stream.str()};

        ASSERT_EQ(str, "324");
    }

    TEST(double, small) // NOLINT
    {
        using namespace arc;

        std::ostringstream stream;
        stream << arc::fmt::Precision{8} << (2.0 / 3.0);

        const auto str{stream.str()};

        ASSERT_EQ(str, "0.66666667");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
