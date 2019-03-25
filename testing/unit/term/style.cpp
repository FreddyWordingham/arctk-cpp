//  == IMPORTS ==
//  -- Arc --
#include "arctk/term/style.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <iostream>



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
    //  -- Colours --
    TEST(colouring, red_fg) // NOLINT
    {
        std::cout << "Hello " << arc::term::col(arc::term::ansi::colour::RED) << "world!" << arc::term::col() << '\n';
    }

    TEST(colouring, green_bg) // NOLINT
    {
        std::cout << "Hello " << arc::term::col(arc::term::ansi::colour::DEFAULT, arc::term::ansi::colour::GREEN) << "world!" << arc::term::col() << '\n';
    }

    TEST(colouring, red_fg_green_bg) // NOLINT
    {
        std::cout << "Hello " << arc::term::col(arc::term::ansi::colour::RED, arc::term::ansi::colour::GREEN) << "world!" << arc::term::col() << '\n';
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
