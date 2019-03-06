//  == IMPORTS ==
//  -- Arc --
#include "arctk/tuple/transform.inl"

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



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
