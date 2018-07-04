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
            inline T to(const std::string& str_) noexcept;
            template <typename... A>
            inline std::tuple<A...> to(const std::vector<std::string>& strs_) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> to_helper(const std::vector<std::string>& strs_, std::index_sequence<I...> /*unused*/) noexcept;



            //  == FUNCTIONS ==
            //  -- Parsing --
            /**
             *  Determine if a string is parsable into a type.
             *
             *  @tparam T   Type to parse into.
             *
             *  @param  str_    String to parse.
             *
             *  @return True if the string is parsable into the type.
             */
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

            /**
             *  Determine if a string is parsable into a boolean type.
             *
             *  @param  str_    String to parse.
             *
             *  @return True if the string is parsable into the boolean type.
             */
            template <>
            inline bool parsable<bool>(const std::string& str_) noexcept
            {
                if ((str_ == "0") || (str_ == "1"))
                {
                    return (true);
                }

                std::string str = str_;
                std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c_) { return std::tolower(c_); });

                if ((str == "false") || (str == "true"))
                {
                    return (true);
                }

                return (false);
            }

            /**
             *  Parse a string to a value.
             *  Function will call error on failed parsing.
             *  Function will call error if characters remain after parsing.
             *
             *  @tparam T   Type to parse.
             *
             *  @param  str_    String to parse.
             *
             *  @return Parsed value.
             */
            template <typename T>
            inline T to(const std::string& str_) noexcept
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

            /**
             *  Parse a string to a boolean value.
             *  Function will call error on failed parsing.
             *  Function will call error if characters remain after parsing.
             *
             *  @param  str_    String to parse.
             *
             *  @return Parsed boolean value.
             */
            template <>
            inline bool to<bool>(const std::string& str_) noexcept
            {
                if (str_ == "0")
                {
                    return (false);
                }
                else if (str_ == "1")
                {
                    return (true);
                }

                std::string str = str_;
                std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c_) { return std::tolower(c_); });

                if (str == "false")
                {
                    return (false);
                }
                else if (str == "true")
                {
                    return (true);
                }

                std::cerr << "Unable to parse string: '" << str_ << "' to type.\n"
                          << "String: '" << str_ << "' can not be parsed to type: '" << typeid(bool).name() << "'.";

                std::exit(exit::error::FAILED_PARSE);
            }

            template <typename... A>
            inline std::tuple<A...> to(const std::vector<std::string>& strs_) noexcept
            {
                PRE(strs_.size() == sizeof...(A));

                return (to_helper<A...>(strs_, std::index_sequence_for<A...>()));
            }

            template <typename... A, size_t... I>
            inline std::tuple<A...> to_helper(const std::vector<std::string>& strs_, std::index_sequence<I...> /*unused*/) noexcept
            {
                std::tuple<A...> tup;
                ((std::get<I>(tup) = to<A>(strs_[I])), ...);

                return (tup);
            }



        } // namespace parse
    }     // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_PARSE_HPP
