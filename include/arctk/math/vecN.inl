/**
 *  @file   arctk/math/vecN.inl
 *  @date   17/10/2018
 *  @author Freddy Wordingham
 *
 *  N-dimensional mathematical vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VECN_INL
#define ARCTK_MATH_VECN_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>
#include <ostream>

//  -- Arctk --
#include <arctk/consts/format.hpp>
#include <arctk/math/mat.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a vec using given values.
         *
         *  @tparam A   Pack of initialisation values.
         *
         *  @param  data_   Values used to initialise vec elements.
         *
         *  @pre    Size of A must equal N.
         */
        template <typename T, size_t N>
        template <typename... A>
        constexpr inline Vec<T, N>::Vec(const A... data_) noexcept
          : _data(init_data(data_...))
        {
            static_assert(sizeof...(A) == N);
        }

        /**
         *  Construct a vec using a smaller vec and given values.
         *
         *  @tparam M   Size of smaller vec.
         *  @tparam A   Pack of initialisation values.
         *
         *  @param  vec_    Vec of values to initialise vec elements.
         *  @param  data_   Values used to initialise vec elements.
         *
         *  @pre    Size of A plus M must equal N.
         */
        template <typename T, size_t N>
        template <size_t M, typename... A>
        constexpr inline Vec<T, N>::Vec(const Vec<T, M>& vec_, const A... data_) noexcept
          : _data(init_data(vec_, data_...))
        {
            static_assert((sizeof...(A) + M) == N);
        }


        //  -- Initialisation --
        /**
         *  Initialise the element data array using a pack of values.
         *
         *  @tparam A   Pack of initialisation values.
         *
         *  @param  data_   Values used to initialise data elements.
         *
         *  @pre    Size of A must equal N.
         *
         *  @return Initialised element data array.
         */
        template <typename T, size_t N>
        template <typename... A>
        inline std::array<T, N> Vec<T, N>::init_data(const A... data_) noexcept
        {
            static_assert(sizeof...(A) == N);

            std::array<T, N> data;

            size_t i = 0;
            ((data[i] = data_, ++i), ...);

            return (data);
        }

        /**
         *  Initialise the element data array using a smaller vec and a pack of values.
         *
         *  @tparam M   Size of smaller vec.
         *  @tparam A   Pack of initialisation values.
         *
         *  @param  vec_    Vec of values to initialise data elements.
         *  @param  data_   Values used to initialise data elements.
         *
         *  @pre    Size of A plus M must equal N.
         *
         *  @return Initialised element data array.
         */
        template <typename T, size_t N>
        template <size_t M, typename... A>
        inline std::array<T, N> Vec<T, N>::init_data(const Vec<T, M>& vec_, const A... data_) noexcept
        {
            static_assert((sizeof...(A) + M) == N);

            std::array<T, N> data;

            size_t i;
            for (i = 0; i < M; ++i)
            {
                data[i] = vec_._data[i];
            }

            ((data[i] = data_, ++i), ...);

            return (data);
        }



        //  == OPERATORS ==
        //  -- Printing --
        /**
         *  Print the vec to a stream.
         *
         *  @tparam S   Type stored by the vec.
         *  @tparam M   Size of the vec.
         *
         *  @param  stream_ Stream to print to.
         *  @param  vec_    Vec to be printed.
         *
         *  @return Reference to the vec post-print.
         */
        template <typename S, size_t M>
        constexpr inline std::ostream& operator<<(std::ostream& stream_, const Vec<S, M>& vec_) noexcept
        {
            stream_ << consts::format::OPENERS[consts::format::container::VEC] << vec_._data[0];
            for (size_t i = 1; i < M; ++i)
            {
                stream_ << consts::format::DELIM << vec_._data[i];
            }
            stream_ << consts::format::CLOSERS[consts::format::container::VEC];

            return (stream_);
        }


        //  -- Assignment --
        /**
         *  Add a value to all elements of the vec.
         *
         *  @param  val_    Value to add to each vec element.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator+=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                _data[i] += val_;
            }

            return (*this);
        }

        /**
         *  Add another vec's elements to each corresponding element of the vec.
         *
         *  @param  vec_    Vec to add to this vec.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator+=(const Vec<T, N>& vec_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                _data[i] += vec_._data[i];
            }

            return (*this);
        }

        /**
         *  Subtract a value from all elements of the vec.
         *
         *  @param  val_    Value to subtract from each vec element.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator-=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                _data[i] -= val_;
            }

            return (*this);
        }

        /**
         *  Subtract another vec's elements from each corresponding element of the vec.
         *
         *  @param  vec_    Vec to subtract from this vec.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator-=(const Vec<T, N>& vec_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                _data[i] -= vec_._data[i];
            }

            return (*this);
        }

        /**
         *  Multiply all elements of the vec by a value.
         *
         *  @param  val_    Value used to multiply each vec element by.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator*=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                _data[i] *= val_;
            }

            return (*this);
        }

        /**
         *  Divide all elements of the vec by a value.
         *
         *  @param  val_    Value used to divide each vec element by.
         *
         *  @return Reference to this vec post-operation.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator/=(const T val_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                _data[i] /= val_;
            }

            return (*this);
        }


        //  -- Increment / Decrement --
        /**
         *  Increment each element of the vec.
         *
         *  @return A reference to this vec pre-increment.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator++() noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                ++_data[i];
            }

            return (*this);
        }

        /**
         *  Increment each element of the vec.
         *
         *  @return A copy of this vec post-increment.
         */
        template <typename T, size_t N>
        constexpr inline const Vec<T, N> Vec<T, N>::operator++(const int) noexcept
        {
            const Vec vec = *this;

            for (size_t i = 0; i < N; ++i)
            {
                ++_data[i];
            }

            return (vec);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @return A reference to this vec pre-decrement.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N>& Vec<T, N>::operator--() noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                --_data[i];
            }

            return (*this);
        }

        /**
         *  Decrement each element of the vec.
         *
         *  @return A copy of this vec post-decrement.
         */
        template <typename T, size_t N>
        constexpr inline const Vec<T, N> Vec<T, N>::operator--(const int) noexcept
        {
            const Vec vec = *this;

            for (size_t i = 0; i < N; ++i)
            {
                --_data[i];
            }

            return (vec);
        }


        //  -- Arithmetic --
        /**
         *  Positive copy the vec.
         *
         *  @return Positive copy of the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator+() const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = +_data[i];
            }

            return (vec);
        }

        /**
         *  Negative copy the vec.
         *
         *  @return Negative copy of the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator-() const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = -_data[i];
            }

            return (vec);
        }

        /**
         *  Add a value to a vec.
         *
         *  @param  val_    Value to add to the vec.
         *
         *  @return Vec formed by adding the value to the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator+(const T val_) const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = _data[i] + val_;
            }

            return (vec);
        }

        /**
         *  Add a vec to a vec.
         *
         *  @param  vec_    Vec to add to the vec.
         *
         *  @return Vec formed by adding the vec to the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator+(const Vec<T, N>& vec_) const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = _data[i] + vec_[i];
            }

            return (vec);
        }

        /**
         *  Subtract a value from a vec.
         *
         *  @param  val_    Value to subtract from the vec.
         *
         *  @return Vec formed by subtracting the value from the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator-(const T val_) const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = _data[i] - val_;
            }

            return (vec);
        }

        /**
         *  Subtract a vec from a vec.
         *
         *  @param  vec_    Vec to subtract from the vec.
         *
         *  @return Vec formed by subtracting the vec from the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator-(const Vec<T, N>& vec_) const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = _data[i] - vec_[i];
            }

            return (vec);
        }

        /**
         *  Multiply a vecs elements by a value.
         *
         *  @param  val_    Value used to multiply the vec elements.
         *
         *  @return Vec formed by multiplying the vec elements by the value.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator*(const T val_) const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = _data[i] * val_;
            }

            return (vec);
        }

        /**
         *  Calculate the dot-product of two vecs.
         *
         *  @param  vec_    Vec to perform the dot-product with.
         *
         *  @return Dot-product of the vecs.
         */
        template <typename T, size_t N>
        constexpr inline T Vec<T, N>::operator*(const Vec<T, N>& vec_) const noexcept
        {
            T dot_prod{};

            for (size_t i = 0; i < N; ++i)
            {
                dot_prod += _data[i] * vec_._data[i];
            }

            return (dot_prod);
        }

        /**
         *  Multiply the vec by a mat.
         *
         *  @param  mat_    Mat to multiply this vec by.
         *
         *  @return Vec formed by multiplying the vec by the mat.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator*(const Mat<T, N>& mat_) const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < N; ++j)
                {
                    vec._data[i] += _data[j] * mat_._data[j][i];
                }
            }

            return (vec);
        }

        /**
         *  Divide a vecs elements by a value.
         *
         *  @param  val_    Value used to divide the vec elements.
         *
         *  @return Vec formed by dividing the vec elements by the value.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator/(const T val_) const noexcept
        {
            Vec vec;

            for (size_t i = 0; i < N; ++i)
            {
                vec[i] = _data[i] / val_;
            }

            return (vec);
        }


        //  -- Access --
        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than N.
         *
         *  @return A reference to the element requested.
         */
        template <typename T, size_t N>
        constexpr inline T& Vec<T, N>::operator[](const size_t index_) noexcept
        {
            assert(index_ < N);

            return (_data[index_]);
        }

        /**
         *  Access an element of the vec.
         *
         *  @param  index_  Index of the element to access.
         *
         *  @pre    index_ must be less than N.
         *
         *  @return A const reference to the element requested.
         */
        template <typename T, size_t N>
        constexpr inline const T& Vec<T, N>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the data array.
         *
         *  @return Data array.
         */
        template <typename T, size_t N>
        constexpr inline const std::array<T, N>& Vec<T, N>::data() const noexcept
        {
            return (_data);
        }


        //  -- Properties --
        /**
         *  Determine if a vec is normalised to within a given tolerance.
         *
         *  @param  tol_    Maximum tolerance of normalisation value.
         *
         *  @pre    tol_ must be positive.
         *
         *  @return True if the vec is normalised.
         */
        template <typename T, size_t N>
        constexpr inline bool Vec<T, N>::normalised(const T tol_) const noexcept
        {
            assert(tol_ > 0);

            return (std::fabs(T{1.0} - mag_sq()) <= tol_);
        }


        //  -- Mathematical --
        /**
         *  Calculate the sum of the vec elements.
         *
         *  @return Sum of the vec elements.
         */
        template <typename T, size_t N>
        constexpr inline T Vec<T, N>::sum() const noexcept
        {
            T sum{};

            for (size_t i = 0; i < N; ++i)
            {
                sum += _data[i];
            }

            return (sum);
        }

        /**
         *  Calculate the magnitude of the vec.
         *
         *  @return Magnitude of the vec.
         */
        template <typename T, size_t N>
        constexpr inline T Vec<T, N>::mag() const noexcept
        {
            return (std::sqrt(mag_sq()));
        }

        /**
         *  Calculate the magnitude-squared of the vec.
         *
         *  @return Magnitude-squared of the vec.
         */
        template <typename T, size_t N>
        constexpr inline T Vec<T, N>::mag_sq() const noexcept
        {
            T sq_sum{};

            for (size_t i = 0; i < N; ++i)
            {
                sq_sum += _data[i] * _data[i];
            }

            return (sq_sum);
        }

        /**
         *  Get the normalised form of the vec.
         *
         *  @return Normalised form of the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::normal() const noexcept
        {
            Vec<T, N> normal = *this;

            normal.normalise();

            return (normal);
        }

        /**
         *  Normalise the vec.
         *
         *  @post   Vec must be normalised.
         */
        template <typename T, size_t N>
        constexpr inline void Vec<T, N>::normalise() noexcept
        {
            const T m = T{1.0} / mag();

            for (size_t i = 0; i < N; ++i)
            {
                _data[i] *= m;
            }

            assert(normalised());
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_VECN_INL
