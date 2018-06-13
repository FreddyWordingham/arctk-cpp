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

//#include <arctk/str.hpp>
#include <arctk/print.hpp>



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
            //  == FIELDS ==
          public:
            //  -- Data --
            std::array<T, N> _data{};


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec() noexcept = default;
            //            constexpr inline Vec(const std::array<double, N>& data_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename _T, size_t _N>
            friend inline S& operator<<(S& stream_, const Vec<T, N>& vec_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == OPERATORS ==
        //  -- Stream --
        template <typename S, typename T, size_t N>
        inline S& operator<<(S& stream_, const Vec<T, N>& vec_) noexcept
        {
            stream_ << str::to_string(vec_._data);

            return (stream_);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC_HPP
