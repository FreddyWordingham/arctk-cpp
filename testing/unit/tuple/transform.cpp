//  == IMPORTS ==
//  -- Arc --
#include "arctk/tuple/transform.inl"
#include "arctk/math/comparison.inl"
#include "arctk/math/properties.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <string>



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
    //  -- Immutable --
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

    TEST_F(tuples, for_each_res_immutable) // NOLINT
    {
        std::vector<bool> res_0;
        arc::tuple::for_each(_tup_char_int, [&](const auto t_) { res_0.emplace_back(arc::math::is_prime(t_)); });
        const std::vector<bool> expected_res_0{true, false};
        ASSERT_EQ(res_0, expected_res_0);

        std::vector<bool> res_1;
        arc::tuple::for_each(_tup_int_double, [&](const auto t_) { res_1.emplace_back(arc::math::equal(static_cast<double>(t_), 3.14159)); });
        const std::vector<bool> expected_res_1{false, true};
        ASSERT_EQ(res_1, expected_res_1);

        std::vector<bool> res_2;
        arc::tuple::for_each(_tup_char_size, [&](const auto t_) { res_2.emplace_back(arc::math::is_prime(t_)); });
        const std::vector<bool> expected_res_2{false, true};
        ASSERT_EQ(res_2, expected_res_2);
    }

    TEST_F(tuples, for_each_zip) // NOLINT
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


    //  -- Mutable --
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

    TEST_F(tuples, for_each_res_mutable) // NOLINT
    {
        auto              tup_char_int{_tup_char_int};
        std::vector<bool> res_0;
        arc::tuple::for_each(&tup_char_int, [&](auto& t_) { res_0.emplace_back(arc::math::is_prime(t_++)); });
        const std::vector<bool> expected_res_0{true, false};
        ASSERT_EQ(res_0, expected_res_0);
        ASSERT_EQ(tup_char_int, (std::tuple<char, int>{'b', 71}));

        auto              tup_int_double{_tup_int_double};
        std::vector<bool> res_1;
        arc::tuple::for_each(&tup_int_double, [&](auto& t_) { res_1.emplace_back(arc::math::equal(static_cast<double>(t_++), 3.14159)); });
        const std::vector<bool> expected_res_1{false, true};
        ASSERT_EQ(res_1, expected_res_1);
        ASSERT_EQ(tup_int_double, (std::tuple<int, double>{-3, 4.14159}));

        auto              tup_char_size{_tup_char_size};
        std::vector<bool> res_2;
        arc::tuple::for_each(&tup_char_size, [&](auto& t_) { res_2.emplace_back(arc::math::is_prime(t_++)); });
        const std::vector<bool> expected_res_2{false, true};
        ASSERT_EQ(res_2, expected_res_2);
        ASSERT_EQ(tup_char_size, (std::tuple<char, std::size_t>{'y', 8}));
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
