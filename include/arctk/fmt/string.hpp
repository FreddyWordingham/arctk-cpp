//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <iosfwd>



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
    {



        //  == FUNCTIONS ==
        //  -- Formatting --
        inline std::string str(bool val_) noexcept;
        template <typename T>
        inline std::string str(const T& val_) noexcept;



    } // namespace fmt
} // namespace arc
