//  == IMPORTS ==
//  -- Arc --
#include "arctk/type/traits.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <cstddef>
#include <map>
#include <stack>
#include <string>
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
    TEST(is_rangeable, primitive) // NOLINT
    {
        ASSERT_FALSE(arc::type::is_rangeable<void>::value);
        ASSERT_FALSE(arc::type::is_rangeable<int>::value);
        ASSERT_FALSE(arc::type::is_rangeable<double>::value);
        ASSERT_FALSE(arc::type::is_rangeable<std::size_t>::value);
    }

    TEST(is_rangeable, array) // NOLINT
    {
        ASSERT_TRUE((arc::type::is_rangeable<std::array<int, 1>>::value));
        ASSERT_TRUE((arc::type::is_rangeable<std::array<double, 2>>::value));
        ASSERT_TRUE((arc::type::is_rangeable<std::array<std::size_t, 0>>::value));
        constexpr auto array_vector_int = arc::type::is_rangeable<std::array<std::vector<int>, 2>>::value;
        ASSERT_TRUE(array_vector_int);
    }

    TEST(is_rangeable, vector) // NOLINT
    {
        ASSERT_TRUE(arc::type::is_rangeable<std::vector<int>>::value);
        ASSERT_TRUE(arc::type::is_rangeable<std::vector<double>>::value);
        ASSERT_TRUE(arc::type::is_rangeable<std::vector<std::size_t>>::value);
        ASSERT_TRUE(arc::type::is_rangeable<std::vector<std::vector<int>>>::value);
    }

    TEST(is_rangeable, stack) // NOLINT
    {
        ASSERT_FALSE(arc::type::is_rangeable<std::stack<int>>::value);
        ASSERT_FALSE(arc::type::is_rangeable<std::stack<double>>::value);
        ASSERT_FALSE(arc::type::is_rangeable<std::stack<std::size_t>>::value);
        ASSERT_FALSE(arc::type::is_rangeable<std::stack<std::stack<int>>>::value);
    }

    TEST(is_rangeable, string) // NOLINT
    {
        ASSERT_TRUE(arc::type::is_rangeable<std::string>::value);
    }

    TEST(is_rangeable, map) // NOLINT
    {
        constexpr auto map_string_int = arc::type::is_rangeable<std::array<std::vector<int>, 2>>::value;
        ASSERT_TRUE(map_string_int);
        constexpr auto map_int_int = arc::type::is_rangeable<std::array<std::vector<int>, 2>>::value;
        ASSERT_TRUE(map_int_int);
        constexpr auto map_void_double = arc::type::is_rangeable<std::array<std::vector<int>, 2>>::value;
        ASSERT_TRUE(map_void_double);
        constexpr auto map_double_void = arc::type::is_rangeable<std::array<std::vector<int>, 2>>::value;
        ASSERT_TRUE(map_double_void);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
