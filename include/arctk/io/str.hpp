/**
 *  @file   arctk/io/str.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  String input/output functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_READ_HPP
#define ARCTK_IO_READ_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/exit.hpp>
#include <arctk/io/format.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {
        namespace str //! string namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Pre-processing --
            inline void                     filter_comments(std::string* const str_) noexcept;
            inline void                     filter_whitespace(std::string* const str_) noexcept;
            inline void                     extract_contents(std::string* const str_, const format::container type_) noexcept;
            inline std::vector<std::string> tokenise(const std::string& str_) noexcept;

            //  -- Parsing --
            template <typename T>
            inline T parse(utl::Tag<T> /*unused*/, std::string* const str_) noexcept;
            template <>
            inline bool parse(utl::Tag<bool> /*unused*/, std::string* const str_) noexcept;
            template <typename T>
            inline std::vector<T> parse(utl::Tag<std::vector<T>> /*unused*/, std::string* const str_) noexcept;
            template <typename T, size_t N>
            inline std::array<T, N> parse(utl::Tag<std::array<T, N>> /*unused*/, std::string* const str_) noexcept;
            template <>
            inline std::string parse(utl::Tag<std::string> /*unused*/, std::string* const str_) noexcept;
            template <typename T, typename S>
            inline std::pair<T, S> parse(utl::Tag<std::pair<T, S>> /*unused*/, std::string* const str_) noexcept;
            template <typename... A>
            inline std::tuple<A...> parse(utl::Tag<std::tuple<A...>> /*unused*/, std::string* const str_) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> parse_helper(utl::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* const tokens_, const std::index_sequence<I...>& /*unused*/) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> parse_helper(utl::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* const tokens_, const std::index_sequence<I...>& /*unused*/) noexcept;



            //  == FUNCTIONS ==
            //  -- Pre-processing --
            inline void filter_comments(std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == format::OPENERS[format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(format::CLOSERS[format::container::STRING], i + 1);

                        if (string_container_end_pos == std::string::npos)
                        {
                            std::cerr << "Unable to parse string.\n"
                                      << "String contains string opener but does not contain a corresponding closer.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        i = string_container_end_pos;
                    }
                    else if (str_ref[i] == format::COMMENT)
                    {
                        size_t j;
                        for (j = i; j < str_ref.size(); ++j)
                        {
                            if (str_ref[j] == format::OPENERS[format::container::STRING])
                            {
                                const size_t string_container_end_pos = str_ref.find_first_of(format::CLOSERS[format::container::STRING], j + 1);

                                if (string_container_end_pos == std::string::npos)
                                {
                                    std::cerr << "Unable to parse string.\n"
                                              << "String contains string opener but does not contain a corresponding closer.\n";

                                    std::exit(exit::error::FAILED_PARSE);
                                }

                                j = string_container_end_pos;
                            }
                            else if (str_ref[j] == '\n')
                            {
                                break;
                            }
                        }

                        str_ref.erase(i, j - i);
                    }
                }
            }

            inline void filter_whitespace(std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == format::OPENERS[format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(format::CLOSERS[format::container::STRING], i + 1);

                        if (string_container_end_pos == std::string::npos)
                        {
                            std::cerr << "Unable to parse string.\n"
                                      << "String contains string opener but does not contain a corresponding closer.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        i = string_container_end_pos;
                    }
                    else
                    {
                        for (size_t j = 0; j < format::WHITESPACE.size(); ++j)
                        {
                            if (str_ref[i] == format::WHITESPACE[j])
                            {
                                str_ref.erase(i, 1);
                                --i;

                                break;
                            }
                        }
                    }
                }
            }

            inline void extract_contents(std::string* const str_, const format::container type_) noexcept
            {
                std::string& str_ref = *str_;

                const size_t open = str_ref.find_first_of(format::OPENERS[type_]);
                if (open == std::string::npos)
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Containter opener was not found.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                else if (open != 0)
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Additional characters found before container opener.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                str_ref.erase(open, 1);

                const size_t close = str_ref.find_last_of(format::CLOSERS[type_]);
                if (close == std::string::npos)
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Containter closer was not found.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                else if (close != (str_ref.size() - 1))
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Additional characters found after container closer.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                str_ref.erase(close, 1);
            }

            inline std::vector<std::string> tokenise(const std::string& str_) noexcept
            {
                std::vector<std::string> tokens;

                size_t prev_delim = 0;
                for (size_t i = 0; i < str_.size(); ++i)
                {
                    if (str_[i] == format::DELIM)
                    {
                        tokens.emplace_back(str_.substr(prev_delim, i - prev_delim));
                        prev_delim = i + 1;
                    }
                    else
                    {
                        for (size_t j = 0; j < format::OPENERS.size(); ++j)
                        {
                            if (str_[i] == format::OPENERS[j])
                            {
                                i = str_.find_first_of(format::CLOSERS[j], i + 1);

                                if (i == std::string::npos)
                                {
                                    std::cerr << "Error parsing container.\n"
                                              << "Corresponding container closer was not found.\n";

                                    std::exit(exit::error::FAILED_PARSE);
                                }

                                break;
                            }
                        }
                    }
                }
                tokens.emplace_back(str_.substr(prev_delim, str_.size() - 1));

                return (tokens);
            }


            //  -- Parsing --
            template <typename T>
            inline T parse(utl::Tag<T> /*unused*/, std::string* const str_) noexcept
            {
                static_assert(std::is_fundamental<T>::value);

                std::string& str_ref = *str_;

                std::stringstream stream;
                stream << str_ref;

                T val{};
                stream >> val;

                if (stream.fail())
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to type.\n"
                              << "String: '" << str_ref << "' can not be parsed to type: '" << typeid(T).name() << "'.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                if (stream.rdbuf()->in_avail() != 0)
                {
                    std::cerr << "Unable to parse string to type.\n"
                              << "String: '" << str_ref << "' contains leftover characters after parsing to type: '" << typeid(T).name() << "'.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (val);
            }

            template <>
            inline bool parse(utl::Tag<bool> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                if (str_ref == "0")
                {
                    return (false);
                }
                if (str_ref == "1")
                {
                    return (true);
                }

                std::transform(str_ref.begin(), str_ref.end(), str_ref.begin(), [](unsigned char c_) { return std::tolower(c_); });

                if (str_ref == "false")
                {
                    return (false);
                }
                if (str_ref == "true")
                {
                    return (true);
                }

                std::cerr << "Unable to parse string: '" << str_ref << "' to type.\n"
                          << "String: '" << str_ref << "' can not be parsed to type: '" << typeid(bool).name() << "'.\n";

                std::exit(exit::error::FAILED_PARSE);
            }

            template <typename T>
            inline std::vector<T> parse(utl::Tag<std::vector<T>> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                extract_contents(str_, format::container::VECTOR);
                std::vector<std::string> tokens = tokenise(str_ref);

                std::vector<T> vec;
                vec.reserve(tokens.size());
                for (size_t i = 0; i < tokens.size(); ++i)
                {
                    vec.emplace_back(parse(utl::Tag<T>(), &tokens[i]));
                }

                return (vec);
            }

            template <typename T, size_t N>
            inline std::array<T, N> parse(utl::Tag<std::array<T, N>> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                extract_contents(str_, format::container::ARRAY);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != N)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to array type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly '" << N << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                std::array<T, N> arr;
                for (size_t i = 0; i < N; ++i)
                {
                    arr[i] = parse(utl::Tag<T>(), &tokens[i]);
                }

                return (arr);
            }

            template <>
            inline std::string parse(utl::Tag<std::string> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                extract_contents(str_, format::container::STRING);

                return (str_ref);
            }

            template <typename T, typename S>
            inline std::pair<T, S> parse(utl::Tag<std::pair<T, S>> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                extract_contents(str_, format::container::PAIR);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 2)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to pair type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly two are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (std::make_pair<T, S>(parse(utl::Tag<T>(), &tokens[0]), parse(utl::Tag<S>(), &tokens[1])));
            }

            template <typename... A>
            inline std::tuple<A...> parse(utl::Tag<std::tuple<A...>> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                extract_contents(str_, format::container::TUPLE);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != sizeof...(A))
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to tuple type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly: '" << sizeof...(A) << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (parse_helper(utl::Tag<std::tuple<A...>>(), &tokens, std::index_sequence_for<A...>()));
            }

            template <typename... A, size_t... I>
            inline std::tuple<A...> parse_helper(utl::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* const tokens_, const std::index_sequence<I...>& /*unused*/) noexcept
            {
                std::vector<std::string>& tokens_ref = *tokens_;

                PRE(sizeof...(A) == tokens_ref.size());
                PRE(sizeof...(A) == sizeof...(I));

                std::tuple<A...> tup;
                ((std::get<I>(tup) = parse(utl::Tag<A>(), &tokens_ref[I])), ...);

                return (tup);
            }



        } // namespace str
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_READ_HPP
