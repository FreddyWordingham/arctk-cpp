//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/debug/assert.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <iostream>



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==
        //  -- Assert --
        constexpr inline void assertion(const bool result_, const char* const func_, const char* const file_, const int line_) noexcept
        {
            if (result_)
            {
                return;
            }

            std::cerr << "Error! Assertion failed.\n";
            std::cerr << "Function: " << func_ << '\n';
            std::cerr << "File    : " << file_ << '\n';
            std::cerr << "Line    : " << line_ << '\n';
        }



    } // namespace debug
} // namespace arc
