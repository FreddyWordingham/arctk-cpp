//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional.inl"

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
    //  -- Bidirectional Iterator --
    class bidirectional_iterator : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 4>                                _arr_0{0, 1, 2, 3};
        const arc::range::iterator::forward::Bidirectional<int> start{&_arr_0.front()};
        const arc::range::iterator::forward::Bidirectional<int> end{&_arr_0.back() + 1};
    };



    //  == TESTS ==
    //  -- Bidirectional Iterator --
    TEST_F(bidirectional_iterator, range) // NOLINT
    {
        arc::range::iterator::forward::Bidirectional it{start};
        ASSERT_EQ(*it, 0);

        ++it;
        ASSERT_EQ(*it, 1);

        ++it;
        ASSERT_EQ(*it, 2);

        ++it;
        ASSERT_EQ(*it, 3);

        --it;
        ASSERT_EQ(*it, 2);

        --it;
        ASSERT_EQ(*it, 1);

        ++it;
        ASSERT_EQ(*it, 2);

        ++it;
        ASSERT_EQ(*it, 3);

        ++it;
        ASSERT_EQ(it, end);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
