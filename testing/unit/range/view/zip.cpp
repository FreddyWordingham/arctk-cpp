//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/zip.inl"
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
        const std::array<int, 8> _arr_prime{2, 3, 5, 7, 11, 13, 17, 19};
        const std::array<int, 8> _arr_non_prime{0, 1, 4, 6, 8, 9, 10, 12};
    };



    //  == TESTS ==
    //  -- Transform --
    TEST_F(array_int, Transform) // NOLINT
    {
        using namespace arc;

        for (auto [prime_0, prime_1, non_prime] : range::view::Zip{_arr_prime, _arr_prime, _arr_non_prime})
        {
            ASSERT_EQ(prime_0, prime_1);
            ASSERT_NE(prime_0, non_prime);
            ASSERT_NE(prime_1, non_prime);
        }
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
