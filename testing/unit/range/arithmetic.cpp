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
    //  -- Assignment --
    TEST(array_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        std::array<int, 5> arr{0, 1, 2, 3, 4};
        arr += 7;

        const std::array<int, 5> ans{7, 8, 9, 10, 11};
        ASSERT_TRUE(arr == ans);
    }

    TEST(vector_arithmetic, val_addition) // NOLINT
    {
        using namespace arc; // NOLINT

        std::vector<int> vec{0, 1, 2, 3, 4};
        vec += 7;

        const std::vector<int> ans{7, 8, 9, 10, 11};
        ASSERT_TRUE(vec == ans);
    }

    TEST(vector_arithmetic, vector_addition) // NOLINT
    {
        using namespace arc; // NOLINT

        std::vector<int> vec{0, 1, 2, 3, 4};
        vec += vec;

        const std::vector<int> ans{0, 2, 4, 6, 8};
        ASSERT_TRUE(vec == ans);
    }

    TEST(array_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        std::array<int, 5> arr{0, 1, 2, 3, 4};
        arr -= 7;

        const std::array<int, 5> ans{-7, -6, -5, -4, -3};
        ASSERT_TRUE(arr == ans);
    }

    TEST(vector_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        std::vector<int> vec{0, 1, 2, 3, 4};
        vec -= 7;

        const std::vector<int> ans{-7, -6, -5, -4, -3};
        ASSERT_TRUE(vec == ans);
    }

    TEST(array_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        std::array<int, 5> arr{0, 1, 2, 3, 4};
        arr *= 7;

        const std::array<int, 5> ans{0, 7, 14, 21, 28};
        ASSERT_TRUE(arr == ans);
    }

    TEST(vector_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        std::vector<int> vec{0, 1, 2, 3, 4};
        vec *= 7;

        const std::vector<int> ans{0, 7, 14, 21, 28};
        ASSERT_TRUE(vec == ans);
    }

    TEST(array_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        std::array<int, 5> arr{0, 1, 2, 3, 4};
        arr /= 3;

        const std::array<int, 5> ans{0, 0, 0, 1, 1};
        ASSERT_TRUE(arr == ans);
    }

    TEST(vector_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        std::vector<int> vec{0, 1, 2, 3, 4};
        vec /= 3;

        const std::vector<int> ans{0, 0, 0, 1, 1};
        ASSERT_TRUE(vec == ans);
    }

    TEST(array_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        std::array<int, 5> arr{0, 1, 2, 3, 4};
        arr %= 3;

        const std::array<int, 5> ans{0, 1, 2, 0, 1};
        ASSERT_TRUE(arr == ans);
    }

    TEST(vector_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        std::vector<int> vec{0, 1, 2, 3, 4};
        vec %= 3;

        const std::vector<int> ans{0, 1, 2, 0, 1};
        ASSERT_TRUE(vec == ans);
    }


    //  -- Arithmetic --
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

    TEST(vector_primitive_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int> vec_0{8, 8, 5, 2, 6};
        const auto             res{vec_0 + 7};

        const std::vector<int> ans{15, 15, 12, 9, 13};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_primitive_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 + 7};

        const std::vector<int> ans{15, 15, 12, 9, 13};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_vector_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>  vec_0{8, 8, 5, 2, 6};
        const std::vector<char> vec_1{8, 8, 5, 2, 6};
        const auto              res{vec_0 + vec_1};

        const std::vector<int> ans{16, 16, 10, 4, 12};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_array_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5>  arr_0{1, 1, 2, 3, 5};
        const std::array<char, 5> arr_1{1, 1, 2, 3, 5};
        const auto                res{arr_0 + arr_1};

        const std::vector<int> ans{2, 2, 4, 6, 10};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_vector_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const std::vector<int>   vec_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 + vec_0};

        const std::vector<int> ans{9, 9, 7, 5, 11};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_array_arithmetic, addition) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>   vec_0{8, 8, 5, 2, 6};
        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const auto               res{vec_0 + arr_0};

        const std::vector<int> ans{9, 9, 7, 5, 11};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_primitive_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int> vec_0{8, 8, 5, 2, 6};
        const auto             res{vec_0 - 7};

        const std::vector<int> ans{1, 1, -2, -5, -1};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_primitive_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 - 7};

        const std::vector<int> ans{1, 1, -2, -5, -1};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_vector_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>  vec_0{8, 8, 5, 2, 6};
        const std::vector<char> vec_1{8, 8, 5, 2, 6};
        const auto              res{vec_0 - vec_1};

        const std::vector<int> ans{0, 0, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_array_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5>  arr_0{1, 1, 2, 3, 5};
        const std::array<char, 5> arr_1{1, 1, 2, 3, 5};
        const auto                res{arr_0 - arr_1};

        const std::vector<int> ans{0, 0, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_vector_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const std::vector<int>   vec_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 - vec_0};

        const std::vector<int> ans{-7, -7, -3, 1, -1};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_array_arithmetic, subtraction) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>   vec_0{8, 8, 5, 2, 6};
        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const auto               res{vec_0 - arr_0};

        const std::vector<int> ans{7, 7, 3, -1, 1};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_primitive_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int> vec_0{8, 8, 5, 2, 6};
        const auto             res{vec_0 * 7};

        const std::vector<int> ans{56, 56, 35, 14, 42};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_primitive_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 * 7};

        const std::vector<int> ans{56, 56, 35, 14, 42};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_vector_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>  vec_0{8, 8, 5, 2, 6};
        const std::vector<char> vec_1{8, 8, 5, 2, 6};
        const auto              res{vec_0 * vec_1};

        const std::vector<int> ans{64, 64, 25, 4, 36};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_array_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5>  arr_0{1, 1, 2, 3, 5};
        const std::array<char, 5> arr_1{1, 1, 2, 3, 5};
        const auto                res{arr_0 * arr_1};

        const std::vector<int> ans{1, 1, 4, 9, 25};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_vector_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const std::vector<int>   vec_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 * vec_0};

        const std::vector<int> ans{8, 8, 10, 6, 30};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_array_arithmetic, multiplication) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>   vec_0{8, 8, 5, 2, 6};
        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const auto               res{vec_0 * arr_0};

        const std::vector<int> ans{8, 8, 10, 6, 30};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_primitive_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int> vec_0{8, 8, 5, 2, 6};
        const auto             res{vec_0 / 7};

        const std::vector<int> ans{1, 1, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_primitive_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 / 7};

        const std::vector<int> ans{1, 1, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_vector_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>  vec_0{8, 8, 5, 2, 6};
        const std::vector<char> vec_1{8, 8, 5, 2, 6};
        const auto              res{vec_0 / vec_1};

        const std::vector<int> ans{1, 1, 1, 1, 1};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_array_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5>  arr_0{1, 1, 2, 3, 5};
        const std::array<char, 5> arr_1{1, 1, 2, 3, 5};
        const auto                res{arr_0 / arr_1};

        const std::vector<int> ans{1, 1, 1, 1, 1};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_vector_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{8, 8, 6, 3, 20};
        const std::vector<int>   vec_0{1, 1, 2, 3, 5};
        const auto               res{arr_0 / vec_0};

        const std::vector<int> ans{8, 8, 3, 1, 4};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_array_arithmetic, division) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>   vec_0{8, 8, 6, 3, 20};
        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const auto               res{vec_0 / arr_0};

        const std::vector<int> ans{8, 8, 3, 1, 4};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_primitive_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int> vec_0{8, 8, 5, 2, 6};
        const auto             res{vec_0 % 7};

        const std::vector<int> ans{1, 1, 5, 2, 6};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_primitive_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{8, 8, 5, 2, 6};
        const auto               res{arr_0 % 7};

        const std::vector<int> ans{1, 1, 5, 2, 6};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_vector_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>  vec_0{8, 8, 5, 2, 6};
        const std::vector<char> vec_1{8, 8, 5, 2, 6};
        const auto              res{vec_0 % vec_1};

        const std::vector<int> ans{0, 0, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_array_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5>  arr_0{1, 1, 2, 3, 5};
        const std::array<char, 5> arr_1{1, 1, 2, 3, 5};
        const auto                res{arr_0 % arr_1};

        const std::vector<int> ans{0, 0, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }

    TEST(array_vector_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::array<int, 5> arr_0{8, 8, 6, 3, 20};
        const std::vector<int>   vec_0{1, 1, 2, 3, 5};
        const auto               res{arr_0 % vec_0};

        const std::vector<int> ans{0, 0, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }

    TEST(vector_array_arithmetic, modulo) // NOLINT
    {
        using namespace arc; // NOLINT

        const std::vector<int>   vec_0{8, 8, 6, 3, 20};
        const std::array<int, 5> arr_0{1, 1, 2, 3, 5};
        const auto               res{vec_0 % arr_0};

        const std::vector<int> ans{0, 0, 0, 0, 0};
        ASSERT_TRUE(res == ans);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
