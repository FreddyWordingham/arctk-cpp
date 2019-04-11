//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <iosfwd>



//  == NAMESPACE ==
namespace arc::fmt
{



    //  == FUNCTIONS ==
    //  -- Formatting --
    inline std::string string(bool val_) noexcept;
    template <typename T>
    inline std::string string(const T& val_) noexcept;



} // namespace arc::fmt
