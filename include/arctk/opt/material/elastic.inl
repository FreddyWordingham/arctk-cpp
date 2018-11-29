/**
 *  @file   arctk/opt/material/elastic.inl
 *  @date   28/11/2018
 *  @author Freddy Wordingham
 *
 *  Elastic scattering material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MATERIAL_ELASTIC_INL
#define ARCTK_OPT_MATERIAL_ELASTIC_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/opt/driver/elastic.hpp>
#include <arctk/phys/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {
        namespace material //! material namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Elastic::Elastic(const std::vector<double>& wavelengths_, const std::vector<double>& ref_indexs_, const std::vector<double>& scat_coefs_, const std::vector<double>& abs_coefs_, const std::vector<double>& asyms_) noexcept
              : Material(wavelengths_.front(), wavelengths_.back())
              , _ref_index(wavelengths_, ref_indexs_)
              , _scat_coef(wavelengths_, scat_coefs_)
              , _abs_coef(wavelengths_, abs_coefs_)
              , _asym(wavelengths_, asyms_)
            {
            }


            //  -- Cloning --
            inline std::unique_ptr<Material> Elastic::clone() const
            {
                return (std::make_unique<Elastic>(*this));
            }



            //  == METHODS ==
            //  -- Driver --
            inline std::unique_ptr<Driver> Elastic::driver(const phys::Photon& phot_) noexcept
            {
                return (std::make_unique<driver::Elastic>(this, _ref_index(phot_.wavelength()), _scat_coef(phot_.wavelength()), _abs_coef(phot_.wavelength()), _asym(phot_.wavelength())));
            }


            //  -- Evolve --
            inline void evolve(const double /*unused*/) noexcept override
            {
            }



        } // namespace material
    }     // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MATERIAL_ELASTIC_INL
