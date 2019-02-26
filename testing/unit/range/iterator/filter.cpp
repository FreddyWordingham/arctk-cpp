//  == IMPORTS ==
//  -- Arc --
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
#pragma clang diagnostic ignored "-Wpadded"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == FIXTURES ==
    //  -- Properties --
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
    TEST_F(array_int, count_if) // NOLINT
    {
        const auto                   even_and_gt_five = [](const int& i_) { return ((i_ > 5) && ((i_ % 2) == 0)); };
        arc::range::iterator::Filter begin{_arr_non_prime.begin(), _arr_non_prime.end(), even_and_gt_five};
        arc::range::iterator::Filter end{_arr_non_prime.end(), _arr_non_prime.end(), even_and_gt_five};

        std::array<int, 4>                     arr{6, 8, 10, 12};
        typename std::array<int, 4>::size_type index{0};
        for (; begin != end; ++begin)
        {
            ASSERT_EQ(*begin, arr[index]);
            ++index;
        }
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
