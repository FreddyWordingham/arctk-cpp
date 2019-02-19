//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == CLASSES ==
        //  -- Iterator --
        template <typename T>
        class Iterator
        {
            //  == ALIASES ==
          public:
            //  -- Iterator --
            using iterator_category = std::forward_iterator_tag;
            using value_type        = std::remove_cv_t<T>;
            using difference_type   = std::ptrdiff_t;
            using pointer           = const T*;
            using reference         = const T&;


            //  == FIELDS ==
          protected:
            //  -- Data --
            const T* _pointer;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Iterator(const T* _pointer) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Increment / Decrement --
            constexpr inline Iterator& operator++() noexcept;
            constexpr inline Iterator  operator++(const int /*unused*/) noexcept;

            //  -- Comparison --
            constexpr inline bool operator==(const Iterator<T>& rhs_) const noexcept;
            inline bool           operator!=(const Iterator<T>& rhs_) const noexcept;

            //  -- Member Access --
            constexpr inline reference operator*() noexcept;
            constexpr inline pointer   operator->() noexcept;
        };



    } // namespace range
} // namespace arc
