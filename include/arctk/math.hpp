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
    //  -- Int Vec --
    using vec2i = math::Vec<int, 2>; //!< Two-dimensional integer precision vec.
    using vec3i = math::Vec<int, 3>; //!< Three-dimensional integer precision vec.
    using vec4i = math::Vec<int, 4>; //!< Four-dimensional integer precision vec.
    template <size_t N>
    using vecNi = math::Vec<int, N>; //!< N-dimensional integer precision vec.  // NOLINT

    //  -- Size Vec --
    using vec2s = math::Vec<size_t, 2>; //!< Two-dimensional size precision vec.
    using vec3s = math::Vec<size_t, 3>; //!< Three-dimensional size precision vec.
    using vec4s = math::Vec<size_t, 4>; //!< Four-dimensional size precision vec.
    template <size_t N>
    using vecNs = math::Vec<size_t, N>; //!< N-dimensional size precision vec.  // NOLINT

    //  -- Float Vec --
    using vec2f = math::Vec<float, 2>; //!< Two-dimensional float precision vec.
    using vec3f = math::Vec<float, 3>; //!< Three-dimensional float precision vec.
    using vec4f = math::Vec<float, 4>; //!< Four-dimensional float precision vec.
    template <size_t N>
    using vecNf = math::Vec<float, N>; //!< N-dimensional float precision vec.  // NOLINT

    //  -- Double Vec --
    using vec2 = math::Vec<double, 2>; //!< Two-dimensional double precision vec.
    using vec4 = math::Vec<double, 4>; //!< Four-dimensional double precision vec.
    template <size_t N>
    using vecN = math::Vec<double, N>; //!< N-dimensional double precision vec. // NOLINT

    //  -- Long Double Vec --
    using vec2l = math::Vec<long double, 2>; //!< Two-dimensional long double precision vec.
    using vec3l = math::Vec<long double, 3>; //!< Three-dimensional long double precision vec.
    using vec4l = math::Vec<long double, 4>; //!< Four-dimensional long double precision vec.
    template <size_t N>
    using vecNl = math::Vec<long double, N>; //!< N-dimensional long double precision vec.  // NOLINT

    //  -- Int Mat --
    using mat2i = math::Mat<int, 2>; //!< Two-dimensional integer precision mat.
    using mat3i = math::Mat<int, 3>; //!< Three-dimensional integer precision mat.
    using mat4i = math::Mat<int, 4>; //!< Four-dimensional integer precision mat.
    template <size_t N>
    using matNi = math::Mat<int, N>; //!< N-dimensional integer precision mat.  // NOLINT

    //  -- Size Mat --
    using mat2s = math::Mat<size_t, 2>; //!< Two-dimensional size precision mat.
    using mat3s = math::Mat<size_t, 3>; //!< Three-dimensional size precision mat.
    using mat4s = math::Mat<size_t, 4>; //!< Four-dimensional size precision mat.
    template <size_t N>
    using matNs = math::Mat<size_t, N>; //!< N-dimensional size precision mat.  // NOLINT

    //  -- Float Mat --
    using mat2f = math::Mat<float, 2>; //!< Two-dimensional float precision mat.
    using mat3f = math::Mat<float, 3>; //!< Three-dimensional float precision mat.
    using mat4f = math::Mat<float, 4>; //!< Four-dimensional float precision mat.
    template <size_t N>
    using matNf = math::Mat<float, N>; //!< N-dimensional float precision mat.  // NOLINT

    //  -- Double Mat --
    using mat2 = math::Mat<double, 2>; //!< Two-dimensional double precision mat.
    using mat3 = math::Mat<double, 3>; //!< Three-dimensional double precision mat.
    using mat4 = math::Mat<double, 4>; //!< Four-dimensional double precision mat.
    template <size_t N>
    using matN = math::Mat<double, N>; //!< N-dimensional double precision mat. // NOLINT

    //  -- Long Double Mat --
    using mat2l = math::Mat<long double, 2>; //!< Two-dimensional long double precision mat.
    using mat3l = math::Mat<long double, 3>; //!< Three-dimensional long double precision mat.
    using mat4l = math::Mat<long double, 4>; //!< Four-dimensional long double precision mat.
    template <size_t N>
    using matNl = math::Mat<long double, N>; //!< N-dimensional long double precision mat.  // NOLINT



} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
