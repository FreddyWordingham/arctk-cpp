//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional/random.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>



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
    //  -- Random Iterator --
    class random_iterator : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 4>                                        _arr_0{0, 1, 2, 3};
        const arc::range::iterator::forward::bidirectional::Random<int> start{&_arr_0.front()};
        const arc::range::iterator::forward::bidirectional::Random<int> end{&_arr_0.back() + 1};
    };



    //  == TESTS ==
    //  -- Random Iterator --
    TEST_F(random_iterator, range) // NOLINT
    {
        arc::range::iterator::forward::bidirectional::Random it{start};
        ASSERT_EQ(*it, 0);

        it += 2;
        ASSERT_EQ(*it, 2);

        it += 2;
        ASSERT_EQ(it, end);

        it -= 3;
        ASSERT_EQ(*it, 1);

        ASSERT_EQ(*(it + 1), 2);

        ASSERT_EQ(*(it - 1), 0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
