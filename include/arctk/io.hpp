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
#include <arctk/type/tag.hpp>



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

            return (input::parse(type::Tag<T>(), str_));
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



//  == GUARD END ==
#endif // ARCTK_IO_HPP
