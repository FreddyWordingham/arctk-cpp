//  == IMPORTS ==
//  -- Arc --
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



    //  == TESTS ==
    //  -- Comparison --
    TEST(equal, array_vector) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{0, 1, 2, 3, 4};
        const std::vector<int>   vec_0{0, 1, 2, 3, 4};

        ASSERT_TRUE(arr_0 == vec_0);
        ASSERT_TRUE(vec_0 == arr_0);

        const std::array<int, 5> arr_1{2, 3, 5, 7, 11};
        std::vector<int>         vec_1{2, 3, 5, 7};

        ASSERT_TRUE(!(arr_1 == vec_1));
        ASSERT_TRUE(!(vec_1 == arr_1));

        vec_1.emplace_back(11);

        ASSERT_TRUE(arr_0 == vec_0);
        ASSERT_TRUE(vec_0 == arr_0);
        ASSERT_TRUE(!(arr_0 == vec_1));
        ASSERT_TRUE(!(vec_0 == arr_1));
        ASSERT_TRUE(!(arr_1 == vec_0));
        ASSERT_TRUE(!(vec_1 == arr_0));
        ASSERT_TRUE(arr_1 == vec_1);
        ASSERT_TRUE(vec_1 == arr_1);
    }

    TEST(equal, size) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 3> arr_0{0, 1, 2};
        const std::vector<int>   vec_0{0, 1, 2, 3, 4};

        ASSERT_FALSE(arr_0 == vec_0);
    }

    TEST(not_equal, array_vector) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{0, 1, 2, 3, 4};
        const std::vector<int>   vec_0{0, 1, 2, 3, 4};

        ASSERT_TRUE(!(arr_0 != vec_0));
        ASSERT_TRUE(!(vec_0 != arr_0));

        const std::array<int, 5> arr_1{2, 3, 5, 7, 11};
        std::vector<int>         vec_1{2, 3, 5, 7};

        ASSERT_TRUE(arr_1 != vec_1);
        ASSERT_TRUE(vec_1 != arr_1);

        vec_1.emplace_back(11);

        ASSERT_TRUE(!(arr_0 != vec_0));
        ASSERT_TRUE(!(vec_0 != arr_0));
        ASSERT_TRUE(arr_0 != vec_1);
        ASSERT_TRUE(vec_0 != arr_1);
        ASSERT_TRUE(arr_1 != vec_0);
        ASSERT_TRUE(vec_1 != arr_0);
        ASSERT_TRUE(!(arr_1 != vec_1));
        ASSERT_TRUE(!(vec_1 != arr_1));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
