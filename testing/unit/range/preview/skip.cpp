//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/skip.inl"

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
    TEST(Reverse, construction) // NOLINT
    {
        arc::range::preview::Skip rev_0{2};
        arc::range::preview::Skip rev_1{2, 3};
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
