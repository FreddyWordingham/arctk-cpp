//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        constexpr inline Iterator<T>::Iterator(const T* pointer_) noexcept
          : _pointer{pointer_}
        {
            assert(pointer_ != nullptr);
        }



    } // namespace range
} // namespace arc
