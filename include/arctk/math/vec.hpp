/**
 *  @file   arctk/math/vec.hpp
 *  @date   13/06/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC_HPP
#define ARCTK_MATH_VEC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Mathematical vector class.
         *
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
         */
        template <typename T, size_t N>
        class Vec
        {
            //  == ASSERTIONS ==
            //  -- Size --
            static_assert(N > 4);


            //  == FIELDS ==
          public:
            //  -- Data --
            std::array<T, N> _data{};


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept = default;
            template <typename... A>
            constexpr inline explicit Vec(const A... a) noexcept;
            template <size_t M, typename... A>
            constexpr inline Vec(const Vec<T, M>& vec_, const A... a) noexcept;

            //  -- Initialisation --
            template <typename... A>
            inline std::array<T, N> init_data(const A... a) noexcept;
            template <size_t M, typename... A>
            inline std::array<T, N> init_data(const Vec<T, M>& vec_, const A... a) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename _T, size_t _N>
            friend inline S& operator<<(S& stream_, const Vec<T, N>& vec_) noexcept;

            //  -- Assignment --
            constexpr inline Vec<T, N>& operator+=(T val_) noexcept;
            constexpr inline Vec<T, N>& operator+=(const Vec<T, N>& vec_) noexcept;
            constexpr inline Vec<T, N>& operator-=(T val_) noexcept;
            constexpr inline Vec<T, N>& operator-=(const Vec<T, N>& vec_) noexcept;
            constexpr inline Vec<T, N>& operator*=(T val_) noexcept;
            constexpr inline Vec<T, N>& operator/=(T val_) noexcept;

            //  -- Increment / Decrement --
            constexpr inline Vec<T, N>&      operator++() noexcept;
            constexpr inline const Vec<T, N> operator++(int) noexcept;
            constexpr inline Vec<T, N>&      operator--() noexcept;
            constexpr inline const Vec<T, N> operator--(int) noexcept;

            //  -- Arithmetic --
            constexpr inline Vec<T, N> operator+() const noexcept;
            constexpr inline Vec<T, N> operator-() const noexcept;
            constexpr inline Vec<T, N> operator+(T val_) const noexcept;
            constexpr inline Vec<T, N> operator+(const Vec<T, N>& vec_) const noexcept;
            constexpr inline Vec<T, N> operator-(T val_) const noexcept;
            constexpr inline Vec<T, N> operator-(const Vec<T, N>& vec_) const noexcept;
            constexpr inline Vec<T, N> operator*(T val_) const noexcept;
            constexpr inline T         operator*(const Vec<T, N>& vec_) const noexcept;
            constexpr inline Vec<T, N> operator/(T val_) const noexcept;

            //  -- Access --
            inline T&       operator[](size_t index_) noexcept;
            inline const T& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<T, N>& data() const noexcept;

            //  -- Properties --
            constexpr inline bool normalised(T tol_ = std::numeric_limits<T>::epsilon()) const noexcept;

            //  -- Mathematical --
            constexpr inline T    sum() const noexcept;
            constexpr inline T    mag() const noexcept;
            constexpr inline T    mag_sq() const noexcept;
            constexpr inline void normalise() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        template <typename... A>
        constexpr inline Vec<T, N>::Vec(const A... a) noexcept
          : _data(init_data(a...))
        {
            static_assert(sizeof...(A) == N);
        }

        template <typename T, size_t N>
        template <size_t M, typename... A>
        constexpr inline Vec<T, N>::Vec(const Vec<T, M>& vec_, const A... a) noexcept
          : _data(init_data(vec_, a...))
        {
            static_assert((sizeof...(A) + M) == N);
        }


        //  -- Initialisation --
        template <typename T, size_t N>
        template <typename... A>
        inline std::array<T, N> Vec<T, N>::init_data(const A... a) noexcept
        {
            static_assert(sizeof...(A) == N);

            std::array<T, N> data;

            size_t i = 0;
            ((data[i] = a, ++i), ...);

            return (data);
        }

        template <typename T, size_t N>
        template <size_t M, typename... A>
        inline std::array<T, N> Vec<T, N>::init_data(const Vec<T, M>& vec_, const A... a) noexcept
        {
            static_assert((sizeof...(A) + M) == N);

            std::array<T, N> data;

            size_t i;
            for (i = 0; i < M; ++i)
            {
                data[i] = vec_._data[i];
            }

            ((data[i] = a, ++i), ...);

            return (data);
        }



        //  == OPERATORS ==
        //  -- Stream --
        template <typename S, typename T, size_t N>
        inline S& operator<<(S& stream_, const Vec<T, N>& vec_) noexcept
        {
            stream_ << str::to_string(vec_._data);

            return (stream_);
        }


        //  -- Assignment --
        /**
         *  Add a value to all elements of the vec.
         *
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vecs.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vecs.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vecs.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vecs.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
         *  @tparam T   Type stored by the vecs.
         *  @tparam N   Size of the vec.
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
         *  Divide a vecs elements by a value.
         *
         *  @tparam T   Type stored by the vec.
         *  @tparam N   Size of the vec.
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
        template <typename T, size_t N>
        inline T& Vec<T, N>::operator[](const size_t index_) noexcept
        {
            assert(index_ < N);

            return (_data[index_]);
        }

        template <typename T, size_t N>
        inline const T& Vec<T, N>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, size_t N>
        inline const std::array<T, N>& Vec<T, N>::data() const noexcept
        {
            return (_data);
        }


        //  -- Properties --
        template <typename T, size_t N>
        constexpr inline bool Vec<T, N>::normalised(const T tol_) const noexcept
        {
            return (std::fabs(1.0 - mag()) <= tol_);
        }


        //  -- Mathematical --
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

        template <typename T, size_t N>
        constexpr inline T Vec<T, N>::mag() const noexcept
        {
            static_assert(std::is_floating_point<T>::value);

            return (std::sqrt(mag_sq()));
        }

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

        template <typename T, size_t N>
        constexpr inline void Vec<T, N>::normalise() const noexcept
        {
            static_assert(std::is_floating_point<T>::value);

            const T m = T{1.0} / mag();

            for (size_t i = 0; i < N; ++i)
            {
                _data[i] *= m;
            }
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC_HPP
