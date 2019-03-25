//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/term/properties.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cstdio>
#include <unistd.h>



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {



        //  == FUNCTIONS ==
        //  -- Ansi --
        inline bool ansi_enabled() noexcept
        {
            const static bool terminal{isatty(fileno(stdout)) == 1};

            return (terminal);
        }



    } // namespace term
} // namespace arc
