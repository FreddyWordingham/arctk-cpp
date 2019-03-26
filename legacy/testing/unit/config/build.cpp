//  == IMPORTS ==
//  -- Arc --
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



    //  == TESTS ==
    //  -- Prime --
    TEST(DIR, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::DIR), 0);
    }

    TEST(BRANCH, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::BRANCH), 0);
    }

    TEST(HASH, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::HASH), 0);
    }

    TEST(COMPILER, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::COMPILER), 0);
    }

    TEST(TYPE, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::TYPE), 0);
    }

    TEST(DATE, occupied) // NOLINT
    {
        ASSERT_GT(std::strlen(arc::config::DATE), 0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
