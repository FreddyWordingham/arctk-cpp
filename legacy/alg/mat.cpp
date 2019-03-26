//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/mat.inl"
#include "arctk/range/arithmetic.inl"
#include "arctk/range/comparison.inl"
#include "arctk/si/dimension.inl"

//  -- GTest --
#include <gtest/gtest.h>



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
    //  -- Instantiation --
    TEST(mat, construction) // NOLINT
    {
        arc::alg::Mat<int, 2, 2>                mat_0{};
        const std::array<std::array<int, 2>, 2> ans_0{{{{0, 0}}, {{0, 0}}}};
        ASSERT_EQ(mat_0[0][0], ans_0[0][0]);
        ASSERT_EQ(mat_0[0][1], ans_0[0][1]);
        ASSERT_EQ(mat_0[1][0], ans_0[1][0]);
        ASSERT_EQ(mat_0[1][1], ans_0[1][1]);

        arc::alg::Mat<int, 3, 3>                mat_1{};
        const std::array<std::array<int, 3>, 3> ans_1{{{{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}};
        ASSERT_EQ(mat_1[0][0], ans_1[0][0]);
        ASSERT_EQ(mat_1[0][1], ans_1[0][1]);
        ASSERT_EQ(mat_1[0][2], ans_1[0][2]);
        ASSERT_EQ(mat_1[1][0], ans_1[1][0]);
        ASSERT_EQ(mat_1[1][1], ans_1[1][1]);
        ASSERT_EQ(mat_1[1][2], ans_1[1][2]);
        ASSERT_EQ(mat_1[2][0], ans_1[2][0]);
        ASSERT_EQ(mat_1[2][1], ans_1[2][1]);
        ASSERT_EQ(mat_1[2][2], ans_1[2][2]);

        arc::alg::Mat<int, 3, 3>                mat_2{arc::alg::Row<int, 3>{1, 2, 3}, arc::alg::Row<int, 3>{4, -5, 6}, arc::alg::Row<int, 3>{7, 8, 9}};
        const std::array<std::array<int, 3>, 3> ans_2{{{{1, 2, 3}}, {{4, -5, 6}}, {{7, 8, 9}}}};
        ASSERT_EQ(mat_2[0][0], ans_2[0][0]);
        ASSERT_EQ(mat_2[0][1], ans_2[0][1]);
        ASSERT_EQ(mat_2[0][2], ans_2[0][2]);
        ASSERT_EQ(mat_2[1][0], ans_2[1][0]);
        ASSERT_EQ(mat_2[1][1], ans_2[1][1]);
        ASSERT_EQ(mat_2[1][2], ans_2[1][2]);
        ASSERT_EQ(mat_2[2][0], ans_2[2][0]);
        ASSERT_EQ(mat_2[2][1], ans_2[2][1]);
        ASSERT_EQ(mat_2[2][2], ans_2[2][2]);

        arc::alg::Mat<char, 2, 7>                mat_3{arc::alg::Row<char, 7>{'a', 'a', 'b', 'c', 'e', 'h', 'm'}, arc::alg::Row<char, 7>{'a', 'b', 'c', 'd', 'f', 'i', 'n'}};
        const std::array<std::array<char, 7>, 2> ans_3{{{{'a', 'a', 'b', 'c', 'e', 'h', 'm'}}, {{'a', 'b', 'c', 'd', 'f', 'i', 'n'}}}};
        ASSERT_EQ(mat_3[0][0], ans_3[0][0]);
        ASSERT_EQ(mat_3[0][1], ans_3[0][1]);
        ASSERT_EQ(mat_3[0][2], ans_3[0][2]);
        ASSERT_EQ(mat_3[0][3], ans_3[0][3]);
        ASSERT_EQ(mat_3[0][4], ans_3[0][4]);
        ASSERT_EQ(mat_3[0][5], ans_3[0][5]);
        ASSERT_EQ(mat_3[0][6], ans_3[0][6]);
        ASSERT_EQ(mat_3[1][0], ans_3[1][0]);
        ASSERT_EQ(mat_3[1][1], ans_3[1][1]);
        ASSERT_EQ(mat_3[1][2], ans_3[1][2]);
        ASSERT_EQ(mat_3[1][3], ans_3[1][3]);
        ASSERT_EQ(mat_3[1][4], ans_3[1][4]);
        ASSERT_EQ(mat_3[1][5], ans_3[1][5]);
        ASSERT_EQ(mat_3[1][6], ans_3[1][6]);

        arc::alg::Mat<char, 4, 7>                mat_4{arc::alg::Col<char, 4>{'a', 'a', 'a', 'z'}, arc::alg::Col<char, 4>{'b', 'c', 'b', 'x'}, arc::alg::Col<char, 4>{'e', 'h', 'e', 's'}, arc::alg::Col<char, 4>{'m', 'a', 'm', 'z'},
                                        arc::alg::Col<char, 4>{'b', 'c', 'b', 'x'}, arc::alg::Col<char, 4>{'d', 'f', 'd', 'u'}, arc::alg::Col<char, 4>{'i', 'n', 'i', 'm'}};
        const std::array<std::array<char, 7>, 4> ans_4{{{{'a', 'b', 'e', 'm', 'b', 'd', 'i'}}, {{'a', 'c', 'h', 'a', 'c', 'f', 'n'}}, {{'a', 'b', 'e', 'm', 'b', 'd', 'i'}}, {{'z', 'x', 's', 'z', 'x', 'u', 'm'}}}};
        ASSERT_EQ(mat_4[0][0], ans_4[0][0]);
        ASSERT_EQ(mat_4[0][1], ans_4[0][1]);
        ASSERT_EQ(mat_4[0][2], ans_4[0][2]);
        ASSERT_EQ(mat_4[0][3], ans_4[0][3]);
        ASSERT_EQ(mat_4[0][4], ans_4[0][4]);
        ASSERT_EQ(mat_4[0][5], ans_4[0][5]);
        ASSERT_EQ(mat_4[0][6], ans_4[0][6]);
        ASSERT_EQ(mat_4[1][0], ans_4[1][0]);
        ASSERT_EQ(mat_4[1][1], ans_4[1][1]);
        ASSERT_EQ(mat_4[1][2], ans_4[1][2]);
        ASSERT_EQ(mat_4[1][3], ans_4[1][3]);
        ASSERT_EQ(mat_4[1][4], ans_4[1][4]);
        ASSERT_EQ(mat_4[1][5], ans_4[1][5]);
        ASSERT_EQ(mat_4[1][6], ans_4[1][6]);
        ASSERT_EQ(mat_4[2][0], ans_4[2][0]);
        ASSERT_EQ(mat_4[2][1], ans_4[2][1]);
        ASSERT_EQ(mat_4[2][2], ans_4[2][2]);
        ASSERT_EQ(mat_4[2][3], ans_4[2][3]);
        ASSERT_EQ(mat_4[2][4], ans_4[2][4]);
        ASSERT_EQ(mat_4[2][5], ans_4[2][5]);
        ASSERT_EQ(mat_4[2][6], ans_4[2][6]);
        ASSERT_EQ(mat_4[3][0], ans_4[3][0]);
        ASSERT_EQ(mat_4[3][1], ans_4[3][1]);
        ASSERT_EQ(mat_4[3][2], ans_4[3][2]);
        ASSERT_EQ(mat_4[3][3], ans_4[3][3]);
        ASSERT_EQ(mat_4[3][4], ans_4[3][4]);
        ASSERT_EQ(mat_4[3][5], ans_4[3][5]);
        ASSERT_EQ(mat_4[3][6], ans_4[3][6]);
    }

    TEST(mat, row) // NOLINT
    {
        arc::alg::Mat<int, 3, 2> mat{arc::alg::Row<int, 2>{1, 2}, arc::alg::Row<int, 2>{0, 0}, arc::alg::Row<int, 2>{-1, -2}};

        const auto row_0{mat.row(0)};
        ASSERT_EQ(*row_0[0], 1);
        ASSERT_EQ(*row_0[1], 2);

        const auto row_1{mat.row(1)};
        ASSERT_EQ(*row_1[0], 0);
        ASSERT_EQ(*row_1[1], 0);

        const auto row_2{mat.row(2)};
        ASSERT_EQ(*row_2[0], -1);
        ASSERT_EQ(*row_2[1], -2);
    }

    TEST(mat, const_row) // NOLINT
    {
        const arc::alg::Mat<int, 3, 2> mat{arc::alg::Row<int, 2>{1, 2}, arc::alg::Row<int, 2>{0, 0}, arc::alg::Row<int, 2>{-1, -2}};

        const auto row_0{mat.row(0)};
        ASSERT_EQ(*row_0[0], 1);
        ASSERT_EQ(*row_0[1], 2);

        const auto row_1{mat.row(1)};
        ASSERT_EQ(*row_1[0], 0);
        ASSERT_EQ(*row_1[1], 0);

        const auto row_2{mat.row(2)};
        ASSERT_EQ(*row_2[0], -1);
        ASSERT_EQ(*row_2[1], -2);
    }

    TEST(mat, col) // NOLINT
    {
        arc::alg::Mat<int, 3, 2> mat{arc::alg::Col<int, 3>{1, 0, -1}, arc::alg::Col<int, 3>{2, 0, -2}};

        const auto col_0{mat.col(0)};
        ASSERT_EQ(*col_0[0], 1);
        ASSERT_EQ(*col_0[1], 0);
        ASSERT_EQ(*col_0[2], -1);

        const auto col_1{mat.col(1)};
        ASSERT_EQ(*col_1[0], 2);
        ASSERT_EQ(*col_1[1], 0);
        ASSERT_EQ(*col_1[2], -2);
    }

    TEST(mat, const_col) // NOLINT
    {
        const arc::alg::Mat<int, 3, 2> mat{arc::alg::Col<int, 3>{1, 0, -1}, arc::alg::Col<int, 3>{2, 0, -2}};

        const auto col_0{mat.col(0)};
        ASSERT_EQ(*col_0[0], 1);
        ASSERT_EQ(*col_0[1], 0);
        ASSERT_EQ(*col_0[2], -1);

        const auto col_1{mat.col(1)};
        ASSERT_EQ(*col_1[0], 2);
        ASSERT_EQ(*col_1[1], 0);
        ASSERT_EQ(*col_1[2], -2);
    }


    //  -- Arithmetic --
    TEST(mat, multiplication) // NOLINT
    {
        using namespace arc;
        arc::alg::Mat<arc::si::Velocity, 3, 2> vel_mat{arc::alg::Row<arc::si::Velocity, 2>{arc::si::Velocity{1.0}, arc::si::Velocity{2.0}}, arc::alg::Row<arc::si::Velocity, 2>{arc::si::Velocity{0.0}, arc::si::Velocity{0.5}},
                                                       arc::alg::Row<arc::si::Velocity, 2>{arc::si::Velocity{-1.0}, arc::si::Velocity{-2.0}}};
        arc::alg::Mat<arc::si::Length, 3, 2>   len_mat{vel_mat * arc::si::Time{2.0}};

        arc::alg::Mat<arc::si::Length, 3, 2> ans{arc::alg::Row<arc::si::Length, 2>{arc::si::Length{2.0}, arc::si::Length{4.0}}, arc::alg::Row<arc::si::Length, 2>{arc::si::Length{0.0}, arc::si::Length{1.0}},
                                                 arc::alg::Row<arc::si::Length, 2>{arc::si::Length{-2.0}, arc::si::Length{-4.0}}};

        ASSERT_TRUE(len_mat[0][0] == ans[0][0]);
        ASSERT_TRUE(len_mat[0][1] == ans[0][1]);
        ASSERT_TRUE(len_mat[1][0] == ans[1][0]);
        ASSERT_TRUE(len_mat[1][1] == ans[1][1]);
        ASSERT_TRUE(len_mat[2][0] == ans[2][0]);
        ASSERT_TRUE(len_mat[2][1] == ans[2][1]);
    }


    // //  -- Access --
    // TEST(vec, access) // NOLINT
    // {
    //     const arc::alg::Vec<int, 4> vec_0{3, 5, 2, -9};
    //     ASSERT_EQ(vec_0[0], 3);
    //     ASSERT_EQ(vec_0[1], 5);
    //     ASSERT_EQ(vec_0[2], 2);
    //     ASSERT_EQ(vec_0[3], -9);

    //     arc::alg::Vec<int, 4> vec_1{3, 5, 2, -9};
    //     ASSERT_EQ(vec_1[0], 3);
    //     ASSERT_EQ(vec_1[1], 5);
    //     ASSERT_EQ(vec_1[2], 2);
    //     ASSERT_EQ(vec_1[3], -9);

    //     vec_1[0] = 1;
    //     vec_1[1] = 1;
    //     vec_1[2] = 2;
    //     vec_1[3] = 3;
    //     ASSERT_EQ(vec_1[0], 1);
    //     ASSERT_EQ(vec_1[1], 1);
    //     ASSERT_EQ(vec_1[2], 2);
    //     ASSERT_EQ(vec_1[3], 3);
    // }


    //  -- Range --
    TEST(vec, range) // NOLINT
    {
        const arc::alg::Mat<int, 4, 3> mat_0{arc::alg::Row<int, 3>{3, 5, 2}, arc::alg::Row<int, 3>{-9, -3, 4}, arc::alg::Row<int, 3>{0, 1, 2}, arc::alg::Row<int, 3>{-2, -3, -4}};
        int                            total_0{0};

        for (const auto& row : mat_0)
        {
            for (const auto& x : row)
            {
                total_0 += x;
            }
        }

        ASSERT_EQ(total_0, -4);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
