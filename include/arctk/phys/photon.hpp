/**
 *  @file   arctk/phys/photon.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Photon particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PHOTON_HPP
#define ARCTK_PHYS_PHOTON_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Photon particle class.
         */
        class Photon
        {
            //  == FIELDS ==
          private:
            //  -- Particle --
            vec3 _pos;
            vec3 _dir;

            //  -- Photon --
            const double _wavelength; //!< Wavelength of the photon.
            const double _energy;     //!< Energy of the packet.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Photon(const vec3& pos_, const vec3& dir_, double wavelength_, double energy_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_, const double energy_) const noexcept
          : _pos(pos_)
          , _dir(dir_)
          , _wavelength(wavelength_)
          , _energy(energy_)
        {
            PRE(dir_.normalised());
            PRE(wavelength_ > 0.0);
            PRE(energy > 0.0);
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PHOTON_HPP
