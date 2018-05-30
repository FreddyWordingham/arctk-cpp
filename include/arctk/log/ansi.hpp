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
            static const Ansi static_ansi;

            return (static_ansi);
        }



        //  == ALIASES ==
        //  -- Ansi --
        const auto ANSI = Ansi::instance(); //!< Alias for the ansi singleton instance.



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_ANSI_HPP
