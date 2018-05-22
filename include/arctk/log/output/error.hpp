/**
 *  @file   arctk/log/output/error.hpp
 *  @date   22/05/2018
 *  @author Freddy Wordingham
 *
 *  Standard console output error log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_ERROR_HPP
#define ARCTK_LOG_OUTPUT_ERROR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cassert>
#include <sstream>

//  -- Arctk --
#include <arctk/log/ansi.hpp>
#include <arctk/log/output.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Standard error message logging.
             */
            class Error : public Output
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Error(const std::string& file_, const std::string& func_, int line_, int exit_val_) noexcept;
                inline Error(const Error&) = delete; //!< Deleted copy constructor.
                inline Error(Error&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                [[noreturn]] inline ~Error() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Error& operator=(const Error&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Error& operator=(Error&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct an error message object which, when destructed, will write its contents to the terminal and exit the program.
             *  Error call location is reported.
             *  Error report string is prepended.
             *
             *  @param  file_       File location of the message.
             *  @param  func_       Function location of the message.
             *  @param  line_       Line location of the message.
             *  @param  exit_val_   Exit value of program used after printing the error message.
             *
             *  @pre    file_ must not be empty.
             *  @pre    func_ must not be empty.
             *  @pre    line_ must be greater than zero.
             *  @pre    exit_val_ must be positive.
             */
            inline Error::Error(const std::string& file_, const std::string& func_, const int line_, const int exit_val_) noexcept
              : Output(file_, func_, line_, exit_val_)
            {
                assert(!file_.empty());
                assert(!func_.empty());
                assert(line_ > 0);
                assert(exit_val_ > 0);

                *this << ANSI.red << file_ << " :: " << func_ << " :: " << line_ << ANSI.reset << "\n";
                *this << "[" << ANSI.red << "!ERROR!" << ANSI.reset << "] : " << ANSI.red;
            }


            //  -- Destructors --
            /**
             *  Error report string is appended.
             *  Reset ansi escape codes and append a newline character.
             *  Exit will be called by base class destructor method.
             */
            inline Error::~Error() noexcept
            {
                *this << ANSI.reset << " : [" << ANSI.red << "!ERROR!" << ANSI.reset << "]";
                *this << ANSI.reset << '\n';
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_ERROR_HPP
