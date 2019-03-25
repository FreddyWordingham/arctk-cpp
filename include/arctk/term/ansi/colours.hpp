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
            //  -- Colours --
            enum class colour
            {
                BLACK = 30,
                RED,
                GREEN,
                YELLOW,
                BLUE,
                MAGENTA,
                CYAN,
                WHITE,
                DEFAULT = 39
            };



            //  == CONSTANTS ==
            //  -- Offset --
            constexpr const int BACKGROUND_OFFSET{10};



        } // namespace ansi
    }     // namespace term
} // namespace arc
