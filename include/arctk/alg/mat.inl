//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/mat.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.inl"
#include "arctk/range/view/zip.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, std::size_t N, std::size_t M>
        constexpr inline Mat<T, N, M>::Mat() noexcept
          : _rows()
        {
        }

        template <typename T, std::size_t N, std::size_t M>
        template <typename... A>
        constexpr inline Mat<T, N, M>::Mat(const A... rows_) noexcept
          : _rows{rows_...}
        {
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename T, std::size_t N, std::size_t M>
        constexpr inline Row<T, M>& Mat<T, N, M>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < N);

            return (_rows[index_]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline const Row<T, M>& Mat<T, N, M>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_rows[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, std::size_t N, std::size_t M>
        constexpr inline const std::array<Row<T, M>, N>& Mat<T, N, M>::rows() const noexcept
        {
            return (_rows);
        }


        //  -- Dimensions --
        template <typename T, std::size_t N, std::size_t M>
        constexpr inline Row<T, M>& Mat<T, N, M>::x() noexcept
        {
            static_assert(N >= 1);

            return (_rows[0]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline const Row<T, M>& Mat<T, N, M>::x() const noexcept
        {
            static_assert(N >= 1);

            return (_rows[0]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline Row<T, M>& Mat<T, N, M>::y() noexcept
        {
            static_assert(N >= 2);

            return (_rows[1]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline const Row<T, M>& Mat<T, N, M>::y() const noexcept
        {
            static_assert(N >= 2);

            return (_rows[1]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline Row<T, M>& Mat<T, N, M>::z() noexcept
        {
            static_assert(N >= 3);

            return (_rows[2]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline const Row<T, M>& Mat<T, N, M>::z() const noexcept
        {
            static_assert(N >= 3);

            return (_rows[2]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline Row<T, M>& Mat<T, N, M>::w() noexcept
        {
            static_assert(N >= 4);

            return (_rows[3]);
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline const Row<T, M>& Mat<T, N, M>::w() const noexcept
        {
            static_assert(N >= 4);

            return (_rows[3]);
        }


        //  -- Range --
        template <typename T, std::size_t N, std::size_t M>
        constexpr inline auto Mat<T, N, M>::begin() noexcept
        {
            return (std::begin(_rows));
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline auto Mat<T, N, M>::begin() const noexcept
        {
            return (std::begin(_rows));
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline auto Mat<T, N, M>::end() noexcept
        {
            return (std::end(_rows));
        }

        template <typename T, std::size_t N, std::size_t M>
        constexpr inline auto Mat<T, N, M>::end() const noexcept
        {
            return (std::end(_rows));
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() + std::declval<S>()), N, M> operator+(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() + std::declval<S>()), N, M> mat{};

        for (auto& [m, l] : range::view::Zip{mat, lhs_})
        {
            m = l + rhs_;
        }

        return (mat);
    }

    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() - std::declval<S>()), N, M> operator-(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() - std::declval<S>()), N, M> mat{};

        for (auto& [m, l] : range::view::Zip{mat, lhs_})
        {
            m = l - rhs_;
        }

        return (mat);
    }

    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() * std::declval<S>()), N, M> operator*(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() * std::declval<S>()), N, M> mat{};

        for (auto& [mat_row, lhs_row] : range::view::Zip{mat, lhs_})
        {
            for (auto& [m, l] : range::view::Zip{mat_row, lhs_row})
            {
                m = l * rhs_;
            }
        }

        return (mat);
    }

    template <typename T, std::size_t N, std::size_t M, typename S>
    inline alg::Mat<decltype(std::declval<T>() / std::declval<S>()), N, M> operator/(const alg::Mat<T, N, M>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() / std::declval<S>()), N, M> mat{};

        for (auto& [m, l] : range::view::Zip{mat, lhs_})
        {
            m = l / rhs_;
        }

        return (mat);
    }



} // namespace arc
