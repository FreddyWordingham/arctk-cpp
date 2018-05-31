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
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Error() noexcept;
                inline Error(const std::string& file_, const std::string& func_, int line_) noexcept;
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
             */
            inline Error::Error() noexcept
              : Output()
            {
                *this << Term::instance().warn_col() << "[Error!] : ";
            }

            /**
             *  Construct a warning message object which, when destructed, will write its contents to the terminal.
             *  Error report string is prepended.
             *
             *  @param  file_   File location of the message.
             *  @param  func_   Function location of the message.
             *  @param  line_   Line location of the message.
             *
             *  @pre    file_ must not be empty.
             *  @pre    func_ must not be empty.
             *  @pre    line_ must be positive.
             */
            inline Error::Error(const std::string& file_, const std::string& func_, const int line_) noexcept
              : Output(file_, func_, line_)
            {
                assert(!file_.empty());
                assert(!func_.empty());
                assert(line_ > 0);

                *this << Term::instance().warn_col() << "[Error!] : ";
            }


            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             */
            inline Error::~Error() noexcept
            {
                *this << Term::instance().reset() << '\n';
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_ERROR_HPP
