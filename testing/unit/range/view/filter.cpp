//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/filter.inl"
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
    TEST_F(array_int, Filter) // NOLINT
    {
        using namespace arc;

        auto is_even  = [](const int& i_) { return ((i_ % 2) == 0); };
        auto is_gt_5  = [](const int& i_) { return (i_ > 5); };
        auto is_lt_10 = [](const int& i_) { return (i_ < 10); };

        const auto filt = _arr_non_prime                         //
                          | arc::range::preview::Filter{is_even} //
                          | arc::range::preview::Filter{is_gt_5} //
                          | arc::range::preview::Filter{is_lt_10};

        ASSERT_TRUE(filt == (std::vector<int>{6, 8}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
