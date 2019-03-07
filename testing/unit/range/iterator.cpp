//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator.inl"
#include "arctk/range/iterator/filter.inl"

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



    //  == FIXTURES ==
    //  -- Filter --
    class array_int : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 8> _arr_ascend{0, 1, 2, 3, 4, 5, 6, 7};
        const std::array<int, 8> _arr_prime{2, 3, 5, 7, 11, 13, 17, 19};
        const std::array<int, 8> _arr_non_prime{0, 1, 4, 6, 8, 9, 10, 12};
    };



    //  == TESTS ==
    //  -- Filter --
    TEST_F(array_int, filter) // NOLINT
    {
        auto is_even = [](const int& i_) { return ((i_ % 2) == 0); };

        arc::range::iterator::Filter filter_start{_arr_ascend.begin(), _arr_ascend.end(), is_even};
        arc::range::iterator::Filter filter_end{_arr_ascend.end(), _arr_ascend.end(), is_even};

        ASSERT_EQ(filter_start, filter_start);
        ASSERT_EQ(filter_end, filter_end);
        ASSERT_NE(filter_start, filter_end);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
