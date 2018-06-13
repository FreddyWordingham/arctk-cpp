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
#include <arctk/math/container.hpp>
#include <arctk/math/conversion.hpp>
#include <arctk/math/power.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/math/vec2.hpp>
#include <arctk/math/vec3.hpp>
#include <arctk/math/vec4.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{



    //  == ALIASES ==
    //  -- Double Vec --
    using vec2 = math::Vec<double, 2>;
    using vec3 = math::Vec<double, 3>;
    using vec4 = math::Vec<double, 4>;
    template <size_t N>
    using vecN = math::Vec<double, N>;



} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_HPP
