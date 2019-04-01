//  == IMPORTS ==
//  -- Arc --
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
namespace testing
{
    namespace unit
    {



        //  == CONSTANT TESTS ==
        //  -- Version --
        TEST(arc_config, VERSION_MAJOR) // NOLINT
        {
            ASSERT_GE(config::VERSION_MAJOR, 0);
        }

        TEST(arc_config, VERSION_MINOR) // NOLINT
        {
            ASSERT_GE(config::VERSION_MINOR, 0);
        }

        TEST(arc_config, VERSION_PATCH) // NOLINT
        {
            ASSERT_GE(config::VERSION_PATCH, 0);
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
