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



        //  == CLASS PROTOTYPES ==
        //  -- Vec --
        template <typename T, std::size_t N>
        class Vec;

        //  -- Col --
        template <typename T, std::size_t N>
        class Col;

        //  -- Row --
        template <typename T, std::size_t N>
        class Row;



        //  == CLASSES ==
        //  -- Vec --
        template <typename T, std::size_t N>
        class Vec
        {
            //  == ASSERTIONS ==
            //  -- Size --
            static_assert(N > 1);


            //  == ALIASES ==
          public:
            //  -- Traits --
            using value_type = T;
            using size_type  = typename std::size_t;


            //  == FIELDS ==
          private:
            //  -- Elements --
            std::array<T, N> _elems;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Vec() noexcept;
            template <typename... A>
            constexpr inline explicit Vec(const T& elem_, const A&... elems_) noexcept;


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


        //  -- Col --
        template <typename T, std::size_t N>
        class Col : public Vec<T, N>
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Col() noexcept;
            template <typename... A>
            constexpr inline explicit Col(const T& elem_, const A&... elems_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Conversions --
            constexpr inline explicit operator Row<T, N>() noexcept;
        };


        //  -- Row --
        template <typename T, std::size_t N>
        class Row : public Vec<T, N>
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Row() noexcept;
            template <typename... A>
            constexpr inline explicit Row(const T& elem_, const A&... elems_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Conversions --
            constexpr inline explicit operator Col<T, N>() noexcept;
        };



        //  == ALIASES ==
        //  -- Col --
        template <typename T>
        using Col2 = Col<T, 2>;
        template <typename T>
        using Col3 = Col<T, 3>;
        template <typename T>
        using Col4 = Col<T, 4>;

        //  -- Row --
        template <typename T>
        using Row2 = Row<T, 2>;
        template <typename T>
        using Row3 = Row<T, 3>;
        template <typename T>
        using Row4 = Row<T, 4>;



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() + std::declval<S>()), N> operator+(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() - std::declval<S>()), N> operator-(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() * std::declval<S>()), N> operator*(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, typename S>
    inline decltype(std::declval<T>() * std::declval<S>()) operator*(const alg::Vec<T, N>& lhs_, const alg::Vec<S, N>& rhs_) noexcept;
    template <typename T, std::size_t N, typename S>
    inline alg::Vec<decltype(std::declval<T>() / std::declval<S>()), N> operator/(const alg::Vec<T, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, typename S>
    inline alg::Vec<decltype(std::declval<T>() * std::declval<S>()), 3> operator^(const alg::Vec<T, 3>& lhs_, const alg::Vec<S, 3>& rhs_) noexcept;



} // namespace arc
