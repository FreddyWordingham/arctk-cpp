//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/progress.inl"
#include "arctk/range/comparison.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <iostream>
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
        const std::array<int, 8> _arr_non_prime{0, 1, 4, 6, 8, 9, 10, 12};
    };



    //  == TESTS ==
    //  -- Progress --
    TEST_F(array_int, Progress) // NOLINT
    {
        using namespace arc;              // NOLINT
        const auto range = _arr_non_prime //
                           | arc::range::preview::Progress{std::cout};

        ASSERT_TRUE(range == (std::vector<int>{0, 1, 4, 6, 8, 9, 10, 12}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
