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
                _data[i] *= val_;
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
                _data[i] += val_;
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
            x -= val_;
            y -= val_;
            z -= val_;
            w -= val_;

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
            x -= vec_.x;
            y -= vec_.y;
            z -= vec_.z;
            w -= vec_.w;

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
            x *= val_;
            y *= val_;
            z *= val_;
            w *= val_;

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
        template <typename T>
        constexpr inline Vec<T, N>& Vec<T, N>::operator/=(const T val_) noexcept
        {
            x /= val_;
            y /= val_;
            z /= val_;
            w /= val_;

            return (*this);
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
