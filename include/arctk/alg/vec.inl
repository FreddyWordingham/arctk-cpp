//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/vec.hpp" // IWYU pragma: export



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
        constexpr inline Vec<T, N>::Vec() noexcept
          : _elems()
        {
        }

        template <typename T, std::size_t N>
        constexpr inline Col<T, N>::Col() noexcept
          : Vec<T, N>{}
        {
        }

        template <typename T, std::size_t N>
        constexpr inline Row<T, N>::Row() noexcept
          : Vec<T, N>{}
        {
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline Vec<T, N>::Vec(const A... elems_) noexcept
          : _elems{elems_...}
        {
            static_assert(sizeof...(A) == N);
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline Col<T, N>::Col(const A... elems_) noexcept
          : Vec<T, N>{elems_...}
        {
            static_assert(sizeof...(A) == N);
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline Row<T, N>::Row(const A... elems_) noexcept
          : Vec<T, N>{elems_...}
        {
            static_assert(sizeof...(A) == N);
        }



        //  == OPERATORS ==
        //  -- Conversions --
        template <typename T, std::size_t N>
        constexpr inline Col<T, N>::operator Row<T, N>() noexcept
        {
            return (Row<T, N>{Vec<T, N>::_elems});
        }

        template <typename T, std::size_t N>
        constexpr inline Row<T, N>::operator Col<T, N>() noexcept
        {
            return (Col<T, N>{Vec<T, N>::_elems});
        }


        //  -- Access --
        template <typename T, std::size_t N>
        constexpr inline T& Vec<T, N>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Vec<T, N>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, std::size_t N>
        constexpr inline const std::array<T, N>& Vec<T, N>::elems() const noexcept
        {
            return (_elems);
        }


        //  -- Dimensions --
        template <typename T, std::size_t N>
        constexpr inline T& Vec<T, N>::x() noexcept
        {
            static_assert(N >= 1);

            return (_elems[0]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Vec<T, N>::x() const noexcept
        {
            static_assert(N >= 1);

            return (_elems[0]);
        }

        template <typename T, std::size_t N>
        constexpr inline T& Vec<T, N>::y() noexcept
        {
            static_assert(N >= 2);

            return (_elems[1]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Vec<T, N>::y() const noexcept
        {
            static_assert(N >= 2);

            return (_elems[1]);
        }

        template <typename T, std::size_t N>
        constexpr inline T& Vec<T, N>::z() noexcept
        {
            static_assert(N >= 3);

            return (_elems[2]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Vec<T, N>::z() const noexcept
        {
            static_assert(N >= 3);

            return (_elems[2]);
        }

        template <typename T, std::size_t N>
        constexpr inline T& Vec<T, N>::w() noexcept
        {
            static_assert(N >= 4);

            return (_elems[3]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Vec<T, N>::w() const noexcept
        {
            static_assert(N >= 4);

            return (_elems[3]);
        }


        //  -- Range --
        template <typename T, std::size_t N>
        constexpr inline auto Vec<T, N>::begin() noexcept
        {
            return (std::begin(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Vec<T, N>::begin() const noexcept
        {
            return (std::begin(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Vec<T, N>::end() noexcept
        {
            return (std::end(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Vec<T, N>::end() const noexcept
        {
            return (std::end(_elems));
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() + std::declval<S>()), N> operator+(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Vec<decltype(std::declval<T>() + std::declval<S>()), N> vec{};

        for (auto& [v, l] : range::view::Zip{vec, lhs_})
        {
            v = l + rhs_;
        }

        return (vec);
    }

    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() - std::declval<S>()), N> operator-(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Vec<decltype(std::declval<T>() - std::declval<S>()), N> vec{};

        for (auto& [v, l] : range::view::Zip{vec, lhs_})
        {
            v = l - rhs_;
        }

        return (vec);
    }

    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() * std::declval<S>()), N> operator*(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Vec<decltype(std::declval<T>() * std::declval<S>()), N> vec{};

        for (auto& [v, l] : range::view::Zip{vec, lhs_})
        {
            v = l * rhs_;
        }

        return (vec);
    }

    template <typename T, std::size_t N, typename S>
    inline decltype(std::declval<T>() * std::declval<S>()) operator*(const alg::Vec<T, N>& lhs_, const alg::Vec<S, N>& rhs_) noexcept
    {
        decltype(std::declval<T>() * std::declval<S>()) sum{};

        for (const auto& [l, r] : range::view::Zip{lhs_, rhs_})
        {
            sum += l * r;
        }

        return (sum);
    }

    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() / std::declval<S>()), N> operator/(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Vec<decltype(std::declval<T>() / std::declval<S>()), N> vec{};

        for (auto& [v, l] : range::view::Zip{vec, lhs_})
        {
            v = l / rhs_;
        }

        return (vec);
    }

    template <typename T, typename S>
    inline alg::Vec<decltype(std::declval<T>() * std::declval<S>()), 3> operator^(const alg::Vec<T, 3>& lhs_, const alg::Vec<S, 3>& rhs_) noexcept
    {
        return (alg::Vec<decltype(std::declval<T>() * std::declval<S>()), 3>{(lhs_.y() * rhs_.z()) - (lhs_.z() * rhs_.y()), (lhs_.z() * rhs_.x()) - (lhs_.x() * rhs_.z()), (lhs_.x() * rhs_.y()) - (lhs_.y() * rhs_.x())});
    }



} // namespace arc
