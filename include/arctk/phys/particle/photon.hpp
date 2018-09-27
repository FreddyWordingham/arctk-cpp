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
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/particle.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {



        //  == CLASS PROTOTYPES ==
        class Entity;



    } // namespace equip



    namespace phys //! physics namespace
    {
        namespace particle //! particle namespace
        {



            //  == CLASS ==
            /**
             *  Photon particle class.
             */
            class Photon : public Particle
            {
                //  == FIELDS ==
              private:
                //  -- Properties --
                const double _wavelength;
                const double _energy;

                //  -- Tracking --
                equip::Entity*             _cur_ent;
                std::stack<equip::Entity*> _ent_stack;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Photon(const vec3& pos_, const vec3& dir_, double wavelength_, equip::Entity* const cur_ent_, double energy_ = 1.0, double time_ = 0.0) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double wavelength() const noexcept;

                //  -- Traversal --
                inline bool enter_entity(equip::Entity* const ent_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_, equip::Entity* const cur_ent_, const double energy_, const double time_) noexcept
              : Particle(pos_, dir_, time_)
              , _wavelength(wavelength_)
              , _energy(energy_)
              , _cur_ent(cur_ent_)
            {
                PRE((wavelength_ > 0.0) && (wavelength_ < 1000e-9));
                PRE(energy_ > 0.0);
                PRE(cur_ent_ != nullptr);
            }



            //  == METHODS ==
            //  -- Getters --
            inline double Photon::wavelength() const noexcept
            {
                return (_wavelength);
            }


            //  -- Traversal --
            /**
             *  Determine if the photon will enter, or exit, a given entity.
             *
             *  @param  ent_    Entity boundary to cross.
             *
             *  @return True if entering the entity, false if exiting it.
             */
            inline bool Photon::enter_entity(equip::Entity* const ent_) noexcept
            {
                if (ent_ == _cur_ent)
                {
                    PRE(_ent_stack.size() >= 1);

                    _cur_ent = _ent_stack.top();
                    _ent_stack.pop();

                    return (false);
                }

                _ent_stack.push(_cur_ent);
                _cur_ent = ent_;

                return (true);
            }



        } // namespace particle
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_PHOTON_HPP
