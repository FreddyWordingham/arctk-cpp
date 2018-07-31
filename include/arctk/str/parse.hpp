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



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>
#include <arctk/settings.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {
        namespace parse //! parsing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- To --
            template <typename T>
            inline bool parsable_to(const std::string& str_) noexcept;
            template <typename T>
            inline T to(const std::string& str_) noexcept;
            template <typename T, typename S>
            inline std::pair<T, S> to(const std::string& str_0_, const std::string& str_1_) noexcept;
            template <typename... A>
            inline std::tuple<A...> to(const std::vector<std::string>& strs_) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> to_helper(const std::vector<std::string>& strs_, std::index_sequence<I...> /*unused*/) noexcept;

            //  -- From --
            inline std::string from(const std::string& str_, bool /*unused*/ = false) noexcept;
            template <typename T, typename>
            inline std::string from(T val_, bool /*unused*/ = false) noexcept;
            template <typename T, typename S>
            inline std::string from(const std::pair<T, S>& pair_, bool limiters_ = true) noexcept;
            template <typename... A>
            inline std::string from(const std::tuple<A...>& tup_, bool limiters_ = true) noexcept;
            template <typename... A, size_t... I>
            inline std::string from_helper(const std::tuple<A...>& tup_, bool limiters_, std::index_sequence<I...> /*unused*/) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline std::string from(const C& cont_, bool limiters_ = true) noexcept;

            //  -- File --
            inline std::string file(const std::string& path_) noexcept;



            //  == FUNCTIONS ==
            //  -- To --
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
            inline bool parsable_to(const std::string& str_) noexcept
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
            inline bool parsable_to<bool>(const std::string& str_) noexcept
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
                              << "String: '" << str_ << "' can not be parsed to type: '" << typeid(T).name() << "'.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                if (stream.rdbuf()->in_avail() != 0)
                {
                    std::cerr << "Unable to parse string to type.\n"
                              << "String: '" << str_ << "' contains leftover characters after parsing to type: '" << typeid(T).name() << "'.\n";

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
                if (str_ == "1")
                {
                    return (true);
                }

                std::string str = str_;
                std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c_) { return std::tolower(c_); });

                if (str == "false")
                {
                    return (false);
                }
                if (str == "true")
                {
                    return (true);
                }

                std::cerr << "Unable to parse string: '" << str_ << "' to type.\n"
                          << "String: '" << str_ << "' can not be parsed to type: '" << typeid(bool).name() << "'.\n";

                std::exit(exit::error::FAILED_PARSE);
            }

            /**
             *  Parse a string to a pair of values.
             *
             *  @tparam T   First type of the pair.
             *  @tparam S   Second type of the pair.
             *
             *  @param  str_0_  First string to parse.
             *  @param  str_1_  Second string to parse.
             *
             *  @return Parsed pair of values.
             */
            template <typename T, typename S>
            inline std::pair<T, S> to(const std::string& str_0_, const std::string& str_1_) noexcept
            {
                return (std::make_pair(to<T>(str_0_), to<S>(str_1_)));
            }

            /**
             *  Parse a string to a tuple of values.
             *
             *  @tparam A   Types stored by the tuple.
             *
             *  @param  strs_   Vector of string to parse.
             *
             *  @pre    strs_ size must equal the number of variadic types.
             *
             *  @return Parsed tuple of values.
             */
            template <typename... A>
            inline std::tuple<A...> to(const std::vector<std::string>& strs_) noexcept
            {
                PRE(strs_.size() == sizeof...(A));

                return (to_helper<A...>(strs_, std::index_sequence_for<A...>()));
            }

            /**
             *  Help parse a string to a tuple of values.
             *  Values are parsed from vector of strings and packed into tuple.
             *
             *  @tparam A   Types to parse.
             *  @tparam I   Index sequence of A.
             *
             *  @param  strs_   Vector of string to parse.
             *
             *  @pre    size of A must equal the size of I.
             *
             *  @return Parsed tuple of values.
             */
            template <typename... A, size_t... I>
            inline std::tuple<A...> to_helper(const std::vector<std::string>& strs_, std::index_sequence<I...> /*unused*/) noexcept
            {
                PRE(sizeof...(A) == sizeof...(I));

                std::tuple<A...> tup;
                ((std::get<I>(tup) = to<A>(strs_[I])), ...);

                return (tup);
            }


            //  -- From --
            /**
             *  Parse a string into a string object.
             *  This function is a passthrough and should only be used within template functions.
             *
             *  @param  str_    String to parse.
             *
             *  @return String parsed from the given string.
             */
            inline std::string from(const std::string& str_, const bool /*unused*/) noexcept
            {
                return (str_);
            }

            /**
             *  Parse a fundamental type into a string object.
             *
             *  @tparam T   Type to be parsed.
             *
             *  @param  val_    Primitive value to parse.
             *
             *  @return String parsed from the given value.
             */
            template <typename T, typename = std::enable_if_t<std::is_fundamental<T>::value>>
            inline std::string from(const T val_, const bool /*unused*/) noexcept
            {
                std::ostringstream stream;

                stream << val_;

                return (stream.str());
            }

            /**
             *  Parse a pair of values into a string object.
             *
             *  @tparam T   First type of the pair.
             *  @tparam S   Second type of the pair.
             *
             *  @param  pair_       Pair to parse.
             *  @param  limiters_   If true, print limiters.
             *
             *  @return String parsed from the given pair.
             */
            template <typename T, typename S>
            inline std::string from(const std::pair<T, S>& pair_, const bool limiters_) noexcept
            {
                std::ostringstream stream;

                if (limiters_)
                {
                    stream << settings::format::TUPLE_START;
                }

                stream << std::setw(settings::format::PRINT_WIDTH) << from(pair_.first, limiters_) << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << from(pair_.second, limiters_);

                if (limiters_)
                {
                    stream << settings::format::TUPLE_END;
                }

                return (stream.str());
            }

            /**
             *  Parse an empty tuple of values into a string object.
             *
             *  @param  limiters_   If true, print limiters.
             *
             *  @return String parsed from the given tuple.
             */
            template <>
            inline std::string from(const std::tuple<>& /*unused*/, const bool limiters_) noexcept
            {
                std::ostringstream stream;

                if (limiters_)
                {
                    stream << settings::format::TUPLE_START << settings::format::TUPLE_END;
                }

                return (stream.str());
            }

            /**
             *  Parse an occupied tuple of values into a string object.
             *
             *  @tparam A   Types stored by the tuple.
             *
             *  @param  tup_        Tuple to parse.
             *  @param  limiters_   If true, print limiters.
             *
             *  @return String parsed from the given tuple.
             */
            template <typename... A>
            inline std::string from(const std::tuple<A...>& tup_, const bool limiters_) noexcept
            {
                return (from_helper(tup_, limiters_, std::make_index_sequence<sizeof...(A) - 1>()));
            }

            /**
             *  Parse an occupied tuple of values into a string object helper function.
             *
             *  @tparam A   Types stored by the tuple.
             *  @tparam I   Index sequence of A.
             *
             *  @param  tup_        Tuple to parse.
             *  @param  limiters_   If true, print limiters.
             *
             *  @return String parsed from the given tuple.
             */
            template <typename... A, size_t... I>
            inline std::string from_helper(const std::tuple<A...>& tup_, const bool limiters_, std::index_sequence<I...> /*unused*/) noexcept
            {
                static_assert(sizeof...(A) > 0);

                std::ostringstream stream;

                if (limiters_)
                {
                    stream << settings::format::TUPLE_START;
                }

                stream << std::setw(settings::format::PRINT_WIDTH) << from(std::get<0>(tup_), limiters_);
                ((stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << from(std::get<I + 1>(tup_), limiters_)), ...);

                if (limiters_)
                {
                    stream << settings::format::TUPLE_END;
                }

                return (stream.str());
            }

            /**
             *  Parse a container into a string object.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_       Container to parse.
             *  @param  limiters_   If true, print limiters.
             *
             *  @return String parsed from the given container.
             */
            template <typename C, typename T, typename I>
            inline std::string from(const C& cont_, bool limiters_) noexcept
            {
                std::ostringstream stream;

                if (limiters_)
                {
                    stream << settings::format::CONTAINER_START;
                }

                if (!cont_.empty())
                {
                    stream << std::setw(settings::format::PRINT_WIDTH) << from(*std::begin(cont_), limiters_);
                    for (I it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
                    {
                        stream << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << from(*it, limiters_);
                    }
                }

                if (limiters_)
                {
                    stream << settings::format::CONTAINER_END;
                }

                return (stream.str());
            }


            //  -- File --
            /**
             *  Parse the contents of a file into a string.
             *
             *  @param  path_   Path to the file to parse.
             *
             *  @pre    path_ may not be empty.
             *
             *  @return String of the file's contents.
             */
            inline std::string file(const std::string& path_) noexcept
            {
                PRE(!path_.empty());

                std::ifstream file(path_);

                if (!file.is_open())
                {
                    std::cerr << "Unable to parse contents of file.\n"
                              << "Unable to open file: `" << path_ << "`.\n";

                    std::exit(exit::error::FILE_OPEN_FAILED);
                }

                std::string str;

                file.seekg(0, std::ios::end);
                str.reserve(static_cast<size_t>(file.tellg()));
                file.seekg(0, std::ios::beg);

                str.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

                return (str);
            }



        } // namespace parse
    }     // namespace str
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_STR_PARSE_HPP
