//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/forward.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            constexpr inline Forward<T>::Forward(const T* pointer_) noexcept
              : Iterator<T>{pointer_}
            {
            }



            //  == OPERATORS ==
            //  -- Increment / Decrement --
            template <typename T>
            constexpr inline Forward<T> Forward<T>::operator++() noexcept
            {
                ++Iterator<T>::_pointer;

                return (*this);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
