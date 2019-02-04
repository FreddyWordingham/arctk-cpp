//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/debug/assert.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <iostream>
#include <vector>

//  -- Arc --
#include <arctk/debug/trace.inl>



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==
        //  -- Assert --
        inline void assertion(const bool result_, const char* const func_, const char* const file_, const int line_) noexcept
        {
            if (result_)
            {
                return;
            }

            std::cerr << "\nError!\t: Assertion failed.\n\n";
            std::cerr << "Func\t: " << func_ << '\n';
            std::cerr << "File\t: " << file_ << '\n';
            std::cerr << "Line\t: " << line_ << "\n\n";

            const std::vector<std::string> trace{stacktrace()};

            std::cerr << "Stacktrace:\n";
            for (std::size_t i = 0; i < trace.size(); ++i)
            {
                std::cerr << i << "\t: " << trace[i] << '\n';
            }
            std::cerr << '\n';
        }



    } // namespace debug
} // namespace arc
