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
            //  -- Transform --
            template <typename I, typename F>
            class Transform : public Iterator<I>
            {
                //  == ASSERTIONS ==
                //  -- Category --
                static_assert(std::is_same_v<std::random_access_iterator_tag, typename I::iterator_category>);


                //  == ALIASES ==
              public:
                //  -- Iterator --
                using iterator_category = typename I::iterator_category;
                using value_type        = typename std::invoke_result_t<F, typename I::value_type>;
                using difference_type   = typename I::difference_type;
                using pointer           = typename I::pointer;
                using reference         = typename I::reference;


                //  == FIELDS ==
              protected:
                //  -- Function --
                F _trans;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Transform(I&& it_, const F& trans_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                constexpr inline Transform& operator+=(const difference_type n_) noexcept;
                constexpr inline Transform& operator-=(const difference_type n_) noexcept;

                //  -- Increment / Decrement --
                constexpr inline Transform& operator++() noexcept;
                constexpr inline Transform  operator++(const int /*unused*/) noexcept;
                constexpr inline Transform& operator--() noexcept;
                constexpr inline Transform  operator--(const int /*unused*/) noexcept;

                //  -- Arithmetic --
                constexpr inline Transform operator+(const difference_type n_) noexcept;
                constexpr inline Transform operator-(const difference_type n_) noexcept;

                //  -- Comparison --
                constexpr inline bool operator==(const Transform& rhs_) const noexcept;
                inline bool           operator!=(const Transform& rhs_) const noexcept;
                constexpr inline bool operator<(const Transform& rhs_) const noexcept;
                constexpr inline bool operator>(const Transform& rhs_) const noexcept;
                constexpr inline bool operator<=(const Transform& rhs_) const noexcept;
                constexpr inline bool operator>=(const Transform& rhs_) const noexcept;

                //  -- Member Access --
                constexpr inline value_type operator*() noexcept;
            };



        } // namespace iterator
    }     // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename I, typename F>
    constexpr inline range::iterator::Transform<I, F> operator+(const typename range::iterator::Transform<I, F>::difference_type n_, const range::iterator::Transform<I, F>& it_) noexcept;
    template <typename I, typename F>
    constexpr inline range::iterator::Transform<I, F> operator-(const typename range::iterator::Transform<I, F>::difference_type n_, const range::iterator::Transform<I, F>& it_) noexcept;



} // namespace arc
