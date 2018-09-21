/**
 *  @file   arctk/write/stl.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Collection of standard template library writing operator functions.
 */



//  == GUARD ==
#ifndef ARCTK_WRITE_STL_HPP
#define ARCTK_WRITE_STL_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <vector>



//  == OPERATOR PROTOTYPES ==
//  -- Vector --
template <typename T, typename S>
inline T& operator<<(T& stream_, const std::vector<S>& vec_) noexcept;
template <typename T, typename S, size_t N>
inline T& operator<<(T& stream_, const std::array<S, N>& arr_) noexcept;



//  == OPERATORS ==
//  -- Vector --
template <typename T, typename S>
inline T& operator<<(T& stream_, const std::vector<S>& vec_) noexcept
{
    stream_ << '{' << vec_[0];
    for (size_t i = 1; i < vec_.size(); ++i)
    {
        stream_ << ", " << vec_[i];
    }
    stream_ << '}';

    return (stream_);
}

template <typename T, typename S, size_t N>
inline T& operator<<(T& stream_, const std::array<S, N>& arr_) noexcept
{
    stream_ << '{' << arr_[0];
    for (size_t i = 1; i < N; ++i)
    {
        stream_ << ", " << arr_[i];
    }
    stream_ << '}';

    return (stream_);
}



//  == GUARD END ==
#endif // ARCTK_WRITE_STL_HPP
