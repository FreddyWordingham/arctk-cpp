//  == IMPORTS ==
//  -- Arc --
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
namespace testing
{
    namespace unit
    {



        //  == CONSTANT TESTS ==
        //  -- Build Information  --
        TEST(arc_config, DIR) // NOLINT
        {
            ASSERT_GT(std::strlen(config::DIR), 5);


            ASSERT_TRUE(std::string{config::DIR}.find("arctk") != std::string::npos);
        }

        TEST(arc_config, BRANCH) // NOLINT
        {
            ASSERT_GE(std::strlen(config::BRANCH), 3);
        }

        TEST(arc_config, HASH) // NOLINT
        {
            ASSERT_GT(std::strlen(config::HASH), 8);
        }

        TEST(arc_config, COMPILER) // NOLINT
        {
            ASSERT_GE(std::strlen(config::COMPILER), 3);

            ASSERT_TRUE((config::COMPILER == "Clang") || (config::COMPILER == "GNU"));
        }

        TEST(arc_config, TYPE) // NOLINT
        {
            ASSERT_GT(std::strlen(config::TYPE), 0);

            ASSERT_TRUE((config::TYPE == "debug") || (config::TYPE == "release"));
        }

        TEST(arc_config, DATE) // NOLINT
        {
            ASSERT_EQ(std::strlen(config::DATE), 10);
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
