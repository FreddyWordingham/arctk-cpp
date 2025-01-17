//  == IMPORTS ==
//  -- Arc --
#include "arctk/cfg/build.inl"

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



//  == NAMESPACE ==
namespace test::unit
{



    //  == TESTS ==
    //  -- Build Information --
    TEST(arc_cfg, DIR) // NOLINT
    {
        ASSERT_GE(std::strlen(arc::cfg::DIR), 5);
        ASSERT_NE(std::string{arc::cfg::DIR}.find("arctk"), std::string::npos);
    }

    TEST(arc_cfg, BRANCH) // NOLINT
    {
        ASSERT_GE(std::strlen(arc::cfg::BRANCH), 3);
    }

    TEST(arc_cfg, HASH) // NOLINT
    {
        ASSERT_GE(std::strlen(arc::cfg::HASH), 6);
    }

    TEST(arc_cfg, COMPILER) // NOLINT
    {
#ifdef __clang__
        ASSERT_STREQ(arc::cfg::COMPILER, "Clang");
#elif __GNUC__
        ASSERT_STREQ(arc::cfg::COMPILER, "GNU");
#else
        GTEST_FAIL();
#endif
    }

    TEST(arc_cfg, TYPE) // NOLINT
    {
#ifdef DEBUG
        ASSERT_STREQ(arc::cfg::TYPE, "debug");
#else
        ASSERT_STREQ(arc::cfg::TYPE, "release");
#endif
    }

    TEST(arc_cfg, DATE) // NOLINT
    {
        const std::string date{arc::cfg::DATE};

        const int year{std::stoi(date.substr(0, date.find_first_of('-')))};
        const int month{std::stoi(date.substr(date.find_first_of('-') + 1, date.find_last_of('-') - date.find_first_of('-') - 1))};
        const int day{std::stoi(date.substr(date.find_last_of('-') + 1))};

        ASSERT_GE(year, 2019);
        ASSERT_GE(month, 1);
        ASSERT_GE(day, 1);
    }



} // namespace test::unit



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
