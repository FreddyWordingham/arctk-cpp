//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.inl"
#include "arctk/range/arithmetic.inl"
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
    TEST(vec, construction) // NOLINT
    {
        arc::alg::Vec<int, 2>    vec_0{};
        const std::array<int, 2> ans_0{0, 0};
        ASSERT_EQ(vec_0.elems(), ans_0);

        arc::alg::Vec<int, 3>    vec_1{};
        const std::array<int, 3> ans_1{0, 0, 0};
        ASSERT_EQ(vec_1.elems(), ans_1);

        arc::alg::Vec<int, 3>    vec_2{{1, 2, 3}};
        const std::array<int, 3> ans_2{{1, 2, 3}};
        ASSERT_EQ(vec_2.elems(), ans_2);

        arc::alg::Vec<char, 7>    vec_3{{'a', 'a', 'b', 'c', 'e', 'h', 'm'}};
        const std::array<char, 7> ans_3{{'a', 'a', 'b', 'c', 'e', 'h', 'm'}};
        ASSERT_EQ(vec_3.elems(), ans_3);
    }


    //  -- Arithmetic --
    TEST(vec, multiplication) // NOLINT
    {
        using namespace arc;
        arc::alg::Vec<arc::si::Velocity, 3> vel_vec{{arc::si::Velocity{1.0}, arc::si::Velocity{2.0}, arc::si::Velocity{3.0}}};
        arc::alg::Vec<arc::si::Length, 3>   len_vec{vel_vec * arc::si::Time{2.0}};

        const arc::alg::Vec<arc::si::Length, 3> ans{{arc::si::Length{2.0}, arc::si::Length{4.0}, arc::si::Length{6.0}}};
        ASSERT_TRUE(len_vec[0] == ans[0]);
        ASSERT_TRUE(len_vec[1] == ans[1]);
        ASSERT_TRUE(len_vec[2] == ans[2]);
    }

    TEST(vec, dot_product) // NOLINT
    {
        using namespace arc;
        arc::alg::Vec<arc::si::Velocity, 3> vel_vec{{arc::si::Velocity{1.0}, arc::si::Velocity{2.0}, arc::si::Velocity{3.0}}};
        arc::alg::Vec<arc::si::Time, 3>     time_vec{{arc::si::Time{1.0}, arc::si::Time{-2.0}, arc::si::Time{1.0 / 3.0}}};
        arc::si::Length                     len{vel_vec * time_vec};

        ASSERT_TRUE(len == arc::si::Length{-2.0});
    }

    TEST(vec, cross_product) // NOLINT
    {
        using namespace arc;
        arc::alg::Vec<arc::si::Velocity, 3> vel_vec{{arc::si::Velocity{1.0}, arc::si::Velocity{2.0}, arc::si::Velocity{3.0}}};
        arc::alg::Vec<arc::si::Time, 3>     time_vec{{arc::si::Time{1.0}, arc::si::Time{-2.0}, arc::si::Time{1.0 / 3.0}}};
        arc::alg::Vec<arc::si::Length, 3>   len_vec{vel_vec ^ time_vec};

        const arc::alg::Vec<arc::si::Length, 3> ans{{arc::si::Length{20.0 / 3.0}, arc::si::Length{8.0 / 3.0}, arc::si::Length{-4.0}}};
        ASSERT_TRUE(len_vec[0] == ans[0]);
        ASSERT_TRUE(len_vec[1] == ans[1]);
        ASSERT_TRUE(len_vec[2] == ans[2]);
    }


    //  -- Access --
    TEST(vec, access) // NOLINT
    {
        const arc::alg::Vec<int, 4> vec_0{{3, 5, 2, -9}};
        ASSERT_EQ(vec_0[0], 3);
        ASSERT_EQ(vec_0[1], 5);
        ASSERT_EQ(vec_0[2], 2);
        ASSERT_EQ(vec_0[3], -9);

        arc::alg::Vec<int, 4> vec_1{{3, 5, 2, -9}};
        ASSERT_EQ(vec_1[0], 3);
        ASSERT_EQ(vec_1[1], 5);
        ASSERT_EQ(vec_1[2], 2);
        ASSERT_EQ(vec_1[3], -9);

        vec_1[0] = 1;
        vec_1[1] = 1;
        vec_1[2] = 2;
        vec_1[3] = 3;
        ASSERT_EQ(vec_1[0], 1);
        ASSERT_EQ(vec_1[1], 1);
        ASSERT_EQ(vec_1[2], 2);
        ASSERT_EQ(vec_1[3], 3);
    }


    //  -- Range --
    TEST(vec, range) // NOLINT
    {
        const arc::alg::Vec<int, 4> vec_0{{3, 5, 2, -9}};
        int                         total_0{0};

        for (const auto& x : vec_0)
        {
            total_0 += x;
        }

        ASSERT_EQ(total_0, 1);

        arc::alg::Vec<int, 4> vec_1{{3, 5, 2, -9}};
        int                   total_1{0};

        for (auto& x : vec_1)
        {
            x = 0;
        }
        for (const auto& x : vec_1)
        {
            total_1 += x;
        }

        ASSERT_EQ(total_1, 0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
