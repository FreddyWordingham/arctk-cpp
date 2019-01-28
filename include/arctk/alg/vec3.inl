//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/alg/vec3.hpp>



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        constexpr inline Vec<T, 3>::Vec() noexcept
          : x{}
          , y{}
          , z{}
        {
        }

        template <typename T>
        constexpr inline Vec<T, 3>::Vec(const T& x_, const T& y_, const T& z_) noexcept
          : x{x_}
          , y{y_}
          , z{z_}
        {
        }



        //  == OPERATORS ==
        //  -- Assignment --
        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator+=(const T& rhs_) noexcept
        {
            x += rhs_;
            y += rhs_;
            z += rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator+=(const Vec& rhs_) noexcept
        {
            x += rhs_.x;
            y += rhs_.y;
            z += rhs_.z;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator-=(const T& rhs_) noexcept
        {
            x -= rhs_;
            y -= rhs_;
            z -= rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator-=(const Vec& rhs_) noexcept
        {
            x -= rhs_.x;
            y -= rhs_.y;
            z -= rhs_.z;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator*=(const T& rhs_) noexcept
        {
            x *= rhs_;
            y *= rhs_;
            z *= rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator/=(const T& rhs_) noexcept
        {
            x /= rhs_;
            y /= rhs_;
            z /= rhs_;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator^=(const Vec& rhs_) noexcept
        {
            const T lhs_x{x};
            const T lhs_y{y};
            const T lhs_z{z};

            x = (lhs_y * rhs_.z) - (lhs_z * rhs_.y);
            y = (lhs_z * rhs_.x) - (lhs_x * rhs_.z);
            z = (lhs_x * rhs_.y) - (lhs_y * rhs_.x);

            return (*this);
        }


        //  -- Increment / Decrement --
        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator++() noexcept
        {
            ++x;
            ++y;
            ++z;

            return (*this);
        }

        template <typename T>
        constexpr inline const Vec<T, 3>& Vec<T, 3>::operator--() noexcept
        {
            --x;
            --y;
            --z;

            return (*this);
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T>
    constexpr inline const alg::Vec<T, 3> operator+(const alg::Vec<T, 3>& rhs_) noexcept
    {
        return (alg::Vec<T, 3>{+rhs_.x, +rhs_.y, +rhs_.z});
    }

    template <typename T>
    constexpr inline const alg::Vec<T, 3> operator-(const alg::Vec<T, 3>& rhs_) noexcept
    {
        return (alg::Vec<T, 3>{-rhs_.x, -rhs_.y, -rhs_.z});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 3> operator+(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 3>{lhs_.x + rhs_, lhs_.y + rhs_, lhs_.z + rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 3> operator+(const alg::Vec<T, 3>& lhs_, const alg::Vec<S, 3>& rhs_) noexcept
    {
        return (alg::Vec<Dim, 3>{lhs_.x + rhs_.x, lhs_.y + rhs_.y, lhs_.z + rhs_.z});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 3> operator-(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 3>{lhs_.x - rhs_, lhs_.y - rhs_, lhs_.z - rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 3> operator-(const alg::Vec<T, 3>& lhs_, const alg::Vec<S, 3>& rhs_) noexcept
    {
        return (alg::Vec<Dim, 3>{lhs_.x - rhs_.x, lhs_.y - rhs_.y, lhs_.z - rhs_.z});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 3> operator*(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 3>{lhs_.x * rhs_, lhs_.y * rhs_, lhs_.z * rhs_});
    }

    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 3> operator/(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 3>{lhs_.x / rhs_, lhs_.y / rhs_, lhs_.z / rhs_});
    }



} // namespace arc
