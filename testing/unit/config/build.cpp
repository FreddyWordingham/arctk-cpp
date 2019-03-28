//  == IMPORTS ==
//  -- Unit --
#include "arctk/config/build.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cstring>
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



    //  == CONSTANT TESTS ==
    //  -- Build Information  --
    TEST(build, DIR) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::DIR), 5);

        ASSERT_TRUE(std::string{arc::config::DIR}.find("arctk") != std::string::npos);
    }

    TEST(build, BRANCH) // NOLINT
    {
        ASSERT_GE(std::strlen(arc::config::BRANCH), 3);
    }

    TEST(build, HASH) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::HASH), 8);
    }

    TEST(build, COMPILER) // NOLINT
    {
        ASSERT_GE(std::strlen(arc::config::COMPILER), 3);

        ASSERT_TRUE((arc::config::COMPILER == "Clang") || (arc::config::COMPILER == "GNU"));
    }

    TEST(build, TYPE) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::TYPE), 0);

        ASSERT_TRUE((arc::config::TYPE == "debug") || (arc::config::TYPE == "release"));
    }

    TEST(build, DATE) // NOLINT
    {
        ASSERT_EQ(std::strlen(arc::config::DATE), 10);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
