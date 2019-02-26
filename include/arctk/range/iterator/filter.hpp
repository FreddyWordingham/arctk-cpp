//  == GUARD ==
#pragma once



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
            //  -- Filter --
            template <typename I, typename F>
            class Filter
            {
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type        = std::iterator_traits<I>::value_type;
                using reference         = std::iterator_traits<I>::reference;
                using pointer           = std::iterator_traits<I>::pointer;
                using difference_type   = std::iterator_traits<I>::difference_type;
                using iterator_category = std::iterator_traits<I>::iterator_category;


                //  == FIELDS ==
              private:
                //  -- Iterators --
                const I _it;
                const I _end;

                //  -- Functors --
                F _pred;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Filter(I* const start_, const I& end_, F pred_) noexcept;

              private:
                //  -- Initialisation --
                static constexpr inline I init_it(I* const start_, const I& end_, F pred_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Filter& operator++() noexcept;
                constexpr inline Filter  operator++(const int /*unused*/) noexcept;

                //  -- Comparison --
                constexpr inline bool operator==(const Filter& rhs_) const noexcept;
                constexpr inline bool operator!=(const Filter& rhs_) const noexcept;

                //  -- Member Access --
                constexpr inline reference operator*() noexcept;
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc
