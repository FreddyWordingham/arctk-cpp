//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/properties.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <functional>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        template <typename C, typename S, typename F>
        constexpr inline bool true_for_all(const C& cont_, F&& func_) noexcept
        {
            for (const S& c : cont_)
            {
                if (!func_(c))
                {
                    return (false);
                }
            }

            return (true);
        }



    } // namespace range
} // namespace arc
