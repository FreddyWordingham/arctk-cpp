//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename I>
            constexpr inline Iterator<I>::Iterator(I&& it_) noexcept
              : _it{std::move(it_)}
            {
            }



            //  == OPERATORS ==
            //  -- Assignment --
            template <typename I>
            constexpr inline& Iterator<I>::operator+=(const difference_type n_) noexcept
            {
                _it += n_;

                return (*this);
            }

            template <typename I>
            constexpr inline& Iterator<I>::operator-=(const difference_type n_) noexcept
            {
                _it -= n_;

                return (*this);
            }


            //  -- Increment / Decrement --
            template <typename I>
            constexpr inline Iterator<I>& Iterator<I>::operator++() noexcept
            {
                ++_it;

                return (*this);
            }

            template <typename I>
            constexpr inline Iterator<I> Iterator<I>::operator++(const int /*unused*/) noexcept
            {
                Iterator<I> it{*this};

                ++_it;

                return (it);
            }

            template <typename I>
            constexpr inline Iterator<I>& Iterator<I>::operator--() noexcept
            {
                --_it;

                return (*this);
            }

            template <typename I>
            constexpr inline Iterator<I> Iterator<I>::operator--(const int /*unused*/) noexcept
            {
                Iterator<I> it{*this};

                --_it;

                return (it);
            }


            //  -- Arithmetic --
            template <typename I>
            constexpr inline Iterator<I> Iterator<I>::operator+(const difference_type n_) noexcept
            {
                return (Iterator<I>{_it + n_});
            }

            template <typename I>
            constexpr inline Iterator<I> Iterator<I>::operator-(const difference_type n_) noexcept
            {
                return (Iterator<I>{_it - n_});
            }


            //  -- Comparison --
            template <typename I>
            constexpr inline bool Iterator<I>::operator==(const Iterator<I>& rhs_) const noexcept
            {
                return (_it == rhs_._it);
            }

            template <typename I>
            inline bool Iterator<I>::operator!=(const Iterator<I>& rhs_) const noexcept
            {
                return (_it != rhs_._it);
            }

            template <typename I>
            constexpr inline bool Iterator<I>::operator<(const Iterator& rhs_) const noexcept
            {
                return (_it < rhs_._it);
            }

            template <typename I>
            constexpr inline bool Iterator<I>::operator>(const Iterator& rhs_) const noexcept
            {
                return (_it > rhs_._it);
            }

            template <typename I>
            constexpr inline bool Iterator<I>::operator<=(const Iterator& rhs_) const noexcept
            {
                return (_it <= rhs_._it);
            }

            template <typename I>
            constexpr inline bool Iterator<I>::operator>=(const Iterator& rhs_) const noexcept
            {
                return (_it >= rhs_._it);
            }



            //  -- Member Access --
            template <typename I>
            constexpr inline typename Iterator<I>::reference Iterator<I>::operator*() noexcept
            {
                return (*_it);
            }

            template <typename I>
            constexpr inline typename Iterator<I>::pointer Iterator<I>::operator->() noexcept
            {
                return (&_it);
            }



        } // namespace iterator
    }     // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename I>
    constexpr inline range::Iterator<I> operator+(const typename range::Iterator<I>::difference_type n_, const range::Iterator<I>& it_) noexcept
    {
        return (it_ + n_);
    }

    template <typename I>
    constexpr inline range::Iterator<I> operator-(const typename range::Iterator<I>::difference_type n_, const range::Iterator<I>& it_) noexcept
    {
        return (it_ + n_);
    }



} // namespace arc
