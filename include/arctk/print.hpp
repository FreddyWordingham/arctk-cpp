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
#include <tuple>
#include <utility>

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
    template <typename S, typename C, typename T, typename I, typename>
    inline S& operator<<(S& stream_, const C& cont_)
    {
        stream_ << arc::str::to_string(cont_);

        return (stream_);
    }

    template <typename S, typename A0, typename A1>
    inline S& operator<<(S& stream_, const std::pair<A0, A1>& pair_)
    {
        stream_ << arc::str::to_string(pair_);

        return (stream_);
    }

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
