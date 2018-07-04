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
#include <array>
#include <iomanip>
#include <iostream>
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
            template <typename T, typename>
            inline std::string from(const T val_, const bool /*unused*/ = false) noexcept;
            template <typename T, typename S>
            inline std::string from(const std::pair<T, S>& pair_, const bool limiters_ = true) noexcept;
            template <typename T>
            inline std::string from(const std::vector<T>& vec_, const bool limiters_ = true) noexcept;
            template <typename T, size_t N>
            inline std::string from(const std::array<T, N>& arr_, const bool limiters_ = true) noexcept;



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
                          << "String: '" << str_ << "' can not be parsed to type: '" << typeid(bool).name() << "'.\n";

                std::exit(exit::error::FAILED_PARSE);
            }

            template <typename T, typename S>
            inline std::pair<T, S> to(const std::string& str_0_, const std::string& str_1_) noexcept
            {
                return (std::make_pair(to<T>(str_0_), to<S>(str_1_)));
            }

            /**
             *  Parse a string to a tuple of values.
             *
             *  @tparam A   Types to parse.
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
            template <typename T, typename = std::enable_if_t<std::is_fundamental<T>::value>>
            inline std::string from(const T val_, const bool /*unused*/) noexcept
            {
                std::stringstream stream;

                stream << val_;

                return (stream.str());
            }

            template <typename T, typename S>
            inline std::string from(const std::pair<T, S>& pair_, const bool limiters_) noexcept
            {
                std::stringstream stream;

                if (limiters_)
                {
                    stream << settings::format::PAIR_START;
                }

                stream << std::setw(settings::format::PRINT_WIDTH) << from(pair_.first, limiters_) << settings::format::DELIMITER << std::setw(settings::format::PRINT_WIDTH) << from(pair_.second, limiters_);

                if (limiters_)
                {
                    stream << settings::format::PAIR_END;
                }

                return (stream.str());
            }

            template <typename T>
            inline std::string from(const std::vector<T>& vec_, const bool limiters_) noexcept
            {
                std::stringstream stream;

                if (limiters_)
                {
                    stream << settings::format::VECTOR_START;
                }

                for (size_t i = 0; i < vec_.size(); ++i)
                {
                    if (i != 0)
                    {
                        stream << settings::format::DELIMITER;
                    }

                    stream << std::setw(settings::format::PRINT_WIDTH) << from(vec_[i], limiters_);
                }

                if (limiters_)
                {
                    stream << settings::format::VECTOR_END;
                }

                return (stream.str());
            }

            template <typename T, size_t N>
            inline std::string from(const std::array<T, N>& arr_, const bool limiters_) noexcept
            {
                std::stringstream stream;

                if (limiters_)
                {
                    stream << settings::format::ARRAY_START;
                }

                for (size_t i = 0; i < N; ++i)
                {
                    if (i != 0)
                    {
                        stream << settings::format::DELIMITER;
                    }

                    stream << std::setw(settings::format::PRINT_WIDTH) << from(arr_[i], limiters_);
                }

                if (limiters_)
                {
                    stream << settings::format::ARRAY_END;
                }

                return (stream.str());
            }



        } // namespace parse
    }     // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_PARSE_HPP
