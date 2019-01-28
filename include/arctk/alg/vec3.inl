//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include <arctk/alg/vec3.hpp>



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        constexpr inline Vec<T, 3>::Vec() noexcept
          : x{0}
          , y{0}
          , z{0}
        {
        }

        template <typename T>
        constexpr inline Vec<T, 3>::Vec(const T& x_, const T& y_, const T& z_) noexcept
          : x{x_}
          , y{y_}
          , z{z_}
        {
        }



    } // namespace alg



    //  == OPERATORS ==
    //  -- Arithmetic --
    template <typename T, typename S, typename Dim>
    constexpr inline const alg::Vec<Dim, 3> operator/(const alg::Vec<T, 3>& lhs_, const S& rhs_) noexcept
    {
        return (alg::Vec<Dim, 3>{lhs_.x / rhs_, lhs_.y / rhs_, lhs_.z / rhs_});
    }



} // namespace arc
