/**
 *  @file   constants.hpp
 *  @date   17/05/2018
 *  @author Freddy Wordingham
 *
 *  Collection of mathematical and physical constants.
 */



//  == GUARD ==
#ifndef ARCTK_CONSTANTS_HPP
#define ARCTK_CONSTANTS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == COLLECTION ==
//  -- Constants --
#include <arctk/constants/math.hpp>
#include <arctk/constants/phys.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace math //! mathematical namespace
    {



        //  == COMMON ==
        //  -- Archimedes' Constant --
        constexpr const double PI = 3.141592653589793238462643383279502884197169399375105820974; //!<  Archimedes' Constant.


        //  -- Euler's Number --
        constexpr const double EXP = 2.718281828459045235360287471352662497757247093699959574966; //!< Euler's Number.



    } // namespace math



    namespace phys //! physics namespace
    {
    } // namespace phys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONSTANTS_HPP
