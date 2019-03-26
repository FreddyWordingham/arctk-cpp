//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.hpp"

//  -- Std --
#include <array>
#include <cstddef>
#include <memory>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == CLASSES ==
        //  -- Mat --
        template <typename T, std::size_t M, std::size_t N>
        class Mat
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
            std::array<Row<T, N>, M> _rows;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Mat() noexcept;
            template <typename... A>
            constexpr inline explicit Mat(const Row<T, N>& row_, const A&... rows_) noexcept;
            template <typename... A>
            constexpr inline explicit Mat(const Col<T, M>& col_, const A&... cols_) noexcept;

          private:
            //  -- Initialisation --
            template <typename... A>
            constexpr inline std::array<Row<T, N>, M> init_rows(const Col<T, M>& col_, const A&... cols_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            constexpr inline Row<T, N>&       operator[](const std::size_t index_) noexcept;
            constexpr inline const Row<T, N>& operator[](const std::size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<Row<T, N>, M>&  rows() const noexcept;
            constexpr inline Row<std::shared_ptr<T>, N>       row(const std::size_t index_) noexcept;
            constexpr inline Row<std::shared_ptr<const T>, N> row(const std::size_t index_) const noexcept;
            constexpr inline Col<std::shared_ptr<T>, M>       col(const std::size_t index_) noexcept;
            constexpr inline Col<std::shared_ptr<const T>, M> col(const std::size_t index_) const noexcept;

            //  -- Dimensions --
            constexpr inline Row<T, M>&       x() noexcept;
            constexpr inline const Row<T, M>& x() const noexcept;
            constexpr inline Row<T, M>&       y() noexcept;
            constexpr inline const Row<T, M>& y() const noexcept;
            constexpr inline Row<T, M>&       z() noexcept;
            constexpr inline const Row<T, M>& z() const noexcept;
            constexpr inline Row<T, M>&       w() noexcept;
            constexpr inline const Row<T, M>& w() const noexcept;

            //  -- Range --
            constexpr inline auto begin() noexcept;
            constexpr inline auto begin() const noexcept;
            constexpr inline auto end() noexcept;
            constexpr inline auto end() const noexcept;
        };



        //  == ALIASES ==
        //  -- Mat --
        template <typename T>
        using Mat2 = Mat<T, 2, 2>;
        template <typename T>
        using Mat3 = Mat<T, 3, 3>;
        template <typename T>
        using Mat4 = Mat<T, 4, 4>;



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() + std::declval<S>()), M, N> operator+(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() - std::declval<S>()), M, N> operator-(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() * std::declval<S>()), M, N> operator*(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() / std::declval<S>()), M, N> operator/(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept;



} // namespace arc
