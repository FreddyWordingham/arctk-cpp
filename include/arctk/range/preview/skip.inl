//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/preview/skip.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace preview
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            constexpr inline Skip::Skip(const std::size_t skip_first_, const std::size_t skip_last_) noexcept
              : skip_first{skip_first_}
              , skip_last{skip_last_}
            {
            }



        } // namespace preview
    }     // namespace range
} // namespace arc
