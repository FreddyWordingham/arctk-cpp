/**
 *  @file   arctk/phys/optical.hpp
 *  @date   04/12/2018
 *  @author Freddy Wordingham
 *
 *  Physics optical functions.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_OPTICAL_HPP
#define ARCTK_PHYS_OPTICAL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace optical //! optical namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Probabilities --
            inline double reflection_prob(double ang_in_, double ref_index_in_, double ref_index_out_) noexcept;
            inline double refraction_prob(double ang_in_, double ref_index_in_, double ref_index_out_) noexcept;

            //  -- Directions --
            inline vec3 reflection_dir(const vec3& in_, const vec3& norm_) noexcept;
            inline vec3 refraction_dir(const vec3& in_, const vec3& norm_, double ref_index_in_, double ref_index_out_) noexcept;



        } // namespace optical
    }     // namespace phys
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/func.inl>



//  == GUARD END ==
#endif // ARCTK_PHYS_OPTICAL_HPP
