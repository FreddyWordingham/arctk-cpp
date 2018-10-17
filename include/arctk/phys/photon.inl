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
#include <arctk/consts.hpp>
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/cell.hpp>
#include <arctk/phys/sop.hpp>



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
            vec3 _pos; //!< Position of the photon.
            vec3 _dir; //!< Direction of the photon.

            //  -- Properties --
            const double _wavelength; //!< Wavelength of the photon.
            const double _energy;     //!< Energy of the packet.
            double       _time;       //!< Current photon time.

            //  -- Statistical --
            double _weight; //!< Statistical weight of the photon.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Photon(const vec3& pos_, const vec3& dir_, double wavelength_, double energy_, double time_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3& pos() const noexcept;
            inline const vec3& dir() const noexcept;
            inline double      wavelength() const noexcept;
            inline double      energy() const noexcept;
            inline double      time() const noexcept;
            inline double      weight() const noexcept;

            //  -- Setters --
            inline void move(double dist_, double ref_index_, Cell* cell_) noexcept;
            inline void rotate(double theta_, double phi_) noexcept;
            inline void set_dir(const vec3& dir_) noexcept;
            inline void multiply_weight(double mult_) noexcept;
        };



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
         *
         *  @pre    dir_ must be normalised.
         *  @pre    wavelength_ must be non-negative.
         *  @pre    energy_ must be positive.
         *  @pre    time_ must be non-negative.
         */
        inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_, const double energy_, const double time_) noexcept
          : _pos(pos_)
          , _dir(dir_)
          , _wavelength(wavelength_)
          , _energy(energy_)
          , _time(time_)
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
         *  @param  cell_       Current domain cell the photon is within.
         *
         *  @pre    ref_index_ must be greater than, or equal to, unity.
         *  @pre    cell_ must intersect the photon's position.
         */
        inline void Photon::move(const double dist_, const double ref_index_, Cell* cell_) noexcept
        {
            assert(ref_index_ >= 1.0);
            assert(cell_->intersect(_pos));

            _pos += _dir * dist_;
            _time += ((dist_ * ref_index_) / consts::phys::SPEED_OF_LIGHT);

            cell_->add_energy(dist_ * _energy * _weight);
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
#endif // ARCTK_PHYS_PHOTON_HPP
