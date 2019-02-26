//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/list.inl"

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
    //  -- List --
    TEST(list, min_max) // NOLINT
    {
        ASSERT_EQ(arc::range::list(0, 4), (std::vector{0, 1, 2, 3, 4}));
    }

    TEST(list, max_min) // NOLINT
    {
        ASSERT_EQ(arc::range::list(4, 0), (std::vector{4, 3, 2, 1, 0}));
    }

    TEST(list, min_max_space) // NOLINT
    {
        ASSERT_EQ(arc::range::list(0, 12, 2), (std::vector{0, 2, 4, 6, 8, 10, 12}));
    }

    TEST(list, max_min_space) // NOLINT
    {
        ASSERT_EQ(arc::range::list(0, -12, -2), (std::vector{0, -2, -4, -6, -8, -10, -12}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
