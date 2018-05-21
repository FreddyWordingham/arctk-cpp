/**
 *  @file   arctk/log/message.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Message log base class class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_MESSAGE_HPP
#define ARCTK_LOG_MESSAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/log/ansi.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        class Message : public std::stringstream
        {
            //  == INSTANTIATION --
          public:
            //  -- Constructors --
            inline Message(const std::string& file_, const std::string& func_, int line_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a message object which, when destructed, will write its contents to the terminal.
         *  Boolean values are printed as words.
         *  If LOCATION is defined, then its value is used to colour the output location of the message.
         *
         *  @param  file_   File location of the message.
         *  @param  func_   Function location of the message.
         *  @param  line_   Line location of the message.
         *
         *  @pre    file_ must not be empty.
         *  @pre    func_ must not be empty.
         *  @pre    line_ must be greater than zero.
         */
        inline Message::Message(const std::string& file_, const std::string& func_, const int line_) noexcept
        {
            assert(!file_.empty());
            assert(!func_.empty());
            assert(line_ > 0);

            *this << std::boolalpha;
#ifdef LOCATION
            *this << LOCATION << file_ << " :: " << func_ << " :: " << line_ << ANSI.reset << "\n";
#else
            (void)(file_);
            (void)(func_);
            (void)(line_);
#endif
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_MESSAGE_HPP
