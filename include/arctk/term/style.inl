//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/term/style.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/term/ansi/colours.inl"
#include "arctk/term/ansi/escape.inl"
#include "arctk/term/properties.inl"

//  -- Std --
#include <string>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {



        //  == FUNCTIONS ==
        //  -- Reset --
        inline std::string reset() noexcept
        {
            return (ansi_enabled() ? (std::string{} + ansi::START + std::to_string(ansi::RESET) + ansi::END) : "");
        }


        //  -- Effects --
        inline std::string font() noexcept
        {
            static int i{0};
            ++i;
            return (ansi_enabled() ? (std::string{} + ansi::START + std::to_string(i) + ansi::END) : "");
        }


        //  -- Colouring --
        inline std::string col(const ansi::colour fg_, const ansi::colour bg_) noexcept
        {
            return (ansi_enabled() ? (std::string{} + ansi::START + std::to_string(static_cast<int>(fg_)) + ';' + std::to_string(static_cast<int>(bg_) + ansi::BACKGROUND_OFFSET) + ansi::END) : "");
        }



    } // namespace term
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
