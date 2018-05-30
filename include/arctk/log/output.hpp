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
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Output(const std::string& file_, const std::string& func_, int line_) noexcept;

            //  -- Destructors --
            inline ~Output() noexcept override;


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
            //  -- Exiting --
            inline void exit(int exit_val_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a stream object which, when destructed, will write its contents to console output.
         *  Boolean values are printed as words.
         *  If LOCATION is defined, then its value is used to colour the output location of the message instantiation.
         *
         *  @param  file_       File location of the message instantiation.
         *  @param  func_       Function location of the message instantiation.
         *  @param  line_       Line location of the message instantiation.
         *
         *  @pre    file_       must not be empty.
         *  @pre    func_       must not be empty.
         *  @pre    line_       must be greater than zero.
         */
        inline Output(const std::string& file_, const std::string& func_, const int line_) noexcept
          : _exit_val(exit_val_)
        {
            assert(!file_.empty());
            assert(!func_.empty());
            assert(line_ > 0);

            *this << std::boolalpha;

            *this << LOCATION << file_ << " :: " << func_ << " :: " << line_ << ANSI.reset << "\n";
        }


        //  -- Destructors --
        /**
         *  Write contents to console output.
         */
        inline Output::~Output() noexcept
        {
            Term::instance().cout(str());

            if (_exit_val > 0)
            {
                exit(_exit_val);
            }
        }



        //  == METHODS ==
        //  -- Exiting --
        /**
         *  Write contents to console output then exit with an error value.
         *
         *  @param  exit_val_   Value to exit program with.
         *
         *  @pre    exit_val_   Must be greater than zero.
         */
        inline void Output::exit(const int exit_val_) noexcept
        {
            assert(exit_val_ > 0);

            Term::instance().cout(str());

            exit(exit_val_);
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_HPP
