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



//  == OPERATOR PROTOTYPES ==
template <typename S, typename C, typename I = typename C::const_iterator>
inline S& operator<<(S& stream_, const C& cont_) noexcept;



//  == OPERATORS ==
template <typename S, typename C, typename I>
inline S& operator<<(S& stream_, const C& cont_) noexcept
{
    stream_ << '{';

    if (!cont_.empty())
    {
        stream_ << cont_.front();

        for (I it = ++std::begin(cont_); it != std::end(cont_); ++it)
        {
            stream_ << ", " << *it;
        }
    }

    stream_ << '}';

    return (stream_);
}



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PRINT_CONTAINER_HPP
