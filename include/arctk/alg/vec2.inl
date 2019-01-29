//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/alg/vec2.hpp>



//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.hpp>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        constexpr inline Vec<T, 2>::Vec() noexcept
          : x{}
          , y{}
        {
        }

        template <typename T>
        constexpr inline Vec<T, 2>::Vec(const T& x_, const T& y_) noexcept
          : x{x_}
          , y{y_}
        {
        }



        //  == OPERATORS ==
        //  -- Assignment --
        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator+=(const T& rhs_) noexcept
        {
            x += rhs_;
            y += rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator+=(const Vec& rhs_) noexcept
        {
            x += rhs_.x;
            y += rhs_.y;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator-=(const T& rhs_) noexcept
        {
            x -= rhs_;
            y -= rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator-=(const Vec& rhs_) noexcept
        {
            x -= rhs_.x;
            y -= rhs_.y;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator*=(const T& rhs_) noexcept
        {
            x *= rhs_;
            y *= rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator/=(const T& rhs_) noexcept
        {
            x /= rhs_;
            y /= rhs_;

            return (*this);
        }


        //  -- Increment / Decrement --
        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator++() noexcept
        {
            ++x;
            ++y;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 2>& Vec<T, 2>::operator--() noexcept
        {
            --x;
            --y;

            return (*this);
        }


        //  -- Access --
        template <typename T>
        constexpr inline T& Vec<T, 2>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < 2);

            return (&x[index_]);
        }

        template <typename T>
        constexpr inline const T& Vec<T, 2>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < 2);

            return (&x[index_]);
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <typename T>
    constexpr inline const alg::Vec<T, 2> operator++(alg::Vec<T, 2>& lhs_, int) noexcept
    {
        alg::Vec<T, 2> vec{lhs_.x, lhs_.y};

        ++lhs_;

        return (vec);
    }

    template <typename T>
    constexpr inline const alg::Vec<T, 2> operator--(alg::Vec<T, 2>& lhs_, int) noexcept
    {
        alg::Vec<T, 2> vec{lhs_.x, lhs_.y};

        --lhs_;

        return (vec);
    }


    //  -- Arithmetic --
    template <typename T>
    constexpr inline const alg::Vec<T, 2> operator+(const alg::Vec<T, 2>& rhs_) noexcept
    {
        return (alg::Vec<T, 2>{+rhs_.x, +rhs_.y});
    }

    template <typename T>
    constexpr inline const alg::Vec<T, 2> operator-(const alg::Vec<T, 2>& rhs_) noexcept
    {
        return (alg::Vec<T, 2>{-rhs_.x, -rhs_.y});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 2> operator+(const alg::Vec<T, 2>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 2>{lhs_.x + rhs_, lhs_.y + rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 2> operator+(const alg::Vec<T, 2>& lhs_, const alg::Vec<S, 2>& rhs_) noexcept
    {
        return (alg::Vec<Dim, 2>{lhs_.x + rhs_.x, lhs_.y + rhs_.y});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 2> operator-(const alg::Vec<T, 2>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 2>{lhs_.x - rhs_, lhs_.y - rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 2> operator-(const alg::Vec<T, 2>& lhs_, const alg::Vec<S, 2>& rhs_) noexcept
    {
        return (alg::Vec<Dim, 2>{lhs_.x - rhs_.x, lhs_.y - rhs_.y});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 2> operator*(const alg::Vec<T, 2>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 2>{lhs_.x * rhs_, lhs_.y * rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 2> operator/(const alg::Vec<T, 2>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 2>{lhs_.x / rhs_, lhs_.y / rhs_});
    }


    //  -- Comparison --
    template <typename T>
    constexpr inline bool operator==(const alg::Vec<T, 2>& lhs_, const alg::Vec<T, 2>& rhs_) noexcept
    {
        return (math::equal(lhs_.x, rhs_.x) && math::equal(lhs_.y, rhs_.y));
    }

    template <typename T>
    constexpr inline bool operator!=(const alg::Vec<T, 2>& lhs_, const alg::Vec<T, 2>& rhs_) noexcept
    {
        return (!(lhs_ == rhs_));
    }

    template <typename T>
    constexpr inline bool operator<(const alg::Vec<T, 2>& lhs_, const alg::Vec<T, 2>& rhs_) noexcept
    {
        return ((lhs_.x < rhs_.x) && (lhs_.y < rhs_.y));
    }

    template <typename T>
    constexpr inline bool operator>(const alg::Vec<T, 2>& lhs_, const alg::Vec<T, 2>& rhs_) noexcept
    {
        return ((lhs_.x > rhs_.x) && (lhs_.y > rhs_.y));
    }

    template <typename T>
    constexpr inline bool operator<=(const alg::Vec<T, 2>& lhs_, const alg::Vec<T, 2>& rhs_) noexcept
    {
        return ((lhs_.x <= rhs_.x) && (lhs_.y <= rhs_.y));
    }

    template <typename T>
    constexpr inline bool operator>=(const alg::Vec<T, 2>& lhs_, const alg::Vec<T, 2>& rhs_) noexcept
    {
        return ((lhs_.x >= rhs_.x) && (lhs_.y >= rhs_.y));
    }



} // namespace arc
