//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional.hpp" // IWYU pragma: export



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
                namespace bidirectional
                {



                    //  == CLASSES ==
                    //  -- Random --
                    template <typename T>
                    class Random : public arc::range::iterator::forward::Bidirectional<T>
                    {
                        //  == ALIASES ==
                      public:
                        //  -- Iterator --
                        using iterator_category = std::random_access_iterator_tag;
                        using value_type        = std::remove_cv_t<T>;
                        using difference_type   = std::ptrdiff_t;
                        using pointer           = const T*;
                        using reference         = const T&;


                        //  == INSTANTIATION ==
                      public:
                        //  -- Constructors --
                        constexpr inline Random(const T* pointer_) noexcept;


                        //  == OPERATORS ==
                      public:
                        //  -- Assignment --
                        constexpr inline Random& operator+=(const difference_type n_) noexcept
                        {
                            Iterator<T>::_pointer += n_;

                            return (*this);
                        }

                        //  -- Increment / Decrement --
                        constexpr inline Random& operator++() noexcept;
                        constexpr inline Random  operator++(const int /*unused*/) noexcept;
                        constexpr inline Random& operator--() noexcept;
                        constexpr inline Random  operator--(const int /*unused*/) noexcept;

                        //  -- Arithmetic --
                        constexpr inline Random operator+(const difference_type n_) noexcept
                        {
                            return (Random<T>{Iterator<T>::_pointer + n_});
                        }

                        //  -- Comparison --
                        constexpr inline bool operator==(const Random& rhs_) const noexcept;
                        inline bool           operator!=(const Random& rhs_) const noexcept;

                        //  -- Member Access --
                        constexpr inline reference operator*() noexcept;
                        constexpr inline pointer   operator->() noexcept;
                    };



                } // namespace bidirectional
            }     // namespace forward
        }         // namespace iterator
    }             // namespace range



    //  == OPERATORS ==
    //  -- Arithetic --
    template <typename T>
    constexpr inline range::iterator::forward::bidirectional::Random<T> operator+(const typename range::iterator::forward::bidirectional::Random<T>::difference_type n_, const range::iterator::forward::bidirectional::Random<T>& it_) noexcept
    {
        return (it_ + n_);
    }



} // namespace arc
