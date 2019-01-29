//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/alg/vec4.hpp>



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
        constexpr inline Vec<T, 4>::Vec() noexcept
          : x{}
          , y{}
          , z{}
          , w{}
        {
        }

        template <typename T>
        constexpr inline Vec<T, 4>::Vec(const T& x_, const T& y_, const T& z_, const T& w_) noexcept
          : x{x_}
          , y{y_}
          , z{z_}
          , w{w_}
        {
        }



        //  == OPERATORS ==
        //  -- Assignment --
        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator+=(const T& rhs_) noexcept
        {
            x += rhs_;
            y += rhs_;
            z += rhs_;
            w += rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator+=(const Vec& rhs_) noexcept
        {
            x += rhs_.x;
            y += rhs_.y;
            z += rhs_.z;
            w += rhs_.w;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator-=(const T& rhs_) noexcept
        {
            x -= rhs_;
            y -= rhs_;
            z -= rhs_;
            w -= rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator-=(const Vec& rhs_) noexcept
        {
            x -= rhs_.x;
            y -= rhs_.y;
            z -= rhs_.z;
            w -= rhs_.w;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator*=(const T& rhs_) noexcept
        {
            x *= rhs_;
            y *= rhs_;
            z *= rhs_;
            w *= rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator/=(const T& rhs_) noexcept
        {
            x /= rhs_;
            y /= rhs_;
            z /= rhs_;
            w /= rhs_;

            return (*this);
        }


        //  -- Increment / Decrement --
        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator++() noexcept
        {
            ++x;
            ++y;
            ++z;
            ++w;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 4>& Vec<T, 4>::operator--() noexcept
        {
            --x;
            --y;
            --z;
            --w;

            return (*this);
        }


        //  -- Access --
        template <typename T>
        constexpr inline T& Vec<T, 4>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < 4);

            return (&x[index_]);
        }

        template <typename T>
        constexpr inline const T& Vec<T, 4>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < 4);

            return (&x[index_]);
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <typename T>
    constexpr inline const alg::Vec<T, 4> operator++(alg::Vec<T, 4>& lhs_, int) noexcept
    {
        alg::Vec<T, 4> vec{lhs_.x, lhs_.y, lhs_.z, lhs_.w};

        ++lhs_;

        return (vec);
    }

    template <typename T>
    constexpr inline const alg::Vec<T, 4> operator--(alg::Vec<T, 4>& lhs_, int) noexcept
    {
        alg::Vec<T, 4> vec{lhs_.x, lhs_.y, lhs_.z, lhs_.w};

        --lhs_;

        return (vec);
    }


    //  -- Arithmetic --
    template <typename T>
    constexpr inline const alg::Vec<T, 4> operator+(const alg::Vec<T, 4>& rhs_) noexcept
    {
        return (alg::Vec<T, 4>{+rhs_.x, +rhs_.y, +rhs_.z, +rhs_.w});
    }

    template <typename T>
    constexpr inline const alg::Vec<T, 4> operator-(const alg::Vec<T, 4>& rhs_) noexcept
    {
        return (alg::Vec<T, 4>{-rhs_.x, -rhs_.y, -rhs_.z, -rhs_.w});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 4> operator+(const alg::Vec<T, 4>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 4>{lhs_.x + rhs_, lhs_.y + rhs_, lhs_.z + rhs_, lhs_.w + rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 4> operator+(const alg::Vec<T, 4>& lhs_, const alg::Vec<S, 4>& rhs_) noexcept
    {
        return (alg::Vec<Dim, 4>{lhs_.x + rhs_.x, lhs_.y + rhs_.y, lhs_.z + rhs_.z, lhs_.w + rhs_.w});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 4> operator-(const alg::Vec<T, 4>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 4>{lhs_.x - rhs_, lhs_.y - rhs_, lhs_.z - rhs_, lhs_.w - rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 4> operator-(const alg::Vec<T, 4>& lhs_, const alg::Vec<S, 4>& rhs_) noexcept
    {
        return (alg::Vec<Dim, 4>{lhs_.x - rhs_.x, lhs_.y - rhs_.y, lhs_.z - rhs_.z, lhs_.w - rhs_.w});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 4> operator*(const alg::Vec<T, 4>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 4>{lhs_.x * rhs_, lhs_.y * rhs_, lhs_.z * rhs_, lhs_.w * rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 4> operator/(const alg::Vec<T, 4>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 4>{lhs_.x / rhs_, lhs_.y / rhs_, lhs_.z / rhs_, lhs_.w / rhs_});
    }


    //  -- Comparison --
    template <typename T>
    constexpr inline bool operator==(const alg::Vec<T, 4>& lhs_, const alg::Vec<T, 4>& rhs_) noexcept
    {
        return (math::equal(lhs_.x, rhs_.x) && math::equal(lhs_.y, rhs_.y) && math::equal(lhs_.z, rhs_.z) && math::equal(lhs_.w, rhs_.w));
    }

    template <typename T>
    constexpr inline bool operator!=(const alg::Vec<T, 4>& lhs_, const alg::Vec<T, 4>& rhs_) noexcept
    {
        return (!(lhs_ == rhs_));
    }

    template <typename T>
    constexpr inline bool operator<(const alg::Vec<T, 4>& lhs_, const alg::Vec<T, 4>& rhs_) noexcept
    {
        return ((lhs_.x < rhs_.x) && (lhs_.y < rhs_.y) && (lhs_.z < rhs_.z) && (lhs_.w < rhs_.w));
    }

    template <typename T>
    constexpr inline bool operator>(const alg::Vec<T, 4>& lhs_, const alg::Vec<T, 4>& rhs_) noexcept
    {
        return ((lhs_.x > rhs_.x) && (lhs_.y > rhs_.y) && (lhs_.z > rhs_.z) && (lhs_.w > rhs_.w));
    }

    template <typename T>
    constexpr inline bool operator<=(const alg::Vec<T, 4>& lhs_, const alg::Vec<T, 4>& rhs_) noexcept
    {
        return ((lhs_.x <= rhs_.x) && (lhs_.y <= rhs_.y) && (lhs_.z <= rhs_.z) && (lhs_.w <= rhs_.w));
    }

    template <typename T>
    constexpr inline bool operator>=(const alg::Vec<T, 4>& lhs_, const alg::Vec<T, 4>& rhs_) noexcept
    {
        return ((lhs_.x >= rhs_.x) && (lhs_.y >= rhs_.y) && (lhs_.z >= rhs_.z) && (lhs_.w >= rhs_.w));
    }



} // namespace arc
