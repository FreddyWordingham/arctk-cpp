/**
 *  @file   arctk/opt/material.hpp
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_HPP
#define ARCTK_OPT_MATERIAL_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == CLASS ==
        /**
         *  Optical material class.
         */
        class Material
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            const double _min; //!< Minimum valid wavelength of the material.
            const double _max; //!< Maximum valid wavelength of the material.

            //  -- Properties --
            double _energy;
            double _scattering;
            double _absorption;
            double _emission;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Material() noexcept;
            inline Material(const Material&) noexcept = default; //!< Defaulted copy constructor.
            inline Material(Material&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Material() noexcept;

            //  -- Cloning --
            virtual std::unique_ptr<Material> clone() const = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Material& operator=(const Material&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Material& operator=(Material&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                   energy() const noexcept;
            inline double                   scattering() const noexcept;
            inline double                   absorption() const noexcept;
            inline double                   emission() const noexcept;
            virtual std::unique_ptr<Driver> driver() const noexcept = 0;
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/material.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_HPP
