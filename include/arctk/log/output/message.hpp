/**
 *  @file   arctk/log/output/message.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Standard console output message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_MESSAGE_HPP
#define ARCTK_LOG_OUTPUT_MESSAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cassert>
#include <sstream>

#include <arctk/log/ansi.hpp>
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
            class Message : public Output
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Message() = default;
                inline Message(const std::string& file_, const std::string& func_, int line_) noexcept;
                inline Message(const Message&) = delete; //!< Deleted copy constructor.
                inline Message(Message&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Message() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Message& operator=(const Message&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Message& operator=(Message&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a message object which, when destructed, will write its contents to the terminal.
             *
             *  @param  file_   File location of the message.
             *  @param  func_   Function location of the message.
             *  @param  line_   Line location of the message.
             *
             *  @pre    file_ must not be empty.
             *  @pre    func_ must not be empty.
             *  @pre    line_ must be positive.
             */
            inline Message::Message(const std::string& file_, const std::string& func_, const int line_) noexcept
              : Output(file_, func_, line_)
            {
                assert(!file_.empty());
                assert(!func_.empty());
                assert(line_ > 0);
            }


            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             */
            inline Message::~Message() noexcept
            {
                *this << Term::instance().reset() << '\n';
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_MESSAGE_HPP
