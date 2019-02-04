//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <string>
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==
        //  -- Stacktrace --
        inline std::vector<std::string> stacktrace() noexcept;



    } // namespace debug
} // namespace arc
