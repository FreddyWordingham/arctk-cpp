//  == IMPORTS ==
//  -- Unit --
#include "arctk/fmt/string.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cstddef>



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
    //  -- Formatting --
    TEST(str, simple) // NOLINT
    {
        ASSERT_EQ(fmt::str(bool{true}), "true");
        ASSERT_EQ(fmt::str(char{'a'}), "a");
        ASSERT_EQ(fmt::str(int{-32749}), "-32749");
        ASSERT_EQ(fmt::str(std::size_t{67280421310721}), "67280421310721");
        ASSERT_EQ(fmt::str(double{-3.14159}), "-3.14159");
        ASSERT_EQ(fmt::str(std::string{"Hello Arc::Torus!\n"}), "Hello Arc::Torus!\n");
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
