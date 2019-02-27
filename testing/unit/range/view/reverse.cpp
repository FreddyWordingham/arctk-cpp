//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/reverse.inl"

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
    //  -- Reverse --
    class array_int : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 8> _arr_ascend{0, 1, 2, 3, 4, 5, 6, 7};
    };



    //  == TESTS ==
    //  -- Reverse --
    TEST_F(array_int, filter) // NOLINT
    {
        const std::vector<int> expect{7, 6, 5, 4, 3, 2, 1, 0};

        arc::range::view::Reverse view(&_arr_ascend);

        std::vector<int>::size_type index{0};
        for (const auto& v : view)
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
