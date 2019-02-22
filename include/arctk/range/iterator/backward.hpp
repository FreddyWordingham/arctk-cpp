//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == CLASSES ==
            //  -- Backward --
            template <typename T>
            class Backward : public arc::range::Iterator<T>
            {
                //  == ALIASES ==
              public:
                //  -- Iterator --
                using iterator_category = std::forward_iterator_tag;
                using value_type        = std::remove_cv_t<T>;
                using difference_type   = std::ptrdiff_t;
                using pointer           = const T*;
                using reference         = const T&;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Backward(const T* pointer_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Backward& operator++() noexcept;
                constexpr inline Backward  operator++(const int /*unused*/) noexcept;

                //  -- Comparison --
                constexpr inline bool operator==(const Backward& rhs_) const noexcept;
                inline bool           operator!=(const Backward& rhs_) const noexcept;

                //  -- Member Access --
                constexpr inline reference operator*() noexcept;
                constexpr inline pointer   operator->() noexcept;
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc
