//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/preview/progress.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace preview
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            constexpr inline Progress<T>::Progress(T& stream_, const int length_) noexcept
              : stream{stream_}
              , length{length_}
            {
                assert(length_ > 10); // TODO
            }



        } // namespace preview
    }     // namespace range
} // namespace arc
