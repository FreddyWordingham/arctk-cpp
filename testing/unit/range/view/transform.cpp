//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/transform.inl"
#include "arctk/range/view/reverse.inl"
#include "arctk/range/view/skip.inl"

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
    //  -- Transform --
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
    //  -- Transform --
    TEST_F(array_int, filter) // NOLINT
    {
        auto trans = [](const int& i_) { return (((i_ % 2) == 0) ? -1 : (i_ * 3)); };

        const std::vector<int> expect{-1, 3, -1, 9, -1, 15, -1, 21};

        arc::range::view::Transform view(&_arr_ascend, trans);

        std::vector<int>::size_type index{0};
        for (const auto v : view)
        {
            ASSERT_EQ(v, expect[index]);
            ++index;
        }
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
