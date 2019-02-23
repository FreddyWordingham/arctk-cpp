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
          protected:
            //  -- Iterator --
            using iterator_type     = I;
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
            //  -- Assignment --
            constexpr inline I& operator+=(const difference_type n_) noexcept;
            constexpr inline I& operator-=(const difference_type n_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Iterator& operator++() noexcept;
            constexpr inline Iterator  operator++(const int /*unused*/) noexcept;
            constexpr inline Iterator& operator--() noexcept;
            constexpr inline Iterator  operator--(const int /*unused*/) noexcept;

            //  -- Arithmetic --
            constexpr inline Iterator operator+(const difference_type n_) noexcept;
            constexpr inline Iterator operator-(const difference_type n_) noexcept;

            //  -- Comparison --
            constexpr inline bool operator==(const Iterator& rhs_) const noexcept;
            inline bool           operator!=(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator<(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator>(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator<=(const Iterator& rhs_) const noexcept;
            constexpr inline bool operator>=(const Iterator& rhs_) const noexcept;

            //  -- Member Access --
            constexpr inline reference operator*() noexcept;
            constexpr inline pointer   operator->() noexcept;
        };



    } // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename I>
    constexpr inline range::Iterator<I> operator+(const typename range::Iterator<I>::difference_type n_, const range::Iterator<I>& it_) noexcept;
    template <typename I>
    constexpr inline range::Iterator<I> operator-(const typename range::Iterator<I>::difference_type n_, const range::Iterator<I>& it_) noexcept;



} // namespace arc
