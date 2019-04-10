//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/fmt/string.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- String --
#include <sstream>
#include <string>



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
    {



        //  == FUNCTIONS ==
        //  -- Formatting --
        inline std::string string(const bool val_) noexcept
        {
            return (val_ ? "true" : "false");
        }

        template <typename T>
        inline std::string string(const T& val_) noexcept
        {
            std::ostringstream stream;

            stream << val_;

            return (stream.str());
        }



    } // namespace fmt
} // namespace arc
