/**
 *  @file   arctk/parse/read.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Read parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_READ_HPP
#define ARCTK_PARSE_READ_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/consts/format.hpp>
#include <arctk/exit/error.hpp>
#include <arctk/index/dim.hpp>
#include <arctk/math/mat.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/parse/process.hpp>
#include <arctk/sys/file.hpp>
#include <arctk/type/tag.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {
        namespace read //! reading namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Parsing --
            template <typename T>
            inline T string(std::string* str_) noexcept;
            template <typename T>
            inline T file(const std::string& path_) noexcept;


            //  -- Helpers --
            template <typename T>
            inline T helper(type::Tag<T> /*unused*/, std::string* str_) noexcept;
            template <>
            inline bool helper(type::Tag<bool> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline std::vector<T> helper(type::Tag<std::vector<T>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline std::array<T, N> helper(type::Tag<std::array<T, N>> /*unused*/, std::string* str_) noexcept;
            template <>
            inline std::string helper(type::Tag<std::string> /*unused*/, std::string* str_) noexcept;
            template <typename T, typename S>
            inline std::pair<T, S> helper(type::Tag<std::pair<T, S>> /*unused*/, std::string* str_) noexcept;
            template <typename... A>
            inline std::tuple<A...> helper(type::Tag<std::tuple<A...>> /*unused*/, std::string* str_) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> parse_helper(type::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* tokens_, const std::index_sequence<I...>& /*unused*/) noexcept;
            template <typename T, typename S>
            inline std::map<T, S> helper(type::Tag<std::map<T, S>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 2> helper(type::Tag<math::Vec<T, 2>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 3> helper(type::Tag<math::Vec<T, 3>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 4> helper(type::Tag<math::Vec<T, 4>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline math::Vec<T, N> helper(type::Tag<math::Vec<T, N>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 2> helper(type::Tag<math::Mat<T, 2>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 3> helper(type::Tag<math::Mat<T, 3>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 4> helper(type::Tag<math::Mat<T, 4>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline math::Mat<T, N> helper(type::Tag<math::Mat<T, N>> /*unused*/, std::string* str_) noexcept;



            //  == FUNCTIONS ==
            //  -- Parsing --
            /**
             *  Parse a given string of characters into a given type.
             *
             *  @tparam T   Type to be parsed into.
             *
             *  @param  str_    String to be parsed.
             *
             *  @pre    str_ may not be nullptr.
             *
             *  @return Parsed type.
             */
            template <typename T>
            inline T string(std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                process::filter_comments(str_);
                process::filter_whitespace(str_);

                return (helper(type::Tag<T>(), str_));
            }

            /**
             *  Parse a file's contents into a given type.
             *
             *  @tparam T   Type to be parsed into.
             *
             *  @param  path_   Path to the file to be parsed.
             *
             *  @pre    path_ may not be empty.
             *
             *  @return Parsed type.
             */
            template <typename T>
            inline T file(const std::string& path_) noexcept
            {
                assert(!path_.empty());

                return (string<T>(sys::file::read(path_)));
            }


            //  -- Helpers --
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
            inline T helper(type::Tag<T> /*unused*/, std::string* const str_) noexcept
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
            inline bool helper(type::Tag<bool> /*unused*/, std::string* const str_) noexcept
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
            inline std::vector<T> helper(type::Tag<std::vector<T>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::VECTOR);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                std::vector<T> vec;
                vec.reserve(tokens.size());
                for (size_t i = 0; i < tokens.size(); ++i)
                {
                    vec.emplace_back(helper(type::Tag<T>(), &tokens[i]));
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
            inline std::array<T, N> helper(type::Tag<std::array<T, N>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::ARRAY);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != N)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to array type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly '" << N << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                std::array<T, N> arr;
                for (size_t i = 0; i < N; ++i)
                {
                    arr[i] = helper(type::Tag<T>(), &tokens[i]);
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
            inline std::string helper(type::Tag<std::string> /*unused*/, std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::STRING);

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
            inline std::pair<T, S> helper(type::Tag<std::pair<T, S>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::PAIR);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != 2)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to pair type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly two are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (std::make_pair<T, S>(helper(type::Tag<T>(), &tokens[0]), helper(type::Tag<S>(), &tokens[1])));
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
            inline std::tuple<A...> helper(type::Tag<std::tuple<A...>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::TUPLE);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != sizeof...(A))
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to tuple type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly: '" << sizeof...(A) << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (parse_helper(type::Tag<std::tuple<A...>>(), &tokens, std::index_sequence_for<A...>()));
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
            inline std::tuple<A...> parse_helper(type::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* const tokens_, const std::index_sequence<I...>& /*unused*/) noexcept
            {
                assert(tokens_ != nullptr);
                assert(sizeof...(A) == tokens_->size());
                assert(sizeof...(A) == sizeof...(I));

                std::vector<std::string>& tokens_ref = *tokens_;

                std::tuple<A...> tup;
                ((std::get<I>(tup) = helper(type::Tag<A>(), &tokens_ref[I])), ...);

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
            inline std::map<T, S> helper(type::Tag<std::map<T, S>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::MAP);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                std::map<T, S> map;
                for (size_t i = 0; i < tokens.size(); ++i)
                {
                    map.emplace(helper(type::Tag<std::pair<T, S>>(), &tokens[i]));
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
            inline math::Vec<T, 2> helper(type::Tag<math::Vec<T, 2>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != 2)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vec2 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly two are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Vec<T, 2>(helper(type::Tag<T>(), &tokens[index::dim::cartesian::X]), helper(type::Tag<T>(), &tokens[index::dim::cartesian::Y])));
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
            inline math::Vec<T, 3> helper(type::Tag<math::Vec<T, 3>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != 3)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vec3 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly three are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Vec<T, 3>(helper(type::Tag<T>(), &tokens[index::dim::cartesian::X]), helper(type::Tag<T>(), &tokens[index::dim::cartesian::Y]), helper(type::Tag<T>(), &tokens[index::dim::cartesian::Z])));
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
            inline math::Vec<T, 4> helper(type::Tag<math::Vec<T, 4>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != 4)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vec4 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly four are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Vec<T, 4>(helper(type::Tag<T>(), &tokens[index::dim::cartesian::X]), helper(type::Tag<T>(), &tokens[index::dim::cartesian::Y]), helper(type::Tag<T>(), &tokens[index::dim::cartesian::Z]), helper(type::Tag<T>(), &tokens[3])));
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
            inline math::Vec<T, N> helper(type::Tag<math::Vec<T, N>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::VEC);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != N)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to vecN type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly '" << N << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                math::Vec<T, N> vec;
                for (size_t i = 0; i < N; ++i)
                {
                    vec[i] = helper(type::Tag<T>(), &tokens[i]);
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
            inline math::Mat<T, 2> helper(type::Tag<math::Mat<T, 2>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != 2)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to mat2 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly two are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Mat<T, 2>(helper(type::Tag<math::Vec<T, 2>>(), &tokens[index::dim::cartesian::X]), helper(type::Tag<math::Vec<T, 2>>(), &tokens[index::dim::cartesian::Y])));
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
            inline math::Mat<T, 3> helper(type::Tag<math::Mat<T, 3>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != 3)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to mat3 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly three are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (
                  math::Mat<T, 3>(helper(type::Tag<math::Vec<T, 3>>(), &tokens[index::dim::cartesian::X]), helper(type::Tag<math::Vec<T, 3>>(), &tokens[index::dim::cartesian::Y]), helper(type::Tag<math::Vec<T, 3>>(), &tokens[index::dim::cartesian::Z])));
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
            inline math::Mat<T, 4> helper(type::Tag<math::Mat<T, 4>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != 4)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to mat4 type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly four are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (math::Mat<T, 4>(helper(type::Tag<math::Vec<T, 4>>(), &tokens[index::dim::cartesian::X]), helper(type::Tag<math::Vec<T, 4>>(), &tokens[index::dim::cartesian::Y]),
                                        helper(type::Tag<math::Vec<T, 4>>(), &tokens[index::dim::cartesian::Z]), helper(type::Tag<math::Vec<T, 4>>(), &tokens[3])));
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
            inline math::Mat<T, N> helper(type::Tag<math::Mat<T, N>> /*unused*/, std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                process::extract_contents(str_, consts::format::container::MAT);
                std::vector<std::string> tokens = process::tokenise(str_ref);

                if (tokens.size() != N)
                {
                    std::cerr << "Unable to parse string: '" << str_ref << "' to matN type.\n"
                              << "String: '" << str_ref << "' contains: '" << tokens.size() << "' values, but exactly '" << N << "' are required.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                math::Mat<T, N> mat;
                for (size_t i = 0; i < N; ++i)
                {
                    mat[i] = helper(type::Tag<math::Vec<T, N>>(), &tokens[i]);
                }

                return (mat);
            }



        } // namespace read
    }     // namespace parse
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PARSE_READ_HPP
