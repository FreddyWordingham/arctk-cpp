//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/alg/vecN.hpp>



//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.hpp>

//  -- Std --
#include <algorithm>
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
          : _elems{}
        {
        }

        template <typename T, std::size_t N>
        constexpr inline Vec<T, N>::Vec(const std::array<T, N>& elems_) noexcept
          : _elems{elems_}
        {
        }



        //  == OPERATORS ==
        //  -- Assignment --
        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator+=(const T& rhs_) noexcept
        {
            std::for_each(std::begin(_elems), std::end(_elems), [&rhs_](T& n) { n += rhs_; });

            return (*this);
        }

        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator+=(const Vec& rhs_) noexcept
        {
            for (auto [l, r] : (_elems, rhs_._elems))
            {
                l += r;
            }

            return (*this);
        }

        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator-=(const T& rhs_) noexcept
        {
            std::for_each(std::begin(_elems), std::end(_elems), [&rhs_](T& n) { n -= rhs_; });

            return (*this);
        }

        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator-=(const Vec& rhs_) noexcept
        {
            for (auto [l, r] : (_elems, rhs_._elems))
            {
                l -= r;
            }

            return (*this);
        }

        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator*=(const T& rhs_) noexcept
        {
            std::for_each(std::begin(_elems), std::end(_elems), [&rhs_](T& n) { n *= rhs_; });

            return (*this);
        }

        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator/=(const T& rhs_) noexcept
        {
            std::for_each(std::begin(_elems), std::end(_elems), [&rhs_](T& n) { n /= rhs_; });

            return (*this);
        }


        //  -- Increment / Decrement --
        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator++() noexcept
        {
            std::for_each(std::begin(_elems), std::end(_elems), [](T& n) { ++n; });

            return (*this);
        }

        template <typename T, std::size_t N>
        constexpr inline const Vec<T, N>& Vec<T, N>::operator--() noexcept
        {
            std::for_each(std::begin(_elems), std::end(_elems), [](T& n) { --n; });

            return (*this);
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



    } // namespace alg



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <typename T, std::size_t N>
    constexpr inline const alg::Vec<T, N> operator++(alg::Vec<T, N>& lhs_, int) noexcept
    {
        alg::Vec<T, N> vec{lhs_.elems()};

        ++lhs_;

        return (vec);
    }

    template <typename T, std::size_t N>
    constexpr inline const alg::Vec<T, N> operator--(alg::Vec<T, N>& lhs_, int) noexcept
    {
        alg::Vec<T, N> vec{lhs_.elems()};

        --lhs_;

        return (vec);
    }


    //  -- Arithmetic --
    template <typename T, std::size_t N>
    constexpr inline const alg::Vec<T, N> operator+(const alg::Vec<T, N>& rhs_) noexcept
    {
        std::array<T, N> elems{rhs_.elems()};

        std::for_each(std::begin(rhs_.elems()), std::end(rhs_.elems()), [](T& n) { n = +n; });

        return (alg::Vec<T, N>{elems});
    }

    template <typename T, std::size_t N>
    constexpr inline const alg::Vec<T, N> operator-(const alg::Vec<T, N>& rhs_) noexcept
    {
        std::array<T, N> elems{rhs_.elems()};

        std::for_each(std::begin(rhs_.elems()), std::end(rhs_.elems()), [](T& n) { n = -n; });

        return (alg::Vec<T, N>{elems});
    }

    template <typename T, std::size_t N, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, N> operator+(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        const alg::Vec<Dim, N> vec{};
        for (auto [v, l] : (vec.elems(), lhs_.elems()))
        {
            v = l + rhs_;
        }

        return (vec);
    }

    template <typename T, typename S, std::size_t N, typename Dim>
    constexpr inline const alg::Vec<Dim, N> operator+(const alg::Vec<T, N>& lhs_, const alg::Vec<S, N>& rhs_) noexcept
    {
        const alg::Vec<Dim, N> vec{};
        for (auto [v, l, r] : (vec.elems(), lhs_.elems(), rhs_.elems()))
        {
            v = l + r;
        }

        return (vec);
    }

    template <typename T, std::size_t N, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, N> operator-(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        const alg::Vec<Dim, N> vec{};
        for (auto [v, l] : (vec.elems(), lhs_.elems()))
        {
            v = l - rhs_;
        }

        return (vec);
    }

    template <typename T, typename S, std::size_t N, typename Dim>
    constexpr inline const alg::Vec<Dim, N> operator-(const alg::Vec<T, N>& lhs_, const alg::Vec<S, N>& rhs_) noexcept
    {
        const alg::Vec<Dim, N> vec{};
        for (auto [v, l, r] : (vec.elems(), lhs_.elems(), rhs_.elems()))
        {
            v = l - r;
        }

        return (vec);
    }

    template <typename T, std::size_t N, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, N> operator*(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        const alg::Vec<Dim, N> vec{};
        for (auto [v, l, r] : (vec.elems(), lhs_.elems(), rhs_.elems()))
        {
            v = l * r;
        }

        return (vec);
    }

    template <typename T, std::size_t N, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, N> operator/(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept
    {
        const alg::Vec<Dim, N> vec{};
        for (auto [v, l, r] : (vec.elems(), lhs_.elems(), rhs_.elems()))
        {
            v = l / r;
        }

        return (vec);
    }


    //  -- Comparison --
    template <typename T, std::size_t N>
    constexpr inline bool operator==(const alg::Vec<T, N>& lhs_, const alg::Vec<T, N>& rhs_) noexcept
    {
        return (math::equal(lhs_.x, rhs_.x) && math::equal(lhs_.y, rhs_.y) && math::equal(lhs_.z, rhs_.z) && math::equal(lhs_.w, rhs_.w));
    }

    template <typename T, std::size_t N>
    constexpr inline bool operator!=(const alg::Vec<T, N>& lhs_, const alg::Vec<T, N>& rhs_) noexcept
    {
        return (!(lhs_ == rhs_));
    }

    template <typename T, std::size_t N>
    constexpr inline bool operator<(const alg::Vec<T, N>& lhs_, const alg::Vec<T, N>& rhs_) noexcept
    {
        return ((lhs_.x < rhs_.x) && (lhs_.y < rhs_.y) && (lhs_.z < rhs_.z) && (lhs_.w < rhs_.w));
    }

    template <typename T, std::size_t N>
    constexpr inline bool operator>(const alg::Vec<T, N>& lhs_, const alg::Vec<T, N>& rhs_) noexcept
    {
        return ((lhs_.x > rhs_.x) && (lhs_.y > rhs_.y) && (lhs_.z > rhs_.z) && (lhs_.w > rhs_.w));
    }

    template <typename T, std::size_t N>
    constexpr inline bool operator<=(const alg::Vec<T, N>& lhs_, const alg::Vec<T, N>& rhs_) noexcept
    {
        return ((lhs_.x <= rhs_.x) && (lhs_.y <= rhs_.y) && (lhs_.z <= rhs_.z) && (lhs_.w <= rhs_.w));
    }

    template <typename T, std::size_t N>
    constexpr inline bool operator>=(const alg::Vec<T, N>& lhs_, const alg::Vec<T, N>& rhs_) noexcept
    {
        return ((lhs_.x >= rhs_.x) && (lhs_.y >= rhs_.y) && (lhs_.z >= rhs_.z) && (lhs_.w >= rhs_.w));
    }



} // namespace arc
