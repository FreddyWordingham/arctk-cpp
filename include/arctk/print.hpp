/**
 *  @file   arctk/print.hpp
 *  @date   28/05/2018
 *  @author Freddy Wordingham
 *
 *  Collection of print functions.
 */



//  == GUARD ==
#ifndef ARCTK_PRINT_HPP
#define ARCTK_PRINT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <tuple>
#include <utility>

//  -- Arctk --
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{



    //  == OPERATOR PROTOTYPES ==
    template <typename S, typename C, typename T = typename C::value_type, typename I = typename C::const_iterator, typename = typename std::enable_if<!std::is_same<C, std::string>::value>::type>
    inline S& operator<<(S& stream_, const C& cont_);
    template <typename S, typename A0, typename A1>
    inline S& operator<<(S& stream_, const std::pair<A0, A1>& pair_);
    template <typename S, typename... A>
    inline S& operator<<(S& stream_, const std::tuple<A...>& tup_);



    //  == OPERATORS ==
    /**
     *  Print a container as a human-readable string.
     *  This function is disabled for the std::string container type.
     *
     *  @tparam S   Type of stream to print to.
     *  @tparam C   Type of container to print.
     *  @tparam T   Type stored by C.
     *  @tparam I   Type of const iterator of C.
     *
     *  @param  stream_ Stream to print to.
     *  @param  cont_   Container to print.
     *
     *  @return A reference to the stream post-print.
     */
    template <typename S, typename C, typename T, typename I, typename>
    inline S& operator<<(S& stream_, const C& cont_)
    {
        stream_ << arc::str::to_string(cont_);

        return (stream_);
    }

    /**
     *  Print a pair as a human-readable string.
     *
     *  @tparam S   Type of stream to print to.
     *  @tparam A0  First type stored by pair.
     *  @tparam A1  Second type stored by pair.
     *
     *  @param  stream_ Stream to print to.
     *  @param  pair_   pair to print.
     *
     *  @return A reference to the stream post-print.
     */
    template <typename S, typename A0, typename A1>
    inline S& operator<<(S& stream_, const std::pair<A0, A1>& pair_)
    {
        stream_ << arc::str::to_string(pair_);

        return (stream_);
    }

    /**
     *  Print a tuple as a human-readable string.
     *
     *  @tparam S   Type of stream to print to.
     *  @tparam A   Types stored by the tuple.
     *
     *  @param  stream_ Stream to print to.
     *  @param  tup_    Tuple to print.
     *
     *  @return A reference to the stream post-print.
     */
    template <typename S, typename... A>
    inline S& operator<<(S& stream_, const std::tuple<A...>& tup_)
    {
        stream_ << arc::str::to_string(tup_);

        return (stream_);
    }



} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PRINT_HPP
