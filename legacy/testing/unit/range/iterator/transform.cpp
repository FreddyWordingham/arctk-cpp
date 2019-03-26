//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/transform.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>


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
    TEST_F(array_int, filter) // NOLINT
    {
        const auto                      triple = [](const int& i_) { return (3 * i_); };
        arc::range::iterator::Transform begin_0{_arr_non_prime.begin(), _arr_non_prime.end(), triple};
        arc::range::iterator::Transform end_0{_arr_non_prime.end(), _arr_non_prime.end(), triple};

        std::array<int, 8>                     arr{0, 3, 12, 18, 24, 27, 30, 36};
        typename std::array<int, 4>::size_type index{0};
        for (; begin_0 != end_0; ++begin_0)
        {
            ASSERT_EQ(*begin_0, arr[index]); // NOLINT
            ++index;
        }
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
