//  == IMPORTS ==
//  -- Arc --
#include "arctk/cfg/version.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace test
{
    namespace unit
    {



        //  == TESTS ==
        //  -- Version --
        TEST(arc_cfg, VERSION_MINOR) // NOLINT
        {
            ASSERT_GE(arc::cfg::VERSION_MINOR, 0);
        }

        TEST(arc_cfg, VERSION_MAJOR) // NOLINT
        {
            ASSERT_GE(arc::cfg::VERSION_MAJOR, 0);
        }

        TEST(arc_cfg, VERSION_PATCH) // NOLINT
        {
            ASSERT_GE(arc::cfg::VERSION_PATCH, 0);
        }



    } // namespace unit
} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
