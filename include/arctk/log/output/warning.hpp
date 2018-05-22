/**
 *  @file   arctk/log/output/warning.hpp
 *  @date   22/05/2018
 *  @author Freddy Wordingham
 *
 *  Standard console output warning message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_WARNING_HPP
#define ARCTK_LOG_OUTPUT_WARNING_HPP



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
             *  Standard output warning message logging.
             */
            class Warning : public Output
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
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
            //  -- Constructors --
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
             *  @pre    line_ must be greater than zero.
             */
            inline Warning::Warning(const std::string& file_, const std::string& func_, const int line_) noexcept
              : Output(file_, func_, line_)
            {
                assert(!file_.empty());
                assert(!func_.empty());
                assert(line_ > 0);

                *this << "[" << ANSI.yellow << "Warning!" << ANSI.reset << "] : ";
            }


            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             */
            inline Warning::~Warning() noexcept
            {
                *this << ANSI.reset << '\n';
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_WARNING_HPP
