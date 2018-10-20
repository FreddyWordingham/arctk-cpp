/**
 *  @file   arctk/io/input.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Input functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_INPUT_HPP
#define ARCTK_IO_INPUT_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cassert>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/exit.hpp>
#include <arctk/index.hpp>
#include <arctk/io/format.hpp>
#include <arctk/math.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {
        namespace input //! input namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Pre-processing --
            inline void                     filter_comments(std::string* str_) noexcept;
            inline void                     filter_whitespace(std::string* str_) noexcept;
            inline void                     extract_contents(std::string* str_, consts::format::container type_) noexcept;
            inline std::vector<std::string> tokenise(const std::string& str_) noexcept;

            //  -- Parsing --
            template <typename T>
            inline T parse(utl::Tag<T> /*unused*/, std::string* str_) noexcept;
            template <>
            inline bool parse(utl::Tag<bool> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline std::vector<T> parse(utl::Tag<std::vector<T>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline std::array<T, N> parse(utl::Tag<std::array<T, N>> /*unused*/, std::string* str_) noexcept;
            template <>
            inline std::string parse(utl::Tag<std::string> /*unused*/, std::string* str_) noexcept;
            template <typename T, typename S>
            inline std::pair<T, S> parse(utl::Tag<std::pair<T, S>> /*unused*/, std::string* str_) noexcept;
            template <typename... A>
            inline std::tuple<A...> parse(utl::Tag<std::tuple<A...>> /*unused*/, std::string* str_) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> parse_helper(utl::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* tokens_, const std::index_sequence<I...>& /*unused*/) noexcept;
            template <typename T, typename S>
            inline std::map<T, S> parse(utl::Tag<std::map<T, S>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 2> parse(utl::Tag<math::Vec<T, 2>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 3> parse(utl::Tag<math::Vec<T, 3>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 4> parse(utl::Tag<math::Vec<T, 4>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline math::Vec<T, N> parse(utl::Tag<math::Vec<T, N>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 2> parse(utl::Tag<math::Mat<T, 2>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 3> parse(utl::Tag<math::Mat<T, 3>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 4> parse(utl::Tag<math::Mat<T, 4>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline math::Mat<T, N> parse(utl::Tag<math::Mat<T, N>> /*unused*/, std::string* str_) noexcept;



            //  == FUNCTIONS ==
            //  -- Pre-processing --
            /**
             *  Filter the comments from a given string.
             *
             *  @param  str_    String to be filtered.
             *
             *  @pre    str_ may not be nullptr.
             */
            inline void filter_comments(std::string* const str_) noexcept // NOLINT
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == consts::format::OPENERS[consts::format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(consts::format::CLOSERS[consts::format::container::STRING], i + 1);

                        if (string_container_end_pos == std::string::npos)
                        {
                            std::cerr << "Unable to parse string.\n"
                                      << "String contains string opener but does not contain a corresponding closer.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        i = string_container_end_pos;
                    }
                    else if (str_ref[i] == consts::format::COMMENT)
                    {
                        size_t j;
                        for (j = i; j < str_ref.size(); ++j)
                        {
                            if (str_ref[j] == consts::format::OPENERS[consts::format::container::STRING])
                            {
                                const size_t string_container_end_pos = str_ref.find_first_of(consts::format::CLOSERS[consts::format::container::STRING], j + 1);

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

            /**
             *  Filter the whitespace from a given string.
             *
             *  @param  str_    String to be filtered.
             *
             *  @pre    str_ may not be nullptr.
             */
            inline void filter_whitespace(std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == consts::format::OPENERS[consts::format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(consts::format::CLOSERS[consts::format::container::STRING], i + 1);

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
                        for (size_t j = 0; j < consts::format::WHITESPACE.size(); ++j)
                        {
                            if (str_ref[i] == consts::format::WHITESPACE[j])
                            {
                                str_ref.erase(i, 1);
                                --i;

                                break;
                            }
                        }
                    }
                }
            }

            /**
             *  Extracted the contents of a string container.
             *
             *  @param  str_    String to be filtered.
             *  @param  type_   Container type contained within the string.
             *
             *  @pre    str_ may not be nullptr.
             */
            inline void extract_contents(std::string* const str_, const consts::format::container type_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                const size_t open = str_ref.find_first_of(consts::format::OPENERS[type_]);
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

                const size_t close = str_ref.find_last_of(consts::format::CLOSERS[type_]);
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

            /**
             *  Split a given string into a vector of token strings which are delimited using the set character.
             *
             *  @param  str_    String to be tokenised.
             *
             *  @return Vector of string tokens.
             */
            inline std::vector<std::string> tokenise(const std::string& str_) noexcept
            {
                std::vector<std::string> tokens;

                size_t prev_delim = 0;
                for (size_t i = 0; i < str_.size(); ++i)
                {
                    if (str_[i] == consts::format::DELIM)
                    {
                        tokens.emplace_back(str_.substr(prev_delim, i - prev_delim));
                        prev_delim = i + 1;
                    }
                    else
                    {
                        for (size_t j = 0; j < consts::format::OPENERS.size(); ++j)
                        {
                            if (str_[i] == consts::format::OPENERS[j])
                            {
                                i = str_.find_first_of(consts::format::CLOSERS[j], i + 1);

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
                tokens.emplace_back(str_.substr(prev_delim, str_.size()));

                return (tokens);
            }


            //  -- Parsing --
            /**
             *  Parse a given string to a fundamental type.
             *
             *  @tparam T   Type to be parsed into.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    T must be a fundamental type.
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed type.
             */
            template <typename T>
            inline T parse(utl::Tag<T> /*unused*/, std::string* const str_) noexcept
            {
                static_assert(std::is_fundamental<T>::value);

                assert(str_ != nullptr);

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

            /**
             *  Parse a given string to a boolean type.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed boolean.
             */
            template <>
            inline bool parse(utl::Tag<bool> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

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

            /**
             *  Parse a given string to a vector type.
             *
             *  @tparam T   Type stored by the vector.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed vector.
             */
            template <typename T>
            inline std::vector<T> parse(utl::Tag<std::vector<T>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::VECTOR);
                std::vector<std::string> tokens = tokenise(str_ref);

                std::vector<T> vec;
                vec.reserve(tokens.size());
                for (size_t i = 0; i < tokens.size(); ++i)
                {
                    vec.emplace_back(parse(utl::Tag<T>(), &tokens[i]));
                }

                return (vec);
            }

            /**
             *  Parse a given string to a array type.
             *
             *  @tparam T   Type stored by the array.
             *  @tparam N   Size of the array.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed array.
             */
            template <typename T, size_t N>
            inline std::array<T, N> parse(utl::Tag<std::array<T, N>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::ARRAY);
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

            /**
             *  Parse a given string to a string type.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed string.
             */
            template <>
            inline std::string parse(utl::Tag<std::string> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::STRING);

                return (str_ref);
            }

            /**
             *  Parse a given string to a pair type.
             *
             *  @tparam T   First type stored by the pair.
             *  @tparam S   Second type stored by the pair.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed pair.
             */
            template <typename T, typename S>
            inline std::pair<T, S> parse(utl::Tag<std::pair<T, S>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::PAIR);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 2)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to pair type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly two are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (std::make_pair<T, S>(parse(utl::Tag<T>(), &tokens[0]), parse(utl::Tag<S>(), &tokens[1])));
            }

            /**
             *  Parse a given string to a tuple type.
             *
             *  @tparam A   Types stored by the tuple.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed tuple.
             */
            template <typename... A>
            inline std::tuple<A...> parse(utl::Tag<std::tuple<A...>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::TUPLE);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != sizeof...(A))
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to tuple type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly: '" << sizeof...(A) << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (parse_helper(utl::Tag<std::tuple<A...>>(), &tokens, std::index_sequence_for<A...>()));
            }

            /**
             *  Helper function to parse a given string to a tuple type.
             *
             *  @tparam A   Types stored by the tuple.
             *
             *  @param  tokens_ Vector of string tokens to be parsed.
             *
             *  @pre    tokens_ may not be nullptr.
             *  @pre    sizeof...(A) must equal tokens_->size.
             *  @pre    sizeof...(A) must equal sizeof...(I).
             *
             *  @return Parsed tuple.
             */
            template <typename... A, size_t... I>
            inline std::tuple<A...> parse_helper(utl::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* const tokens_, const std::index_sequence<I...>& /*unused*/) noexcept
            {
                assert(tokens_ != nullptr);
                assert(sizeof...(A) == tokens_->size());
                assert(sizeof...(A) == sizeof...(I));

                std::vector<std::string>& tokens_ref = *tokens_;

                std::tuple<A...> tup;
                ((std::get<I>(tup) = parse(utl::Tag<A>(), &tokens_ref[I])), ...);

                return (tup);
            }

            /**
             *  Parse a given string to a map type.
             *
             *  @tparam T   Type used to store map keys.
             *  @tparam S   Type used to store map values.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed map.
             */
            template <typename T, typename S>
            inline std::map<T, S> parse(utl::Tag<std::map<T, S>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::MAP);
                std::vector<std::string> tokens = tokenise(str_ref);

                std::map<T, S> map;
                for (size_t i = 0; i < tokens.size(); ++i)
                {
                    map.emplace(parse(utl::Tag<std::pair<T, S>>(), &tokens[i]));
                }

                return (map);
            }

            /**
             *  Parse a given string to a two-dimensional vec type.
             *
             *  @tparam T   Type stored by the vec.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed vec.
             */
            template <typename T>
            inline math::Vec<T, 2> parse(utl::Tag<math::Vec<T, 2>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 2)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vec2 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly two are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Vec<T, 2>(parse(utl::Tag<T>(), &tokens[index::dim::cartesian::X]), parse(utl::Tag<T>(), &tokens[index::dim::cartesian::Y])));
            }

            /**
             *  Parse a given string to a three-dimensional vec type.
             *
             *  @tparam T   Type stored by the vec.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed vec.
             */
            template <typename T>
            inline math::Vec<T, 3> parse(utl::Tag<math::Vec<T, 3>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 3)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vec3 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly three are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Vec<T, 3>(parse(utl::Tag<T>(), &tokens[index::dim::cartesian::X]), parse(utl::Tag<T>(), &tokens[index::dim::cartesian::Y]), parse(utl::Tag<T>(), &tokens[index::dim::cartesian::Z])));
            }

            /**
             *  Parse a given string to a four-dimensional vec type.
             *
             *  @tparam T   Type stored by the vec.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed vec.
             */
            template <typename T>
            inline math::Vec<T, 4> parse(utl::Tag<math::Vec<T, 4>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 4)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vec4 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly four are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Vec<T, 4>(parse(utl::Tag<T>(), &tokens[index::dim::cartesian::X]), parse(utl::Tag<T>(), &tokens[index::dim::cartesian::Y]), parse(utl::Tag<T>(), &tokens[index::dim::cartesian::Z]), parse(utl::Tag<T>(), &tokens[3])));
            }

            /**
             *  Parse a given string to an n-dimensional vec type.
             *
             *  @tparam T   Type stored by the vec.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed vec.
             */
            template <typename T, size_t N>
            inline math::Vec<T, N> parse(utl::Tag<math::Vec<T, N>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != N)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vecN type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly '" << N << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                math::Vec<T, N> vec;
                for (size_t i = 0; i < N; ++i)
                {
                    vec[i] = parse(utl::Tag<T>(), &tokens[i]);
                }

                return (vec);
            }

            /**
             *  Parse a given string to a two-by-two mat type.
             *
             *  @tparam T   Type stored by the mat.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed mat.
             */
            template <typename T>
            inline math::Mat<T, 2> parse(utl::Tag<math::Mat<T, 2>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 2)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to mat2 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly two are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Mat<T, 2>(parse(utl::Tag<math::Vec<T, 2>>(), &tokens[index::dim::cartesian::X]), parse(utl::Tag<math::Vec<T, 2>>(), &tokens[index::dim::cartesian::Y])));
            }

            /**
             *  Parse a given string to a three-by-three mat type.
             *
             *  @tparam T   Type stored by the mat.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed mat.
             */
            template <typename T>
            inline math::Mat<T, 3> parse(utl::Tag<math::Mat<T, 3>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 3)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to mat3 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly three are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Mat<T, 3>(parse(utl::Tag<math::Vec<T, 3>>(), &tokens[index::dim::cartesian::X]), parse(utl::Tag<math::Vec<T, 3>>(), &tokens[index::dim::cartesian::Y]), parse(utl::Tag<math::Vec<T, 3>>(), &tokens[index::dim::cartesian::Z])));
            }

            /**
             *  Parse a given string to a four-by-four mat type.
             *
             *  @tparam T   Type stored by the mat.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed mat.
             */
            template <typename T>
            inline math::Mat<T, 4> parse(utl::Tag<math::Mat<T, 4>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != 4)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to mat4 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly four are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Mat<T, 4>(parse(utl::Tag<math::Vec<T, 4>>(), &tokens[index::dim::cartesian::X]), parse(utl::Tag<math::Vec<T, 4>>(), &tokens[index::dim::cartesian::Y]), parse(utl::Tag<math::Vec<T, 4>>(), &tokens[index::dim::cartesian::Z]),
                                        parse(utl::Tag<math::Vec<T, 4>>(), &tokens[3])));
            }

            /**
             *  Parse a given string to a n-by-n mat type.
             *
             *  @tparam T   Type stored by the mat.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed mat.
             */
            template <typename T, size_t N>
            inline math::Mat<T, N> parse(utl::Tag<math::Mat<T, N>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = tokenise(str_ref);

                if (tokens.size() != N)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to matN type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly '" << N << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                math::Mat<T, N> mat;
                for (size_t i = 0; i < N; ++i)
                {
                    mat[i] = parse(utl::Tag<math::Vec<T, N>>(), &tokens[i]);
                }

                return (mat);
            }



        } // namespace input
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_INPUT_HPP
