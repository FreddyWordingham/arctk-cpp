/**
 *  @file   arctk/log/ansi.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Ansi escape code definition class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_ANSI_HPP
#define ARCTK_LOG_ANSI_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <string>
#if defined(__APPLE__) || defined(___unix__)
#include <unistd.h>
#endif



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         *  Ansi escape code definitions.
         *  Codes are set for the platform during instantiation.
         */
        class Ansi
        {
            //  == FIELDS ==
          public:
            //  -- General --
            const std::string reset; //!< Reset ansi settings to default.

            //  -- Text Colouring --
            const std::string black;          //!< Colour the text black.
            const std::string red;            //!< Colour the text red.
            const std::string green;          //!< Colour the text green.
            const std::string yellow;         //!< Colour the text yellow.
            const std::string blue;           //!< Colour the text blue.
            const std::string magenta;        //!< Colour the text magenta.
            const std::string cyan;           //!< Colour the text cyan.
            const std::string white;          //!< Colour the text white.
            const std::string bright_black;   //!< Colour the text bright black.
            const std::string bright_red;     //!< Colour the text bright red.
            const std::string bright_green;   //!< Colour the text bright green.
            const std::string bright_yellow;  //!< Colour the text bright yellow.
            const std::string bright_blue;    //!< Colour the text bright blue.
            const std::string bright_magenta; //!< Colour the text bright magenta.
            const std::string bright_cyan;    //!< Colour the text bright cyan.
            const std::string bright_white;   //!< Colour the text bright white.

            //  -- Utility --
            const std::string overwrite; //!< Overwrite the previous printed line.


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
          , black((isatty(fileno(stdout)) == 1) ? "\033[0;30m" : "")
          , red((isatty(fileno(stdout)) == 1) ? "\033[0;31m" : "")
          , green((isatty(fileno(stdout)) == 1) ? "\033[0;32m" : "")
          , yellow((isatty(fileno(stdout)) == 1) ? "\033[0;33m" : "")
          , blue((isatty(fileno(stdout)) == 1) ? "\033[0;34m" : "")
          , magenta((isatty(fileno(stdout)) == 1) ? "\033[0;35m" : "")
          , cyan((isatty(fileno(stdout)) == 1) ? "\033[0;36m" : "")
          , white((isatty(fileno(stdout)) == 1) ? "\033[0;37m" : "")
          , bright_black((isatty(fileno(stdout)) == 1) ? "\033[0;90m" : "")
          , bright_red((isatty(fileno(stdout)) == 1) ? "\033[0;91m" : "")
          , bright_green((isatty(fileno(stdout)) == 1) ? "\033[0;92m" : "")
          , bright_yellow((isatty(fileno(stdout)) == 1) ? "\033[0;93m" : "")
          , bright_blue((isatty(fileno(stdout)) == 1) ? "\033[0;94m" : "")
          , bright_magenta((isatty(fileno(stdout)) == 1) ? "\033[0;95m" : "")
          , bright_cyan((isatty(fileno(stdout)) == 1) ? "\033[0;96m" : "")
          , bright_white((isatty(fileno(stdout)) == 1) ? "\033[0;97m" : "")
          , overwrite((isatty(fileno(stdout)) == 1) ? "%\n\033[A\33[2K\r" : "\n")
#else
          : reset("")
          , black("")
          , red("")
          , green("")
          , yellow("")
          , blue("")
          , magenta("")
          , cyan("")
          , white("")
          , bright_black("")
          , bright_red("")
          , bright_green("")
          , bright_yellow("")
          , bright_blue("")
          , bright_magenta("")
          , bright_cyan("")
          , bright_white("")
          , overwrite("\n")
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
