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
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == SPECILAISATIONS ==
        //  -- VecN --
        template <typename T, std::size_t N>
        class Vec
        {
            //  == ASSERTIONS ==
            //  -- Size --
            static_assert(N > 4);


            //  == FIELDS ==
          public:
            //  -- Elements --
            std::array<T, N> _elems;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Vec() noexcept;
            constexpr inline explicit Vec(const std::array<T, N>& elems_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            constexpr inline const Vec& operator+=(const T& rhs_) noexcept;
            constexpr inline const Vec& operator+=(const Vec& rhs_) noexcept;
            constexpr inline const Vec& operator-=(const T& rhs_) noexcept;
            constexpr inline const Vec& operator-=(const Vec& rhs_) noexcept;
            constexpr inline const Vec& operator*=(const T& rhs_) noexcept;
            constexpr inline const Vec& operator/=(const T& rhs_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline const Vec& operator++() noexcept;
            constexpr inline const Vec& operator--() noexcept;

            //  -- Access --
            constexpr inline T&       operator[](std::size_t index_) noexcept;
            constexpr inline const T& operator[](std::size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<T, N>& elems() const noexcept;
        };



        //  == ALIASES ==
        //  -- Dimensionless --
        template <typename T, std::size_t N>
        using VecN = Vec<T, N>;



    } // namespace alg



    //  == OPERATORS ==



} // namespace arc
