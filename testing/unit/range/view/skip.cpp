//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/skip.inl"
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
    //  -- Filter --
    TEST_F(array_int, Skip_first) // NOLINT
    {
        using namespace arc;

        const auto rev = _arr_non_prime //
                         | arc::range::preview::Skip{4};

        ASSERT_TRUE(rev == (std::vector<int>{8, 9, 10, 12}));
    }

    TEST_F(array_int, Skip_first_and_last) // NOLINT
    {
        using namespace arc;

        const auto rev = _arr_non_prime //
                         | arc::range::preview::Skip{3, 2};

        ASSERT_TRUE(rev == (std::vector<int>{6, 8, 9}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
