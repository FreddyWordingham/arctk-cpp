//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/mat.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.inl"
#include "arctk/range/list.inl"
#include "arctk/range/view/zip.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Mat<T, M, N>::Mat() noexcept
          : _rows()
        {
        }

        template <typename T, std::size_t M, std::size_t N>
        template <typename... A>
        constexpr inline Mat<T, M, N>::Mat(const Row<T, N>& row_, const A&... rows_) noexcept
          : _rows{row_, rows_...}
        {
            static_assert(sizeof...(A) == (M - 1));
        }

        template <typename T, std::size_t M, std::size_t N>
        template <typename... A>
        constexpr inline Mat<T, M, N>::Mat(const Col<T, M>& col_, const A&... cols_) noexcept
          : _rows{init_rows(col_, cols_...)}
        {
            static_assert(sizeof...(A) == (N - 1));
        }


        //  -- Initialisation --
        template <typename T, std::size_t M, std::size_t N>
        template <typename... A>
        constexpr inline std::array<Row<T, N>, M> Mat<T, M, N>::init_rows(const Col<T, M>& col_, const A&... cols_) noexcept
        {
            static_assert(sizeof...(A) == (N - 1));

            std::array<Col<T, M>, N> cols{col_, cols_...};
            std::array<Row<T, N>, M> rows;

            for (auto& [row, row_index] : arc::range::view::Zip{rows, arc::range::list(M)})
            {
                for (auto& [x, col] : arc::range::view::Zip{row, cols})
                {
                    x = col[row_index];
                }
            }

            return (rows);
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Row<T, N>& Mat<T, M, N>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < M);

            return (_rows[index_]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline const Row<T, N>& Mat<T, M, N>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < M);

            return (_rows[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, std::size_t M, std::size_t N>
        constexpr inline const std::array<Row<T, N>, M>& Mat<T, M, N>::rows() const noexcept
        {
            return (_rows);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Row<std::shared_ptr<T>, N> Mat<T, M, N>::row(const std::size_t index_) noexcept
        {
            assert(index_ < M);

            Row<std::shared_ptr<T>, N> row;

            for (auto& [r, x] : arc::range::view::Zip{row, _rows[index_]})
            {
                r = std::make_shared<T>(x);
            }

            return (row);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Row<std::shared_ptr<const T>, N> Mat<T, M, N>::row(const std::size_t index_) const noexcept
        {
            assert(index_ < M);

            Row<std::shared_ptr<const T>, N> row;

            for (auto& [r, x] : arc::range::view::Zip{row, _rows[index_]})
            {
                r = std::make_shared<const T>(x);
            }

            return (row);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Col<std::shared_ptr<T>, M> Mat<T, M, N>::col(const std::size_t index_) noexcept
        {
            assert(index_ < N);

            Col<std::shared_ptr<T>, M> col;

            for (auto& [c, row] : arc::range::view::Zip{col, _rows})
            {
                c = std::make_shared<T>(row[index_]);
            }

            return (col);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Col<std::shared_ptr<const T>, M> Mat<T, M, N>::col(const std::size_t index_) const noexcept
        {
            assert(index_ < N);

            Col<std::shared_ptr<const T>, M> col;

            for (auto& [c, row] : arc::range::view::Zip{col, _rows})
            {
                c = std::make_shared<const T>(row[index_]);
            }

            return (col);
        }



        //  -- Dimensions --
        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Row<T, M>& Mat<T, M, N>::x() noexcept
        {
            static_assert(M > 0);

            return (_rows[0]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline const Row<T, M>& Mat<T, M, N>::x() const noexcept
        {
            static_assert(M > 0);

            return (_rows[0]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Row<T, M>& Mat<T, M, N>::y() noexcept
        {
            static_assert(M > 1);

            return (_rows[1]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline const Row<T, M>& Mat<T, M, N>::y() const noexcept
        {
            static_assert(M > 1);

            return (_rows[1]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Row<T, M>& Mat<T, M, N>::z() noexcept
        {
            static_assert(M > 2);

            return (_rows[2]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline const Row<T, M>& Mat<T, M, N>::z() const noexcept
        {
            static_assert(M > 2);

            return (_rows[2]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline Row<T, M>& Mat<T, M, N>::w() noexcept
        {
            static_assert(M > 3);

            return (_rows[3]);
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline const Row<T, M>& Mat<T, M, N>::w() const noexcept
        {
            static_assert(M > 3);

            return (_rows[3]);
        }


        //  -- Range --
        template <typename T, std::size_t M, std::size_t N>
        constexpr inline auto Mat<T, M, N>::begin() noexcept
        {
            return (std::begin(_rows));
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline auto Mat<T, M, N>::begin() const noexcept
        {
            return (std::begin(_rows));
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline auto Mat<T, M, N>::end() noexcept
        {
            return (std::end(_rows));
        }

        template <typename T, std::size_t M, std::size_t N>
        constexpr inline auto Mat<T, M, N>::end() const noexcept
        {
            return (std::end(_rows));
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() + std::declval<S>()), M, N> operator+(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() + std::declval<S>()), M, N> mat{};

        for (auto& [m, l] : range::view::Zip{mat, lhs_})
        {
            m = l + rhs_;
        }

        return (mat);
    }

    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() - std::declval<S>()), M, N> operator-(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() - std::declval<S>()), M, N> mat{};

        for (auto& [m, l] : range::view::Zip{mat, lhs_})
        {
            m = l - rhs_;
        }

        return (mat);
    }

    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() * std::declval<S>()), M, N> operator*(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() * std::declval<S>()), M, N> mat{};

        for (auto& [mat_row, lhs_row] : range::view::Zip{mat, lhs_})
        {
            for (auto& [m, l] : range::view::Zip{mat_row, lhs_row})
            {
                m = l * rhs_;
            }
        }

        return (mat);
    }

    template <typename T, std::size_t M, std::size_t N, typename S>
    inline alg::Mat<decltype(std::declval<T>() / std::declval<S>()), M, N> operator/(const alg::Mat<T, M, N>& lhs_, const S& rhs_) noexcept
    {
        alg::Mat<decltype(std::declval<T>() / std::declval<S>()), M, N> mat{};

        for (auto& [m, l] : range::view::Zip{mat, lhs_})
        {
            m = l / rhs_;
        }

        return (mat);
    }



} // namespace arc
