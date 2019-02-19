//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include <arctk/range/iterator.hpp>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == CLASSES ==
            //  -- Forward --
            template <typename T>
            class Forward : public Iterator<T>
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Forward(const T* _pointer) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Forward operator++() noexcept;
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc
