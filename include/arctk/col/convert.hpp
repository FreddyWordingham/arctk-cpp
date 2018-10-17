/**
 *  @file   arctk/col/convert.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  Colour conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_COL_CONVERT_HPP
#define ARCTK_COL_CONVERT_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace col //! colour namespace
    {
        namespace convert //! convertsion namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- HSV --
            inline vec3 hsv_to_rgb(double hue_, double sat_, double val_) noexcept;



        } // namespace convert
    }     // namespace col
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/col/convert.inl>



//  == GUARD END ==
#endif // ARCTK_COL_CONVERT_HPP
