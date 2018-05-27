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



//  == OPERATOR PROTOTYPES ==
template <typename S, typename C, typename I = typename C::const_iterator>
inline S& operator<<(S& stream_, const C& cont_) noexcept;



//  == OPERATORS ==



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PRINT_TUPLE_HPP
