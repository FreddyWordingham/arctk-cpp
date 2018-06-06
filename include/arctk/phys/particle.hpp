/**
 *  @file   arctk/phys/particle.hpp
 *  @date   05/06/2018
 *  @author Freddy Wordingham
 *
 *  Particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PARTICLE_HPP
#define ARCTK_PHYS_PARTICLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
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
            //  -- Spatial --
            math::Vec3<double> _pos; //!< Position of the particle.
            math::Vec3<double> _dir; //!< Direction of travel.



            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Particle(const math::Vec3<double>& pos_, const math::Vec3<double>& dir_) noexcept;

            //  -- Destructors --
            virtual inline ~Particle() noexcept = default;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const math::Vec3<double>& pos() noexcept;
            inline const math::Vec3<double>& dir() noexcept;

            //  -- Setters --
            inline void move(double dist_) noexcept;
            inline void rotate(double theta_, double phi_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a particle at a given position travelling in a given direction.
         *
         *  @param  pos_    Position to start at.
         *  @param  dir_    Direction of travel.
         *
         *  @pre    dir_ must be normalised.
         */
        inline Particle::Particle(const math::Vec3<double>& pos_, const math::Vec3<double>& dir_) noexcept
          : _pos(pos_)
          , _dir(dir_)
        {
            assert(dir_.normalised());
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the position of the particle.
         *
         *  @return Position of the particle.
         */
        inline const math::Vec3<double>& Particle::pos() noexcept
        {
            return (_pos);
        }

        /**
         *  Get the direction of the particle.
         *
         *  @return Direction of the particle.
         */
        inline const math::Vec3<double>& Particle::dir() noexcept
        {
            return (_dir);
        }


        //  -- Setters --
        /**
         *  Move the particle along it's current direction by a given distance.
         *
         *  @param  dist_   Distance to travel.
         *
         *  @pre    dist_ must be positive.
         */
        inline void Particle::move(const double dist_) noexcept
        {
            assert(dist_ > 0.0);

            _pos += _dir * dist_;
        }

        /**
         *  Rotate the particle such that it faces a new direction.
         *
         *  @param  theta_  Angle to rotate back on itself.
         *  @param  phi_    Angle to rotate around previous axis of travel.
         */
        inline void Particle::rotate(const double theta_, const double phi_) noexcept
        {
            math::Vec3<double> front = _dir;
            math::Vec3<double> right = _dir ^ math::Vec3<double>(0.0, 0.0, 1.0);

            _dir.rotate(right, theta_);
            _dir.rotate(front, phi_);
        }



    } // namespace phys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_HPP
