/**
 *  @file   arctk/log/cout/message.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Standard console output message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_COUT_MESSAGE_HPP
#define ARCTK_LOG_COUT_MESSAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cassert>
#include <sstream>

//  -- Arctk --
#include <arctk/log/ansi.hpp>
#include <arctk/log/cout.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {
        namespace cout //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Standard cout message logging.
             */
            class Message : public Cout
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Message(const std::string& file_, const std::string& func_, int line_) noexcept;
                //        inline Message(const Message&) = delete; //!< Deleted copy constructor.
                //        inline Message(Message&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Message() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                //        inline Message& operator=(const Message&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                //        inline Message& operator=(Message&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             */
            inline Message::~Message() noexcept
            {
                *this << ANSI.reset << '\n';
            }



        } // namespace cout
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_COUT_MESSAGE_HPP
