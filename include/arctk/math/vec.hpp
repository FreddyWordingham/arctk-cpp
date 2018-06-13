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
            constexpr inline Vec(A... a) noexcept;

            //  -- Initialisation --
            template <typename... A>
            inline std::array<T, N> init_data(A... a) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename _T, size_t _N>
            friend inline S& operator<<(S& stream_, const Vec<T, N>& vec_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::array<T, N>& data() noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, size_t N>
        template <typename... A>
        constexpr inline Vec<T, N>::Vec(A... a) noexcept
          : _data(init_data(a...))
        {
            static_assert(sizeof...(A) == N);
        }


        //  -- Initialisation --
        template <typename T, size_t N>
        template <typename... A>
        inline std::array<T, N> Vec<T, N>::init_data(A... a) noexcept
        {
            static_assert(sizeof...(A) == N);

            std::array<T, N> data;

            size_t i = 0;
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
