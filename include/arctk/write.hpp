/**
 *  @file   arctk/write.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Collection of writing operators and functions.
 */



//  == GUARD ==
#ifndef ARCTK_PRINT_HPP
#define ARCTK_PRINT_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <ostream>
#include <vector>



//  == OPERATOR PROTOTYPES ==
//  -- Stl --
template <typename T>
inline std::ostream& operator<<(const std::vector<T>& vec_) noexcept;
template <typename T, size_t N>
inline std::ostream& operator<<(const std::array<T, N>& arr_) noexcept;



//  == OPERATORS ==
//  -- Stl --
template <typename T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept
{
    stream_ << '{' << vec_[0];

    for (size_t i = 1; i < vec_.size(); ++i)
    {
        stream_ << ", " << vec_[i];
    }

    stream_ << '}';
}

template <typename T, size_t N>
inline std::ostream& operator<<(const std::array<T, N>& arr_) noexcept
{
    stream_ << '{' << arr_[0];

    for (size_t i = 1; i < N; ++i)
    {
        stream_ << ", " << arr_[i];
    }

    stream_ << '}';
}



//  == GUARD END ==
#endif // ARCTK_PRINT_HPP
