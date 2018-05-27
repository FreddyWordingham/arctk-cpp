/**
 *  @file   arctk/print/pair.hpp
 *  @date   26/05/2018
 *  @author Freddy Wordingham
 *
 *  Pair print functions.
 */



//  == GUARD ==
#ifndef ARCTK_PRINT_PAIR_HPP
#define ARCTK_PRINT_PAIR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == OPERATOR PROTOTYPES ==
template <typename A0, typename A1>
inline std::ostream& operator<<(std::ostream& stream_, const std::pair<A0, A1>& pair_) noexcept;



//  == OPERATORS ==
/**
 *  Print pair's contents to a stream.
 *
 *  @tparam S   Stream type.
 *  @tparam A0  First type stored by pair.
 *  @tparam A1  Second type stored by pair.
 *
 *  @param  stream_ Stream to print to.
 *  @param  pair_   Pair to print.
 *
 *  @return Reference to stream post-print.
 */
template <typename A0, typename A1>
inline std::ostream& operator<<(std::ostream& stream_, const std::pair<A0, A1>& pair_) noexcept
{
    stream_ << '(' << std::get<0>(pair_) << ", " << std::get<1>(pair_) << ')';
}



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PRINT_PAIR_HPP
