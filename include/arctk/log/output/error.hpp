/**
 *  @file   arctk/log/output/error.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Error console output message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_ERROR_HPP
#define ARCTK_LOG_OUTPUT_ERROR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cassert>

#include <arctk/log/output.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Error message logging.
             */
            class Error : public Output
            {
                //  == FIELDS ==
              private:
                const int _exit_val; //!< Value to exit the program with after printing error message.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Error(int exit_val_) noexcept;
                inline Error(const std::string& file_, const std::string& func_, int line_, int exit_val_) noexcept;
                inline Error(const Error&) = delete; //!< Deleted copy constructor.
                inline Error(Error&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Error() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Error& operator=(const Error&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Error& operator=(Error&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a message object which, when destructed, will write its contents to the terminal.
             *  Error report string is prepended.
             *
             *  @param  exit_val_   Value to exit the program with after reporting the error.
             *
             *  @pre    exit_val_ must be positive.
             */
            inline Error::Error(const int exit_val_) noexcept
              : Output()
              , _exit_val(exit_val_)
            {
                assert(exit_val_ > 0);

                *this << Term::instance().error_col() << "[Error!] : ";
            }

            /**
             *  Construct a warning message object which, when destructed, will write its contents to the terminal.
             *  Error report string is prepended.
             *
             *  @param  file_       File location of the message.
             *  @param  func_       Function location of the message.
             *  @param  line_       Line location of the message.
             *  @param  exit_val_   Value to exit the program with after reporting the error.
             *
             *  @pre    file_ must not be empty.
             *  @pre    func_ must not be empty.
             *  @pre    line_ must be positive.
             *  @pre    exit_val_ must be positive.
             */
            inline Error::Error(const std::string& file_, const std::string& func_, const int line_, const int exit_val_) noexcept
              : Output(file_, func_, line_)
              , _exit_val(exit_val_)
            {
                assert(!file_.empty());
                assert(!func_.empty());
                assert(line_ > 0);
                assert(exit_val_ > 0);

                *this << Term::instance().error_col() << "[Error!] : ";
            }


            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             *  Exit the program.
             */
            inline Error::~Error() noexcept
            {
                *this << Term::instance().reset() << '\n';

                exit(_exit_val);
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_ERROR_HPP
