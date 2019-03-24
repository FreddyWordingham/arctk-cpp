//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <array> // TODO remove for vec3.



//  == NAMESPACE ==
namespace arc
{
    namespace term
    {



        //  == CLASSES ==
        //  -- Col --
        class Col : public std::array<char, 3>
        {
        };



    } // namespace term



    //  == OPERATORS ==
    //  -- Printing --
    template <typename T>
    constexpr inline T& operator<<(T& stream_, const term::Col& col_) noexcept
    {
        stream_ << "\033[38;2;" << col_[0] << ';' << col_[1] << ';' << col_[2] << "m;"; // TODO convert to .r .g .b.

        return (stream_);
    }



} // namespace arc
