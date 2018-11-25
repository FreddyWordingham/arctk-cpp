/**
 *  @file   arctk/math/matN.inl
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical N-by-N matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MATN_INL
#define ARCTK_MATH_MATN_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>
#include <ostream>

//  -- Arctk --
#include <arctk/consts/format.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a mat using given vecs of values.
         *
         *  @tparam A   Pack of initialisation vecs.
         *
         *  @param  data_   Vecs used to initialise mat elements.
         *
         *  @pre    Size of A must equal N.
         */
        template <typename T, size_t N>
        template <typename... A>
        constexpr inline Mat<T, N>::Mat(const A&... data_) noexcept
          : _data(init_data(data_...))
        {
            static_assert(sizeof...(A) == N);
        }


        //  -- Initialisation --
        /**
         *  Initialise the vec data array using a pack of vecs.
         *
         *  @tparam A   Pack of initialisation vecs.
         *
         *  @param  data_   Vec of values used to initialise data elements.
         *
         *  @pre    Size of A must equal N.
         *
         *  @return Initialised vec data array.
         */
        template <typename T, size_t N>
        template <typename... A>
        inline std::array<Vec<T, N>, N> Mat<T, N>::init_data(const A&... data_) noexcept
        {
            static_assert(sizeof...(A) == N);

            std::array<Vec<T, N>, N> data;

            size_t i = 0;
            ((data[i] = data_, ++i), ...);

            return (data);
        }



        //  == OPERATORS ==
        //  -- Assignment --
        /**
         *  Add a value to all elements of the mat.
         *
         *  @param  val_    Value to add to each mat element.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator+=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    _data[i][j] += val_;
                }
            }

            return (*this);
        }

        /**
         *  Add another mat's elements to each corresponding element of the mat.
         *
         *  @param  mat_    mat to add to this mat.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator+=(const Mat<T, N>& mat_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    _data[i][j] += mat_._data[i][j];
                }
            }

            return (*this);
        }

        /**
         *  Subtract a value from all elements of the mat.
         *
         *  @param  val_    Value to subtract from each mat element.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator-=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    _data[i][j] -= val_;
                }
            }

            return (*this);
        }

        /**
         *  Subtract another mat's elements from each corresponding element of the mat.
         *
         *  @param  mat_    mat to subtract from this mat.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator-=(const Mat<T, N>& mat_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    _data[i][j] -= mat_._data[i][j];
                }
            }

            return (*this);
        }

        /**
         *  Multiply all elements of the mat by a value.
         *
         *  @param  val_    Value used to multiply each mat element by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator*=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    _data[i][j] *= val_;
                }
            }

            return (*this);
        }

        /**
         *  Multiply the mat by another mat.
         *
         *  @param  mat_    Matrix to multiply this matrix by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator*=(const Mat<T, N>& mat_) noexcept
        {
            const std::array<Vec<T, N>, N> pre = _data;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    _data[i][j] = 0.0;

                    for (size_t k = 0; k < N; ++k)
                    {
                        _data[i][j] += pre[i][k] * mat_._data[k][j];
                    }
                }
            }

            return (*this);
        }

        /**
         *  Divide all elements of the mat by a value.
         *
         *  @param  val_    Value used to divide each mat element by.
         *
         *  @return Reference to this mat post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator/=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    _data[i][j] /= val_;
                }
            }

            return (*this);
        }


        //  -- Increment / Decrement --
        /**
         *  Increment each element of the mat.
         *
         *  @return A reference to this mat pre-increment.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator++() noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    ++_data[i][j];
                }
            }

            return (*this);
        }

        /**
         *  Increment each element of the mat.
         *
         *  @return A copy of this mat post-increment.
         */
        template <typename T, size_t N>
        constexpr inline const Mat<T, N> Mat<T, N>::operator++(const int) noexcept
        {
            const Mat mat = *this;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    ++_data[i][j];
                }
            }

            return (mat);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A reference to this mat pre-decrement.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N>& Mat<T, N>::operator--() noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    --_data[i][j];
                }
            }

            return (*this);
        }

        /**
         *  Decrement each element of the mat.
         *
         *  @return A copy of this mat post-decrement.
         */
        template <typename T, size_t N>
        constexpr inline const Mat<T, N> Mat<T, N>::operator--(const int) noexcept
        {
            const Mat mat = *this;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    --_data[i][j];
                }
            }

            return (mat);
        }


        //  -- Arithmetic --
        /**
         *  Positive copy the mat.
         *
         *  @return Positive copy of the mat.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator+() const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = +_data[i][j];
                }
            }

            return (mat);
        }

        /**
         *  Negative copy the mat.
         *
         *  @return Negative copy of the mat.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator-() const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = -_data[i][j];
                }
            }

            return (mat);
        }

        /**
         *  Add a value to a mat.
         *
         *  @param  val_    Value to add to the mat.
         *
         *  @return Mat formed by adding the value to the mat.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator+(const T val_) const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = _data[i][j] + val_;
                }
            }

            return (mat);
        }

        /**
         *  Add a mat to a mat.
         *
         *  @param  mat_    Mat to add to the mat.
         *
         *  @return Mat formed by adding the mat to the mat.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator+(const Mat<T, N>& mat_) const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = _data[i][j] + mat_._data[i][j];
                }
            }

            return (mat);
        }

        /**
         *  Subtract a value from a mat.
         *
         *  @param  val_    Value to subtract from the mat.
         *
         *  @return Mat formed by subtracting the value from the mat.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator-(const T val_) const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = _data[i][j] - val_;
                }
            }

            return (mat);
        }

        /**
         *  Subtract a mat from a mat.
         *
         *  @param  mat_    Mat to subtract from the mat.
         *
         *  @return Mat formed by subtracting the mat from the mat.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator-(const Mat<T, N>& mat_) const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = _data[i][j] - mat_._data[i][j];
                }
            }

            return (mat);
        }

        /**
         *  Multiply a mats elements by a value.
         *
         *  @param  val_    Value used to multiply the mat elements.
         *
         *  @return Mat formed by multiplying the mat elements by the value.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator*(const T val_) const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = _data[i][j] * val_;
                }
            }

            return (mat);
        }

        /**
         *  Multiply the mat by a vec.
         *
         *  @param  vec_    Vec to multiply this mat by.
         *
         *  @return Vec formed by multiplying the mat by the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Mat<T, N>::operator*(const Vec<T, N>& vec_) const noexcept
        {
            Vec<T, N> vec;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    vec[i] += vec_[j] * _data[i][j];
                }
            }

            return (vec);
        }

        /**
         *  Multiply two mats together.
         *
         *  @param  mat_    Right hand side mat of the operation.
         *
         *  @return Mat formed by multiplying the two mats together.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator*(const Mat<T, N>& mat_) const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    for (size_t k = 0; k < N; ++k)
                    {
                        mat._data[i][j] += _data[i][k] * mat_._data[k][j];
                    }
                }
            }

            return (mat);
        }

        /**
         *  Divide a mats elements by a value.
         *
         *  @param  val_    Value used to divide the mat elements.
         *
         *  @return Mat formed by dividing the mat elements by the value.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::operator/(const T val_) const noexcept
        {
            Mat mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat._data[i][j] = _data[i][j] / val_;
                }
            }

            return (mat);
        }


        //  -- Access --
        /**
         *  Access a row of the mat.
         *
         *  @param  index_  Index of the row to access.
         *
         *  @pre    index_ must be less than N.
         *
         *  @return A reference to the row requested.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Mat<T, N>::operator[](const size_t index_) noexcept
        {
            assert(index_ < N);

            return (_data[index_]);
        }

        /**
         *  Access a row of the mat.
         *
         *  @param  index_  Index of the row to access.
         *
         *  @pre    index_ must be less than N.
         *
         *  @return A const reference to the row requested.
         */
        template <typename T, size_t N>
        constexpr inline const Vec<T, N>& Mat<T, N>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_data[index_]);
        }


        //  -- Printing --
        /**
         *  Print the matrix to a stream.
         *
         *  @tparam S   Type stored by the matrix.
         *  @tparam M   Dimensions of the matrix.
         *
         *  @param  stream_ Stream to print to.
         *  @param  mat_    Matrix to be printed.
         *
         *  @return Reference to the matrix post-print.
         */
        template <typename S, size_t M>
        constexpr inline std::ostream& operator<<(std::ostream& stream_, const Mat<S, M>& mat_) noexcept
        {
            stream_ << consts::format::OPENERS[consts::format::container::MAT] << mat_._data[0];
            for (size_t i = 1; i < M; ++i)
            {
                stream_ << consts::format::DELIM << mat_._data[i];
            }
            stream_ << consts::format::CLOSERS[consts::format::container::MAT];

            return (stream_);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the data array.
         *
         *  @return Data array.
         */
        template <typename T, size_t N>
        constexpr inline const std::array<Vec<T, N>, N>& Mat<T, N>::data() const noexcept
        {
            return (_data);
        }


        //  -- Mathematical --
        /**
         *  Calculate the sum of the mat elements.
         *
         *  @return Sum of the mat elements.
         */
        template <typename T, size_t N>
        constexpr inline T Mat<T, N>::sum() const noexcept
        {
            T sum{};

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    sum += _data[i][j];
                }
            }

            return (sum);
        }

        /**
         *  Calculate the determinant of the matrix.
         *
         *  @return Determinant of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline T Mat<T, N>::det() const noexcept
        {
            T det = T{0};

            for (size_t i = 0; i < N; ++i)
            {
                det += _data[0][i] * cofactor(0, i);
            }

            return (det);
        }

        /**
         *  Calculate the minor of an element of the matrix.
         *
         *  @param  row_    Index of the matrix row element to calculate the minor of.
         *  @param  col_    Index of the matrix column element to calculate the minor of.
         *
         *  @pre    row_ must be less than N.
         *  @pre    col_ must be less than N.
         *
         *  @return Minor of an element of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline T Mat<T, N>::minors(const size_t row_, const size_t col_) const noexcept
        {
            assert(row_ < N);
            assert(col_ < N);

            Mat<T, N - 1> sub;
            size_t        n = 0;
            for (size_t k = 0; k < N; ++k)
            {
                if (k == row_)
                {
                    continue;
                }

                size_t m = 0;
                for (size_t l = 0; l < N; ++l)
                {
                    if (l == col_)
                    {
                        continue;
                    }

                    sub[n][m] = _data[k][l];
                    ++m;
                }
                ++n;
            }

            return (sub.det());
        }

        /**
         *  Calculate the matrix of minors of the matrix.
         *
         *  @return Matrix of minors of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::minors() const noexcept
        {
            Mat<T, N> mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat[i][j] = minors(i, j);
                }
            }

            return (mat);
        }

        /**
         *  Calculate the cofactor of an element of the matrix.
         *
         *  @param  row_    Index of the matrix row element to calculate the cofactor of.
         *  @param  col_    Index of the matrix column element to calculate the cofactor of.
         *
         *  @pre    row_ must be less than N.
         *  @pre    col_ must be less than N.
         *
         *  @return Cofactor of an element of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline T Mat<T, N>::cofactor(const size_t row_, const size_t col_) const noexcept
        {
            assert(row_ < N);
            assert(col_ < N);

            return (std::pow(-1, row_ + col_) * minors(row_, col_));
        }

        /**
         *  Calculate the matrix of cofactors of the matrix.
         *
         *  @return Matrix of cofactors of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::cofactor() const noexcept
        {
            Mat<T, N> mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat[i][j] = cofactor(i, j);
                }
            }

            return (mat);
        }

        /**
         *  Calculate the transpose matrix of the matrix.
         *
         *  @return Transpose matrix of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::trans() const noexcept
        {
            Mat<T, N> mat;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    mat[j][i] = _data[i][j];
                }
            }

            return (mat);
        }

        /**
         *  Calculate the adjoint matrix of the matrix.
         *
         *  @return Adjoint matrix of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::adj() const noexcept
        {
            return (cofactor().trans());
        }

        /**
         *  Calculate the inverse matrix of the matrix.
         *
         *  @return Inverse matrix of the matrix.
         */
        template <typename T, size_t N>
        constexpr inline Mat<T, N> Mat<T, N>::inv() const noexcept
        {
            return (adj() /= det());
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_MATN_INL
