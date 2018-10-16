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
            PRE(dir_.normalised());
            PRE(wavelength_ > 0.0);
            PRE(energy_ > 0.0);
            PRE(time_ >= 0.0);
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

        inline double Photon::wavelength() const noexcept
        {
            return (_wavelength);
        }

        inline double Photon::energy() const noexcept
        {
            return (_energy);
        }

        inline double Photon::time() const noexcept
        {
            return (_time);
        }

        inline double Photon::weight() const noexcept
        {
            return (_weight);
        }


        //  -- Setters --
        inline void Photon::move(const double dist_, const double ref_index_, Cell* cell_) noexcept
        {
            PRE(ref_index_ >= 1.0);

            _pos += _dir * dist_;
            _time += ((dist_ * ref_index_) / consts::phys::SPEED_OF_LIGHT);

            cell_->add_energy(dist_ * _energy * _weight);
        }

        inline void Photon::rotate(const double theta_, const double phi_) noexcept
        {
            PRE(_dir.normalised());

            vec3 front = _dir;
            vec3 right = math::compare::equal(std::fabs(_dir.z), 1.0) ? (_dir ^ vec3(1.0, 0.0, 0.0)) : (_dir ^ vec3(0.0, 0.0, 1.0));
            right.normalise();

            _dir.rotate(right, theta_);
            _dir.rotate(front, phi_);

            _dir.normalise();

            POST(_dir.normalised());
        }

        inline void Photon::set_dir(const vec3& dir_) noexcept
        {
            PRE(dir_.normalised());

            _dir = dir_;
        }

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
