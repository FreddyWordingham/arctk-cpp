//  == IMPORTS ==
//  -- Unit --
#include "arctk/config/build.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cstring>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == BUILD INFORMATION TESTS ==
    //  -- DIR --
    TEST(DIR, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::DIR), 5);
    }

    TEST(DIR, contains_arctk_keyword) // NOLINT
    {
        const std::string dir{arc::config::DIR};

        ASSERT_TRUE(dir.find("arctk") != std::string::npos);
    }


    //  -- BRANCH --
    TEST(BRANCH, occupied) // NOLINT
    {
        ASSERT_GE(std::strlen(arc::config::BRANCH), 3);
    }


    //  -- HASH --
    TEST(HASH, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::HASH), 8);
    }


    //  -- COMPILER --
    TEST(COMPILER, occupied) // NOLINT
    {
        ASSERT_GE(std::strlen(arc::config::COMPILER), 3);
    }

    TEST(COMPILER, valid) // NOLINT
    {
        ASSERT_TRUE((arc::config::COMPILER == "Clang") || (arc::config::COMPILER == "GNU"));
    }


    //  -- TYPE --
    TEST(TYPE, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::TYPE), 0);
    }

    TEST(TYPE, valid) // NOLINT
    {
        ASSERT_TRUE((arc::config::TYPE == "debug") || (arc::config::TYPE == "release"));
    }


    //  -- DATE --
    TEST(DATE, occupied) // NOLINT
    {
        ASSERT_EQ(std::strlen(arc::config::DATE), 10);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
