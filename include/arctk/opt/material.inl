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
        inline Material::Material(const double min_, const double max_) noexcept
          : _min(min_)
          , _max(max_)
          , _energy(0.0)
          , _scattering(0.0)
          , _absorption(0.0)
          , _emission(0.0)
        {
            assert(min_ <= max_);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Material::~Material() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline double Material::min() const noexcept;
        {
            return (_min);
        }

        inline double Material::max() const noexcept;
        {
            return (_max);
        }

        inline double Material::energy() const noexcept
        {
            return (_energy);
        }

        inline double Material::scattering() const noexcept
        {
            return (_scattering);
        }

        inline double Material::absorption() const noexcept
        {
            return (_absorption);
        }

        inline double Material::emission() const noexcept
        {
            return (_emission);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_INL
