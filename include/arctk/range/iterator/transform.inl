//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/transform.hpp" // IWYU pragma: export



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
            template <typename I, typename F>
            constexpr inline Transform<I, F>::Transform(I&& it_, const F& trans_) noexcept
              : Iterator<I>{std::move(it_)}
              , _trans{trans_}
            {
            }



            //  == OPERATORS ==
            //  -- Assignment --
            template <typename I, typename F>
            constexpr inline Transform<I>& Transform<I, F>::operator+=(const difference_type n_) noexcept
            {
                _it += n_;

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Transform<I>& Transform<I, F>::operator-=(const difference_type n_) noexcept
            {
                _it -= n_;

                return (*this);
            }


            //  -- Increment / Decrement --
            template <typename I, typename F>
            constexpr inline Transform<I>& Transform<I, F>::operator++() noexcept
            {
                ++_it;

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Transform<I> Transform<I, F>::operator++(const int /*unused*/) noexcept
            {
                Transform<I> it{*this};

                ++_it;

                return (it);
            }

            template <typename I, typename F>
            constexpr inline Transform<I>& Transform<I, F>::operator--() noexcept
            {
                --_it;

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Transform<I> Transform<I, F>::operator--(const int /*unused*/) noexcept
            {
                Transform<I> it{*this};

                --_it;

                return (it);
            }


            //  -- Arithmetic --
            template <typename I, typename F>
            constexpr inline Transform<I> Transform<I, F>::operator+(const difference_type n_) noexcept
            {
                return (Transform<I>{_it + n_});
            }

            template <typename I, typename F>
            constexpr inline Transform<I> Transform<I, F>::operator-(const difference_type n_) noexcept
            {
                return (Transform<I>{_it - n_});
            }



            //  -- Member Access --
            template <typename I, typename F>
            constexpr inline typename iterator::Transform<I, F>::trans_type Transform<I, F>::operator*() noexcept
            {
                return (_trans(*_it));
            }



        } // namespace iterator
    }     // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename I, typename F>
    constexpr inline range::iterator::Transform<I> operator+(const typename range::iterator::Transform<I>::difference_type n_, const range::Iterator<I>& it_) noexcept
    {
        return (it_ + n_);
    }

    template <typename I, typename F>
    constexpr inline range::iterator::Transform<I> operator-(const typename range::iterator::Transform<I>::difference_type n_, const range::Iterator<I>& it_) noexcept
    {
        return (it_ + n_);
    }



} // namespace arc
