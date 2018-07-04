/**
 *  @file   arctk/str/parse.hpp
 *  @date   04/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of string parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_STR_PARSE_HPP
#define ARCTK_STR_PARSE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <iostream>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {
        namespace parse //! parsing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Parsing --
            template <typename T>
            inline bool parsable(const std::string& str_) noexcept;
            template <typename T>
            inline T from(const std::string& str_) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> from(const std::vector<std::string>& strs_) noexcept
            {
                PRE(strs_.size() == sizeof...(A));

                std::tuple<A...>          tup;
                std::index_sequence<I...> seq = std::index_sequence_for<A...>();

                ((std::get<I>(tup) = from<A>(strs_[I])), ...);

                return (tup);
            }



            //  == FUNCTIONS ==
            //  -- Parsing --
            template <typename T>
            inline bool parsable(const std::string& str_) noexcept
            {
                std::stringstream stream;
                stream << str_;

                T val{};
                stream >> val;

                if (stream.fail())
                {
                    return (false);
                }

                if (stream.rdbuf()->in_avail() != 0)
                {
                    return (false);
                }

                return (true);
            }

            template <>
            inline bool parsable<bool>(const std::string& str_) noexcept
            {
                std::string str = str_;
                std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c_) { return std::tolower(c_); });

                if ((str == "false") || (str == "true"))
                {
                    return (true);
                }

                return (false);
            }

            template <typename T>
            inline T from(const std::string& str_) noexcept
            {
                std::stringstream stream;
                stream << str_;

                T val{};
                stream >> val;

                if (stream.fail())
                {
                    std::cerr << "Unable to parse string: '" << str_ << "' to type.\n"
                              << "String: '" << str_ << "' can not be parsed to type: '" << typeid(T).name() << "'.";

                    std::exit(exit::error::FAILED_PARSE);
                }

                if (stream.rdbuf()->in_avail() != 0)
                {
                    std::cerr << "Unable to parse string to type.\n"
                              << "String: '" << str_ << "' contains leftover characters after parsing to type: '" << typeid(T).name() << "'.";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (val);
            }



        } // namespace parse
    }     // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_PARSE_HPP
