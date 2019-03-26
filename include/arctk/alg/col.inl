//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/col.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/arithmetic.inl"
#include "arctk/range/view/zip.inl" // TODO find a way to remove this? Need it to know result of operator/ etc.

//  -- Std --
#include <cassert>
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, std::size_t N>
        constexpr inline Col<T, N>::Col() noexcept
          : _elems()
        {
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline Col<T, N>::Col(const A... elems_) noexcept
          : _elems{elems_...}
        {
        }

        // TODO col and row conversion constructors / operators?



        //  == OPERATORS ==
        //  -- Access --
        template <typename T, std::size_t N>
        constexpr inline T& Col<T, N>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Col<T, N>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, std::size_t N>
        constexpr inline const std::array<T, N>& Col<T, N>::elems() const noexcept
        {
            return (_elems);
        }


        //  -- Dimensions --
        template <typename T, std::size_t N>
        constexpr inline T& Col<T, N>::x() noexcept
        {
            static_assert(N >= 1);

            return (_elems[0]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Col<T, N>::x() const noexcept
        {
            static_assert(N >= 1);

            return (_elems[0]);
        }

        template <typename T, std::size_t N>
        constexpr inline T& Col<T, N>::y() noexcept
        {
            static_assert(N >= 2);

            return (_elems[1]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Col<T, N>::y() const noexcept
        {
            static_assert(N >= 2);

            return (_elems[1]);
        }

        template <typename T, std::size_t N>
        constexpr inline T& Col<T, N>::z() noexcept
        {
            static_assert(N >= 3);

            return (_elems[2]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Col<T, N>::z() const noexcept
        {
            static_assert(N >= 3);

            return (_elems[2]);
        }

        template <typename T, std::size_t N>
        constexpr inline T& Col<T, N>::w() noexcept
        {
            static_assert(N >= 4);

            return (_elems[3]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Col<T, N>::w() const noexcept
        {
            static_assert(N >= 4);

            return (_elems[3]);
        }



        //  -- Range --
        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::begin() noexcept
        {
            return (std::begin(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::begin() const noexcept
        {
            return (std::begin(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::end() noexcept
        {
            return (std::end(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::end() const noexcept
        {
            return (std::end(_elems));
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() + std::declval<S>()), N> operator+(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Col<decltype(std::declval<T>() + std::declval<S>()), N> col{};

        for (auto& [c, l] : range::view::Zip{col, lhs_})
        {
            c = l + rhs_;
        }

        return (col);
    }

    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() - std::declval<S>()), N> operator-(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Col<decltype(std::declval<T>() - std::declval<S>()), N> col{};

        for (auto& [c, l] : range::view::Zip{col, lhs_})
        {
            c = l - rhs_;
        }

        return (col);
    }

    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() * std::declval<S>()), N> operator*(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Col<decltype(std::declval<T>() * std::declval<S>()), N> col{};

        for (auto& [c, l] : range::view::Zip{col, lhs_})
        {
            c = l * rhs_;
        }

        return (col);
    }

    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() / std::declval<S>()), N> operator/(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Col<decltype(std::declval<T>() / std::declval<S>()), N> col{};

        for (auto& [c, l] : range::view::Zip{col, lhs_})
        {
            c = l / rhs_;
        }

        return (col);
    }

    template <typename T, typename S>
    inline alg::Col<decltype(std::declval<T>() * std::declval<S>()), 3> operator^(const alg::Col<T, 3>& lhs_, const alg::Col<S, 3>& rhs_) noexcept
    {
        return (alg::Col<decltype(std::declval<T>() * std::declval<S>()), 3>{(lhs_.y() * rhs_.z()) - (lhs_.z() * rhs_.y()), (lhs_.z() * rhs_.x()) - (lhs_.x() * rhs_.z()), (lhs_.x() * rhs_.y()) - (lhs_.y() * rhs_.x())});
    }



} // namespace arc
