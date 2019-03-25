//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/fmt/pad.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iomanip>



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
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



    } // namespace fmt



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const fmt::Pad& val_) noexcept
    {
        stream_ << std::setfill(val_.fill()) << std::setw(val_.width());

        return (stream_);
    }



} // namespace arc
