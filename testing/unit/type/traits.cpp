//  == IMPORTS ==
//  -- Unit --
#include "arctk/type/traits.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <cstddef>
#include <map>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == ALIASES ==
//  -- Namespaces --
using namespace arc; // NOLINT



//  == NAMESPACE ==
namespace test
{



    //  == FREE FUNCTION TESTS ==
    //  -- Ranges --
    TEST(traits, is_rangeable) // NOLINT
    {
        ASSERT_FALSE(type::is_rangeable_v<void>);
        ASSERT_FALSE(type::is_rangeable_v<bool>);
        ASSERT_FALSE(type::is_rangeable_v<char>);
        ASSERT_FALSE(type::is_rangeable_v<int>);
        ASSERT_FALSE(type::is_rangeable_v<std::size_t>);
        ASSERT_FALSE(type::is_rangeable_v<double>);
        ASSERT_TRUE(type::is_rangeable_v<std::string>);
        ASSERT_TRUE(type::is_rangeable_v<std::vector<int>>);
        ASSERT_TRUE((type::is_rangeable_v<std::array<int, 7>>));
        ASSERT_TRUE(type::is_rangeable_v<std::vector<std::vector<int>>>);
        ASSERT_TRUE((type::is_rangeable_v<std::array<std::array<std::array<double, 3>, 4>, 8>>));
        ASSERT_FALSE(type::is_rangeable_v<std::stack<std::string>>);
        ASSERT_TRUE((type::is_rangeable_v<std::map<std::string, int>>));
        ASSERT_FALSE((type::is_rangeable_v<std::pair<std::vector<double>, std::string>>));
        ASSERT_FALSE((type::is_rangeable_v<std::tuple<std::vector<double>, std::string, std::size_t>>));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
