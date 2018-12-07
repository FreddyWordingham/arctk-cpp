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
        inline double Material::min() const noexcept
        {
            return (_min);
        }

        inline double Material::max() const noexcept
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

        inline const std::map<std::string, double>& Material::data() const noexcept
        {
            return (_data);
        }


        //  -- Setters --
        inline void Material::add_energy(const double energy_) noexcept
        {
            assert(energy_ > 0.0);

            _energy += energy_;
        }

        inline void Material::add_scattering(const double scattering_) noexcept
        {
            assert(scattering_ > 0.0);

            _scattering += scattering_;
        }

        inline void Material::add_absorption(const double absorption_) noexcept
        {
            assert(absorption_ >= 0.0);

            _absorption += absorption_;
        }

        inline void Material::add_emission(const double emission_) noexcept
        {
            assert(emission_ > 0.0);

            _emission += emission_;
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_INL
