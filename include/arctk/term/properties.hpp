//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <cstdio>
#include <iostream>
#include <unistd.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {



        //  == FUNCTIONS ==
        //  -- Support --
        const bool ANSI_ENABLED{isatty(fileno(stdout)) == 1};



    } // namespace term
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
