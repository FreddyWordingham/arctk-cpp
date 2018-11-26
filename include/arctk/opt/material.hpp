/**
 *  @file   arctk/opt/material.hpp
 *  @date   26/11/2018
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

//  -- Arctk --
#include <arctk/opt/slice.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace phys //! physics namespace
    {
        class Photon;
    } // namespace phys
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {



        //  == CLASS ==
        /**
         *  Optical properties material capable of generating specific optical property slices.
         */
        class Material
        {
            //  == INSTANTIATION ==
          private:
            //  -- Bounds --
            double _min; //!< Minimum valid wavelength of the material.
            double _max; //!< Maximum valid wavelength of the material.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Material(double min_, double max_) noexcept;
            inline Material(const Material&) = default; //!< Defaulted copy constructor.
            inline Material(Material&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual ~Material() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Material& operator=(const Material&) noexcept = default; //!< Default copy operator. @return Reference to copied object.
            inline Material& operator=(Material&&) noexcept = default;      //!< Default move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double min() const noexcept;
            inline double max() const noexcept;

            //  -- Specific Optical Properties --
            virtual std::unique_ptr<Slice> slice(const phys::Photon& phot_) const noexcept = 0;
        };



    } // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/material.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_HPP
