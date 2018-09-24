/**
 *  @file   arctk/io/tuple.hpp
 *  @date   24/09/2018
 *  @author Freddy Wordingham
 *
 *  Tuple input/output functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_TUPLE_HPP
#define ARCTK_IO_TUPLE_HPP



//  == IMPORTS ==
//  -- Std --
#include <ostream>
#include <tuple>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {
        namespace tuple //! tuple namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Printing --
            template <typename... A, size_t... I>
            inline std::ostream& tuple_print_helper(std::ostream& stream_, const std::tuple<A...>& tup_, const std::index_sequence<I...>& /*unused*/) noexcept;



            //  == FUNCTIONS ==
            //  -- Printing --
            template <typename... A, size_t... I>
            inline std::ostream& tuple_print_helper(std::ostream& stream_, const std::tuple<A...>& tup_, const std::index_sequence<I...>& /*unused*/) noexcept
            {
                static_assert(sizeof...(A) > 0);
                static_assert(sizeof...(A) == (sizeof...(I) + 1));

                stream_ << std::get<0>(tup_);
                ((stream_ << arc::io::format::DELIM << std::get<I + 1>(tup_)), ...);

                return (stream_);
            }



        } // namespace tuple
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_TUPLE_HPP
