//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include <arctk/alg/vec.hpp>



//  == IMPORTS ==
//  -- Arc --
#include <arctk/si/dimension.hpp>
#include <arctk/type/arithmetic.hpp>

//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == SPECILAISATIONS ==
        //  -- Vec3 --
        template <typename T>
        class Vec<T, 3>
        {
            //  == FIELDS ==
          public:
            //  -- Elements --
            T x;
            T y;
            T z;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Vec() noexcept;
            constexpr inline explicit Vec(const T& x_, const T& y_, const T& z_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            constexpr inline const Vec& operator+=(const T& rhs_) noexcept;
            constexpr inline const Vec& operator+=(const Vec& rhs_) noexcept;
            constexpr inline const Vec& operator-=(const T& rhs_) noexcept;
            constexpr inline const Vec& operator-=(const Vec& rhs_) noexcept;
            constexpr inline const Vec& operator*=(const T& rhs_) noexcept;
            constexpr inline const Vec& operator/=(const T& rhs_) noexcept;
            constexpr inline const Vec& operator^=(const Vec& rhs_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline const Vec& operator++() noexcept;
            constexpr inline const Vec& operator--() noexcept;

            //  -- Access --
            constexpr inline T&       operator[](std::size_t index_) noexcept;
            constexpr inline const T& operator[](std::size_t index_) const noexcept;
        };



        //  == ALIASES ==
        //  -- Dimensionless --
        template <typename T>
        using Vec3 = Vec<T, 3>;



    } // namespace alg



    //  == OPERATORS ==
    //  -- Increment / Decrement --
    template <typename T>
    constexpr inline const alg::Vec<T, 3> operator++(alg::Vec<T, 3>& lhs_, int) noexcept;
    template <typename T>
    constexpr inline const alg::Vec<T, 3> operator--(alg::Vec<T, 3>& lhs_, int) noexcept;

    //  -- Arithmetic --
    template <typename T>
    constexpr inline const alg::Vec<T, 3> operator+(const alg::Vec<T, 3>& rhs_) noexcept;
    template <typename T>
    constexpr inline const alg::Vec<T, 3> operator-(const alg::Vec<T, 3>& rhs_) noexcept;
    template <typename T, typename S, typename Dim = type::arithmetic::add<T, S>>
    constexpr inline const alg::Vec<Dim, 3> operator+(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept;
    template <typename T, typename S, typename Dim = type::arithmetic::add<T, S>>
    constexpr inline const alg::Vec<Dim, 3> operator+(const alg::Vec<T, 3>& lhs_, const alg::Vec<S, 3>& rhs_) noexcept;
    template <typename T, typename S, typename Dim = type::arithmetic::sub<T, S>>
    constexpr inline const alg::Vec<Dim, 3> operator-(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept;
    template <typename T, typename S, typename Dim = type::arithmetic::sub<T, S>>
    constexpr inline const alg::Vec<Dim, 3> operator-(const alg::Vec<T, 3>& lhs_, const alg::Vec<S, 3>& rhs_) noexcept;
    template <typename T, typename S, typename Dim = type::arithmetic::mult<T, S>>
    constexpr inline const alg::Vec<Dim, 3> operator*(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept;
    template <typename T, typename S, typename Dim = type::arithmetic::div<T, S>>
    constexpr inline const alg::Vec<Dim, 3> operator/(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept;
    template <typename T, typename S, typename Dim = type::arithmetic::mult<T, S>>
    constexpr inline const alg::Vec<Dim, 3> operator^(const alg::Vec<T, 3>& lhs_, const alg::Vec<T, 3>& rhs_) noexcept;

    //  -- Comparison --
    template <typename T>
    constexpr inline bool operator==(const alg::Vec<T, 3>& lhs_, const alg::Vec<T, 3>& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator!=(const alg::Vec<T, 3>& lhs_, const alg::Vec<T, 3>& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator<(const alg::Vec<T, 3>& lhs_, const alg::Vec<T, 3>& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator>(const alg::Vec<T, 3>& lhs_, const alg::Vec<T, 3>& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator<=(const alg::Vec<T, 3>& lhs_, const alg::Vec<T, 3>& rhs_) noexcept;
    template <typename T>
    constexpr inline bool operator>=(const alg::Vec<T, 3>& lhs_, const alg::Vec<T, 3>& rhs_) noexcept;



} // namespace arc
