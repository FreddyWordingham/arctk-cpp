//  == IMPORTS ==
//  -- Arc --
#include "arctk/type/is_iterable.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <type_traits>
#include <vector>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"



//  == NAMESPACE ==
namespace arc
{
    namespace type
    {



        //  == TESTS ==
        //  -- Iterable --
        TEST(is_iterable, int) // NOLINT
        {
            ASSERT_FALSE(is_iterable<int>::value);
        }

        TEST(is_iterable, bool) // NOLINT
        {
            ASSERT_FALSE(is_iterable<bool>::value);
        }

        TEST(is_iterable, char) // NOLINT
        {
            ASSERT_FALSE(is_iterable<char>::value);
        }

        TEST(is_iterable, vector) // NOLINT
        {
            ASSERT_TRUE(is_iterable<std::vector<double>>::value);
        }

        TEST(is_iterable, array) // NOLINT
        {
            ASSERT_TRUE((is_iterable<std::array<double, 4>>::value));
        }



    } // namespace type
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
