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
#include <ostream>
#include <vector>



//  == OPERATOR PROTOTYPES ==
//  -- Stl --
template <typename T>
inline std::ostream& operator<<(const std::vector<T>& vec_) noexcept;



//  == OPERATORS ==
//  -- Stl --
template <typename T>
inline std::ostream& operator<<(const std::vector<T>& vec_) noexcept
{
    stream_ << '{' << vec_[0];

    for (size_t i = 1; i < vec_.size(); ++i)
    {
        stream_ << ", " << vec_[i];
    }

    stream << '}';
}



//  == GUARD END ==
#endif // ARCTK_PRINT_HPP
