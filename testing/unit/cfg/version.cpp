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
namespace testing
{
    namespace unit
    {



        //  == TESTS ==
        //  -- Prime --
        TEST(arc::cfg, version::DIR) // NOLINT
        {
            GTEST_FAIL();
        }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
