/**
 *  @file   arctk/phys/photon.hpp
 *  @date   17/10/2018
 *  @author Freddy Wordingham
 *
 *  Photon particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PHOTON_INL
#define ARCTK_PHYS_PHOTON_INL



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/consts/phys.hpp>
#include <arctk/dom/cell.hpp>
#include <arctk/math/compare.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a photon at a given position with a given direction, wavelength, energy and emission time.
         *
         *  @param  pos_        Initial position of the photon.
         *  @param  dir_        Initial direction of the photon.
         *  @param  wavelength_ Wavelength of the photon.
         *  @param  energy_     Energy of the photon.
         *  @param  time_       Time of photon emission.
         *  @param  phase_      Initial phase of the photon.
         *
         *  @pre    dir_ must be normalised.
         *  @pre    wavelength_ must be non-negative.
         *  @pre    energy_ must be positive.
         *  @pre    time_ must be non-negative.
         */
        inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_, const double energy_, const double time_, const double phase_) noexcept
          : _pos(pos_)
          , _dir(dir_)
          , _wavelength(wavelength_)
          , _energy(energy_)
          , _time(time_)
          , _phase(phase_)
          , _weight(1.0)
        {
            assert(dir_.normalised());
            assert(wavelength_ > 0.0);
            assert(energy_ > 0.0);
            assert(time_ >= 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the position of the photon.
         *
         *  @return Position of the photon.
         */
        inline const vec3& Photon::pos() const noexcept
        {
            return (_pos);
        }

        /**
         *  Get the direction of the photon.
         *
         *  @return Direction of the photon.
         */
        inline const vec3& Photon::dir() const noexcept
        {
            return (_dir);
        }

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
         *  Get the energy of the photon.
         *
         *  @return Energy of the photon.
         */
        inline double Photon::energy() const noexcept
        {
            return (_energy);
        }

        /**
         *  Get the time of the photon.
         *
         *  @return Time of the photon.
         */
        inline double Photon::time() const noexcept
        {
            return (_time);
        }

        /**
         *  Get the phase of the photon.
         *
         *  @return Phase of the photon.
         */
        inline double Photon::phase() const noexcept
        {
            return (_phase);
        }

        /**
         *  Get the statistical weight of the photon.
         *
         *  @return Statistical weight of the photon.
         */
        inline double Photon::weight() const noexcept
        {
            return (_weight);
        }


        //  -- Setters --
        /**
         *  Move the photon along its current direction vector.
         *
         *  @param  dist_       Distance to move the photon.
         *  @param  ref_index_  Current refractive index of the photon's specific-optical-properties.
         *
         *  @pre    ref_index_ must be greater than, or equal to, unity.
         */
        inline void Photon::move(const double dist_, const double ref_index_) noexcept
        {
            assert(ref_index_ >= 1.0);

            _phase += dist_ * ref_index_;

            _pos += _dir * dist_;
            _time += ((dist_ * ref_index_) / consts::phys::SPEED_OF_LIGHT);
        }

        /**
         *  Rotate the photon.
         *
         *  @param  theta_  Polar angle to rotate.
         *  @param  phi_    Azimuthal angle to rotate.
         *
         *  @pre    _dir must be normalised.
         *
         *  @post   _dir must be normalised.
         */
        inline void Photon::rotate(const double theta_, const double phi_) noexcept
        {
            assert(_dir.normalised());

            vec3 front = _dir;
            vec3 right = math::compare::equal(std::fabs(_dir.z), 1.0) ? (_dir ^ vec3(1.0, 0.0, 0.0)) : (_dir ^ vec3(0.0, 0.0, 1.0));
            right.normalise();

            _dir.rotate(right, theta_);
            _dir.rotate(front, phi_);

            _dir.normalise();

            assert(_dir.normalised());
        }

        /**
         *  Set the direction of the photon.
         *
         *  @param  dir_    Direction to set for the photon.
         *
         *  @pre    dir_ must be normalised.
         */
        inline void Photon::set_dir(const vec3& dir_) noexcept
        {
            assert(dir_.normalised());

            _dir = dir_;
        }

        /**
         *  Multiply the weight of the photon.
         *
         *  @param  mult_   Value to multiply the weight of the photon by.
         *
         *  @pre    mult_ must be positive.
         *  @pre    mult_ must be less than, or equal to, unity.
         */
        inline void Photon::multiply_weight(const double mult_) noexcept
        {
            assert(mult_ > 0.0);
            assert(mult_ <= 1.0);

            _weight *= mult_;
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PHOTON_INL
