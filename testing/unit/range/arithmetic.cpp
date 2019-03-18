//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/arithmetic.inl"

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



    //  == TESTS ==
    //  -- Comparison --
    TEST(array_arithmetic, copy_positive) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr{0, 1, 2, 3, 4};
        const auto               res{+arr};

        const std::array<int, 5> ans{0, 1, 2, 3, 4};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_arithmetic, copy_positive) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int> vec{0, 1, 2, 3, 4};
        const auto             res{+vec};

        const std::vector<int> ans{0, 1, 2, 3, 4};
        ASSERT_TRUE(res == ans);
    }

    // TEST(map_arithmetic, copy_positive) // NOLINT
    // { TODO test with pair arithmetic
    //     using namespace arc; // NOLINT

    //     const std::map<int, double> map{{0, 0.0}, {1, 1.0}, {2, 2.0}, {3, 3.0}, {4, 4.0}};
    //     const auto                  res{+map};

    //     const std::map<int, double> ans{{0, 0.0}, {1, 1.0}, {2, 2.0}, {3, 3.0}, {4, 4.0}};
    //     ASSERT_TRUE(res == ans);
    // }

    TEST(array_arithmetic, copy_negative) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr{0, 1, 2, 3, 4};
        const auto               res{-arr};

        const std::array<int, 5> ans{0, -1, -2, -3, -4};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_arithmetic, copy_negative) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int> vec{0, 1, 2, 3, 4};
        const auto             res{-vec};

        const std::vector<int> ans{0, -1, -2, -3, -4};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_array_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>  vec_0{0, 1, 2, 3, 4};
        const std::vector<char> vec_1{1, 1, 2, 3, 5};
        const auto              res{vec_0 + vec_1};

        const std::vector<int> ans{1, 2, 4, 6, 9};
        ASSERT_TRUE(res == ans);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
