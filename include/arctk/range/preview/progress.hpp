//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <iostream>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace preview
        {



            //  == CLASSES ==
            //  -- Progress --
            template <typename T>
            class Progress
            {
                //  == FIELDS ==
              public:
                //  -- Stream --
                T& stream;

                //  -- Formatting --
                const int length;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Progress(T& stream_, const int length_ = 20) noexcept;
            };



        } // namespace preview
    }     // namespace range
} // namespace arc
