//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator/forward.hpp" // IWYU pragma: export



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
            namespace forward
            {



                //  == CLASSES ==
                //  -- Bidirectional --
                template <typename T>
                class Bidirectional : public arc::range::iterator::Forward<T>
                {
                    //  == ALIASES ==
                  public:
                    //  -- Iterator --
                    using iterator_category = std::bidirectional_iterator_tag;
                    using value_type        = std::remove_cv_t<T>;
                    using difference_type   = std::ptrdiff_t;
                    using pointer           = const T*;
                    using reference         = const T&;


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    constexpr inline Bidirectional(const T* pointer_) noexcept;


                    //  == OPERATORS ==
                  public:
                    //  -- Increment / Decrement --
                    constexpr inline Bidirectional& operator++() noexcept;
                    constexpr inline Bidirectional  operator++(const int /*unused*/) noexcept;
                    constexpr inline Bidirectional& operator--() noexcept;
                    constexpr inline Bidirectional  operator--(const int /*unused*/) noexcept;

                    //  -- Comparison --
                    constexpr inline bool operator==(const Bidirectional& rhs_) const noexcept;
                    inline bool           operator!=(const Bidirectional& rhs_) const noexcept;

                    //  -- Member Access --
                    constexpr inline reference operator*() noexcept;
                    constexpr inline pointer   operator->() noexcept;
                };



            } // namespace forward
        }     // namespace iterator
    }         // namespace range
} // namespace arc
