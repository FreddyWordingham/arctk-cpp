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
#include <arctk/equip/entity.hpp>



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


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Getters --



        } // namespace particle
    }     // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_PARTICLE_PHOTON_HPP
