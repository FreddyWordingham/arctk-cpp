/**
 *  @file   arctk/log/output/warning.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Warning console output message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_WARNING_HPP
#define ARCTK_LOG_OUTPUT_WARNING_HPP



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
             *  Standard output message logging.
             */
            class Warning : public Output
            {
                //  == FIELDS ==
              public:
                //  -- Colouring --
                static std::string _col;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Warning() noexcept;
                inline Warning(const std::string& file_, const std::string& func_, int line_) noexcept;
                inline Warning(const Warning&) = delete; //!< Deleted copy constructor.
                inline Warning(Warning&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Warning() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Warning& operator=(const Warning&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Warning& operator=(Warning&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Statics --
            std::string Warning::_col = ansi::FG_MAGENTA;


            //  -- Constructors --
            /**
             *  Construct a message object which, when destructed, will write its contents to the terminal.
             *  Warning report string is prepended.
             */
            inline Warning::Warning() noexcept
              : Output()
            {
                *this << _col << "[Warning!] : ";
            }

            /**
             *  Construct a warning message object which, when destructed, will write its contents to the terminal.
             *  Warning report string is prepended.
             *
             *  @param  file_   File location of the message.
             *  @param  func_   Function location of the message.
             *  @param  line_   Line location of the message.
             *
             *  @pre    file_ must not be empty.
             *  @pre    func_ must not be empty.
             *  @pre    line_ must be positive.
             */
            inline Warning::Warning(const std::string& file_, const std::string& func_, const int line_) noexcept
              : Output(file_, func_, line_)
            {
                assert(!file_.empty());
                assert(!func_.empty());
                assert(line_ > 0);

                *this << _col << "[Warning!] : ";
            }


            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             */
            inline Warning::~Warning() noexcept
            {
                *this << Term::instance().reset() << '\n';
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_WARNING_HPP
