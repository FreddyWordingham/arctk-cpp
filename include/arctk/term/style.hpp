//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/term/ansi/colours.hpp"
#include "arctk/term/ansi/styles.hpp"

//  -- Std --
#include <iosfwd>



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {



        //  == FUNCTIONS ==
        //  -- Effects --
        inline std::string style(const ansi::style style_ = ansi::style::DEFAULT) noexcept;

        //  -- Colouring --
        inline std::string col(const ansi::colour fg_ = ansi::colour::DEFAULT, const ansi::colour bg_ = ansi::colour::DEFAULT) noexcept;



    } // namespace term
} // namespace arc
