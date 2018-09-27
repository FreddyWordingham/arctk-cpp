/**
 *  @file   arctk/phys/particle/photon.hpp
 *  @date   27/09/2018
 *  @author Freddy Wordingham
 *
 *  Photon particle physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_PARTICLE_PHOTON_HPP
#define ARCTK_PHYS_PARTICLE_PHOTON_HPP



//  == IMPORTS ==
//  -- Std --
#include <stack>

//  -- Arctk --
#include <arctk/equip.hpp>
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
             *  Photon particle class.
             */
            class Photon
            {
                //  == FIELDS ==
              private:
                //  -- Properties --
                const double _wavelength;

                //  -- Tracking --
                equip::Entity*             _cur_ent;
                std::stack<equip::Entity*> _ent_stack;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Photon(const vec3& pos_, const vec3& dir_, const equip::Entity* cur_ent_, double time_ = 0.0) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double wavelength() const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double _wavelength, const equip::Entity* cur_ent_, const double time_) noexcept
              : Particle(pos_, dir_, time_)
              , _wavelength(wavelength_)
              , _cur_ent(cur_ent_)
            {
                PRE((wavelength_ > 0.0) && (wavelength_ < 1000e-9));
                PRE(cur_ent_ != nullptr)
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Photon::wavelength() const noexcept
            {
                return (_wavelength);
            }



        } // namespace particle
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_PHOTON_HPP
