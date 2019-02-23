//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <vector>



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
    //  -- Iterator --
    TEST(prime, special) // NOLINT
    {
        const std::vector<int> vec{43, 42, 41};

        arc::range::Iterator it{vec.begin()};

        ASSERT_EQ(*it, 43);
        ASSERT_EQ(*(++it), 42);
        ASSERT_EQ(*(++(++it)), 41);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
