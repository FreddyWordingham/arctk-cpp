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
        //  -- Progress Bar --
        inline std::string progress(const int length_, const double frac_) noexcept;



    } // namespace fmt
} // namespace arc
