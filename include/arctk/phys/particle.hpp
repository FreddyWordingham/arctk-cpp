/**
 *  @file   arctk/phys/particle.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PARTICLE_HPP
#define ARCTK_PHYS_PARTICLE_HPP



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



        //  == CLASS ==
        /**
         *  Physical particle class.
         */
        class Particle
        {
            //  == FIELDS ==
          private:
            //  -- Statistical --
            double _weight; //!< Statistical weight of the photon.

          protected:
            //  -- Spatial --
            vec3 _pos; //!< Position of the particle.
            vec3 _dir; //!< Direction of travel.

            //  -- Temporal --
            double _time; //!< Current timestamp.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Particle(const vec3& pos_, const vec3& dir_, double time_ = 0.0) noexcept;
            inline Particle(const Particle&) = default; //!< Defaulted copy constructor.
            inline Particle(Particle&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Particle() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Particle& operator=(const Particle&) = default;     //!< Defaulted copy operator. @return Reference to copied object.
            inline Particle& operator=(Particle&&) noexcept = default; //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3& pos() const noexcept;
            inline const vec3& dir() const noexcept;
            inline double      time() const noexcept;

            //  -- Setters --
            inline void         set_pos(const vec3& pos_) noexcept;
            inline void         set_dir(const vec3& dir_) noexcept;
            inline void         multiply_weight(double m_) noexcept;
            virtual inline void move(double dist_) noexcept;
            inline void         rotate(double theta_, double phi_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a particle at a given position travelling in a given direction.
         *
         *  @param  pos_    Position to start at.
         *  @param  dir_    Direction of travel.
         *  @param  time_   Time of emission.
         *
         *  @pre    dir_ must be normalised.
         *  @pre    time_ must be non-negative.
         */
        inline Particle::Particle(const vec3& pos_, const vec3& dir_, const double time_) noexcept
          : _weight(1.0)
          , _pos(pos_)
          , _dir(dir_)
          , _time(time_)
        {
            PRE(dir_.normalised());
            PRE(time_ >= 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the position of the particle.
         *
         *  @return Position of the particle.
         */
        inline const vec3& Particle::pos() const noexcept
        {
            return (_pos);
        }

        /**
         *  Get the direction of the particle.
         *
         *  @return Direction of the particle.
         */
        inline const vec3& Particle::dir() const noexcept
        {
            return (_dir);
        }

        /**
         *  Get the time of the particle.
         *
         *  @return Time of the particle.
         */
        inline double Particle::time() const noexcept
        {
            return (_time);
        }


        //  -- Setters --
        /**
         *  Set the position of the particle.
         *
         *  @param  pos_    Position to set for particle.
         */
        inline void Particle::set_pos(const vec3& pos_) noexcept
        {
            _pos = pos_;
        }

        /**
         *  Set the direction of the particle.
         *
         *  @param  dir_    Direction to set for particle.
         *
         *  @pre    dir_ must be normalised.
         */
        inline void Particle::set_dir(const vec3& dir_) noexcept
        {
            PRE(dir_.normalised());

            _dir = dir_;
        }

        /**
         *  Multiply the weight of the photon.
         *
         *  @param  m_  Multiplier.
         *
         *  @pre    m_ must be non-negative.
         */
        inline void Particle::multiply_weight(const double m_) noexcept
        {
            PRE(m_ >= 0.0);

            _weight *= m_;
        }

        /**
         *  Move the particle along it's current direction by a given distance.
         *
         *  @param  dist_   Distance to travel.
         *
         *  @pre    dist_ must be positive.
         *  @pre    _dir must be normalised.
         */
        inline void Particle::move(const double dist_) noexcept
        {
            PRE(dist_ > 0.0);
            PRE(_dir.normalised());

            _pos += _dir * dist_;
        }

        /**
         *  Rotate the particle such that it faces a new direction.
         *
         *  @param  theta_  Angle to rotate back on itself.
         *  @param  phi_    Angle to rotate around previous axis of travel.
         *
         *  @pre    _dir must be normalised.
         *
         *  @post   _dir must be normalised.
         */
        inline void Particle::rotate(const double theta_, const double phi_) noexcept
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



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_HPP
