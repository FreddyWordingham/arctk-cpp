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
#include <algorithm>
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
        inline bool parsable_from_str(const std::string& str_) noexcept;

        template <typename T>
        inline T from_str(const std::string& str_) noexcept;
        template <typename... A>
        inline std::tuple<A...> from_str(const std::vector<std::string>& str_) noexcept;
        template <typename... A, size_t... I>
        inline std::tuple<A...> from_str_helper(const std::vector<std::string>& str_, std::tuple<A...>& tup_, std::index_sequence<I...> /*unused*/) noexcept;



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
        inline bool parsable_from_str(const std::string& str_) noexcept
        {
            std::stringstream stream;
            stream << str_;

            T x{};
            stream >> x;

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
        inline bool parsable_from_str<bool>(const std::string& str_) noexcept
        {
            std::string str = str_;
            std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });

            if (str == "false")
            {
                return (true);
            }

            if (str == "true")
            {
                return (true);
            }

            return (false);
        }

        /**
         *  Parse a value from a string.
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
        inline T from_str(const std::string& str_) noexcept
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

        /**
         *  Parse a boolean value from a string.
         *  Function will call error on failed parsing.
         *  Function will call error if characters remain after parsing.
         *
         *  @param  str_    String to parse.
         *
         *  @return Parsed boolean value.
         */
        template <>
        inline bool from_str(const std::string& str_) noexcept
        {
            std::string str = str_;
            std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });

            if (str == "false")
            {
                return (false);
            }

            if (str == "true")
            {
                return (true);
            }

            ERROR(42) << "Unable to parse string to type.\n"
                      << "String: '" << str << "' contains leftover characters after parsing to type: '" << typeid(bool).name() << "'.";
        }

        /**
         *  Parse a vector of strings into a tuple.
         *
         *  @tparam A   Types to parse.
         *
         *  @param  str_    Vector of strings to parse into tuple types.
         *
         *  @return Parsed tuple of values.
         */
        template <typename... A>
        inline std::tuple<A...> from_str(const std::vector<std::string>& str_) noexcept
        {
            assert(str_.size() == sizeof...(A));

            std::tuple<A...> tup;
            from_str_helper(str_, tup, std::index_sequence_for<A...>());

            return (tup);
        }

        /**
         *  String tuple helper function.
         *  Required for constexpr index sequence generation.
         *
         *  @param  str_    Vector of strings to parse into tuple types.
         *  @param  tup_    Tuple to initialise.
         *
         *  @return Tuple of initialised values.
         */
        template <typename... A, size_t... I>
        inline std::tuple<A...> from_str_helper(const std::vector<std::string>& str_, std::tuple<A...>& tup_, std::index_sequence<I...> /*unused*/) noexcept
        {
            ((std::get<I>(tup_) = from_str<A>(str_[I])), ...);

            return (tup_);
        }



    } // namespace parse
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PARSE_STRING_HPP
