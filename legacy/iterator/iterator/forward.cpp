//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/forward.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <array>
#include <cstddef>



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
    //  -- Forward Iterator --
    class forward_iterator : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 4>                 _arr_0{0, 1, 2, 3};
        const arc::range::iterator::Forward<int> start{&_arr_0.front()};
        const arc::range::iterator::Forward<int> end{&_arr_0.back() + 1};
    };



    //  == TESTS ==
    //  -- Forward Iterator --
    TEST_F(forward_iterator, range) // NOLINT
    {
        std::size_t i{0};
        for (auto it{start}; it != end; ++it, ++i)
        {
            ASSERT_EQ(*it, i);
        }
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
