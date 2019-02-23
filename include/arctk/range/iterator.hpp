//  == GUARD ==
#pragma once



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
            //  -- Iterator --
            using iterator_category = typename I::iterator_category;
            using value_type        = typename I::value_type;
            using difference_type   = typename I::difference_type;
            using pointer           = typename I::pointer;
            using reference         = typename I::reference;


            //  == FIELDS ==
          protected:
            //  -- Data --
            I _it;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Iterator(I&& it_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Comparison --
            constexpr inline bool operator==(const Iterator& rhs_) const noexcept;
            inline bool           operator!=(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator<(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator>(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator<=(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator>=(const Iterator& rhs_) const noexcept;
        };



    } // namespace range
} // namespace arc
