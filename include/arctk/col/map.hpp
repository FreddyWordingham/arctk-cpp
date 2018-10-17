/**
 *  @file   arctk/col/map.hpp
 *  @date   12/07/2018
 *  @author Freddy Wordingham
 *
 *  Colour mapping functions.
 */



//  == GUARD ==
#ifndef ARCTK_COL_MAP_HPP
#define ARCTK_COL_MAP_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace col //! colour namespace
    {
        namespace map //! mapping namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Matlab --
            inline vec3 jet(double x_) noexcept;
            inline vec3 jet_line(double x_) noexcept;
            inline vec3 jet_block(double x_, unsigned int num_ = 10) noexcept;



        } // namespace map
    }     // namespace col
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/col/map.inl>



//  == GUARD END ==
#endif // ARCTK_COL_MAP_HPP
