//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/backward.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator.inl"

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
            constexpr inline Backward<T>::Backward(const T* pointer_) noexcept
              : Iterator<T>{pointer_}
            {
                assert(pointer_ != nullptr);
            }



            //  -- Increment / Decrement --
            template <typename T>
            constexpr inline Backward<T>& Backward<T>::operator++() noexcept
            {
                --Iterator<T>::_pointer;

                return (*this);
            }

            template <typename T>
            constexpr inline Backward<T> Backward<T>::operator++(const int /*unused*/) noexcept
            {
                Backward<T> it{*this};

                --Iterator<T>::_pointer;

                return (it);
            }


            //  -- Comparison --
            template <typename T>
            constexpr inline bool Backward<T>::operator==(const Backward<T>& rhs_) const noexcept
            {
                return (Iterator<T>::_pointer == rhs_._pointer);
            }

            template <typename T>
            inline bool Backward<T>::operator!=(const Backward<T>& rhs_) const noexcept
            {
                return (Iterator<T>::_pointer != rhs_._pointer);
            }


            //  -- Member Access --
            template <typename T>
            constexpr inline typename Backward<T>::reference Backward<T>::operator*() noexcept
            {
                return (*Iterator<T>::_pointer);
            }

            template <typename T>
            constexpr inline typename Backward<T>::pointer Backward<T>::operator->() noexcept
            {
                return (Iterator<T>::_pointer);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
