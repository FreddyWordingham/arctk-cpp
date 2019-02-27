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



        //  == CLASSES ==
        //  -- Iterator --
        template <typename I>
        class Iterator
        {
            //  == ALIASES ==
          public:
            //  -- Traits --
            using value_type        = typename std::iterator_traits<I>::value_type;
            using reference         = typename std::iterator_traits<I>::reference;
            using pointer           = typename std::iterator_traits<I>::pointer;
            using difference_type   = typename std::iterator_traits<I>::difference_type;
            using iterator_category = typename std::iterator_traits<I>::iterator_category;


            //  == FIELDS ==
          protected:
            //  -- Iterators --
            I       _it;
            const I _end;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Iterator(const I& start_, const I& end_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Comparison --
            constexpr inline bool operator==(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator!=(const Iterator& rhs_) const noexcept;
        };



    } // namespace range
} // namespace arc
