//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == TESTS ==
    //  -- Preview --
    TEST(preview, construction) // NOLINT
    {
        arc::range::Preview preview{};
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
