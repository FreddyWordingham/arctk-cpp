/**
 *  @file   arctk/io.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Collection of input/output operators and functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_HPP
#define ARCTK_IO_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <ostream>
#include <vector>

//  -- Arctk --
#include <arctk/io/format.hpp>
#include <arctk/io/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Reading --



        //  == FUNCTIONS ==
        //  -- Reading --



    } // namespace io
} // namespace arc



//  == OPERATOR PROTOTYPES ==
//  -- Io --
template <typename T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept;
template <typename T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept;



//  == OPERATORS ==
//  -- Io --
template <typename T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept
{
    stream_ << arc::io::format::OPENERS[arc::io::format::container::ARRAY] << arr_[0];

    for (size_t i = 1; i < N; ++i)
    {
        stream_ << arc::io::format::DELIM << arr_[i];
    }

    stream_ << arc::io::format::CLOSERS[arc::io::format::container::ARRAY];
}

template <typename T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept
{
    stream_ << arc::io::format::OPENERS[arc::io::format::container::VECTOR] << vec_[0];

    for (size_t i = 1; i < vec_.size(); ++i)
    {
        stream_ << arc::io::format::DELIM << vec_[i];
    }

    stream_ << arc::io::format::CLOSERS[arc::io::format::container::VECTOR];
}



//  == GUARD END ==
#endif // ARCTK_IO_HPP
