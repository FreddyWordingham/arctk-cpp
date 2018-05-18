/**
 *  @file   arctk/constant/math.hpp
 *  @date   18/05/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical constants.
 */



//  == GUARD ==
#ifndef ARCTK_CONSTANT_MATH_HPP
#define ARCTK_CONSTANT_MATH_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace constant //! constant namespace
    {



        //  == COMMON ==
        //  -- Archimedes' Constant --
        constexpr const double PI{3.141592653589793238462643383279502884197169399375105820974}; //!<  Archimedes' Constant.


        //  -- Euler's Number --
        constexpr const double EXP{2.718281828459045235360287471352662497757247093699959574966}; //!< Euler's Number.



    } // namespace constant
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONSTANT_MATH_HPP
