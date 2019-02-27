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
        std::vector<int> vec_0{0, 1, 2, 3};
        arc::range::View view(&vec_0);

        std::vector<int> vec_1{4, 5, 6};
        view.set_range(&vec_1);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
