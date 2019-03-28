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
    TEST(version, VERSION_MAJOR) // NOLINT
    {
        ASSERT_GE(arc::config::VERSION_MAJOR, 0);
    }

    TEST(version, VERSION_MINOR) // NOLINT
    {
        ASSERT_GE(arc::config::VERSION_MINOR, 0);
    }

    TEST(version, VERSION_PATCH) // NOLINT
    {
        ASSERT_GE(arc::config::VERSION_PATCH, 0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
