//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/reverse.inl"

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
        arc::range::preview::Reverse rev{};
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
