/**
 *  @file   arctk/opt/mat/basic.hpp
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Basic optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_BASIC_HPP
#define ARCTK_OPT_MATERIAL_BASIC_HPP



//  == BASE ==
#include <arctk/opt/material.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <vector>

//  -- Arctk --
#include <arctk/math/formula/linear.hpp>
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
        namespace material //! material namespace
        {



            //  == CLASS ==
            /**
             *  Material with basic optical properties.
             */
            class Basic : public Material
            {
                //  == INSTANTIATION ==
              private:
                //  -- Optical Properties --
                const math::formula::Linear _ref_index; //!< Refractive index.
                const math::formula::Linear _scat_coef; //!< Scattering coefficient.
                const math::formula::Linear _abs_coef;  //!< Absorption coefficient.
                const math::formula::Linear _asym;      //!< Asymmetry factor.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --

              private:
                //  -- Initialisation --



                //  == METHODS ==
              public:
            };



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/opt/mat/basic.inl>



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_BASIC_HPP
