/**
 *  @file   arctk/log/ansi.hpp
 *  @date   30/05/2018
 *  @author Freddy Wordingham
 *
 *  Ansi escape code definition class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_ANSI_HPP
#define ARCTK_LOG_ANSI_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <string>
#if defined(__APPLE__) || defined(___unix__)
#include <unistd.h>
#endif



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



//  == CONSTANTS ==
//  -- Standard Output --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
        const bool STDOUT_IS_TERM = isatty(fileno(stdout)) == 1; //!< True if standard output is a terminal.
#pragma clang diagnostic pop



        //  == CLASS ==
        /**
         *  Ansi escape code definitions.
         *  Codes are set for the platform during instantiation.
         */
        class Ansi
        {
            //  == ENUMERATIONS ==
          public:
            //  -- Colours --
            enum class col
            {
                BLACK,
                RED,
                GREEN,
                YELLOW,
                BLUE,
                MAGENTA,
                CYAN,
                WHITE,
                BRIGHT_BLACK,
                BRIGHT_RED,
                BRIGHT_GREEN,
                BRIGHT_YELLOW,
                BRIGHT_BLUE,
                BRIGHT_MAGENTA,
                BRIGHT_CYAN,
                BRIGHT_WHITE,
                TOTAL
            };


            //  == FIELDS ==
          public:
            //  -- General --
            const std::string reset; //!< Reset ansi settings to default.

            //  -- Utility --
            const std::string overwrite; //!< Overwrite the previous printed line.


            //  -- Text Colouring --
            const std::array<std::string, static_cast<size_t>(col::TOTAL)> text_col;


            //  == INSTANTIATION ==
          public:
            //  -- Singleton --
            inline static const Ansi& instance() noexcept;

          private:
            //  -- Constructors --
            inline Ansi() noexcept;
        };



        //  == INSTANTIATION --
        //  -- Singleton --
        /**
         *  Ansi singleton getter method.
         *
         *  @return Const reference to the static ansi instance.
         */
        inline const Ansi& Ansi::instance() noexcept
        {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
            static const Ansi static_ansi;
#pragma clang diagnostic pop

            return (static_ansi);
        }


        //  -- Constructors --
        /**
         *  Construct an ansi object with escape codes for the current platform.
         */
        inline Ansi::Ansi() noexcept
#if defined(__APPLE__) || defined(___unix__)
          : reset((isatty(fileno(stdout)) == 1) ? "\033[0;0m" : "")
          , overwrite((isatty(fileno(stdout)) == 1) ? "\n\033[A\33[2K\r" : "\n")
          , text_col({{STDOUT_IS_TERM ? "\033[0;30m" : "", STDOUT_IS_TERM ? "\033[0;31m" : "", STDOUT_IS_TERM ? "\033[0;32m" : "", STDOUT_IS_TERM ? "\033[0;33m" : "", STDOUT_IS_TERM ? "\033[0;34m" : "", STDOUT_IS_TERM ? "\033[0;35m" : "",
                       STDOUT_IS_TERM ? "\033[0;36m" : "", STDOUT_IS_TERM ? "\033[0;37m" : "", STDOUT_IS_TERM ? "\033[0;90m" : "", STDOUT_IS_TERM ? "\033[0;91m" : "", STDOUT_IS_TERM ? "\033[0;92m" : "", STDOUT_IS_TERM ? "\033[0;93m" : "",
                       STDOUT_IS_TERM ? "\033[0;94m" : "", STDOUT_IS_TERM ? "\033[0;95m" : "", STDOUT_IS_TERM ? "\033[0;96m" : "", STDOUT_IS_TERM ? "\033[0;97m" : ""}})
#else
          : reset("")
          , overwrite("\n")
          , text_col({{"", "", "", "", "", "", "", "", "", "", "", "", "", "", ""}})
#endif
        {
        }



//  == ALIASES ==
//  -- Ansi --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
        const auto ANSI = Ansi::instance(); //!< Alias for the ansi singleton instance.
#pragma clang diagnostic pop



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_ANSI_HPP
