//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {
        namespace ansi
        {



            //  == CONSTANTS ==
            //  -- Escape Sequences --
            constexpr const char* const START{"\033["};
            constexpr const char* const END{"m"};


            //  -- Codes --
            constexpr const int RESET{0};



        } // namespace ansi
    }     // namespace term
} // namespace arc
