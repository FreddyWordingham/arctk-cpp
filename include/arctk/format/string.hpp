//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Str --
#include <iosfwd>



//  == NAMESPACE ==
namespace arc
{
    namespace format
    {



        //  == FUNCTIONS ==
        //  -- String --
        template <typename T>
        inline std::string string(const T& var_) noexcept;



    } // namespace format
} // namespace arc
