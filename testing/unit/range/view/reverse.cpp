//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/reverse.inl"
#include "arctk/range/comparison.inl"

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
        const std::array<int, 8> _arr_non_prime{0, 1, 4, 6, 8, 9, 10, 12};
    };



    //  == TESTS ==
    //  -- Filter --
    TEST_F(array_int, Reverse) // NOLINT
    {
        using namespace arc;

        const auto rev = _arr_non_prime //
                         | arc::range::preview::Reverse{};

        ASSERT_TRUE(rev == (std::vector<int>{12, 10, 9, 8, 6, 4, 1, 0}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
