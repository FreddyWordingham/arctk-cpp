//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.hpp"

//  -- Std --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == CLASSES ==
        //  -- Mat --
        template <typename T, std::size_t N, std::size_t M>
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
            std::array<Row<T, M>, N> _rows;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Mat() noexcept;
            template <typename... A>
            constexpr inline explicit Mat(const A... rows_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            constexpr inline Row<T, M>&       operator[](const std::size_t index_) noexcept;
            constexpr inline const Row<T, M>& operator[](const std::size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<Row<T, M>, N>& rows() const noexcept;

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
    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() + std::declval<S>()), N, M> operator+(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() - std::declval<S>()), N, M> operator-(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() * std::declval<S>()), N, M> operator*(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept;
    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() / std::declval<S>()), N, M> operator/(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept;



} // namespace arc
