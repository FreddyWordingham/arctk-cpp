/**
 *  @file   arctk/parse/string.hpp
 *  @date   04/06/2018
 *  @author Freddy Wordingham
 *
 *  String parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_STRING_HPP
#define ARCTK_PARSE_STRING_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <sstream>
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Parsing --
        template <typename T>
        inline T string(const std::string& str_) noexcept;



        //  == FUNCTIONS ==
        //  -- Parsing --
        template <typename T>
        inline T string(const std::string& str_) noexcept
        {
            std::stringstream stream;
            stream << str_;

            T x{};
            stream >> x;

            if (stream.fail())
            {
                ERROR(42) << "Unable to parse string: '" << str_ << "' to type.\n"
                          << "String: '" << str_ << "' can not be parsed to type: '" << typeid(T).name() << "'.";
            }

            if (stream.rdbuf()->in_avail() != 0)
            {
                ERROR(42) << "Unable to parse string to type.\n"
                          << "String: '" << str_ << "' contains leftover characters after parsing to type: '" << typeid(T).name() << "'.";
            }

            return (x);
        }



    } // namespace parse
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PARSE_STRING_HPP
