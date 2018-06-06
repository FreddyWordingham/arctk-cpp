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
//  -- Std --
#include <cassert>

//  -- Arctk --
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
                //  == FIELDS ==
              private:
                //  -- Colour --
                static std::string _col; //!< String used to colour this type of message. // NOLINT


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Message() noexcept;
                inline Message(const std::string& file_, const std::string& func_, int line_) noexcept;
                inline Message(const Message&) noexcept = delete; //!< Deleted copy constructor.
                inline Message(Message&&) noexcept      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Message() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Message& operator=(const Message&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Message& operator=(Message&&) = default;              //!< Defaulted move operator. @return Reference to moved object.


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
            std::string Message::_col = ANSI_SUPPORT ? ansi::FG_WHITE : ""; // NOLINT
#pragma clang diagnostic pop


            //  -- Constructors --
            /**
             *  Construct a message object which, when destructed, will write its contents to the terminal.
             */
            inline Message::Message() noexcept
              : Output()
            {
                *this << _col;
            }

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

                *this << _col;
            }


            //  -- Destructors --
            /**
             *  Reset ansi escape codes and append a newline character.
             */
            inline Message::~Message() noexcept
            {
                *this << Term::instance().reset() << '\n';
            }



            //  == METHODS ==
            //  -- Setters --
            /**
             *  Set the colouring string of this message type.
             *
             *  @param  col_    Colouring string.
             */
            inline void Message::set_col(const std::string& col_) noexcept
            {
                _col = col_;
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_MESSAGE_HPP
