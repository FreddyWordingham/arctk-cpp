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
                const double _wavelength; //!< Wavelength of the photon.
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
                inline double               wavelength() const noexcept;
                inline const equip::Entity* entity() const noexcept;
                inline const equip::Entity* prev_entity() const noexcept;

                //  -- Traversal --
                inline bool enter_entity(equip::Entity* const ent_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a photon with a given position, direction, wavelength within a given entity.
             *
             *  @param pos_         Position of the photon.
             *  @param dir_         Direction of the photon.
             *  @param wavelength_  Wavelength of the photon.
             *  @param cur_ent_     Current entity containing the photon.
             *  @param energy_      Initial energy associated within the photon.
             *  @param time_        Initial time of the photon.
             *
             *  @pre    dir_ must be normalised.
             *  @pre    wavelength_ must be greater than zero and less than 1000nm.
             *  @pre    energy_ must be positive.
             *  @pre    cur_ent_ may not be nullptr.
             */
            inline Photon::Photon(const vec3& pos_, const vec3& dir_, const double wavelength_, equip::Entity* const cur_ent_, const double energy_, const double time_) noexcept
              : Particle(pos_, dir_, time_)
              , _wavelength(wavelength_)
              , _energy(energy_)
              , _cur_ent(cur_ent_)
            {
                PRE(dir_.normalised());
                PRE((wavelength_ > 0.0) && (wavelength_ < 1000e-9));
                PRE(energy_ > 0.0);
                PRE(cur_ent_ != nullptr);
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
             *  Get the pointer to the entity currently containing the photon.
             *
             *  @return Pointer to the entity currently containing the photon.
             */
            inline const equip::Entity* Photon::entity() const noexcept
            {
                return (_cur_ent);
            }

            /**
             *  Get the pointer to the last entity containing the photon.
             *
             *  @return Pointer to the last entity containing the photon.
             */
            inline const equip::Entity* Photon::prev_entity() const noexcept
            {
                PRE(_ent_stack.size() >= 1);

                return (_ent_stack.top());
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
