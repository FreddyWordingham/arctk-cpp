//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/forward.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>



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
                assert(pointer_ != nullptr);
            }



            //  -- Increment / Decrement --
            template <typename T>
            constexpr inline Forward<T>& Forward<T>::operator++() noexcept
            {
                ++_pointer;

                return (*this);
            }

            template <typename T>
            constexpr inline Forward<T> Forward<T>::operator++(const int /*unused*/) noexcept
            {
                Forward<T> it{*this};

                ++_pointer;

                return (it);
            }


            //  == METHODS ==
            //  -- Getters --



        } // namespace iterator
    }     // namespace range
} // namespace arc
