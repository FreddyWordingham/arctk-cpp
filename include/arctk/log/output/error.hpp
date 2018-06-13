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



//  == BASE ==
//  -- Arctk --
#include <arctk/log/output.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstdlib>



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
                //  -- Colour --
                static std::string _col; //!< String used to colour this type of message. // NOLINT

                //  -- Exiting --
                const int _exit_val; //!< Value to exit the program with after printing error message.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Error(int exit_val_) noexcept;
                inline Error(const std::string& file_, const std::string& func_, int line_, int exit_val_) noexcept;
                inline Error(const Error&) noexcept = delete; //!< Deleted copy constructor.
                inline Error(Error&&) noexcept      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                [[noreturn]] inline ~Error() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Error& operator=(const Error&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Error& operator=(Error&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


                //  == METHODS ==
              public:
                //  -- Setters --
                inline static void set_col(const std::string& col_) noexcept;
            };



            //  == INSTANTIATION --
            //  -- Colour --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
            std::string Error::_col = ANSI_SUPPORT ? ansi::FG_RED : ""; // NOLINT
#pragma clang diagnostic pop


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

                *this << _col << "[Error!] : ";
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

                *this << _col << "[Error!] : ";
            }


            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             *  Write the message buffer to standard output.
             *  Exit the program.
             */
            inline Error::~Error() noexcept
            {
                *this << Term::instance().reset() << '\n';

                Term::instance().cout(str());

                std::exit(_exit_val);
            }



            //  == METHODS ==
            //  -- Setters --
            /**
             *  Set the colouring string of this message type.
             *
             *  @param  col_    Colouring string.
             */
            inline void Error::set_col(const std::string& col_) noexcept
            {
                _col = col_;
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_ERROR_HPP
