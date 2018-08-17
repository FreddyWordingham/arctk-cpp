/**
 *  @file   arctk/phys/material/fluorescent.hpp
 *  @date   16/08/2018
 *  @author Freddy Wordingham
 *
 *  Fluorescent material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_FLUORESCENT_HPP
#define ARCTK_PHYS_MATERIAL_FLUORESCENT_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/material.hpp>
#include <arctk/phys/optical.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Fluorescent material particle class.
             */
            class Fluorescent : public Material
            {
                //  == FIELDS ==
              private:
                //  -- Optical --
                const math::formula::Linear _ref_index;
                const math::formula::Linear _interact_coef;
                const math::formula::Linear _albedo;
                const math::formula::Linear _asym;
                const math::formula::Linear _flu_prob;
                const math::formula::Linear _delta_wavelength;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --

              private:
                //  -- Initialisation --


                //  == METHODS ==
              public:
                //  -- Properties --
                inline void set_optical_props(particle::Photon* phot_) const noexcept override;

                //  -- Interaction --
                inline double interaction_dist(random::Generator* rng_, const particle::Photon& phot_) const noexcept override;
                inline void   interact(random::Generator* rng_, particle::Photon* phot_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Flourescent::Flourescent() noexcept
              : Material(wavelength_.front(), wavelength_.back())
            {
            }


            //  -- Initialisation --



            //  == METHODS ==
            //  -- Properties --
            inline void Flourescent::set_optical_props(particle::Photon* const phot_) const noexcept
            {
            }


            //  -- Interaction --
            inline double Flourescent::interaction_dist(random::Generator* rng_, const particle::Photon& phot_) const noexcept
            {
            }

            inline void Flourescent::interact(random::Generator* rng_, particle::Photon* phot_) const noexcept
            {
            }



        } // namespace material
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_FLUORESCENT_HPP
