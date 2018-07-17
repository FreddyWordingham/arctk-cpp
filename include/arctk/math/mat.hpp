/**
 *  @file   arctk/math/mat.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical square matrix class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_MAT_HPP
#define ARCTK_MATH_MAT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <iomanip>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/settings.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Mathematical square matrix class.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
         */
        template <typename T, size_t N>
        class Mat : public str::Printable
        {
            //  == ASSERTIONS ==
            //  -- Size --
            static_assert(N > 4);


            //  == FIELDS ==
          private:
            //  -- Data --
            std::array<Vec<T, N>, N> _data{}; //!< Array of matrix rows.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Mat() noexcept = default;
            template <typename... A>
            constexpr inline explicit Mat(const A&... data_) noexcept;

            //  -- Initialisation --
            template <typename... A>
            inline std::array<Vec<T, N>, N> init_data(const A&... data_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            constexpr inline Mat<T, N>& operator+=(T val_) noexcept;
            constexpr inline Mat<T, N>& operator+=(const Mat<T, N>& mat_) noexcept;
            constexpr inline Mat<T, N>& operator-=(T val_) noexcept;
            constexpr inline Mat<T, N>& operator-=(const Mat<T, N>& mat_) noexcept;
            constexpr inline Mat<T, N>& operator*=(T val_) noexcept;
            constexpr inline Mat<T, N>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Mat<T, N>&      operator++() noexcept;
            constexpr inline const Mat<T, N> operator++(int) noexcept;
            constexpr inline Mat<T, N>&      operator--() noexcept;
            constexpr inline const Mat<T, N> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Mat<T, N> operator+() const noexcept;
            constexpr inline Mat<T, N> operator-() const noexcept;
            constexpr inline Mat<T, N> operator+(T val_) const noexcept;
            constexpr inline Mat<T, N> operator+(const Mat<T, N>& mat_) const noexcept;
            constexpr inline Mat<T, N> operator-(T val_) const noexcept;
            constexpr inline Mat<T, N> operator-(const Mat<T, N>& mat_) const noexcept;
            constexpr inline Mat<T, N> operator*(T val_) const noexcept;
            constexpr inline Mat<T, N> operator*(const Mat<T, N>& mat_) const noexcept;
            constexpr inline Mat<T, N> operator/(T val_) const noexcept;

            //  -- Access --
            constexpr inline Vec<T, N>&       operator[](size_t index_) noexcept;
            constexpr inline const Vec<T, N>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<Vec<T, N>, N>& data() const noexcept;

            //  -- Mathematical --
            constexpr inline T sum() const noexcept;
            constexpr inline T det() const noexcept;
            constexpr inline T minor(size_t row_, size_t col_) const noexcept;

            //  -- Printing --
            inline std::string str() const noexcept override;
        };



        //  == FUNCTION PROTOTYPES ==
        //  -- Utility --
        template <typename T, size_t N>
        constexpr inline Mat<T, N> indentity() noexcept;



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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mats.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mats.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  Divide all elements of the mat by a value.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mats.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mats.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  Multiply two mats together.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
            PRE(index_ < N);

            return (_data[index_]);
        }

        /**
         *  Access a row of the mat.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
            PRE(index_ < N);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the data array.
         *
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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
         *  @tparam T   Type stored by the mat.
         *  @tparam N   Size of the mat.
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

        template <typename T, size_t N>
        constexpr inline T Mat<T, N>::minor(const size_t row_, const size_t col_) const noexcept
        {
            PRE(row_ < N);
            PRE(col_ < N);

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


        //  -- Printing --
        /**
         *  Create a human readable string of the mat.
         *
         *  @return Human readable string of the mat.
         */
        template <typename T, size_t N>
        inline std::string Mat<T, N>::str() const noexcept
        {
            std::stringstream stream;

            stream << settings::format::VEC_START;

            for (size_t i = 0; i < N; ++i)
            {
                if (i != 0)
                {
                    stream << '\n' << settings::format::DELIMITER;
                }

                stream << settings::format::VEC_START;

                for (size_t j = 0; j < N; ++j)
                {
                    if (j != 0)
                    {
                        stream << settings::format::DELIMITER;
                    }

                    stream << std::setw(settings::format::PRINT_WIDTH) << _data[i][j];
                }

                stream << settings::format::VEC_END;
            }

            stream << settings::format::VEC_END;

            return (stream.str());
        }



        //  == FUNCTIONS ==
        //  -- Utility --
        template <typename T, size_t N>
        constexpr inline Mat<T, N> indentity() noexcept
        {
            Mat<T, N> mat;

            for (size_t i = 0; i < N; ++i)
            {
                mat[i][i] = T{1};
            }

            return (mat);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_MAT_HPP
