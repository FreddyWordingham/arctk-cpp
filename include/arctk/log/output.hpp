/**
 *  @file   arctk/log/cout.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Console output logging class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_COUT_HPP
#define ARCTK_LOG_COUT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cassert>
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
         *  Console output logging class.
         *  Will print contents of stream to std::cout upon destruction.
         */
        class Cout : public std::stringstream
        {
            //  == INSTANTIATION --
          public:
            //  -- Constructors --
            inline Cout(const std::string& file_, const std::string& func_, int line_) noexcept;
            inline Cout(const Cout&) = delete; //!< Deleted copy constructor.
            inline Cout(Cout&&)      = delete; //!< Deleted move constructor.

            //  -- Destructors --
            inline ~Cout() noexcept override;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Cout& operator=(const Cout&) = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Cout& operator=(Cout&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a stream object which, when destructed, will write its contents to the terminal.
         *  Boolean values are printed as words.
         *  If LOCATION is defined, then its value is used to colour the output location of the message instantiation.
         *
         *  @param  file_   File location of the message instantiation.
         *  @param  func_   Function location of the message instantiation.
         *  @param  line_   Line location of the message instantiation.
         *
         *  @pre    file_ must not be empty.
         *  @pre    func_ must not be empty.
         *  @pre    line_ must be greater than zero.
         */
        inline Cout::Cout(const std::string& file_, const std::string& func_, const int line_) noexcept
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



        //  -- Destructors --
        /**
         *  Write contents to console output.
         */
        inline Cout::~Cout() noexcept
        {
            Term::instance().cout(str());
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_COUT_HPP
