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
#include <iostream>
#include <mutex>
#include <string>
#include <unistd.h>

#include <arctk/ansi.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



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
            std::string _message_col; //!< String used to colour standard message text.
            std::string _warn_col;    //!< String used to colour warning message text.
            std::string _error_col;   //!< String used to colour error message text.

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
            inline const std::string& message_col() noexcept;
            inline const std::string& warn_col() noexcept;
            inline const std::string& error_col() noexcept;
            inline const std::string& reset() noexcept;
            inline const std::string& overwrite() noexcept;

            //  -- Setters --
            inline void set_message_col(const std::string& str_) noexcept;
            inline void set_warn_col(const std::string& str_) noexcept;
            inline void set_error_col(const std::string& str_) noexcept;

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
          : _message_col{(isatty(fileno(stdout)) == 1) ? ansi::FG_CYAN : ""}
          , _warn_col{(isatty(fileno(stdout)) == 1) ? ansi::FG_YELLOW : ""}
          , _error_col{(isatty(fileno(stdout)) == 1) ? ansi::FG_RED : ""}
          , _reset{(isatty(fileno(stdout)) == 1) ? ansi::RESET : ""}
          , _overwrite{(isatty(fileno(stdout)) == 1) ? ansi::OVERWRITE : "\n"}
        {
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the message colouring string.
         *
         *  @return Message colour string.
         */
        inline const std::string& Term::message_col() noexcept
        {
            return (_message_col);
        }

        /**
         *  Get the warning colouring string.
         *
         *  @return Warning colour string.
         */
        inline const std::string& Term::warn_col() noexcept
        {
            return (_warn_col);
        }

        /**
         *  Get the error colouring string.
         *
         *  @return Error colour string.
         */
        inline const std::string& Term::error_col() noexcept
        {
            return (_error_col);
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
         *  Set the standard message colour.
         *
         *  @param  str_    String used to colour standard messages.
         */
        inline void Term::set_message_col(const std::string& str_) noexcept
        {
            _message_col = str_;
        }

        /**
         *  Set the warning message colour.
         *
         *  @param  str_    String used to colour warning messages.
         */
        inline void Term::set_warn_col(const std::string& str_) noexcept
        {
            _warn_col = str_;
        }

        /**
         *  Set the error message colour.
         *
         *  @param  str_    String used to colour error messages.
         */
        inline void Term::set_error_col(const std::string& str_) noexcept
        {
            _error_col = str_;
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
