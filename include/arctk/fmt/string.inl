//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/fmt/string.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <sstream>
#include <string>



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
    {



        //  == FUNCTIONS ==
        //  -- Formatting --
        inline std::string str(const bool val_) noexcept
        {
            return (val_ ? "true" : "false");
        }

        template <typename T>
        inline std::string str(const T& val_) noexcept
        {
            std::ostringstream stream;

            stream << val_;

            return (stream.str());
        }



    } // namespace fmt
} // namespace arc
