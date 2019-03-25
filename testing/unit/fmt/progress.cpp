//  == IMPORTS ==
//  -- Arc --
#include "arctk/fmt/progress.inl"

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



    //  == TESTS ==
    //  -- Progress Bat --
    TEST(progress, medium) // NOLINT
    {
        ASSERT_EQ(arc::fmt::progress(20, 0.25), "[====              ]");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
