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
            constexpr inline Vec(const A... a) noexcept;
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


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<T, N>& data() noexcept;
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
         *
         *  @return A copy of this vec post-increment.
         */
        template <typename T, size_t N>
        constexpr inline const Vec<T, N> Vec<T, N>::operator++(int) noexcept
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
         *
         *  @return A copy of this vec post-decrement.
         */
        template <typename T, size_t N>
        constexpr inline const Vec<T, N> Vec<T, N>::operator--(int) noexcept
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
         *
         *  @return Positive copy of the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator+() const noexcept
        {
            VecN vec;

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
         *
         *  @return Negative copy of the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator-() const noexcept
        {
            VecN vec;

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
         *
         *  @param  val_    Value to add to the vec.
         *
         *  @return Vec formed by adding the value to the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator+(T val_) const noexcept
        {
            return (Vec4(x + val_, y + val_, z + val_, w + val_));
        }

        /**
         *  Add a vec to a vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to add to the vec.
         *
         *  @return Vec formed by adding the vec to the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator+(const Vec<T, N>& vec_) const noexcept
        {
            return (Vec4(x + vec_.x, y + vec_.y, z + vec_.z, w + vec_.w));
        }

        /**
         *  Subtract a value from a vec.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value to subtract from the vec.
         *
         *  @return Vec formed by subtracting the value from the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator-(T val_) const noexcept
        {
            return (Vec4(x - val_, y - val_, z - val_, w - val_));
        }

        /**
         *  Subtract a vec from a vec.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to subtract from the vec.
         *
         *  @return Vec formed by subtracting the vec from the vec.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator-(const Vec<T, N>& vec_) const noexcept
        {
            return (Vec4(x - vec_.x, y - vec_.y, z - vec_.z, w - vec_.w));
        }

        /**
         *  Multiply a vecs elements by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to multiply the vec elements.
         *
         *  @return Vec formed by multiplying the vec elements by the value.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator*(T val_) const noexcept
        {
            return (Vec4(x * val_, y * val_, z * val_, w * val_));
        }

        /**
         *  Calculate the dot-product of two vecs.
         *
         *  @tparam T   Type stored by the vecs.
         *
         *  @param  vec_    Vec to perform the dot-product with.
         *
         *  @return Dot-product of the vecs.
         */
        template <typename T, size_t N>
        constexpr inline T Vec<T, N>::operator*(const Vec<T, N>& vec_) const noexcept
        {
            return ((x * vec_.x) + (y * vec_.y) + (z * vec_.z) + (w * vec_.w));
        }

        /**
         *  Divide a vecs elements by a value.
         *
         *  @tparam T   Type stored by the vec.
         *
         *  @param  val_    Value used to divide the vec elements.
         *
         *  @return Vec formed by dividing the vec elements by the value.
         */
        template <typename T, size_t N>
        constexpr inline Vec<T, N> Vec<T, N>::operator/(T val_) const noexcept
        {
            return (Vec4(x / val_, y / val_, z / val_, w / val_));
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, size_t N>
        inline const std::array<T, N>& Vec<T, N>::data() noexcept
        {
            return (_data);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC_HPP
