//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/preview.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/preview/filter.hpp" // IWYU pragma: export, keep



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace preview
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename F>
            constexpr inline Filter<F>::Filter(const F& pred_) noexcept
              : pred{pred_}
            {
            }



        } // namespace preview
    }     // namespace range
} // namespace arc
