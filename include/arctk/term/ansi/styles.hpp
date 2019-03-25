//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/term/ansi/escape.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {
        namespace ansi
        {



            //  == ENUMERATIONS ==
            //  -- Styles --
            enum class style
            {
                DEFAULT = 0,
                BOLD,
                FAINT,
                ITALIC,
                UNDERLINE,
                REVERSE = 7,
                CONCEAL
            };



        } // namespace ansi
    }     // namespace term
} // namespace arc
