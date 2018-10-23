/**
 *  @file   arctk/math.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of mathematical classes and functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_HPP
#define ARCTK_MATH_HPP



//  == IMPORTS ==
//  -- Std --
#include <type_traits>

//  -- Arctk --
#include <arctk/math/compare.hpp>
#include <arctk/math/container.hpp>
#include <arctk/math/convert.hpp>
#include <arctk/math/formula.hpp>
#include <arctk/math/formula/constant.hpp>
#include <arctk/math/formula/linear.hpp>
#include <arctk/math/formula/polynomial.hpp>
#include <arctk/math/mat.hpp>
#include <arctk/math/mat2.hpp>
#include <arctk/math/mat3.hpp>
#include <arctk/math/mat4.hpp>
#include <arctk/math/pow.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/math/vec2.hpp>
#include <arctk/math/vec3.hpp>
#include <arctk/math/vec4.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{



    //  == ALIASES ==
    //  -- Int Mat --
    using mat3i = math::Mat<int, 3>; //!< Three-dimensional integer precision mat.
    using mat4i = math::Mat<int, 4>; //!< Four-dimensional integer precision mat.

    //  -- Size Mat --
    using mat3s = math::Mat<size_t, 3>; //!< Three-dimensional size precision mat.
    using mat4s = math::Mat<size_t, 4>; //!< Four-dimensional size precision mat.

    //  -- Float Mat --
    using mat3f = math::Mat<float, 3>; //!< Three-dimensional float precision mat.
    using mat4f = math::Mat<float, 4>; //!< Four-dimensional float precision mat.

    //  -- Double Mat --
    using mat3 = math::Mat<double, 3>; //!< Three-dimensional double precision mat.
    using mat4 = math::Mat<double, 4>; //!< Four-dimensional double precision mat.

    //  -- Long Double Mat --
    using mat3l = math::Mat<long double, 3>; //!< Three-dimensional long double precision mat.
    using mat4l = math::Mat<long double, 4>; //!< Four-dimensional long double precision mat.



} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
