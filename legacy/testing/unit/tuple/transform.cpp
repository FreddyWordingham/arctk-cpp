//  == IMPORTS ==
//  -- Arc --
#include "arctk/tuple/transform.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <sstream>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == FIXTURES ==
    //  -- Transform --
    class tuples : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::tuple<char, int>         _tup_char_int{'a', 70};
        const std::tuple<int, double>       _tup_int_double{-4, 3.14159};
        const std::tuple<char, std::size_t> _tup_char_size{'x', 7};
    };



    //  == TESTS ==
    //  -- For Each --
    TEST_F(tuples, for_each_immutable) // NOLINT
    {
        std::stringstream stream_0;
        arc::tuple::for_each(_tup_char_int, [&](const auto t_) { stream_0 << t_; });
        ASSERT_EQ(stream_0.str(), "a70");

        std::stringstream stream_1;
        arc::tuple::for_each(_tup_int_double, [&](const auto t_) { stream_1 << t_; });
        ASSERT_EQ(stream_1.str(), "-43.14159");

        std::stringstream stream_2;
        arc::tuple::for_each(_tup_char_size, [&](const auto t_) { stream_2 << t_; });
        ASSERT_EQ(stream_2.str(), "x7");
    }

    TEST_F(tuples, for_each_mutable) // NOLINT
    {
        auto tup_char_int{_tup_char_int};
        arc::tuple::for_each(&tup_char_int, [](auto& t_) { t_ += 4; });
        ASSERT_EQ(tup_char_int, std::tuple('a' + 4, 74));

        auto tup_int_double{_tup_int_double};
        arc::tuple::for_each(&tup_int_double, [](auto& t_) { t_ += 4; });
        ASSERT_EQ(tup_int_double, std::tuple(0, 7.14159));

        auto tup_char_size{_tup_char_size};
        arc::tuple::for_each(&tup_char_size, [](auto& t_) { t_ += 4; });
        ASSERT_EQ(tup_char_size, std::tuple('x' + 4, 11));
    }

    TEST_F(tuples, for_each_zip_immutable) // NOLINT
    {
        std::stringstream stream_0;
        arc::tuple::for_each_zip(_tup_char_int, _tup_int_double, [&](const auto t_0_, const auto t_1_) { stream_0 << '[' << t_0_ << ',' << t_1_ << ']'; });
        ASSERT_EQ(stream_0.str(), "[a,-4][70,3.14159]");

        std::stringstream stream_1;
        arc::tuple::for_each_zip(_tup_int_double, _tup_char_size, [&](const auto t_0_, const auto t_1_) { stream_1 << '[' << t_0_ << ',' << t_1_ << ']'; });
        ASSERT_EQ(stream_1.str(), "[-4,x][3.14159,7]");

        std::stringstream stream_2;
        arc::tuple::for_each_zip(_tup_char_size, _tup_char_int, [&](const auto t_0_, const auto t_1_) { stream_2 << '[' << t_0_ << ',' << t_1_ << ']'; });
        ASSERT_EQ(stream_2.str(), "[x,a][7,70]");
    }

    TEST_F(tuples, for_each_zip_mutable) // NOLINT
    {
        auto tup_0_a{_tup_char_int};
        auto tup_0_b{_tup_char_size};
        arc::tuple::for_each_zip(&tup_0_a, &tup_0_b, [](auto& t_0_, auto& t_1_) {
            t_0_ = 0;
            t_1_ = 1;
        });
        ASSERT_EQ(tup_0_a, std::tuple(0, 0));
        ASSERT_EQ(tup_0_b, std::tuple(1, 1));

        auto tup_1_a{_tup_int_double};
        auto tup_1_b{_tup_char_size};
        arc::tuple::for_each_zip(&tup_1_a, &tup_1_b, [](auto& t_0_, auto& t_1_) {
            t_0_ = 0;
            t_1_ = 1;
        });
        ASSERT_EQ(tup_1_a, std::tuple(0, 0));
        ASSERT_EQ(tup_1_b, std::tuple(1, 1));

        auto tup_2_a{_tup_char_size};
        auto tup_2_b{_tup_char_int};
        arc::tuple::for_each_zip(&tup_2_a, &tup_2_b, [](auto& t_0_, auto& t_1_) {
            t_0_ = 0;
            t_1_ = 1;
        });
        ASSERT_EQ(tup_2_a, std::tuple(0, 0));
        ASSERT_EQ(tup_2_b, std::tuple(1, 1));
    }


    //  -- Transform --
    TEST_F(tuples, transform) // NOLINT
    {
        const auto res_0{arc::tuple::transform(_tup_char_int, [](const auto& t_) { return (t_ + 23); })};
        ASSERT_EQ(res_0, std::tuple('x', 93));

        const auto res_1{arc::tuple::transform(_tup_int_double, [](const auto& t_) { return (t_ >= 0); })};
        ASSERT_EQ(res_1, std::tuple(false, true));

        const auto res_2{arc::tuple::transform(_tup_char_size, [](const auto& t_) { return (std::is_same_v<decltype(t_), const char&>); })};
        ASSERT_EQ(res_2, std::tuple(true, false));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
