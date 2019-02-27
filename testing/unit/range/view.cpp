//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <vector>



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
    //  -- Prime --
    TEST(view, constructor) // NOLINT
    {
        std::vector<int> vec{0, 1, 2, 3};
        arc::range::View view(&vec);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
