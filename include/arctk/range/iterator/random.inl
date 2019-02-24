//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/random.hpp" // IWYU pragma: export



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
            constexpr inline Random<I>::Random(I&& it_) noexcept
              : Iterator<I>{std::move(it_)}
            {
            }



            //  == OPERATORS ==
            //  -- Assignment --
            template <typename I>
            constexpr inline Random<I>& Random<I>::operator+=(const difference_type n_) noexcept
            {
                Iterator<I>::_it += n_;

                return (*this);
            }

            template <typename I>
            constexpr inline Random<I>& Random<I>::operator-=(const difference_type n_) noexcept
            {
                Iterator<I>::_it -= n_;

                return (*this);
            }


            //  -- Increment / Decrement --
            template <typename I>
            constexpr inline Random<I>& Random<I>::operator++() noexcept
            {
                ++Iterator<I>::_it;

                return (*this);
            }

            template <typename I>
            constexpr inline Random<I> Random<I>::operator++(const int /*unused*/) noexcept
            {
                Random<I> it{*this};

                ++Iterator<I>::_it;

                return (it);
            }

            template <typename I>
            constexpr inline Random<I>& Random<I>::operator--() noexcept
            {
                --Iterator<I>::_it;

                return (*this);
            }

            template <typename I>
            constexpr inline Random<I> Random<I>::operator--(const int /*unused*/) noexcept
            {
                Random<I> it{*this};

                --Iterator<I>::_it;

                return (it);
            }


            //  -- Arithmetic --
            template <typename I>
            constexpr inline Random<I> Random<I>::operator+(const difference_type n_) noexcept
            {
                return (Random<I>{Iterator<I>::_it + n_});
            }

            template <typename I>
            constexpr inline Random<I> Random<I>::operator-(const difference_type n_) noexcept
            {
                return (Random<I>{Iterator<I>::_it - n_});
            }


            //  -- Comparison --
            template <typename I>
            constexpr inline bool Random<I>::operator==(const Random<I>& rhs_) const noexcept
            {
                return (Iterator<I>::_it == rhs_._it);
            }

            template <typename I>
            inline bool Random<I>::operator!=(const Random<I>& rhs_) const noexcept
            {
                return (Iterator<I>::_it != rhs_._it);
            }

            template <typename I>
            constexpr inline bool Random<I>::operator<(const Random& rhs_) const noexcept
            {
                return (Iterator<I>::_it < rhs_._it);
            }

            template <typename I>
            constexpr inline bool Random<I>::operator>(const Random& rhs_) const noexcept
            {
                return (Iterator<I>::_it > rhs_._it);
            }

            template <typename I>
            constexpr inline bool Random<I>::operator<=(const Random& rhs_) const noexcept
            {
                return (Iterator<I>::_it <= rhs_._it);
            }

            template <typename I>
            constexpr inline bool Random<I>::operator>=(const Random& rhs_) const noexcept
            {
                return (Iterator<I>::_it >= rhs_._it);
            }


            //  -- Member Access --
            template <typename I>
            constexpr inline typename Random<I>::reference Random<I>::operator*() noexcept
            {
                return (*Iterator<I>::_it);
            }

            template <typename I>
            constexpr inline typename Random<I>::pointer Random<I>::operator->() noexcept
            {
                return (&Iterator<I>::_it);
            }



        } // namespace iterator
    }     // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename I>
    constexpr inline range::iterator::Random<I> operator+(const typename range::iterator::Random<I>::difference_type n_, const range::iterator::Random<I>& it_) noexcept
    {
        return (range::iterator::Random<I>{it_ + n_});
    }

    template <typename I>
    constexpr inline range::iterator::Random<I> operator-(const typename range::iterator::Random<I>::difference_type n_, const range::iterator::Random<I>& it_) noexcept
    {
        return (range::iterator::Random<I>{it_ - n_});
    }



} // namespace arc
