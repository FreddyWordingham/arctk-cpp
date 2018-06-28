/**
 *  @file   arctk/math.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Collection of mathematical functions and classes.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_HPP
#define ARCTK_MATH_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/comparison.hpp>
#include <arctk/math/container.hpp>
#include <arctk/math/conversion.hpp>
#include <arctk/math/mat.hpp>
#include <arctk/math/mat2.hpp>
#include <arctk/math/mat3.hpp>
#include <arctk/math/power.hpp>
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
    using vecNi = math::Vec<int, N>; //!< N-dimensional integer precision vec. // NOLINT

    //  -- Float Vec --
    using vec2f = math::Vec<float, 2>; //!< Two-dimensional float precision vec.
    using vec3f = math::Vec<float, 3>; //!< Three-dimensional float precision vec.
    using vec4f = math::Vec<float, 4>; //!< Four-dimensional float precision vec.
    template <size_t N>
    using vecNf = math::Vec<float, N>; //!< N-dimensional float precision vec. // NOLINT


    //  -- Double Vec --
    using vec2 = math::Vec<double, 2>; //!< Two-dimensional double precision vec.
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.
    using vec4 = math::Vec<double, 4>; //!< Four-dimensional double precision vec.
    template <size_t N>
    using vecN = math::Vec<double, N>; //!< N-dimensional double precision vec. // NOLINT


    //  -- Long Double Vec --
    using vec2l = math::Vec<long double, 2>; //!< Two-dimensional long double precision vec.
    using vec3l = math::Vec<long double, 3>; //!< Three-dimensional long double precision vec.
    using vec4l = math::Vec<long double, 4>; //!< Four-dimensional long double precision vec.
    template <size_t N>
    using vecNl = math::Vec<long double, N>; //!< N-dimensional long double precision vec. // NOLINT



} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
