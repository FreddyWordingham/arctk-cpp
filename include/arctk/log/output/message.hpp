/**
 *  @file   arctk/log/output/message.hpp
 *  @date   30/05/2018
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
                inline Message() noexcept = default;
                inline Message(const std::string& file_, const std::string& func_, int line_) noexcept;

                //  -- Destructors --


                //  == OPERATORS ==
              public:
                //  -- Assignment --
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



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_MESSAGE_HPP
