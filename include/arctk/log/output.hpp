/**
 *  @file   arctk/log/output.hpp
 *  @date   30/05/2018
 *  @author Freddy Wordingham
 *
 *  Console output logging class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_HPP
#define ARCTK_LOG_OUTPUT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cassert>
#include <sstream>

#include <arctk/log/ansi.hpp>
#include <arctk/log/term.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         *  Console output logging class.
         *  Will print contents of stream to console output upon destruction.
         */
        class Output : public std::stringstream
        {
            //  == FIELDS ==
          public:
            //  -- Exit --
            const int _exit_val{0}; //!< Exit value. Positive when exiting with fatal error.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Output(const std::string& file_, const std::string& func_, int line_, int exit_val_) noexcept;


            //  == OPERATORS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a stream object which, when destructed, will write its contents to console output.
         *  Boolean values are printed as words.
         *  Upon destruction program will exit with an exit code of _exit_val.
         *  If LOCATION is defined, then its value is used to colour the output location of the message instantiation.
         *
         *  @param  file_       File location of the message instantiation.
         *  @param  func_       Function location of the message instantiation.
         *  @param  line_       Line location of the message instantiation.
         *  @param  exit_val_   Exit value of program used when reporting a fatal error.
         *
         *  @pre    file_       must not be empty.
         *  @pre    func_       must not be empty.
         *  @pre    line_       must be greater than zero.
         *  @pre    exit_val_   must be positive.
         */
        inline Output(const std::string& file_, const std::string& func_, const int line_, const int exit_val_) noexcept
          : _exit_val(exit_val_)
        {
            assert(!file_.empty());
            assert(!func_.empty());
            assert(line_ > 0);
            assert(exit_val_ > 0);

            *this << std::boolalpha;

#ifdef LOCATION
            *this << LOCATION << file_ << " :: " << func_ << " :: " << line_ << ANSI.reset << "\n";
#else
            (void)(file_);
            (void)(func_);
            (void)(line_);
#endif
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_HPP
