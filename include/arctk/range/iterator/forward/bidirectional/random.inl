//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional/random.hpp" // IWYU pragma: export



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional.inl" // IWYU pragma: export



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
            namespace forward
            {
                namespace bidirectional
                {



                    //  == INSTANTIATION ==
                    //  -- Constructors --
                    template <typename T>
                    constexpr inline Random<T>::Random(const T* pointer_) noexcept
                      : Bidirectional<T>{pointer_}
                    {
                        assert(pointer_ != nullptr);
                    }



                    //  -- Increment / Decrement --
                    template <typename T>
                    constexpr inline Random<T>& Random<T>::operator++() noexcept
                    {
                        ++Iterator<T>::_pointer;

                        return (*this);
                    }

                    template <typename T>
                    constexpr inline Random<T> Random<T>::operator++(const int /*unused*/) noexcept
                    {
                        Random<T> it{*this};

                        ++Iterator<T>::_pointer;

                        return (it);
                    }

                    template <typename T>
                    constexpr inline Random<T>& Random<T>::operator--() noexcept
                    {
                        --Iterator<T>::_pointer;

                        return (*this);
                    }

                    template <typename T>
                    constexpr inline Random<T> Random<T>::operator--(const int /*unused*/) noexcept
                    {
                        Random<T> it{*this};

                        --Iterator<T>::_pointer;

                        return (it);
                    }


                    //  -- Comparison --
                    template <typename T>
                    constexpr inline bool Random<T>::operator==(const Random<T>& rhs_) const noexcept
                    {
                        return (Iterator<T>::_pointer == rhs_._pointer);
                    }

                    template <typename T>
                    inline bool Random<T>::operator!=(const Random<T>& rhs_) const noexcept
                    {
                        return (Iterator<T>::_pointer != rhs_._pointer);
                    }


                    //  -- Member Access --
                    template <typename T>
                    constexpr inline typename Random<T>::reference Random<T>::operator*() noexcept
                    {
                        return (*Iterator<T>::_pointer);
                    }

                    template <typename T>
                    constexpr inline typename Random<T>::pointer Random<T>::operator->() noexcept
                    {
                        return (Iterator<T>::_pointer);
                    }



                } // namespace bidirectional
            }     // namespace forward
        }         // namespace iterator
    }             // namespace range
} // namespace arc
