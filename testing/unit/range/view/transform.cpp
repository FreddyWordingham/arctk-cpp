//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/transform.inl"
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
    //  -- Transform --
    class array_int : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 8> _arr_non_prime{0, 1, 4, 6, 8, 9, 10, 12};
    };



    //  == TESTS ==
    //  -- Transform --
    TEST_F(array_int, Transform) // NOLINT
    {
        using namespace arc;

        const auto triple_int  = [](const int& i_) { return (i_ * 3); };
        const auto add_half    = [](const int& i_) { return (i_ + 0.5); };
        const auto triple_doub = [](const double& x_) { return (x_ * 3.0); };

        const auto trans = _arr_non_prime                               //
                           | arc::range::preview::Transform{triple_int} //
                           | arc::range::preview::Transform{add_half}   //
                           | arc::range::preview::Transform{triple_doub};

        ASSERT_TRUE(trans == (std::vector<double>{1.5, 10.5, 37.5, 55.5, 73.5, 82.5, 91.5, 109.5}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
