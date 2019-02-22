//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/forward.hpp" // IWYU pragma: export



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.inl" // IWYU pragma: export



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
                ++Iterator<T>::_pointer;

                return (*this);
            }

            template <typename T>
            constexpr inline Forward<T> Forward<T>::operator++(const int /*unused*/) noexcept
            {
                Forward<T> it{*this};

                ++Iterator<T>::_pointer;

                return (it);
            }


            //  -- Comparison --
            template <typename T>
            constexpr inline bool Forward<T>::operator==(const Forward<T>& rhs_) const noexcept
            {
                return (Iterator<T>::_pointer == rhs_._pointer);
            }

            template <typename T>
            inline bool Forward<T>::operator!=(const Forward<T>& rhs_) const noexcept
            {
                return (Iterator<T>::_pointer != rhs_._pointer);
            }


            //  -- Member Access --
            template <typename T>
            constexpr inline typename Forward<T>::reference Forward<T>::operator*() noexcept
            {
                return (*Iterator<T>::_pointer);
            }

            template <typename T>
            constexpr inline typename Forward<T>::pointer Forward<T>::operator->() noexcept
            {
                return (Iterator<T>::_pointer);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
