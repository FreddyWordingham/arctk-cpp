/**
 *  @file   arctk/phys/material.hpp
 *  @date   10/08/2018
 *  @author Freddy Wordingham
 *
 *  Material physics class.
 */



//  == GUARD ==
#ifndef ARCTK_PHYS_MATERIAL_HPP
#define ARCTK_PHYS_MATERIAL_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>
#include <arctk/phys/particle/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {



        //  == CLASS ==
        /**
         *  Physical material class.
         */
        class Material
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Material(const Material&) = default; //!< Defaulted copy constructor.
            inline Material(Material&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Material() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Material& operator=(const Material&) = default;     //!< Defaulted copy operator. @return Reference to copied object.
            inline Material& operator=(Material&&) noexcept = default; //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline double interaction_dist(const particle::Photon& phot_) const noexcept = 0;
            virtual inline void   interact(particle::Photon& phot_) const noexcept               = 0;
        };



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_HPP
