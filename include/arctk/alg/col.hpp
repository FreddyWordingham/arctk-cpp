//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/si/dimension.hpp"

//  -- Std --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == CLASSES ==
        //  -- Col --
        template <typename T, std::size_t N>
        class Col
        {
            //  == ALIASES ==
          public:
            //  -- Traits --
            using value_type = typename std::size_t;
            using size_type  = typename std::size_t;


            //  == FIELDS ==
          private:
            //  -- Elements --
            std::array<T, N> _elems;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Col() noexcept;
            template <typename... A>
            constexpr inline Col(const A... elems_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            constexpr inline T&       operator[](const std::size_t index_) noexcept;
            constexpr inline const T& operator[](const std::size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<T, N>& elems() const noexcept;

            //  -- Dimensions --
            constexpr inline T&       x() noexcept;
            constexpr inline const T& x() const noexcept;
            constexpr inline T&       y() noexcept;
            constexpr inline const T& y() const noexcept;
            constexpr inline T&       z() noexcept;
            constexpr inline const T& z() const noexcept;
            constexpr inline T&       w() noexcept;
            constexpr inline const T& w() const noexcept;

            //  -- Range --
            constexpr inline auto begin() noexcept;
            constexpr inline auto begin() const noexcept;
            constexpr inline auto end() noexcept;
            constexpr inline auto end() const noexcept;
        };



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() + std::declval<S>()), N> operator+(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() - std::declval<S>()), N> operator-(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() * std::declval<S>()), N> operator*(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, typename S>
    inline alg::Col<decltype(std::declval<T>() / std::declval<S>()), N> operator/(const alg::Col<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, typename S>
    inline alg::Col<decltype(std::declval<T>() * std::declval<S>()), 3> operator^(const alg::Col<T, 3>& lhs_, const alg::Col<S, 3>& rhs_) noexcept;



} // namespace arc
