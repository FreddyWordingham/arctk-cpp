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
#include <ostream>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/io/format.hpp>
#include <arctk/io/str.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Reading --
        template <typename T>
        inline T parse(std::string* const str_) noexcept;

        //  -- Printing --
        template <typename... A, size_t... I>
        inline std::ostream& tuple_print_helper(std::ostream& stream_, const std::tuple<A...>& tup_, const std::index_sequence<I...>& /*unused*/) noexcept;



        //  == FUNCTIONS ==
        //  -- Reading --
        template <typename T>
        inline T parse(std::string* const str_) noexcept
        {
            str::filter_comments(str_);
            str::filter_whitespace(str_);

            return (str::parse(utl::Tag<T>(), str_));
        }


        //  -- Printing --
        template <typename... A, size_t... I>
        inline std::ostream& tuple_print_helper(std::ostream& stream_, const std::tuple<A...>& tup_, const std::index_sequence<I...>& /*unused*/) noexcept
        {
            static_assert(sizeof...(A) > 0);
            static_assert(sizeof...(A) == (sizeof...(I) + 1));

            stream_ << std::get<0>(tup_);
            ((stream_ << format::DELIM << std::get<I + 1>(tup_)), ...);

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



//  == OPERATORS ==
//  -- Io --
template <typename T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept
{
    stream_ << arc::io::format::OPENERS[arc::io::format::container::ARRAY] << arr_[0];

    for (size_t i = 1; i < N; ++i)
    {
        stream_ << arc::io::format::DELIM << arr_[i];
    }

    stream_ << arc::io::format::CLOSERS[arc::io::format::container::ARRAY];

    return (stream_);
}

template <typename T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept
{
    stream_ << arc::io::format::OPENERS[arc::io::format::container::VECTOR] << vec_[0];

    for (size_t i = 1; i < vec_.size(); ++i)
    {
        stream_ << arc::io::format::DELIM << vec_[i];
    }

    stream_ << arc::io::format::CLOSERS[arc::io::format::container::VECTOR];

    return (stream_);
}

inline std::ostream& operator<<(std::ostream& stream_, const std::string& str_) noexcept
{
    stream_ << arc::io::format::OPENERS[arc::io::format::container::STRING] << str_.c_str() << arc::io::format::CLOSERS[arc::io::format::container::STRING];

    return (stream_);
}

template <typename T, typename S>
inline std::ostream& operator<<(std::ostream& stream_, const std::pair<T, S>& pair_) noexcept
{
    stream_ << arc::io::format::OPENERS[arc::io::format::container::PAIR] << pair_.first << arc::io::format::DELIM << pair_.second << arc::io::format::CLOSERS[arc::io::format::container::PAIR];

    return (stream_);
}

template <typename... A>
inline std::ostream& operator<<(std::ostream& stream_, const std::tuple<A...>& tup_) noexcept
{
    stream_ << arc::io::format::OPENERS[arc::io::format::container::TUPLE];

    if (sizeof...(A) > 0)
    {
        arc::io::tuple::tuple_print_helper(stream_, tup_, std::make_index_sequence<sizeof...(A) - 1>());
    }

    stream_ << arc::io::format::CLOSERS[arc::io::format::container::TUPLE];

    return (stream_);
}



//  == GUARD END ==
#endif // ARCTK_IO_HPP
