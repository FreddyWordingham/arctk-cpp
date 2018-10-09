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

            //  -- Statistical --
            double _weight;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Photon(const vec3& pos_, const vec3& dir_, double wavelength_, double energy_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3& pos() const noexcept;
            inline const vec3& dir() const noexcept;
            inline double      wavelength() const noexcept;
            inline double      energy() const noexcept;
            inline double      weight() const noexcept;

            //  -- Setters --
            inline void multiply_weight(double mult_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_, const double energy_) noexcept
          : _pos(pos_)
          , _dir(dir_)
          , _wavelength(wavelength_)
          , _energy(energy_)
        {
            PRE(dir_.normalised());
            PRE(wavelength_ > 0.0);
            PRE(energy_ > 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        inline const vec3& Photon::pos() const noexcept
        {
            return (_pos);
        }

        inline const vec3& Photon::dir() const noexcept
        {
            return (_dir);
        }

        inline double Photon::wavelength() const noexcept
        {
            return (_wavelength);
        }

        inline double Photon::energy() const noexcept
        {
            return (_energy);
        }

        inline double Photon::weight() const noexcept
        {
            return (_weight);
        }


        //  -- Setters --
        inline void Photon::multiply_weight(double mult_) noexcept
        {
            PRE(mult_ > 0.0);
            PRE(mult_ <= 1.0);

            _weight *= mult_;
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PHOTON_HPP
