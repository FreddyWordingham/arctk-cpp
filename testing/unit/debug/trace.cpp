//  == IMPORTS ==
//  -- Arc --
#include "arctk/debug/trace.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"



//  == TESTS ==
TEST(TestSuitName, TestName)
{
    const std::vector<std::string> trace{arc::debug::stacktrace()};

    for (std::size_t i = 0; i < trace.size(); ++i)
    {
        std::cout << trace[i] << '\n';
    }
}



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
