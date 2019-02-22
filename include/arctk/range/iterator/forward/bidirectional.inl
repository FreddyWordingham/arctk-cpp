//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator.inl"         // IWYU pragma: keep
                                            // IWYU pragma: no_include "arctk/range/iterator.hpp"
#include "arctk/range/iterator/forward.inl" // IWYU pragma: keep
                                            // IWYU pragma: no_include "arctk/range/iterator/forward.hpp"

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {
            namespace forward
            {



                //  == INSTANTIATION ==
                //  -- Constructors --
                template <typename T>
                constexpr inline Bidirectional<T>::Bidirectional(const T* pointer_) noexcept
                  : Forward<T>{pointer_}
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



            } // namespace forward
        }     // namespace iterator
    }         // namespace range
} // namespace arc
