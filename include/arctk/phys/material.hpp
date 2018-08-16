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
#include <arctk/phys/optical.hpp>
#include <arctk/phys/particle/photon.hpp>
#include <arctk/random.hpp>



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
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const double _min; //!< Minimum valid wavelength of the material.
            const double _max; //!< Maximum valid wavelength of the material.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Material(double min_, double max_) noexcept;
            noexcept inline Material(const Material&) noexcept = default; //!< Defaulted copy constructor.
            inline Material(Material&&) noexcept               = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Material() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Material& operator=(const Material&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Material& operator=(Material&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double min() const noexcept;
            inline double max() const noexcept;

            //  -- Properties --
            virtual inline Optical optical_props() const noexcept = 0;

            //  -- Interaction --
            virtual inline double interaction_dist(random::Generator* rng_, const particle::Photon& phot_, const Optical& opt_) const
              noexcept = 0; //!< Determine the distance until a material interaction occurs. @param  rng_    Random number generator.    @param  phot_   Photon to interact with.    @return Distance to interaction.
            virtual inline void interact(random::Generator* rng_, particle::Photon* phot_, const Optical& opt_) const
              noexcept = 0; //!< Perform an interaction on a given photon.   @param  rng_    Random number generator.    @param  phot_   Photon to interact with.
        };



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum wavelength bound of the material.
         *
         *  @return Minimum wavelength bound of the material.
         */
        inline double Material::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum wavelength bound of the material.
         *
         *  @return Maximum wavelength bound of the material.
         */
        inline double Material::max() const noexcept
        {
            return (_max);
        }



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_HPP
