//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/format/string.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <sstream>
#include <string>



//  == NAMESPACE ==
namespace arc
{
    namespace format
    {



        //  == FUNCTIONS ==
        //  -- String --
        template <typename T, typename>
        inline std::string string(const T& var_) noexcept
        {
            std::stringstream stream{};

            stream << var_;

            return (stream.str());
        }



    } // namespace format
} // namespace arc
