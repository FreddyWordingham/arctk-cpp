/**
 *  @file   arctk/print/stl.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Collection of standard template library printing operator functions.
 */



//  == GUARD ==
#ifndef ARCTK_PRINT_STL_HPP
#define ARCTK_PRINT_STL_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == OPERATOR PROTOTYPES ==
//  -- Vector --
template <typename T, typename S>
inline T& operator<<(T& stream_, const std::vector<S>& vec_) noexcept;



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



//  == GUARD END ==
#endif // ARCTK_PRINT_STL_HPP
