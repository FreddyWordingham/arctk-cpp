//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/reverse.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>



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
    //  -- Access --
    TEST(reverse, access) // NOLINT
    {
        std::array<int, 4>        arr{0, 1, 2, 3};
        arc::range::view::Reverse rev{arr};

        ASSERT_EQ(rev[0], 3);
        ASSERT_EQ(rev[1], 2);
        ASSERT_EQ(rev[2], 1);
        ASSERT_EQ(rev[3], 0);
    }


    //  -- Range --
    TEST(reverse, range) // NOLINT
    {
        std::array<int, 4> arr{0, 1, 2, 3};

        int sum{0};
        for (const auto& v : arc::range::view::Reverse{arr})
        {
            sum += v;
        }

        ASSERT_EQ(sum, 6);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
