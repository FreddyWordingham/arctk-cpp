//  == IMPORTS ==
//  -- Arc --
#include "arctk/tuple/comparison.inl"

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
    TEST(num_equal_elems, empty) // NOLINT
    {
        const std::tuple<> tup_0{};
        const std::tuple<> tup_1{};

        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_1), 0);
    }

    TEST(num_equal_elems, single) // NOLINT
    {
        const std::tuple<std::size_t>   tup_0{7};
        const std::tuple<unsigned int>  tup_1{3};
        const std::tuple<unsigned int>  tup_2{3};
        const std::tuple<unsigned char> tup_3{7};

        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_0), 1);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_1), 0);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_2), 0);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_3), 1);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_1, tup_1), 1);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_1, tup_2), 1);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_1, tup_3), 0);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_2, tup_2), 1);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_2, tup_3), 0);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_3, tup_3), 1);
    }

    TEST(num_equal_elems, multiple) // NOLINT
    {
        const std::tuple<std::size_t, unsigned char, unsigned char> tup_0{7, 1, 7};
        const std::tuple<unsigned int, std::size_t, unsigned char>  tup_1{3, 7, 7};
        const std::tuple<std::size_t, std::size_t, unsigned int>    tup_2{3, 1, 7};

        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_0), 3);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_1), 1);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_0, tup_2), 2);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_1, tup_1), 3);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_1, tup_2), 2);
        ASSERT_EQ(arc::tuple::num_equal_elems(tup_2, tup_2), 3);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
