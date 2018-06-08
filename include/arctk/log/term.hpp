/**
 *  @file   arctk/log/term.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Terminal logger class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_TERM_HPP
#define ARCTK_LOG_TERM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <iostream>
#include <mutex>
#include <string>
#include <unistd.h>

//  -- Arctk --
#include <arctk/ansi.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



        //  == CONSTANTS ==
        //  -- Output --
#ifdef __APPLE__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
        const bool ANSI_SUPPORT = (isatty(fileno(stdout)) == 1); //!< True if output supports ansi escape codes.
#pragma clang diagnostic pop
#elif __linux__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
        const bool ANSI_SUPPORT = (isatty(fileno(stdout)) == 1); //!< True if output supports ansi escape codes.
#pragma clang diagnostic pop #else
        const bool ANSI_SUPPORT = false;                         //!< True if output supports ansi escape codes.
#endif



        //  == CLASS ==
        /**
         *  Terminal access class.
         *  Singleton object.
         *  Provides thread-safe terminal logging.
         */
        class Term
        {
            //  == FIELDS ==
          private:
            //  -- Writing --
            std::mutex _write_guard; //!< Terminal write guard.

            //  -- Colouring --
            std::string _location_col; //!< String used to colour location text.

            //  -- Utility --
            const std::string _reset;     //!< String used to reset colouring.
            const std::string _overwrite; //!< String used to overwrite the previous string.


            //  == INSTANTIATION ==
          public:
            //  -- Singleton --
            inline static Term& instance() noexcept;

          private:
            //  -- Constructors --
            inline Term() noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string& location_col() noexcept;
            inline const std::string& reset() noexcept;
            inline const std::string& overwrite() noexcept;

            //  -- Setters --
            inline void set_location_col(const std::string& str_) noexcept;

            //  -- Output --
            inline void cout(const std::string& str_) noexcept;
            inline void cerr(const std::string& str_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Singleton --
        /**
         *  Term singleton getter method.
         *
         *  @return Reference to the static term instance.
         */
        inline Term& Term::instance() noexcept
        {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
            static Term static_term;
#pragma clang diagnostic pop

            return (static_term);
        }


        //  -- Constructors --
        /**
         *  Construct a terminal writer object.
         *  Should only be called via the instance method.
         */
        inline Term::Term() noexcept
          : _location_col(ANSI_SUPPORT ? ansi::FG_WHITE : "")
          , _reset(ANSI_SUPPORT ? ansi::RESET : "")
          , _overwrite(ANSI_SUPPORT ? ansi::OVERWRITE : "\n")
        {
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the location colouring string.
         *
         *  @return Location colour string.
         */
        inline const std::string& Term::location_col() noexcept
        {
            return (_location_col);
        }

        /**
         *  Get the reset string.
         *
         *  @return Reset string.
         */
        inline const std::string& Term::reset() noexcept
        {
            return (_reset);
        }

        /**
         *  Get the overwrite string.
         *
         *  @return Overwrite string.
         */
        inline const std::string& Term::overwrite() noexcept
        {
            return (_overwrite);
        }


        //  -- Setters --
        /**
         *  Set the location text colour.
         *
         *  @param  str_    String used to colour location text.
         */
        inline void Term::set_location_col(const std::string& str_) noexcept
        {
            _location_col = str_;
        }


        //  -- Output --
        /**
         *  Write a string to the standard output.
         *
         *  @param  str_    String to be written.
         */
        inline void Term::cout(const std::string& str_) noexcept
        {
            std::lock_guard<std::mutex> write_lock(_write_guard);

            std::cout << str_;
        }

        /**
         *  Write a string to the standard error.
         *
         *  @param  str_    String to be written.
         */
        inline void Term::cerr(const std::string& str_) noexcept
        {
            std::lock_guard<std::mutex> write_lock(_write_guard);

            std::cerr << str_;
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_TERM_HPP
