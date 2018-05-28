/**
 *  @file   arctk/print/container.hpp
 *  @date   26/05/2018
 *  @author Freddy Wordingham
 *
 *  Container print functions.
 */



//  == GUARD ==
#ifndef ARCTK_PRINT_CONTAINER_HPP
#define ARCTK_PRINT_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <arctk/str.hpp>



//  == OPERATOR PROTOTYPES ==
template <typename S, typename C, typename I = typename C::const_iterator, typename = typename std::enable_if<!std::is_same<C, std::string>::value>::type>
inline S& operator<<(S& stream_, const C& cont_) noexcept;



//  == OPERATORS ==
/**
 *  Print container contents to a stream.
 *
 *  @tparam S   Stream type.
 *  @tparam C   Container type.
 *  @tparam I   Iterator type of C.
 *
 *  @param  stream_ Stream to print to.
 *  @param  cont_   Container to print.
 *
 *  @return Reference to stream post-print.
 */
template <typename S, typename C, typename I>
inline S& operator<<(S& stream_, const C& cont_) noexcept
{
    stream_ << arc::str::to_string(cont_);

    return (stream_);
}



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PRINT_CONTAINER_HPP
