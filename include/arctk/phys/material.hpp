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
          protected:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Particle(const vec3& pos_, const vec3& dir_) noexcept;
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
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_HPP
