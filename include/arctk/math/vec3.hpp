/**
 *  @file   arctk/math/vec3.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical size three vector class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_VEC3_HPP
#define ARCTK_MATH_VEC3_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == CLASS ==
        /**
         *  Size three mathematical vector class.
         */
        template <typename T>
        class Vec3
        {
            //  == FIELDS ==
          public:
            //  -- Data --
            T x{0};
            T y{0};
            T z{0};


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline Vec3() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename L>
            friend inline S& operator<<(S& stream_, const Vec3<T>& vec_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == OPERATORS ==
        //  -- Stream --
        template <typename S, typename T>
        inline S& operator<<(S& stream_, const Vec3<T>& vec_) noexcept
        {
            stream_ << '{' << vec_.x << ", " << vec_.y << ", " << vec_.z << '}';

            return (stream_);
        }



        //  == METHODS ==



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_VEC3_HPP
