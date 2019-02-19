//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        constexpr inline Iterator<T>::Iterator(const T* pointer_) noexcept
          : _pointer(pointer_)
        {
        }


        //  == OPERATORS ==
        //  -- Increment / Decrement --
        template <typename T>
        constexpr inline Iterator<T> Iterator<T>::operator++() noexcept
        {
            _pointer++;

            return (*this);
        }

        template <typename T>
        constexpr inline Iterator<T> Iterator<T>::operator++(const int /*unused*/) noexcept
        {
            Iterator it{*this};

            _pointer++;

            return (it);
        }


        //  -- Comparison --
        template <typename T>
        constexpr inline bool Iterator<T>::operator==(const Iterator<T>& rhs_) noexcept
        {
            return (_pointer == rhs_._pointer);
        }

        template <typename T>
        constexpr inline bool Iterator<T>::operator!=(const Iterator<T>& rhs_) noexcept
        {
            return (_pointer != rhs_._pointer);
        }


        //  -- Member Access --
        template <typename T>
        constexpr inline T& Iterator<T>::operator*() noexcept
        {
            return (*_pointer);
        }

        template <typename T>
        constexpr inline T* Iterator<T>::operator->() noexcept
        {
            return (_pointer);
        }



    } // namespace range
} // namespace arc
