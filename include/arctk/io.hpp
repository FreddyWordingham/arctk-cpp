/**
 *  @file   arctk/io.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Collection of input/output operators and functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_HPP
#define ARCTK_IO_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cassert>
#include <fstream>
#include <ostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/io/file.hpp>
#include <arctk/io/input.hpp>
#include <arctk/io/output.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Parsing --
        template <typename T>
        inline T parse(std::string* str_) noexcept;

        //  -- Printing --
        template <typename... A, size_t... I>
        inline std::ostream& tuple_print_helper(std::ostream& stream_, const std::tuple<A...>& tup_, const std::index_sequence<I...>& /*unused*/) noexcept;



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
        inline T parse(std::string* const str_) noexcept
        {
            assert(str_ != nullptr);

            input::filter_comments(str_);
            input::filter_whitespace(str_);

            return (input::parse(utl::Tag<T>(), str_));
        }


        //  -- Printing --
        /**
         *  Tuple printing helper function.
         *
         *  @tparam A   Types stored by the tuple.
         *  @tparam I   Index sequence of the tuple types.
         *
         *  @param  stream_ Stream to print to.
         *  @param  tup_    Tuple to be printed.
         *
         *  @pre    size of A must be positive.
         *  @pre    size of A must equal the size of I plus one.
         *
         *  @return Reference to the stream post-print.
         */
        template <typename... A, size_t... I>
        inline std::ostream& tuple_print_helper(std::ostream& stream_, const std::tuple<A...>& tup_, const std::index_sequence<I...>& /*unused*/) noexcept
        {
            static_assert(sizeof...(A) > 0);
            static_assert(sizeof...(A) == (sizeof...(I) + 1));

            stream_ << std::get<0>(tup_);
            ((stream_ << consts::format::DELIM << std::get<I + 1>(tup_)), ...);

            return (stream_);
        }



    } // namespace io
} // namespace arc



//  == OPERATOR PROTOTYPES ==
//  -- Io --
template <typename T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept;
template <typename T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept;
inline std::ostream& operator<<(std::ostream& stream_, const std::string& str_) noexcept;
template <typename T, typename S>
inline std::ostream& operator<<(std::ostream& stream_, const std::pair<T, S>& pair_) noexcept;
template <typename... A>
inline std::ostream& operator<<(std::ostream& stream_, const std::tuple<A...>& tup_) noexcept;
template <typename T, typename S>
inline std::ostream& operator<<(std::ostream& stream_, const std::map<T, S>& map_) noexcept;



//  == OPERATORS ==
//  -- Io --
/**
 *  Print an array to a stream.
 *
 *  @tparam T   Type stored by the array.
 *  @tparam N   Size of the array.
 *
 *  @param  stream_ Stream to print to.
 *  @param  arr_    Array to be printed.
 *
 *  @return Reference to the stream post-print.
 */
template <typename T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept
{
    stream_ << arc::consts::format::OPENERS[arc::consts::format::container::ARRAY] << arr_[0];

    for (size_t i = 1; i < N; ++i)
    {
        stream_ << arc::consts::format::DELIM << arr_[i];
    }

    stream_ << arc::consts::format::CLOSERS[arc::consts::format::container::ARRAY];

    return (stream_);
}

/**
 *  Print a vector to a stream.
 *
 *  @tparam T   Type stored by the vector.
 *
 *  @param  stream_ Stream to print to.
 *  @param  vec_    Vector to be printed.
 *
 *  @return Reference to the stream post-print.
 */
template <typename T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept
{
    stream_ << arc::consts::format::OPENERS[arc::consts::format::container::VECTOR] << vec_[0];

    for (size_t i = 1; i < vec_.size(); ++i)
    {
        stream_ << arc::consts::format::DELIM << vec_[i];
    }

    stream_ << arc::consts::format::CLOSERS[arc::consts::format::container::VECTOR];

    return (stream_);
}

/**
 *  Print a string to a stream.
 *
 *  @param  stream_ Stream to print to.
 *  @param  str_    String to be printed.
 *
 *  @return Reference to the stream post-print.
 */
inline std::ostream& operator<<(std::ostream& stream_, const std::string& str_) noexcept
{
    stream_ << arc::consts::format::OPENERS[arc::consts::format::container::STRING] << str_.c_str() << arc::consts::format::CLOSERS[arc::consts::format::container::STRING];

    return (stream_);
}

/**
 *  Print a pair to a stream.
 *
 *  @tparam T   First stored by the pair.
 *  @tparam S   Second stored by the pair.
 *
 *  @param  stream_ Stream to print to.
 *  @param  pair_   Pair to be printed.
 *
 *  @return Reference to the stream post-print.
 */
template <typename T, typename S>
inline std::ostream& operator<<(std::ostream& stream_, const std::pair<T, S>& pair_) noexcept
{
    stream_ << arc::consts::format::OPENERS[arc::consts::format::container::PAIR] << pair_.first << arc::consts::format::DELIM << pair_.second << arc::consts::format::CLOSERS[arc::consts::format::container::PAIR];

    return (stream_);
}

/**
 *  Print a tuple to a stream.
 *
 *  @tparam A   Types stored by the tuple.
 *
 *  @param  stream_ Stream to print to.
 *  @param  tup_    Tuple to be printed.
 *
 *  @return Reference to the stream post-print.
 */
template <typename... A>
inline std::ostream& operator<<(std::ostream& stream_, const std::tuple<A...>& tup_) noexcept
{
    stream_ << arc::consts::format::OPENERS[arc::consts::format::container::TUPLE];

    if (sizeof...(A) > 0)
    {
        arc::io::tuple_print_helper(stream_, tup_, std::make_index_sequence<sizeof...(A) - 1>());
    }

    stream_ << arc::consts::format::CLOSERS[arc::consts::format::container::TUPLE];

    return (stream_);
}

/**
 *  Print a map to a stream.
 *
 *  @tparam T   Type used to store map keys.
 *  @tparam S   Type used to store map values.
 *
 *  @param  stream_ Stream to print to.
 *  @param  map_    Map to be printed.
 *
 *  @return Reference to the stream post-print.
 */
template <typename T, typename S>
inline std::ostream& operator<<(std::ostream& stream_, const std::map<T, S>& map_) noexcept
{
    stream_ << arc::consts::format::OPENERS[arc::consts::format::container::MAP];

    bool first = true;

    for (auto const& pair : map_)
    {
        if (!first)
        {
            stream_ << arc::consts::format::DELIM;

            first = false;
        }

        stream_ << pair;
    }

    stream_ << arc::consts::format::CLOSERS[arc::consts::format::container::MAP];

    return (stream_);
}



//  == GUARD END ==
#endif // ARCTK_IO_HPP
