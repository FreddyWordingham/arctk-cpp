//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/fmt/progress.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstddef>
#include <sstream>
#include <string>



//  == NAMESPACE ==
namespace arc
{
    namespace fmt
    {



        //  == FUNCTIONS ==
        //  -- Progress Bar --
        inline std::string progress(const int length_, const double frac_) noexcept
        {
            assert(length_ > 2);

            const auto filled{static_cast<std::size_t>((length_ - 2) * frac_)};

            return (std::string{} + '[' + std::string(filled, '=') + std::string(static_cast<std::size_t>(length_ - 2) - filled, ' ') + ']');
        }



    } // namespace fmt
} // namespace arc
