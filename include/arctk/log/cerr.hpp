/**
 *  @file   arctk/log/cerr.hpp
 *  @date   22/05/2018
 *  @author Freddy Wordingham
 *
 *  Console error logging class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_CERR_HPP
#define ARCTK_LOG_CERR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cassert>
#include <sstream>

//  -- Arctk --
#include <arctk/log/ansi.hpp>
#include <arctk/log/term.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         *  Console error logging class.
         *  Will print contents of stream to std::cerr upon destruction.
         *  Will exit with _exit_val upon destruction.
         */
        class Cerr : public std::stringstream
        {
            //  == FIELDS ==
          private:
            //  -- Exit --
            const int _exit_val; //!< Exit code upon destruction.


            //  == INSTANTIATION --
          public:
            //  -- Constructors --
            inline Cerr(const std::string& file_, const std::string& func_, int line_) noexcept;
            inline Cerr(const Cerr&) = delete; //!< Deleted copy constructor.
            inline Cerr(Cerr&&)      = delete; //!< Deleted move constructor.

            //  -- Destructors --
            inline ~Cerr() noexcept override;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Cerr& operator=(const Cerr&) = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Cerr& operator=(Cerr&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a stream object which, when destructed, will write its contents to the terminal.
         *  Boolean values are printed as words.
         *  If LOCATION is defined, then its value is used to colour the output location of the message instantiation.
         *
         *  @param  file_   File location of the message instantiation.
         *  @param  func_   Function location of the message instantiation.
         *  @param  line_   Line location of the message instantiation.
         *
         *  @pre    file_ must not be empty.
         *  @pre    func_ must not be empty.
         *  @pre    line_ must be greater than zero.
         */
        inline Cerr::Cerr(const std::string& file_, const std::string& func_, const int line_) noexcept
        {
            assert(!file_.empty());
            assert(!func_.empty());
            assert(line_ > 0);

            *this << std::boolalpha;
#ifdef LOCATION
            *this << LOCATION << file_ << " :: " << func_ << " :: " << line_ << ANSI.reset << "\n";
#else
            (void)(file_);
            (void)(func_);
            (void)(line_);
#endif
        }



        //  -- Destructors --
        /**
         *  Write contents to console output.
         */
        inline Cerr::~Cerr() noexcept
        {
            Term::instance().cout(str());
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_CERR_HPP
