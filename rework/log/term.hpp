/**
 *  @file   arctk/log/term.hpp
 *  @date   30/05/2018
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

#include <arctk/log/ansi.hpp>



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


            //  == INSTANTIATION ==
          public:
            //  -- Singleton --
            inline static Term& instance() noexcept;

          private:
            //  -- Constructors --
            inline Term() noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            inline void set_message_col(Ansi::col col_) noexcept;
            inline void set_warn_col(Ansi::col col_) noexcept;
            inline void set_error_col(Ansi::col col_) noexcept;

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
          : _message_col{Ansi::instance().text_col[static_cast<size_t>(Ansi::col::WHITE)]}
          , _warn_col{Ansi::instance().text_col[static_cast<size_t>(Ansi::col::YELLOW)]}
          , _error_col{Ansi::instance().text_col[static_cast<size_t>(Ansi::col::RED)]}
        {
        }



        //  == METHODS ==
        //  -- Setters --
        /**
         *  Set the standard message colour.
         *
         *  @param  col_    Ansi colour used to colour standard messages.
         */
        inline void Term::set_message_col(const Ansi::col col_) noexcept
        {
            _message_col = Ansi::instance().text_col[static_cast<size_t>(col_)];
        }

        /**
         *  Set the warning message colour.
         *
         *  @param  col_    Ansi colour used to colour warning messages.
         */
        inline void Term::set_warn_col(const Ansi::col col_) noexcept
        {
            _warn_col = Ansi::instance().text_col[static_cast<size_t>(col_)];
        }

        /**
         *  Set the error message colour.
         *
         *  @param  col_    Ansi colour used to colour error messages.
         */
        inline void Term::set_error_col(const Ansi::col col_) noexcept
        {
            _error_col = Ansi::instance().text_col[static_cast<size_t>(col_)];
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
