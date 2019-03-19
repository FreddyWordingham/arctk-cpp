//  == IMPORTS ==
//  -- Arc --
#include "arctk/type/traits.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <list>
#include <tuple>
#include <utility>
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



    //  == TESTS ==
    //  -- Ranges --
    TEST(is_rangeable, false) // NOLINT
    {
        ASSERT_FALSE(arc::type::is_rangeable_v<int>);
        ASSERT_FALSE(arc::type::is_rangeable_v<double>);
        ASSERT_FALSE(arc::type::is_rangeable_v<char>);

        const auto ans_0{arc::type::is_rangeable_v<std::pair<char, int>>};
        ASSERT_FALSE(ans_0);

        const auto ans_1{arc::type::is_rangeable_v<std::tuple<bool, char, int>>};
        ASSERT_FALSE(ans_1);
    }

    TEST(is_rangeable, true) // NOLINT
    {
        ASSERT_TRUE(arc::type::is_rangeable_v<std::vector<int>>);
        ASSERT_TRUE(arc::type::is_rangeable_v<std::list<double>>);

        const auto ans{arc::type::is_rangeable_v<std::array<char, 5>>};
        ASSERT_TRUE(ans);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
