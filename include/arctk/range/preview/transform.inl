//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/preview.inl" // IWYU pragma: export



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/preview/transform.hpp" // IWYU pragma: export



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
            constexpr inline Transform<F>::Transform(const F& trans_) noexcept
              : trans{trans_}
            {
            }



        } // namespace preview
    }     // namespace range
} // namespace arc
