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
            inline Material(const vec3& pos_, const vec3& dir_) noexcept;
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
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==



    } // namespace phys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PHYS_MATERIAL_HPP
