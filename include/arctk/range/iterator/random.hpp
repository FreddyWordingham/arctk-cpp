//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.hpp"



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == CLASSES ==
            //  -- Random --
            template <typename I>
            class Random : public Iterator<I>
            {
                //  == ASSERTIONS ==
                //  -- Category --
                static_assert(std::is_same_v<std::random_access_iterator_tag, typename I::iterator_category>);


                //  == ALIASES ==
              public:
                //  -- Iterator --
                using iterator_category = typename I::iterator_category;
                using value_type        = typename I::value_type;
                using difference_type   = typename I::difference_type;
                using pointer           = typename I::pointer;
                using reference         = typename I::reference;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Random(I&& it_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                constexpr inline Random& operator+=(const difference_type n_) noexcept;
                constexpr inline Random& operator-=(const difference_type n_) noexcept;

                //  -- Increment / Decrement --
                constexpr inline Random& operator++() noexcept;
                constexpr inline Random  operator++(const int /*unused*/) noexcept;
                constexpr inline Random& operator--() noexcept;
                constexpr inline Random  operator--(const int /*unused*/) noexcept;

                //  -- Arithmetic --
                constexpr inline Random operator+(const difference_type n_) noexcept;
                constexpr inline Random operator-(const difference_type n_) noexcept;

                //  -- Comparison --
                constexpr inline bool operator==(const Random& rhs_) const noexcept;
                inline bool           operator!=(const Random& rhs_) const noexcept;
                constexpr inline bool operator<(const Random& rhs_) const noexcept;
                constexpr inline bool operator>(const Random& rhs_) const noexcept;
                constexpr inline bool operator<=(const Random& rhs_) const noexcept;
                constexpr inline bool operator>=(const Random& rhs_) const noexcept;

                //  -- Member Access --
                constexpr inline reference operator*() noexcept;
                constexpr inline pointer   operator->() noexcept;
            };



        } // namespace iterator
    }     // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename I>
    constexpr inline range::iterator::Random<I> operator+(const typename range::iterator::Random<I>::difference_type n_, const range::iterator::Random<I>& it_) noexcept;
    template <typename I>
    constexpr inline range::iterator::Random<I> operator-(const typename range::iterator::Random<I>::difference_type n_, const range::iterator::Random<I>& it_) noexcept;



} // namespace arc
