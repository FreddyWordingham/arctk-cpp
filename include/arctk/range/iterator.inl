//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename I>
        constexpr inline Iterator<I>::Iterator(I&& it_) noexcept
          : _it{std::move(it_)}
        {
        }



    } // namespace range
} // namespace arc
