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
        //  -- Standard Colours --
        constexpr const char* const FG_BLACK   = "\033[0;30m"; //!< Colour text black.
        constexpr const char* const FG_RED     = "\033[0;31m"; //!< Colour text red.
        constexpr const char* const FG_GREEN   = "\033[0;32m"; //!< Colour text green.
        constexpr const char* const FG_YELLOW  = "\033[0;33m"; //!< Colour text yellow.
        constexpr const char* const FG_BLUE    = "\033[0;34m"; //!< Colour text blue.
        constexpr const char* const FG_MAGENTA = "\033[0;35m"; //!< Colour text magenta.
        constexpr const char* const FG_CYAN    = "\033[0;36m"; //!< Colour text cyan.
        constexpr const char* const FG_WHITE   = "\033[0;37m"; //!< Colour text white.

        //  -- Bright Colours --
        constexpr const char* const FG_BRIGHT_BLACK   = "\033[0;90m"; //!< Colour text bright black.
        constexpr const char* const FG_BRIGHT_RED     = "\033[0;91m"; //!< Colour text bright red.
        constexpr const char* const FG_BRIGHT_GREEN   = "\033[0;92m"; //!< Colour text bright green.
        constexpr const char* const FG_BRIGHT_YELLOW  = "\033[0;93m"; //!< Colour text bright yellow.
        constexpr const char* const FG_BRIGHT_BLUE    = "\033[0;94m"; //!< Colour text bright blue.
        constexpr const char* const FG_BRIGHT_MAGENTA = "\033[0;95m"; //!< Colour text bright magenta.
        constexpr const char* const FG_BRIGHT_CYAN    = "\033[0;96m"; //!< Colour text bright cyan.
        constexpr const char* const FG_BRIGHT_WHITE   = "\033[0;97m"; //!< Colour text bright white.



    } // namespace ansi
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_ANSI_FOREGROUND_HPP
