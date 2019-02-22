//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/bidirectional.hpp" // IWYU pragma: export



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
            constexpr inline Bidirectional<T>::Bidirectional(const T* pointer_) noexcept
              : Iterator<T>{pointer_}
            {
                assert(pointer_ != nullptr);
            }



            //  -- Increment / Decrement --
            template <typename T>
            constexpr inline Bidirectional<T>& Bidirectional<T>::operator++() noexcept
            {
                ++Iterator<T>::_pointer;

                return (*this);
            }

            template <typename T>
            constexpr inline Bidirectional<T> Bidirectional<T>::operator++(const int /*unused*/) noexcept
            {
                Bidirectional<T> it{*this};

                ++Iterator<T>::_pointer;

                return (it);
            }

            template <typename T>
            constexpr inline Bidirectional<T>& Bidirectional<T>::operator--() noexcept
            {
                --Iterator<T>::_pointer;

                return (*this);
            }

            template <typename T>
            constexpr inline Bidirectional<T> Bidirectional<T>::operator--(const int /*unused*/) noexcept
            {
                Bidirectional<T> it{*this};

                --Iterator<T>::_pointer;

                return (it);
            }


            //  -- Comparison --
            template <typename T>
            constexpr inline bool Bidirectional<T>::operator==(const Bidirectional<T>& rhs_) const noexcept
            {
                return (Iterator<T>::_pointer == rhs_._pointer);
            }

            template <typename T>
            inline bool Bidirectional<T>::operator!=(const Bidirectional<T>& rhs_) const noexcept
            {
                return (Iterator<T>::_pointer != rhs_._pointer);
            }


            //  -- Member Access --
            template <typename T>
            constexpr inline typename Bidirectional<T>::reference Bidirectional<T>::operator*() noexcept
            {
                return (*Iterator<T>::_pointer);
            }

            template <typename T>
            constexpr inline typename Bidirectional<T>::pointer Bidirectional<T>::operator->() noexcept
            {
                return (Iterator<T>::_pointer);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
