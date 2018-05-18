/**
 *  @file   arctk/utl/string.hpp
 *  @date   17/05/2018
 *  @author Freddy Wordingham
 *
 *  String utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_STRING_HPP
#define ARCTK_UTL_STRING_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/utl/char.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        template <class T>
        inline bool parsable(const std::string& str_) noexcept;
        inline bool numerical(const std::string& str_) noexcept;
        inline bool whitespace(const std::string& str_) noexcept;
        inline bool glyph(const std::string& str_) noexcept;

        //  -- Filtering --
        inline void remove(std::string* str_, char ch_) noexcept;
        inline void remove(std::string* str_, const std::string& sub_) noexcept;
        inline void remove_blank_lines(std::string* str_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if a given string can be converted to a given type.
         *
         *  @tparam T   Type to convert the string to.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string can be converted to the given type.
         */
        template <class T>
        inline bool parsable(const std::string& str_) noexcept
        {
            T                 result;
            std::stringstream stream{str_};

            stream >> result;
            stream >> std::ws;

            return (!stream.fail() && stream.eof());
        }

        /**
         *  Determine if a given string can be converted to an arithmetic type.
         *  If the string can be converted to a double, then it can be converted to any arithmetic type.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string can be converted to an arithmetic type.
         */
        inline bool numerical(const std::string& str_) noexcept
        {
            return (parsable<double>(str_));
        }

        /**
         *  Determine if a given string contains only whitespace characters.
         *
         *  @pre    str_ must not be empty.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string contains only whitespace characters.
         */
        inline bool whitespace(const std::string& str_) noexcept
        {
            assert(!str_.empty());

            return (str_.find_first_not_of(WHITESPACE_CHARS) == std::string::npos);
        }

        /**
         *  Determine if a given string contains only glyph characters and is not numerical.
         *
         *  @pre    str_ must not be empty.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string contains only glyph characters and is not numerical.
         */
        inline bool glyph(const std::string& str_) noexcept
        {
            assert(!str_.empty());

            return ((str_.find_first_not_of(GLYPH_CHARS) == std::string::npos) && !numerical(str_));
        }


        //  -- Filtering --
        /**
         *  Remove all instances of a character from a string.
         *
         *  @param  str_    String to be filtered.
         *  @param  ch_     Character to be removed from the string.
         */
        inline void remove(std::string* const str_, const char ch_) noexcept
        {
            str_->erase(std::remove(str_->begin(), str_->end(), ch_), str_->end());
        }

        /**
         *  Remove all instances of a sub-string from a string.
         *
         *  @pre    sub_ must not be empty.
         *
         *  @param  str_    String to be filtered.
         *  @param  sub_    Sub-string to be removed from the string.
         */
        inline void remove(std::string* const str_, const std::string& sub_) noexcept
        {
            assert(!sub_.empty());

            replace(str_, sub_, "");
        }

        /**
         *  Remove all blank lines from a string.
         *
         *  @param  str_    String to be filtered.
         */
        inline void remove_blank_lines(std::string* str_) noexcept
        {
            str_->erase(std::unique(str_->begin(), str_->end(), [](const char first_, const char second_) { return ((first_ == '\n') && (second_ == '\n')); }), str_->end());
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_STRING_HPP
