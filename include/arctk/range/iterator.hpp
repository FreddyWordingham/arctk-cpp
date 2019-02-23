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
            constexpr inline I& operator+=(const difference_type n_) noexcept
            {
                _it += n_;

                return (*this);
            }

            //  -- Increment / Decrement --
            constexpr inline Iterator& operator++() noexcept;
            constexpr inline Iterator  operator++(const int /*unused*/) noexcept;

            //  -- Comparison --
            constexpr inline bool operator==(const Iterator& rhs_) const noexcept;
            inline bool           operator!=(const Iterator& rhs_) const noexcept;

            //  -- Member Access --
            constexpr inline reference operator*() noexcept;
            constexpr inline pointer   operator->() noexcept;
        };



    } // namespace range
} // namespace arc
