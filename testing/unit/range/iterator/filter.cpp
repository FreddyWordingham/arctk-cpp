//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/filter.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
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
    TEST_F(array_int, filter) // NOLINT
    {
        const auto                   even_and_gt_five = [](const int& i_) { return ((i_ > 5) && ((i_ % 2) == 0)); };
        arc::range::iterator::Filter begin_0{_arr_non_prime.begin(), _arr_non_prime.end(), even_and_gt_five};
        arc::range::iterator::Filter end_0{_arr_non_prime.end(), _arr_non_prime.end(), even_and_gt_five};

        std::array<int, 4>                     arr{6, 8, 10, 12};
        typename std::array<int, 4>::size_type index{0};
        for (; begin_0 != end_0; ++begin_0)
        {
            ASSERT_EQ(*begin_0, arr[index]);
            ++index;
        }

        std::vector<int>             _vec_ascend{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        arc::range::iterator::Filter begin_1{_vec_ascend.begin(), _vec_ascend.end(), even_and_gt_five};
        arc::range::iterator::Filter end_1{_vec_ascend.end(), _vec_ascend.end(), even_and_gt_five};

        for (; begin_1 != end_1; ++begin_1)
        {
            *begin_1 = 0;
        }

        const std::vector<int> _vec_ascend_post{0, 1, 2, 3, 4, 5, 0, 7, 0, 9, 0, 11, 0, 13, 0, 15, 0, 17, 0, 19, 0};
        ASSERT_EQ(_vec_ascend, _vec_ascend_post);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
