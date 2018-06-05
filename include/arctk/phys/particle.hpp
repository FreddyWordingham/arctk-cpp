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
            Particle(const math::Vec3<double>& pos_, const math::Vec3<double>& dir_);


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const math::Vec3<double>& pos() noexcept;
            inline const math::Vec3<double>& dir() noexcept;

            //  -- Setters --
            inline void move(double dist_) noexcept;
            inline void rotate(double azi_, double dec_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        Particle::Particle(const math::Vec3<double>& pos_, const math::Vec3<double>& dir_)
          : _pos(pos_)
          , _dir(dir_)
        {
            assert(dir_.normalised());
        }



        //  == METHODS ==
        //  -- Getters --
        inline const math::Vec3<double>& Particle::pos() noexcept
        {
            return (_pos);
        }

        inline const math::Vec3<double>& Particle::dir() noexcept
        {
            return (_dir);
        }


        //  -- Setters --
        inline void Particle::move(const double dist_) noexcept
        {
            _pos += _dir * dist_;
        }

        inline void Particle::rotate(const double azi_, const double dec_) noexcept
        {
        }



    } // namespace phys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_HPP
