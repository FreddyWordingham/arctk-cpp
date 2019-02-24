//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.inl"



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
              , _trans(trans_)
            {
            }



            //  == OPERATORS ==
            //  -- Assignment --
            template <typename I, typename F>
            constexpr inline Transform<I, F>& Transform<I, F>::operator+=(const difference_type n_) noexcept
            {
                Iterator<I>::_it += n_;

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Transform<I, F>& Transform<I, F>::operator-=(const difference_type n_) noexcept
            {
                Iterator<I>::_it -= n_;

                return (*this);
            }


            //  -- Increment / Decrement --
            template <typename I, typename F>
            constexpr inline Transform<I, F>& Transform<I, F>::operator++() noexcept
            {
                ++Iterator<I>::_it;

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Transform<I, F> Transform<I, F>::operator++(const int /*unused*/) noexcept
            {
                Transform<I, F> it{*this};

                ++Iterator<I>::_it;

                return (it);
            }

            template <typename I, typename F>
            constexpr inline Transform<I, F>& Transform<I, F>::operator--() noexcept
            {
                --Iterator<I>::_it;

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Transform<I, F> Transform<I, F>::operator--(const int /*unused*/) noexcept
            {
                Transform<I, F> it{*this};

                --Iterator<I>::_it;

                return (it);
            }


            //  -- Arithmetic --
            template <typename I, typename F>
            constexpr inline Transform<I, F> Transform<I, F>::operator+(const difference_type n_) noexcept
            {
                return (Transform<I, F>{Iterator<I>::_it + n_});
            }

            template <typename I, typename F>
            constexpr inline Transform<I, F> Transform<I, F>::operator-(const difference_type n_) noexcept
            {
                return (Transform<I, F>{Iterator<I>::_it - n_});
            }


            //  -- Comparison --
            template <typename I, typename F>
            constexpr inline bool Transform<I, F>::operator==(const Transform<I, F>& rhs_) const noexcept
            {
                return (Iterator<I>::_it == rhs_._it);
            }

            template <typename I, typename F>
            inline bool Transform<I, F>::operator!=(const Transform<I, F>& rhs_) const noexcept
            {
                return (Iterator<I>::_it != rhs_._it);
            }

            template <typename I, typename F>
            constexpr inline bool Transform<I, F>::operator<(const Transform& rhs_) const noexcept
            {
                return (Iterator<I>::_it < rhs_._it);
            }

            template <typename I, typename F>
            constexpr inline bool Transform<I, F>::operator>(const Transform& rhs_) const noexcept
            {
                return (Iterator<I>::_it > rhs_._it);
            }

            template <typename I, typename F>
            constexpr inline bool Transform<I, F>::operator<=(const Transform& rhs_) const noexcept
            {
                return (Iterator<I>::_it <= rhs_._it);
            }

            template <typename I, typename F>
            constexpr inline bool Transform<I, F>::operator>=(const Transform& rhs_) const noexcept
            {
                return (Iterator<I>::_it >= rhs_._it);
            }


            //  -- Member Access --
            template <typename I, typename F>
            constexpr inline typename Transform<I, F>::value_type Transform<I, F>::operator*() noexcept
            {
                return (_trans(*Iterator<I>::_it));
            }



        } // namespace iterator
    }     // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename I, typename F>
    constexpr inline range::iterator::Transform<I, F> operator+(const typename range::iterator::Transform<I, F>::difference_type n_, const range::iterator::Transform<I, F>& it_) noexcept
    {
        return (range::iterator::Transform<I, F>{it_ + n_});
    }

    template <typename I, typename F>
    constexpr inline range::iterator::Transform<I, F> operator-(const typename range::iterator::Transform<I, F>::difference_type n_, const range::iterator::Transform<I, F>& it_) noexcept
    {
        return (range::iterator::Transform<I, F>{it_ - n_});
    }



} // namespace arc
