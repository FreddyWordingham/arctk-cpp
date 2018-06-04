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
#include <vector>

//  -- Arctk --
#include <arctk/log.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Parsing --
        template <typename T>
        inline T string(const std::string& str_) noexcept;
        template <typename... A>
        inline std::tuple<A...> string(const std::vector<std::string>& str_) noexcept;
        template <typename... A, size_t... I>
        inline std::tuple<A...> string_helper(const std::vector<std::string>& str_, std::tuple<A...>& tup_, std::index_sequence<I...>) noexcept;



        //  == FUNCTIONS ==
        //  -- Parsing --
        /**
         *  Parse a value from a string.
         *  Function will call error on failed parsing.
         *  Function will call error if characters remain after parsing.
         *
         *  @param  str_    String to parse.
         *
         *  @return Parsed value.
         */
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

        template <typename... A>
        inline std::tuple<A...> string(const std::vector<std::string>& str_) noexcept
        {
            assert(str_.size() == sizeof...(A));


            std::tuple<A...> tup;
            string_helper(str_, tup, std::index_sequence_for<A...>());

            return (tup);
        }

        template <typename... A, size_t... I>
        inline std::tuple<A...> string_helper(const std::vector<std::string>& str_, std::tuple<A...>& tup_, std::index_sequence<I...>) noexcept
        {
            ((std::get<I>(tup_) = string<A>(str_[I])), ...);

            return (tup_);
        }



    } // namespace parse
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PARSE_STRING_HPP
