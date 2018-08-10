/**
 *  @file   arctk/phys/particle/photon.hpp
 *  @date   10/08/2018
 *  @author Freddy Wordingham
 *
 *  Photon particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PARTICLE_PHOTON_HPP
#define ARCTK_PHYS_PARTICLE_PHOTON_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        namespace particle //! particle namespace
        {



            //  == CLASS ==
            /**
             *  Physical particle class.
             */
            class Photon : public Particle
            {
                //  == FIELDS ==
              private:
                //  -- Optical --
                double _wavelength;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Photon(const vec3& pos_, const vec3& dir_, double wavelength_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_) noexcept
              : Particle(pos_, dir_)
              , _wavelength(wavelength_)
            {
                PRE(wavelength_ > 0.0);
            }



            //  == METHODS ==



        } // namespace particle
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_PHOTON_HPP
