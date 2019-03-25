//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/progress.inl"

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
    //  -- Progress --
    TEST_F(array_int, progress) // NOLINT
    {
        arc::range::iterator::Progress begin_0{_arr_non_prime.begin(), _arr_non_prime.end(), std::cout, 20, 8};
        arc::range::iterator::Progress end_0{_arr_non_prime.end(), _arr_non_prime.end(), std::cout, 20, 8};

        std::array<int, 8>                     arr{_arr_non_prime};
        typename std::array<int, 8>::size_type index{0};
        for (; begin_0 != end_0; ++begin_0, ++index)
        {
            ASSERT_EQ(*begin_0, arr[index]); // NOLINT
        }
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
