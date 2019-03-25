//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/progress.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <iostream>



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
    TEST(Progress, construction) // NOLINT
    {
        arc::range::preview::Progress bar{std::cout, 20};
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
