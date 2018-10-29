/**
 *  @file   arctk/opt/func.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Optical functions.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_FUNC_HPP
#define ARCTK_OPT_FUNC_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {
        namespace func //! function namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Probabilities --
            inline double reflection_prob(double ang_in_, double ref_index_in_, double ref_index_out_) noexcept;
            inline double refraction_prob(double ang_in_, double ref_index_in_, double ref_index_out_) noexcept;

            //  -- Directions --
            inline vec3 reflection_dir(const vec3& in_, const vec3& norm_) noexcept;
            inline vec3 refraction_dir(const vec3& in_, const vec3& norm_, double ref_index_in_, double ref_index_out_) noexcept;



        } // namespace func
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/func.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_FUNC_HPP
