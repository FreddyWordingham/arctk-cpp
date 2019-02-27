//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/filter.inl"

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
    TEST(Filter, construction) // NOLINT
    {
        const auto pred = [](const int i_) { return ((i_ % 2) == 0); };

        arc::range::preview::Filter filter{pred};
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
