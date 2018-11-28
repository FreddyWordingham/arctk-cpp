/**
 *  @file   arctk/opt/material.inl
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_INL
#define ARCTK_OPT_MATERIAL_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Material::Material() noexcept
          : _energy(0.0)
          , _scattering(0.0)
          , _absorption(0.0)
          , _emission(0.0)
        {
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Material::~Material() noexcept = default;



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_INL
