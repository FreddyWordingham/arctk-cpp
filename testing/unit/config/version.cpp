//  == IMPORTS ==
//  -- Unit --
#include "arctk/config/version.inl"

//  -- GTest --
#include <gtest/gtest.h>



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



    //  == CONSTANT TESTS ==
    //  -- Version --
    TEST(VERSION_MAJOR, non_negative) // NOLINT
    {
        ASSERT_GE(arc::config::VERSION_MAJOR, 0);
    }

    TEST(VERSION_MINOR, non_negative) // NOLINT
    {
        ASSERT_GE(arc::config::VERSION_MINOR, 0);
    }

    TEST(VERSION_PATCH, non_negative) // NOLINT
    {
        ASSERT_GE(arc::config::VERSION_PATCH, 0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
