//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace lin
    {



        //  == CLASSES ==
        //  -- Vec --
        template <typename T, std::size_t N>
        class Vec
        {
            //  == FIELDS ==
          public:
            //  -- Elements --
            std::array<T, N> _elems;
        };



    } // namespace lin
} // namespace arc
