//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/debug/assert.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/debug/trace.inl"

//  -- Std --
#include <cstddef>
#include <iostream>
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==
        //  -- Assert --
        inline void assertion(const bool result_, const char* const expression_, const char* const func_, const char* const file_, const int line_) noexcept
        {
            if (result_)
            {
                return;
            }

            std::cerr << "\n\nError! Assertion failed:\n" << expression_ << "\n\n";

            std::cerr << "Location:\n"
                      << "Func\t: " << func_ << '\n'
                      << "File\t: " << file_ << '\n'
                      << "Line\t: " << line_ << "\n\n";

            const std::vector<std::string> trace{stacktrace()};

            std::cerr << "Stacktrace:\n";
            for (std::size_t i = 1; i < trace.size(); ++i)
            {
                std::cerr << i << "\t: " << trace[i] << '\n';
            }
            std::cerr << '\n';

            std::exit(exit::error::ASSERTION_FAILED);
        }



    } // namespace debug
} // namespace arc
