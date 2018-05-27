/**
 *  @file   arctk/print/tuple.hpp
 *  @date   26/05/2018
 *  @author Freddy Wordingham
 *
 *  Tuple print functions.
 */



//  == GUARD ==
#ifndef ARCTK_PRINT_TUPLE_HPP
#define ARCTK_PRINT_TUPLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <arctk/utl.hpp>



//  == OPERATOR PROTOTYPES ==
template <typename... A>
inline std::ostream& operator<<(std::ostream& stream_, const std::tuple<A...>& tup_) noexcept;



//  == OPERATORS ==
/**
 *  Print tuple's contents to a stream.
 *
 *  @tparam S   Stream type.
 *  @tparam A   Types stored by tuple.
 *
 *  @param  stream_ Stream to print to.
 *  @param  tup_    Tuple to print.
 *
 *  @return Reference to stream post-print.
 */
template <typename... A>
inline std::ostream& operator<<(std::ostream& stream_, const std::tuple<A...>& tup_) noexcept
{
    stream_ << '(';
    arc::utl::apply_with_index(tup_, [&stream_]<typename L>(const L& val_, const size_t i, const size_t total) { stream_ << ((i == 0) ? "" : ", ") << val_; });
    stream_ << ')';
}



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PRINT_TUPLE_HPP
