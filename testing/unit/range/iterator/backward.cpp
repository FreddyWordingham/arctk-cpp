//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/backward.inl"

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
    //  -- Backward Iterator --
    class backward_iterator : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const std::array<int, 4>                  _arr_0{3, 2, 1, 0};
        const arc::range::iterator::Backward<int> start{&_arr_0.back()};
        const arc::range::iterator::Backward<int> end{&_arr_0.front() - 1};
    };



    //  == TESTS ==
    //  -- Backward Iterator --
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
