/**
 *  @file   arctk/math/pow.hpp
 *  @date   07/07/2018
 *  @author Freddy Wordingham
 *
 *  Math power functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_POW_HPP
#define ARCTK_MATH_POW_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace pow //! power namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Power --
            template <typename T>
            inline T sq(T val_) noexcept;
            template <typename T>
            inline T cube(T val_) noexcept;



        } // namespace pow
    }     // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/pow.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_POW_HPP
