//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/term/ansi/colours.hpp"

//  -- Std --
#include <iosfwd>



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {



        //  == FUNCTIONS ==
        //  -- Reset --
        inline std::string reset() noexcept;

        //  -- Effects --
        inline std::string font() noexcept;

        //  -- Colouring --
        inline std::string col(const ansi::colour fg_ = ansi::colour::DEFAULT, const ansi::colour bg_ = ansi::colour::DEFAULT) noexcept;



    } // namespace term
} // namespace arc
