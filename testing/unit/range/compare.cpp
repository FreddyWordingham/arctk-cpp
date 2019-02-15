//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/compare.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <vector>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wpadded"



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == TESTS ==
        //  -- Array Int Comparison --
        class array_int_test : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const std::array<int, 4>                _arr_0{1, 2, 3, 4};
            const std::array<int, 4>                _arr_1{1, 1, 1, 1};
            const std::array<int, 4>                _arr_2{9, 5, 2, 7};
            const std::array<int, 4>                _arr_3{-2, 3, 8, -4};
            const std::array<int, 4>                _arr_4{-3, -3, -2, -1};
            const std::array<int, 0>                _arr_5{};
            const std::array<int, 2>                _arr_6{-2, 2};
            const std::array<std::array<int, 3>, 4> _arr_a{{{-3, -4, -2}, {3, 2, -3}, {2, 1, 3}, {-2, -3, 0}}};
            const std::array<std::array<int, 0>, 4> _arr_b{{{}, {}, {}, {}}};
        };

        TEST_F(array_int_test, equal)
        {
            ASSERT_FALSE(_arr_0 == 1);
            ASSERT_TRUE(_arr_1 == 1);
            ASSERT_FALSE(_arr_2 == 1);
            ASSERT_FALSE(_arr_3 == 1);
            ASSERT_FALSE(_arr_4 == 1);
            ASSERT_TRUE(_arr_5 == 1);
            ASSERT_FALSE(_arr_6 == 1);
            ASSERT_FALSE(_arr_a == 1);
            ASSERT_TRUE(_arr_b == 1);
        }

        TEST_F(array_int_test, not_equal)
        {
            ASSERT_FALSE(_arr_0 != 1);
            ASSERT_FALSE(_arr_1 != 1);
            ASSERT_TRUE(_arr_2 != 1);
            ASSERT_TRUE(_arr_3 != 1);
            ASSERT_TRUE(_arr_4 != 1);
            ASSERT_TRUE(_arr_5 != 1);
            ASSERT_TRUE(_arr_6 != 1);
            ASSERT_FALSE(_arr_a != 1);
            ASSERT_TRUE(_arr_b != 1);
        }

        TEST_F(array_int_test, less_than)
        {
            ASSERT_FALSE(_arr_0 < 4);
            ASSERT_TRUE(_arr_1 < 4);
            ASSERT_FALSE(_arr_2 < 4);
            ASSERT_FALSE(_arr_3 < 4);
            ASSERT_TRUE(_arr_4 < 4);
            ASSERT_TRUE(_arr_5 < 4);
            ASSERT_TRUE(_arr_6 < 4);
            ASSERT_TRUE(_arr_a < 4);
            ASSERT_TRUE(_arr_b < 4);
        }

        TEST_F(array_int_test, more_than)
        {
            ASSERT_FALSE(_arr_0 > 4);
            ASSERT_FALSE(_arr_1 > 4);
            ASSERT_FALSE(_arr_2 > 4);
            ASSERT_FALSE(_arr_3 > 4);
            ASSERT_FALSE(_arr_4 > 4);
            ASSERT_TRUE(_arr_5 > 4);
            ASSERT_FALSE(_arr_6 > 4);
            ASSERT_FALSE(_arr_a > 4);
            ASSERT_TRUE(_arr_b > 4);
        }

        TEST_F(array_int_test, less_than_or_equal_to)
        {
            ASSERT_TRUE(_arr_0 <= 4);
            ASSERT_TRUE(_arr_1 <= 4);
            ASSERT_FALSE(_arr_2 <= 4);
            ASSERT_FALSE(_arr_3 <= 4);
            ASSERT_TRUE(_arr_4 <= 4);
            ASSERT_TRUE(_arr_5 <= 4);
            ASSERT_TRUE(_arr_6 <= 4);
            ASSERT_TRUE(_arr_a <= 4);
            ASSERT_TRUE(_arr_b <= 4);
        }

        TEST_F(array_int_test, more_than_or_equal_to)
        {
            ASSERT_FALSE(_arr_0 >= 4);
            ASSERT_FALSE(_arr_1 >= 4);
            ASSERT_FALSE(_arr_2 >= 4);
            ASSERT_FALSE(_arr_3 >= 4);
            ASSERT_FALSE(_arr_4 >= 4);
            ASSERT_TRUE(_arr_5 >= 4);
            ASSERT_FALSE(_arr_6 >= 4);
            ASSERT_FALSE(_arr_a >= 4);
            ASSERT_TRUE(_arr_b >= 4);
        }


        //  -- Array Double Comparison --
        class array_double_test : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const std::array<double, 4>                _arr_0{1.0, 2.0, 3.0, 4.0};
            const std::array<double, 4>                _arr_1{1.0, 1.0, 1.0, 1.0};
            const std::array<double, 4>                _arr_2{9.0, 5.0, 2.0, 7.0};
            const std::array<double, 4>                _arr_3{-2.0, 3.0, 8.0, -4.0};
            const std::array<double, 4>                _arr_4{-3.0, -3.0, -2.0, -1.0};
            const std::array<double, 0>                _arr_5{};
            const std::array<double, 2>                _arr_6{-2.0, 2.0};
            const std::array<std::array<double, 3>, 4> _arr_a{{{-3.0, -4.0, -2.0}, {3.0, 2.0, -3.0}, {2.0, 1.0, 3.0}, {-2.0, -3.0, 0.0}}};
            const std::array<std::array<double, 0>, 4> _arr_b{{{}, {}, {}, {}}};
        };

        TEST_F(array_double_test, less_than)
        {
            ASSERT_FALSE(_arr_0 < 4.0);
            ASSERT_TRUE(_arr_1 < 4.0);
            ASSERT_FALSE(_arr_2 < 4.0);
            ASSERT_FALSE(_arr_3 < 4.0);
            ASSERT_TRUE(_arr_4 < 4.0);
            ASSERT_TRUE(_arr_5 < 4.0);
            ASSERT_TRUE(_arr_6 < 4.0);
            ASSERT_TRUE(_arr_a < 4.0);
            ASSERT_TRUE(_arr_b < 4.0);
        }

        TEST_F(array_double_test, more_than)
        {
            ASSERT_FALSE(_arr_0 > 4.0);
            ASSERT_FALSE(_arr_1 > 4.0);
            ASSERT_FALSE(_arr_2 > 4.0);
            ASSERT_FALSE(_arr_3 > 4.0);
            ASSERT_FALSE(_arr_4 > 4.0);
            ASSERT_TRUE(_arr_5 > 4.0);
            ASSERT_FALSE(_arr_6 > 4.0);
            ASSERT_FALSE(_arr_a > 4.0);
            ASSERT_TRUE(_arr_b > 4.0);
        }

        TEST_F(array_double_test, less_than_or_equal_to)
        {
            ASSERT_TRUE(_arr_0 <= 4.0);
            ASSERT_TRUE(_arr_1 <= 4.0);
            ASSERT_FALSE(_arr_2 <= 4.0);
            ASSERT_FALSE(_arr_3 <= 4.0);
            ASSERT_TRUE(_arr_4 <= 4.0);
            ASSERT_TRUE(_arr_5 <= 4.0);
            ASSERT_TRUE(_arr_6 <= 4.0);
            ASSERT_TRUE(_arr_a <= 4.0);
            ASSERT_TRUE(_arr_b <= 4.0);
        }

        TEST_F(array_double_test, more_than_or_equal_to)
        {
            ASSERT_FALSE(_arr_0 >= 4.0);
            ASSERT_FALSE(_arr_1 >= 4.0);
            ASSERT_FALSE(_arr_2 >= 4.0);
            ASSERT_FALSE(_arr_3 >= 4.0);
            ASSERT_FALSE(_arr_4 >= 4.0);
            ASSERT_TRUE(_arr_5 >= 4.0);
            ASSERT_FALSE(_arr_6 >= 4.0);
            ASSERT_FALSE(_arr_a >= 4.0);
            ASSERT_TRUE(_arr_b >= 4.0);
        }


        //  -- Vector Int Comparison --
        class vector_int_test : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const std::vector<int>              _vec_0{1, 2, 3, 4};
            const std::vector<int>              _vec_1{1, 1, 1, 1};
            const std::vector<int>              _vec_2{9, 5, 2, 7};
            const std::vector<int>              _vec_3{-2, 3, 8, -4};
            const std::vector<int>              _vec_4{-3, -3, -2, -1};
            const std::vector<int>              _vec_5{};
            const std::vector<int>              _vec_6{-2, 2};
            const std::vector<std::vector<int>> _vec_a{{{-3, -4, -2}, {3, 2, -3}, {2, 1, 3}, {-2, -3, 0}}};
            const std::vector<std::vector<int>> _vec_b{4, std::vector<int>{}};
        };

        TEST_F(vector_int_test, equal)
        {
            std::cout << '\n';
            for (std::size_t i = 0; i < _vec_b.size(); ++i)
            {
                for (std::size_t j = 0; j < _vec_b[i].size(); ++j)
                {
                    std::cout << i << '\t' << j << '\t' << _vec_b[i][j] << '\n';
                }
            }

            ASSERT_FALSE(_vec_0 == 1);
            ASSERT_TRUE(_vec_1 == 1);
            ASSERT_FALSE(_vec_2 == 1);
            ASSERT_FALSE(_vec_3 == 1);
            ASSERT_FALSE(_vec_4 == 1);
            ASSERT_TRUE(_vec_5 == 1);
            ASSERT_FALSE(_vec_6 == 1);
            ASSERT_FALSE(_vec_a == 1);
            ASSERT_TRUE(_vec_b == 1);
        }

        TEST_F(vector_int_test, not_equal)
        {
            ASSERT_FALSE(_vec_0 != 1);
            ASSERT_FALSE(_vec_1 != 1);
            ASSERT_TRUE(_vec_2 != 1);
            ASSERT_TRUE(_vec_3 != 1);
            ASSERT_TRUE(_vec_4 != 1);
            ASSERT_TRUE(_vec_5 != 1);
            ASSERT_TRUE(_vec_6 != 1);
            ASSERT_FALSE(_vec_a != 1);
            ASSERT_TRUE(_vec_b != 1);
        }

        TEST_F(vector_int_test, less_than)
        {
            ASSERT_FALSE(_vec_0 < 4);
            ASSERT_TRUE(_vec_1 < 4);
            ASSERT_FALSE(_vec_2 < 4);
            ASSERT_FALSE(_vec_3 < 4);
            ASSERT_TRUE(_vec_4 < 4);
            ASSERT_TRUE(_vec_5 < 4);
            ASSERT_TRUE(_vec_6 < 4);
            ASSERT_TRUE(_vec_a < 4);
            ASSERT_TRUE(_vec_b < 4);
        }

        TEST_F(vector_int_test, more_than)
        {
            ASSERT_FALSE(_vec_0 > 4);
            ASSERT_FALSE(_vec_1 > 4);
            ASSERT_FALSE(_vec_2 > 4);
            ASSERT_FALSE(_vec_3 > 4);
            ASSERT_FALSE(_vec_4 > 4);
            ASSERT_TRUE(_vec_5 > 4);
            ASSERT_FALSE(_vec_6 > 4);
            ASSERT_FALSE(_vec_a > 4);
            ASSERT_TRUE(_vec_b > 4);
        }

        TEST_F(vector_int_test, less_than_or_equal_to)
        {
            ASSERT_TRUE(_vec_0 <= 4);
            ASSERT_TRUE(_vec_1 <= 4);
            ASSERT_FALSE(_vec_2 <= 4);
            ASSERT_FALSE(_vec_3 <= 4);
            ASSERT_TRUE(_vec_4 <= 4);
            ASSERT_TRUE(_vec_5 <= 4);
            ASSERT_TRUE(_vec_6 <= 4);
            ASSERT_TRUE(_vec_a <= 4);
            ASSERT_TRUE(_vec_b <= 4);
        }

        TEST_F(vector_int_test, more_than_or_equal_to)
        {
            ASSERT_FALSE(_vec_0 >= 4);
            ASSERT_FALSE(_vec_1 >= 4);
            ASSERT_FALSE(_vec_2 >= 4);
            ASSERT_FALSE(_vec_3 >= 4);
            ASSERT_FALSE(_vec_4 >= 4);
            ASSERT_TRUE(_vec_5 >= 4);
            ASSERT_FALSE(_vec_6 >= 4);
            ASSERT_FALSE(_vec_a >= 4);
            ASSERT_TRUE(_vec_b >= 4);
        }



    } // namespace range
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
