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
        arc::range::View view_0(vec_0);

        const std::vector<int> vec_1{0, 1, 2, 3};
        arc::range::View       view_1(vec_1);

        std::vector<int>       vec_2{0, 1, 2, 3};
        const arc::range::View view_2(vec_2);

        const std::vector<int> vec_3{0, 1, 2, 3};
        const arc::range::View view_3(vec_3);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
