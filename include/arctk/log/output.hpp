/**
 *  @file   arctk/log/output.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Console output logging class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_HPP
#define ARCTK_LOG_OUTPUT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cassert>
#include <sstream>

#include <arctk/log/term.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         *  Console output logging class.
         *  Will print contents of stream to console output upon destruction.
         */
        class Output : public std::stringstream
        {
            //  == FIELDS ==
          private:
            //  -- Colour --
            static std::string _col;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Output() noexcept;
            inline Output(const std::string& file_, const std::string& func_, int line_) noexcept;
            inline Output(const Output&) = delete; //!< Deleted copy constructor.
            inline Output(Output&&)      = delete; //!< Deleted move constructor.

            //  -- Destructors --
            inline ~Output() noexcept override;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Output& operator=(const Output&) = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Output& operator=(Output&&) = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
            //  -- Getters --
            inline void Warning::set_col(const std::string& col_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a stream object which, when destructed, will write its contents to console output.
         *  Boolean values are printed as words.
         */
        inline Output::Output() noexcept
        {
            *this << std::boolalpha;
        }

        /**
         *  Construct a stream object which, when destructed, will write its contents to console output.
         *  Boolean values are printed as words.
         *  If LOCATION is defined, then its value is used to colour the output location of the message instantiation.
         *
         *  @param  file_       File location of the message instantiation.
         *  @param  func_       Function location of the message instantiation.
         *  @param  line_       Line location of the message instantiation.
         *
         *  @pre    file_       must not be empty.
         *  @pre    func_       must not be empty.
         *  @pre    line_       must be greater than zero.
         */
        inline Output::Output(const std::string& file_, const std::string& func_, const int line_) noexcept
        {
            assert(!file_.empty());
            assert(!func_.empty());
            assert(line_ > 0);

            *this << std::boolalpha;

            *this << Term::instance().location_col() << file_ << " :: " << func_ << " :: " << line_ << Term::instance().reset() << "\n";
        }


        //  -- Destructors --
        /**
         *  Write contents to console output.
         */
        inline Output::~Output() noexcept
        {
            Term::instance().cout(str());
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Set the colouring string of this message type.
         *
         *  @param  col_    Colouring string.
         */
        inline void Output::set_col(const std::string& col_) noexcept
        {
            _col = col_;
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_HPP
