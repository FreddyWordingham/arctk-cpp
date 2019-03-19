//  == IMPORTS ==
//  -- Arc --
#include "arctk/pair/comparison.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cstddef>



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
    //  -- Comparisom --
    TEST(num_equal_elems, pair) // NOLINT
    {
        const std::pair<std::size_t, unsigned char> pair_0{7, 1};
        const std::pair<unsigned int, std::size_t>  pair_1{3, 7};
        const std::pair<std::size_t, unsigned int>  pair_2{3, 1};

        ASSERT_EQ(arc::pair::num_equal_elems(pair_0, pair_0), 2);
        ASSERT_EQ(arc::pair::num_equal_elems(pair_0, pair_1), 0);
        ASSERT_EQ(arc::pair::num_equal_elems(pair_0, pair_2), 1);
        ASSERT_EQ(arc::pair::num_equal_elems(pair_1, pair_1), 2);
        ASSERT_EQ(arc::pair::num_equal_elems(pair_1, pair_2), 1);
        ASSERT_EQ(arc::pair::num_equal_elems(pair_2, pair_2), 2);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
