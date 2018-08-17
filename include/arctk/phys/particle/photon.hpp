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
#include <arctk/consts.hpp>
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/optical.hpp>
#include <arctk/phys/particle.hpp>



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
                double  _wavelength; //!< Optical wavelength.
                Optical _opt;        //!< Optical properties.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Photon(const vec3& pos_, const vec3& dir_, double wavelength_, double time_ = 0.0) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double         wavelength() const noexcept;
                inline const Optical& opt() const noexcept;

                //  -- Setters --
                inline void move(double dist_) noexcept override;
                inline void set_optical_props(const Optical& opt_) noexcept;
                inline void shift_wavelength(double delta_wavelength_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a photon with an initial position, direction and wavelength.
             *
             *  @param  pos_        Position of the photon.
             *  @param  dir_        Direction of the photon.
             *  @param  wavelength_ Wavelength of the photon.
             *
             *  @pre    dir_ must be normalised.
             *  @pre    wavelength_ must be positive.
             *  @pre    time_ must be non-negative.
             */
            inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_, const double time_) noexcept
              : Particle(pos_, dir_, time_)
              , _wavelength(wavelength_)
            {
                PRE(dir_.normalised());
                PRE(wavelength_ > 0.0);
                PRE(time_ >= 0.0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the wavelength of the photon.
             *
             *  @return Wavelength of the photon.
             */
            inline double Photon::wavelength() const noexcept
            {
                return (_wavelength);
            }

            /**
             *  Get the optical properties of the photon.
             *
             *  @return Optical properties of the photon.
             */
            inline const Optical& Photon::opt() const noexcept
            {
                return (_opt);
            }


            //  -- Setters --
            /**
             *  Move the photon along it's current direction by a given distance.
             *
             *  @param  dist_   Distance to travel.
             *
             *  @pre    dist_ must be positive.
             *  @pre    _dir must be normalised.
             */
            inline void Photon::move(const double dist_) noexcept
            {
                PRE(dist_ > 0.0);
                PRE(_dir.normalised());

                _pos += _dir * dist_;
                _time += (dist_ * _opt.ref_index()) / consts::phys::SPEED_OF_LIGHT;
            }

            /**
             *  Set the optical properties of the photon.
             *
             *  @param  opt_    Optical properties to set for the photon.
             */
            inline void Photon::set_optical_props(const Optical& opt_) noexcept
            {
                _opt = opt_;
            }

            /**
             *  Shift the wavelength of the photon.
             *
             *  @param  delta_wavelength_   Value to shift the wavelength.
             *
             *  @post   _wavelength must be positive.
             */
            inline void Photon::shift_wavelength(const double delta_wavelength_) noexcept
            {
                _wavelength += delta_wavelength_;

                POST(_wavelength > 0.0);
            }



        } // namespace particle
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_PHOTON_HPP
