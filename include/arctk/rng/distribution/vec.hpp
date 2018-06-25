/**
 *  @file   arctk/rng/distribution/vec.hpp
 *  @date   25/06/2018
 *  @author Freddy Wordingham
 *
 *  Vec distribution functions.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_DISTRIBUTION_VEC_HPP
#define ARCTK_RNG_DISTRIBUTION_VEC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/constant.hpp>
#include <arctk/math.hpp>
#include <arctk/rng/distribution/floating.hpp>
#include <arctk/rng/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! utility namespace
    {
        namespace distribution //! distribution namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Two-Dimensional --
            inline vec2 uniform_vec2(Generator& rng_) noexcept;
            inline vec3 uniform_vec3(Generator& rng_) noexcept;


            //  == FUNCTIONS ==
            //  -- Two-Dimensional --
            inline vec2 uniform_vec2(Generator& rng_) noexcept
            {
                const double theta = uniform_floating<double>(rng_, 0.0, 2.0 * constant::PI);

                return (vec2(std::sin(theta), std::cos(theta)));
            }

            inline vec3 uniform_vec3(Generator& rng_) noexcept
            {
                const double phi   = uniform_floating<double>(rng_, 0.0, 2.0 * constant::PI);
                const double theta = std::acos(uniform_floating<double>(rng_, -1.0, 1.0));

                return (vec3(std::sin(theta) * std::cos(phi), std::sin(theta) * std::sin(phi), std::cos(theta)));
            }



        } // namespace distribution
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_DISTRIBUTION_VEC_HPP
