/**
 *  @file   arctk/log/warning.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Warning log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_WARNING_HPP
#define ARCTK_LOG_WARNING_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <sstream>

//  -- Arctk --
#include <arctk/log/ansi.hpp>
#include <arctk/log/term.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         */
        class Warning : public std::stringstream
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
        //  -- Destructors --
        /**
         *  Write the contents of the stream to the terminal.
         */
        inline Warning::~Warning() noexcept
        {
            *this << ANSI.reset << '\n';

            Logger::instance().cout(str());
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_WARNING_HPP
