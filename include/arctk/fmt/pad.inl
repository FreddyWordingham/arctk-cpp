//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/fmt/pad.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iomanip>
#include <ostream>



//  == NAMESPACE ==
namespace arc::fmt
{



    //  == INSTANTIATION ==
    //  -- Constructors --
    constexpr inline Pad::Pad(const int width_, const char fill_) noexcept
      : _width{width_}
      , _fill{fill_}
    {
        assert(width_ > 0);
    }



    //  == METHODS ==
    //  -- Getters --
    constexpr inline int Pad::width() const noexcept
    {
        return (_width);
    }

    constexpr inline char Pad::fill() const noexcept
    {
        return (_fill);
    }



} // namespace arc::fmt



//  == OPERATORS ==
//  -- Printing --
inline std::ostream& operator<<(std::ostream& stream_, const arc::fmt::Pad& pad_) noexcept
{
    stream_ << std::setfill(pad_.fill()) << std::setw(pad_.width());

    return (stream_);
}
