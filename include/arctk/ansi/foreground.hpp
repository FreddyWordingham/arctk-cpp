/**
 *  @file   arctk/ansi/foreground.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Ansi foreground colouring constants.
 */



//  == GUARD ==
#ifndef ARCTK_ANSI_FOREGROUND_HPP
#define ARCTK_ANSI_FOREGROUND_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace ansi //! ansi namespace
    {



        //  == CONSTANTS ==
        constexpr const char* const FG_BLACK          = "\033[0;30m";
        constexpr const char* const FG_RED            = "\033[0;31m";
        constexpr const char* const FG_GREEN          = "\033[0;32m";
        constexpr const char* const FG_YELLOW         = "\033[0;33m";
        constexpr const char* const FG_BLUE           = "\033[0;34m";
        constexpr const char* const FG_MAGENTA        = "\033[0;35m";
        constexpr const char* const FG_CYAN           = "\033[0;36m";
        constexpr const char* const FG_WHITE          = "\033[0;37m";
        constexpr const char* const FG_BRIGHT_BLACK   = "\033[0;90m";
        constexpr const char* const FG_BRIGHT_RED     = "\033[0;91m";
        constexpr const char* const FG_BRIGHT_GREEN   = "\033[0;92m";
        constexpr const char* const FG_BRIGHT_YELLOW  = "\033[0;93m";
        constexpr const char* const FG_BRIGHT_BLUE    = "\033[0;94m";
        constexpr const char* const FG_BRIGHT_MAGENTA = "\033[0;95m";
        constexpr const char* const FG_BRIGHT_CYAN    = "\033[0;96m";
        constexpr const char* const FG_BRIGHT_WHITE   = "\033[0;97m";



    } // namespace ansi
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_ANSI_FOREGROUND_HPP
