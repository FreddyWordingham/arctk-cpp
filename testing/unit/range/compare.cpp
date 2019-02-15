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



//  == NAMESPACE ==
namespace arc
{
    inline namespace range
    {



        //  == FIXTURES ==
        //  -- Array --
        class array_test : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const std::array<int, 4> _arr_0;
            const std::array<int, 4> _arr_1;
            const std::array<int, 4> _arr_2;
            const std::array<int, 4> _arr_3;
            const std::array<int, 4> _arr_4;



            //  == INSTANTIATION ==
          protected:
            //  -- Constructors --
            inline explicit array_test() noexcept
              : _arr_0{1, 2, 3, 4}
              , _arr_1{1, 1, 1, 1}
              , _arr_2{9, 5, 2, 7}
              , _arr_3{-2, 3, 8, -4}
              , _arr_4{-3, -3, -2, -1}
            {
            }
        };


        //  -- Vector --
        class vector_test : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const std::vector<int> _vec_0;
            const std::vector<int> _vec_1;
            const std::vector<int> _vec_2;
            const std::vector<int> _vec_3;
            const std::vector<int> _vec_4;
            const std::vector<int> _vec_5;
            const std::vector<int> _vec_6;



            //  == INSTANTIATION ==
          protected:
            //  -- Constructors --
            inline explicit vector_test() noexcept
              : _vec_0{1, 2, 3, 4}
              , _vec_1{1, 1, 1, 1}
              , _vec_2{9, 5, 2, 7}
              , _vec_3{-2, 3, 8, -4}
              , _vec_4{-3, -3, -2, -1}
              , _vec_5{}
              , _vec_6{-2, 2}
            {
            }
        };



        //  == TESTS ==
        TEST_F(array_test, equal)
        {
            ASSERT_FALSE(_arr_0 == 1);
            ASSERT_TRUE(_arr_1 == 1);
            ASSERT_FALSE(_arr_2 == 1);
            ASSERT_FALSE(_arr_3 == 1);
            ASSERT_FALSE(_arr_4 == 1);
        }

        TEST_F(vector_test, equal)
        {
            ASSERT_FALSE(_vec_0 == 1);
            ASSERT_FALSE(_vec_1 == 0);
            ASSERT_TRUE(_vec_1 == 1);
            ASSERT_FALSE(_vec_2 == 1);
            ASSERT_FALSE(_vec_3 == 1);
            ASSERT_FALSE(_vec_4 == 1);
            ASSERT_TRUE(_vec_5 == 0);
            ASSERT_TRUE(_vec_5 == 1);
            ASSERT_FALSE(_vec_6 == 1);
        }

        TEST_F(array_test, not_equal)
        {
            ASSERT_TRUE(_arr_0 != 1);
            ASSERT_FALSE(_arr_1 != 1);
            ASSERT_TRUE(_arr_2 != 1);
            ASSERT_TRUE(_arr_3 != 1);
            ASSERT_TRUE(_arr_4 != 1);
        }

        TEST_F(vector_test, not_equal)
        {
            ASSERT_TRUE(_vec_0 != 1);
            ASSERT_TRUE(_vec_1 != 0);
            ASSERT_FALSE(_vec_1 != 1);
            ASSERT_TRUE(_vec_2 != 1);
            ASSERT_TRUE(_vec_3 != 1);
            ASSERT_TRUE(_vec_4 != 1);
            ASSERT_FALSE(_vec_5 != 0);
            ASSERT_FALSE(_vec_5 != 1);
            ASSERT_TRUE(_vec_6 != 1);
        }

        TEST_F(array_test, less_than)
        {
            ASSERT_FALSE(_arr_0 < 3);
            ASSERT_TRUE(_arr_1 < 3);
            ASSERT_FALSE(_arr_2 < 3);
            ASSERT_FALSE(_arr_3 < 3);
            ASSERT_TRUE(_arr_4 < 3);
        }

        TEST_F(vector_test, less_than)
        {
            ASSERT_FALSE(_vec_0 < 3);
            ASSERT_TRUE(_vec_1 < 3);
            ASSERT_FALSE(_vec_2 < 3);
            ASSERT_FALSE(_vec_3 < 3);
            ASSERT_TRUE(_vec_4 < 3);
            ASSERT_TRUE(_vec_5 < 0);
            ASSERT_FALSE(_vec_6 < 1);
        }

        TEST_F(array_test, more_than)
        {
            ASSERT_FALSE(_arr_0 > 3);
            ASSERT_FALSE(_arr_1 > 3);
            ASSERT_FALSE(_arr_2 > 3);
            ASSERT_FALSE(_arr_3 > 3);
            ASSERT_FALSE(_arr_4 > 3);
        }

        TEST_F(vector_test, more_than)
        {
            ASSERT_FALSE(_vec_0 > 3);
            ASSERT_FALSE(_vec_1 > 3);
            ASSERT_FALSE(_vec_2 > 3);
            ASSERT_FALSE(_vec_3 > 3);
            ASSERT_FALSE(_vec_4 > 3);
            ASSERT_TRUE(_vec_5 > 0);
            ASSERT_FALSE(_vec_6 > 1);
        }

        TEST_F(array_test, less_than_or_equal_to)
        {
            ASSERT_FALSE(_arr_0 <= 3);
            ASSERT_TRUE(_arr_1 <= 3);
            ASSERT_FALSE(_arr_2 <= 3);
            ASSERT_FALSE(_arr_3 <= 3);
            ASSERT_TRUE(_arr_4 <= 3);
        }

        TEST_F(vector_test, less_than_or_equal_to)
        {
            ASSERT_FALSE(_vec_0 <= 3);
            ASSERT_TRUE(_vec_1 <= 3);
            ASSERT_FALSE(_vec_2 <= 3);
            ASSERT_FALSE(_vec_3 <= 3);
            ASSERT_TRUE(_vec_4 <= 3);
            ASSERT_TRUE(_vec_5 <= 0);
            ASSERT_FALSE(_vec_6 <= 1);
        }

        TEST_F(array_test, more_than_or_equal_to)
        {
            ASSERT_FALSE(_arr_0 >= 3);
            ASSERT_FALSE(_arr_1 >= 3);
            ASSERT_FALSE(_arr_2 >= 3);
            ASSERT_FALSE(_arr_3 >= 3);
            ASSERT_FALSE(_arr_4 >= 3);
        }

        TEST_F(vector_test, more_than_or_equal_to)
        {
            ASSERT_FALSE(_vec_0 >= 3);
            ASSERT_FALSE(_vec_1 >= 3);
            ASSERT_FALSE(_vec_2 >= 3);
            ASSERT_FALSE(_vec_3 >= 3);
            ASSERT_FALSE(_vec_4 >= 3);
            ASSERT_TRUE(_vec_5 >= 0);
            ASSERT_FALSE(_vec_6 >= 1);
        }



    } // namespace range
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
