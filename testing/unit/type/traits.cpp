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
    TEST(is_rangeable, primitive) // NOLINT
    {
        ASSERT_FALSE(arc::type::is_rangeable_v<void>);
        ASSERT_FALSE(arc::type::is_rangeable_v<int>);
        ASSERT_FALSE(arc::type::is_rangeable_v<double>);
        ASSERT_FALSE(arc::type::is_rangeable_v<std::size_t>);
    }

    TEST(is_rangeable, array) // NOLINT
    {
        ASSERT_TRUE((arc::type::is_rangeable_v<std::array<int, 1>>));
        ASSERT_TRUE((arc::type::is_rangeable_v<std::array<double, 2>>));
        ASSERT_TRUE((arc::type::is_rangeable_v<std::array<std::size_t, 0>>));
        const bool array_vector_int{arc::type::is_rangeable_v<std::array<std::vector<int>, 2>>};
        ASSERT_TRUE(array_vector_int);
    }

    TEST(is_rangeable, vector) // NOLINT
    {
        ASSERT_TRUE(arc::type::is_rangeable_v<std::vector<int>>);
        ASSERT_TRUE(arc::type::is_rangeable_v<std::vector<double>>);
        ASSERT_TRUE(arc::type::is_rangeable_v<std::vector<std::size_t>>);
        ASSERT_TRUE(arc::type::is_rangeable_v<std::vector<std::vector<int>>>);
    }

    TEST(is_rangeable, stack) // NOLINT
    {
        ASSERT_FALSE(arc::type::is_rangeable_v<std::stack<int>>);
        ASSERT_FALSE(arc::type::is_rangeable_v<std::stack<double>>);
        ASSERT_FALSE(arc::type::is_rangeable_v<std::stack<std::size_t>>);
        ASSERT_FALSE(arc::type::is_rangeable_v<std::stack<std::stack<int>>>);
    }

    TEST(is_rangeable, string) // NOLINT
    {
        ASSERT_TRUE(arc::type::is_rangeable_v<std::string>);
    }

    TEST(is_rangeable, map) // NOLINT
    {
        const bool map_string_int{arc::type::is_rangeable_v<std::map<std::vector<int>, bool>>};
        ASSERT_TRUE(map_string_int);
        const bool map_int_int{arc::type::is_rangeable_v<std::map<std::string, int>>};
        ASSERT_TRUE(map_int_int);
        const bool map_void_double{arc::type::is_rangeable_v<std::map<int, char>>};
        ASSERT_TRUE(map_void_double);
        const bool map_double_void{arc::type::is_rangeable_v<std::map<std::array<int, 2>, std::size_t>>};
        ASSERT_TRUE(map_double_void);
    }

    TEST(is_printable, true) // NOLINT
    {
        const bool printable_bool_value{arc::type::is_printable_v<bool>};
        ASSERT_TRUE(printable_bool_value);
        const bool printable_int_value{arc::type::is_printable_v<int>};
        ASSERT_TRUE(printable_int_value);
        const bool printable_double_value{arc::type::is_printable_v<double>};
        ASSERT_TRUE(printable_double_value);
        const bool printable_string_value{arc::type::is_printable_v<std::string>};
        ASSERT_TRUE(printable_string_value);
        const bool printable_cstring_value{arc::type::is_printable_v<char*>};
        ASSERT_TRUE(printable_cstring_value);
    }

    TEST(is_printable, false) // NOLINT
    {
        const bool printable_array_value{arc::type::is_printable_v<std::array<int, 4>>};
        ASSERT_FALSE(printable_array_value);
        const bool printable_vector_value{arc::type::is_printable_v<std::vector<double>>};
        ASSERT_FALSE(printable_vector_value);
        const bool printable_pair_value{arc::type::is_printable_v<std::pair<int, char>>};
        ASSERT_FALSE(printable_pair_value);
        const bool printable_map_value{arc::type::is_printable_v<std::map<std::string, int>>};
        ASSERT_FALSE(printable_map_value);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
