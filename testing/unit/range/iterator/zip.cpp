//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/zip.inl"

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
    //  -- Filter --
    TEST_F(array_int, Zip) // NOLINT
    {
        arc::range::iterator::Zip begin{_arr_ascend.begin(), std::make_tuple(_arr_prime.begin(), _arr_non_prime.begin()), _arr_ascend.end(), std::make_tuple(_arr_prime.end(), _arr_non_prime.end())};
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
