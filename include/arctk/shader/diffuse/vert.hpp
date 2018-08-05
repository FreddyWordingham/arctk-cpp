/**
 *  @file   arctk/shader/diffuse/vert.hpp
 *  @date   04/08/2018
 *  @author Freddy Wordingham
 *
 *  Diffuse lighting vertex subshader source code.
 */



//  == GUARD ==
#ifndef ARCTK_SHADER_DIFFUSE_VERT_HPP
#define ARCTK_SHADER_DIFFUSE_VERT_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace shader //! shader namespace
    {
        namespace diffuse //! diffuse shader namespace
        {



            //  == CONSTANTS ==
            //  -- Source --
            const char* vert =
#include <arctk/shader/diffuse/diffuse.vert>
              ;



        } // namespace diffuse
    }     // namespace shader
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SHADER_DIFFUSE_VERT_HPP
